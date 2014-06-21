#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

struct BuildingHeightsEasy {
    int minimum(int M, vector <int> heights) {
        int ans = INT_MAX;
        sort(all(heights));
        int N=heights.size();
        for(int i = M - 1; i < N; i++) {
            int cost = 0;
            for(int j = 1; j < M; ++j ) {
                cost+=heights[i]-heights[i-j];
            }
            ans=min(ans,cost);
        }
        return ans;
    }
};

// BEGIN CUT HERE
#include <ctime>
#include <cmath>
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cout << "Testing BuildingHeightsEasy (500.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1402965422;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 500.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        BuildingHeightsEasy _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int M = 2;
            int heights[] = {1, 2, 1, 4, 3};
            _expected = 0;
            _received = _obj.minimum(M, vector <int>(heights, heights + sizeof(heights) / sizeof(int)));
            break;
        }
        case 1: {
            int M = 3;
            int heights[] = {1, 3, 5, 2, 1};
            _expected = 2;
            _received = _obj.minimum(M, vector <int>(heights, heights + sizeof(heights) / sizeof(int)));
            break;
        }
        case 2: {
            int M = 1;
            int heights[] = {43, 19, 15};
            _expected = 0;
            _received = _obj.minimum(M, vector <int>(heights, heights + sizeof(heights) / sizeof(int)));
            break;
        }
        case 3: {
            int M = 3;
            int heights[] = {19, 23, 9, 12};
            _expected = 15;
            _received = _obj.minimum(M, vector <int>(heights, heights + sizeof(heights) / sizeof(int)));
            break;
        }
        case 4: {
            int M = 12;
            int heights[] = {25, 18, 38, 1, 42, 41, 14, 16, 19, 46, 42, 39, 38, 31, 43, 37, 26, 41, 33, 37, 45, 27, 19, 24, 33, 11, 22, 20, 36, 4, 4};
            _expected = 47;
            _received = _obj.minimum(M, vector <int>(heights, heights + sizeof(heights) / sizeof(int)));
            break;
        }
        case 5:
        {
        	int M = 1;
        	int heights[] ={1,2,3} ;
        	_expected = 0;
        	_received = _obj.minimum(M, vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
        }
        /*case 6:
        {
        	int M = ;
        	int heights[] = ;
        	_expected = ;
        	_received = _obj.minimum(M, vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
        }*/
        /*case 7:
        {
        	int M = ;
        	int heights[] = ;
        	_expected = ;
        	_received = _obj.minimum(M, vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
        }*/
        default:
            return 0;
        }
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        double _elapsed = (double)(clock() - _start) / CLOCKS_PER_SEC;
        if (_received == _expected)
            cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
        else {
            cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
            cout << "           Expected: " << _expected << endl;
            cout << "           Received: " << _received << endl;
        }
    }
}

// END CUT HERE
