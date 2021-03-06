#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <functional>
#include <numeric>
using namespace std;

#define all(V) (V).begin(),(V).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
class SpeedRadar {
public:
    double averageSpeed(int minLimit, int maxLimit, vector <int> readings) {
        double dev=0;
        int cnt=0;
        for(int i=0;i<readings.sz;i++){
           if(readings[i]>=minLimit && readings[i]<=maxLimit){
             dev+=readings[i];
             cnt++;
           }
        }
        if(100*(readings.sz-cnt)>(readings.sz*10))
          return 0;
        return dev/cnt;
    }
    //Powered by [Ziklon] 1.0!!

};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.4 (beta) modified by pivanof
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <int> p2, bool hasAnswer, double p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}";
	cout << "]" << endl;
	SpeedRadar *obj;
	double answer;
	obj = new SpeedRadar();
	clock_t startTime = clock();
	answer = obj->averageSpeed(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = fabs(p3 - answer) <= 1e-9 * max(1.0, fabs(p3));
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	vector <int> p2;
	double p3;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 50;
	int t2[] = {45,40,50};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 45.0;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 50;
	int t2[] = {42,43,44,45,46,47,48,49,50,51};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 46.0;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 50;
	int t2[] = {42,46,48,50,52};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0.0;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 20;
	p1 = 60;
	int t2[] = {25,45,45,43,24,9,51,55,60,34,61,23,40,40,47,49,33,23,47,54,54};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 41.68421052631579;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING// Powered by FileEdit
// Powered by CodeProcessor
