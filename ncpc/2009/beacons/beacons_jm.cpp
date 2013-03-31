#include <cassert>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

//#define DEBUG
//#define VERBOSE_DEBUG

const int MAX_DEVICES = 2500;
const int MAX_OBSTACLES = 2500;

using namespace std;

const double PI = 3.141592653589793238462643;

typedef pair<double,double> TInterval;

bool overlaps(TInterval ival1, TInterval ival2)
{
	return ival2.second - ival1.first > 0.0 && ival1.second - ival2.first > 0.0;
}

bool overlaps(set<TInterval> &intervals, TInterval interval)
{
	set<TInterval>::iterator probe = lower_bound(intervals.begin(), intervals.end(), interval);
	if (probe != intervals.end() && overlaps(interval, *probe)) 
		return true;
	if (probe == intervals.begin())
		return false;
	probe--;
	return overlaps(interval, *probe);
}

bool circular_overlaps(set<TInterval> &intervals, TInterval interval)
{
	if (interval.second > interval.first)
		return overlaps(intervals, interval);

	TInterval ival1(interval.first, 2*PI);
	TInterval ival2(0, interval.second);
	
	return overlaps(intervals, ival1) || overlaps(intervals, ival2);
}

void insert(set<TInterval> &intervals, TInterval interval)
{
	if (intervals.size() == 0 || interval.second < intervals.begin()->first)
	{
		intervals.insert(interval);
		return;
	}

	TInterval startPoint = make_pair(interval.first, interval.first);
	TInterval endPoint = make_pair(interval.second, interval.second);

	// Find iterator to the first overlapping interval 
	// (or the first interval after it if no overlapping interval exist)
	set<TInterval>::iterator firstNode = lower_bound(intervals.begin(), intervals.end(), startPoint);
	if (firstNode != intervals.begin()) firstNode--;
	if (firstNode->second < interval.first) firstNode++;
	
	// Find iterator to the last overlapping interval
	// (or the first interval before it if no overlapping interval exist)
	set<TInterval>::iterator lastNode = lower_bound(intervals.begin(), intervals.end(), endPoint);
	if (lastNode == intervals.end() || (lastNode != intervals.begin() && lastNode->first != interval.second))
		lastNode--;

	// If no existing intervals overlap, firstNode will now be greater than lastNode
	if (firstNode == intervals.end() || firstNode->first > lastNode->first)
	{		
		intervals.insert(interval);
		return;
	}
	
	double mergedFirst = min(firstNode->first, interval.first);
	double mergedSecond = max(lastNode->second, interval.second);

	intervals.erase(firstNode, ++lastNode);	
	intervals.insert(make_pair(mergedFirst, mergedSecond));
}

void circular_insert(set<TInterval> &intervals, TInterval interval)
{
	if (interval.second > interval.first)
	{
		insert(intervals, interval);
	}
	else
	{
		insert(intervals, make_pair(interval.first, 2*PI));
		insert(intervals, make_pair(0, interval.second));
	}
}


void show(set<TInterval> &intervals)
{
	for(set<TInterval>::iterator i = intervals.begin(); i != intervals.end(); i++)
	{
		cout << "[" << i->first << "," << i->second << "]" << "  ";
	}
	cout << endl;
}

struct Object
{		
	double x, y, radius;
	double angle, theta, distance;
	int index;
	TInterval interval;
	
	Object() {}
	
	Object(int xx, int yy, int rr) {
		x = xx;
		y = yy;
		radius = rr;
		
	}
	
	Object operator-(const Object &offset) const
	{
		Object res(x - offset.x, y - offset.y, radius);
		res.index = index;
		return res;
	}
	
	bool operator<(const Object &other) const
	{
		return distance < other.distance;
	}

	void calc()
	{
		angle = atan2(y, x);
		int distanceSquared = x*x + y*y;
		distance = sqrt(distanceSquared);
		if (radius > 0)
		{
			theta = asin(radius/distance);
			assert(theta >= 0);
			distance = sqrt(distanceSquared - radius*radius);
		}
		else
		{
			theta = 1e-9;
		}
		
		angle = fmod(angle + 2*PI, 2*PI);
		double fromAngle = fmod(angle - theta + 2*PI, 2*PI);
		double toAngle = fmod(angle + theta + 2*PI, 2*PI);
		
		interval = make_pair(fromAngle, toAngle);
	}
};

#ifdef DEBUG
bool hasEdge[MAX_DEVICES][MAX_DEVICES];
int noEdges = 0;
#endif

int main()
{
	int noDevices, noObstacles;
	cin >> noDevices >> noObstacles;
	
	vector<Object> devices(noDevices), obstacles(noObstacles);
	vector<int> component(noDevices);
	
	for (int i = 0; i < noDevices; i++) {
		cin >> devices[i].x >> devices[i].y;
		devices[i].index = i;
		component[i] = i;
	}
	
	for (int i = 0; i < noObstacles; i++) {
		cin >> obstacles[i].x >> obstacles[i].y >> obstacles[i].radius;
		obstacles[i].index = -1;
	}
	
	// Build graph by considering from each device which other devices are visible
	for (int i = 0; i < noDevices; i++)
	{
		Object* cur = &devices[i];
		
		// Sort remaining devices and obstacles according to distance
		// from the current device in ascending order. 
		// Maintain a circular set of blocked angles which is updated after each obstacle.
		// Note: distance for obstacles is not their centers but the distance to the sides of the circle
#ifdef VERBOSE_DEBUG
		cout << "Checking outgoing edges from point at " << devices[i].x << "," << devices[i].y << endl;
#endif	
		vector<Object> objects;
		for (int j = 0; j < noDevices; j++)
			if (i != j) 
				objects.push_back(devices[j] - *cur);
		for (int j = 0; j < noObstacles; j++)
			objects.push_back(obstacles[j] - *cur);
		
		for(int j = 0; j < objects.size(); j++)
			objects[j].calc();
			
		sort(objects.begin(), objects.end());
		
		set<TInterval> blockedView;
		
		for(vector<Object>::iterator o = objects.begin(); o != objects.end(); o++)
		{
			if (o->index >= 0)
			{
				// A point, check if visible
#ifdef VERBOSE_DEBUG	
				cout << "Check visibility to point at " << (o->x + cur->x) << "," << (o->y + cur->y) << "  (angle " << o->angle << ")" << endl;
#endif
				if (!circular_overlaps(blockedView, o->interval))
				{
#ifdef DEBUG
					cout << "Edge between " << i << " and " << o->index << endl;
					hasEdge[i][o->index] = true;
					noEdges++;
#endif				
					int oldComponent = component[o->index], newComponent = component[i];
					if (newComponent != oldComponent) 
					{
						for(int k=0; k<noDevices; k++)
							if (component[k] == oldComponent)
								component[k] = newComponent;
					}
				}
			}
			else
			{
				// An obstacle, add to blocking set
#ifdef VERBOSE_DEBUG				
				cout << "Adding blocking angle [" << o->interval.first << "," << o->interval.second << "]" << endl;
#endif
				circular_insert(blockedView, o->interval);
			}
		}
	}

#ifdef DEBUG
	for(int i=0; i<noDevices; i++)
		for(int j=i+1; j<noDevices; j++)
			if (hasEdge[i][j] != hasEdge[j][i])
				cerr << "Error - edge status between " << i << " and " << j << " differs." << endl;
	cout << noEdges << " edges" << endl;
#endif
	
	set<int> uniqueComponents(component.begin(), component.end());
	
	cout << uniqueComponents.size() - 1 << endl;
	
	return 0;
}
