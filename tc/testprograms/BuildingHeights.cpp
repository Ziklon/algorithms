#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;
#define MAXN 4005
#define INF 1<<29

int dp[MAXN];

struct BuildingHeights {
    int minimum(vector <int> heights) {
        int ans = 0;
        int N = heights.size();

        for(int i = 0; i < MAXN; ++i) dp[i] = INF;

        dp[0] = dp[1] = 0;
        
        sort(all(heights));
    
        for(int i = 1; i < N; ++i) {
            int sum = 0;
            for(int j = i - 1; j >= 0; --j) {
                sum += heights[i] - heights[j];
                dp[i - j + 1] = min(dp[i - j + 1], sum);
            }
        }

        for(int i = 1; i <= N; ++i)ans ^= dp[i];
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
        cout << "Testing BuildingHeights (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1402855618;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        BuildingHeights _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int heights[] = {1, 5, 4, 3, 8};
            _expected = 22;
            _received = _obj.minimum(vector <int>(heights, heights + sizeof(heights) / sizeof(int)));
            break;
        }
        case 1: {
            int heights[] = {1, 2, 3};
            _expected = 2;
            _received = _obj.minimum(vector <int>(heights, heights + sizeof(heights) / sizeof(int)));
            break;
        }
        case 2: {
            int heights[] = {3, 4, 1, 6, 8, 1};
            _expected = 21;
            _received = _obj.minimum(vector <int>(heights, heights + sizeof(heights) / sizeof(int)));
            break;
        }
        case 3: {
            int heights[] = {990, 20, 2359, 1667, 51, 2455, 1659, 1093, 2015, 205, 656, 752, 1760, 1594, 857,
                             2033, 1868, 1932, 2408, 1518, 91, 2220, 1696, 1552, 933, 143, 1888, 1261, 2298, 1975,
                             929, 2139, 1994, 2139, 158, 896, 2093, 1816, 841, 459, 2020, 1496, 63, 131, 589, 919,
                             1015, 1308, 350, 922, 326, 1792, 641, 2021, 843, 425, 1015, 231, 1685, 2165, 1057,
                             1465, 655, 550, 1103, 812, 297, 2048, 1479, 1137, 6, 2350, 1484, 1420, 1332, 925, 2338,
                             1198, 2232, 1539, 2119, 57, 830, 1611, 929, 525, 888
                            };
            _expected = 56068;
            _received = _obj.minimum(vector <int>(heights, heights + sizeof(heights) / sizeof(int)));
            break;
        }
        /*case 4:
        {
        	int heights[] = ;
        	_expected = ;
        	_received = _obj.minimum(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
        }*/
        /*case 5:
        {
        	int heights[] = ;
        	_expected = ;
        	_received = _obj.minimum(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
        }*/
        /*case 6:
        {
        	int heights[] = ;
        	_expected = ;
        	_received = _obj.minimum(vector <int>(heights, heights+sizeof(heights)/sizeof(int))); break;
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
