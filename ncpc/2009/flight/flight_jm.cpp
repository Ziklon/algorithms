#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

const int INF = 999999999;
const int MIN = 4;
const int MAX = 2500;

struct Edge
{
	int x, y;
};

struct Node
{
	vector<Node*> neighbors;
	bool side;
	int maxDepth; // 0 = leaf, 1 = has a child that is leaf
	int maxDistance; // Distance to node farthest away in tree
	int maxPath; // Maximum length of path going through this node

	void build(Node* parent, bool side)
	{
		maxDepth = 0;
		this->side = side;
		for(int i=0; i<neighbors.size(); i++)
		{
			Node* child = neighbors[i];
			if (child == parent) continue;
			child->build(this, side);
			maxDepth = max(maxDepth, child->maxDepth + 1);
		}
	}

	void calcMaxDist(Node* parent, int maxDistBack)
	{
		// maxDistBack = max distance when starting with parent node

		maxPath = maxDistBack;
		maxDistance = maxDistBack;

		// Find the two children with the highest depths
		Node* c1 = 0, *c2 = 0;
		for(int i=0; i<neighbors.size(); i++)
		{
			Node* child = neighbors[i];
			if (child == parent) continue;
			if (!c1 || child->maxDepth > c1->maxDepth)
			{
				c2 = c1;
				c1 = child;
			}
			else if (!c2 || child->maxDepth > c2->maxDepth)
			{
				c2 = child;
			}

			maxDistance = max(maxDistance, child->maxDepth + 1);
		}
		if (c1 && c2)
		{
			// Path from one child through this node to another child
			int dist = 2 + c1->maxDepth + c2->maxDepth;
			maxPath = max(maxPath, dist);
		}
		if (c1)
		{
			// Path from one child through node and parent
			int dist = 1 + c1->maxDepth + maxDistBack;
			maxPath = max(maxPath, dist);
		}

		for(int i=0; i<neighbors.size(); i++)
		{
			Node* child = neighbors[i];
			if (child == parent) continue;

			int newMaxDistBack = maxDistBack + 1;
			if (c2)
			{
				// Or through another child
				int v = (c1 == child ? c2 : c1)->maxDepth + 2;
				newMaxDistBack = max(newMaxDistBack, v);
			}

			child->calcMaxDist(this, newMaxDistBack);
		}
	}
};

int main()
{
	int n;
	cin >> n;
	
	assert(n >= MIN && n <= MAX);
	
	vector<Node> nodes(n);
	vector<Edge> edges(n-1);

	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		assert(x >= 1 && x <= n);
		assert(y >= 1 && y <= n);
		assert(x != y);
		
		x--; y--;
		edges[i].x = x;
		edges[i].y = y;
		nodes[x].neighbors.push_back(&nodes[y]);
		nodes[y].neighbors.push_back(&nodes[x]);
	}
	
	nodes[0].build(0, false);
	nodes[0].calcMaxDist(0, 0);
	
	int currentMax = 0;
	for(int i=0; i<nodes.size(); i++)
		if (nodes[i].maxPath > currentMax)
			currentMax = nodes[i].maxPath;
			
	//cerr << "Current max: " << currentMax << endl;

	int best = INF;
	Edge bestOldEdge, bestNewEdge;
	for(int e = 0; e < edges.size(); e++)
	{
		Edge edge = edges[e];
		nodes[edge.x].build(&nodes[edge.y], true);
		nodes[edge.x].calcMaxDist(&nodes[edge.y], 0);
		
		nodes[edge.y].build(&nodes[edge.x], false);
		nodes[edge.y].calcMaxDist(&nodes[edge.x], 0);

		/*
		for (int i = 0; i < nodes.size(); i++)
		{
			Node *node = nodes[i];
			cout << (i+1) << " " << node->size << " " << node->maxDistance << " " << node->maxPath << endl;
		}
		cout << endl;
		*/

		int maxDist1 = INF, maxDist2 = INF;
		int x = -1, y = -1, worst = 0;
		for (int i = 0; i < nodes.size(); i++)
		{
			Node *node = &nodes[i];
			worst = max(worst, node->maxPath);
			if (node->side && node->maxDistance < maxDist1)
			{
				maxDist1 = node->maxDistance;
				x = i;
			}
			if (!node->side && node->maxDistance < maxDist2)
			{
				maxDist2 = node->maxDistance;
				y = i;
			}
		}
		worst = max(worst, maxDist1 + maxDist2 + 1);
		if (worst <= best)
		{
			best = worst;
			bestOldEdge = edge;
			bestNewEdge.x = x;
			bestNewEdge.y = y;
		}
	}
	
	assert(best < currentMax);

	cout << best << endl;
	cout << (bestOldEdge.x + 1) << " " << (bestOldEdge.y + 1) << endl;
	cout << (bestNewEdge.x + 1) << " " << (bestNewEdge.y + 1) << endl;
	
	return 0;
}
