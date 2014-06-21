#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;
#define MAXN 55
int e[MAXN][MAXN], g[MAXN][MAXN];


struct BuildingRoutes {
    int build(vector <string> dist, int T) {
        int ans = 0;
        int n = dist.size();
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                e[i][j] = g[i][j] = dist[i][j] - '0';


        for(int k = 0; k < n; ++k)
            for(int i = 0; i < n; ++i)
                for(int j = 0; j < n; ++j)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);

        for(int x = 0; x < n; ++x)
            for(int y = 0; y < n; ++y){
                    int cnt = 0;
                    for(int i = 0; i < n; ++i)
                        for(int j = 0; j < n; ++j)
                            if(g[i][j] == g[i][x] + e[x][y] + g[y][j])cnt++;

                    if(cnt >= T)ans += e[x][y];
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
        cout << "Testing BuildingRoutes (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1401929339;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        BuildingRoutes _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            string dist[] = {"011",
                             "101",
                             "110"
                            };
            int T = 1;
            _expected = 6;
            _received = _obj.build(vector <string>(dist, dist + sizeof(dist) / sizeof(string)), T);
            break;
        }
        case 1: {
            string dist[] = {"033",
                             "309",
                             "390"
                            };
            int T = 1;
            _expected = 12;
            _received = _obj.build(vector <string>(dist, dist + sizeof(dist) / sizeof(string)), T);
            break;
        }
        case 2: {
            string dist[] = {"0123",
                             "1023",
                             "1203",
                             "1230"
                            };
            int T = 2;
            _expected = 5;
            _received = _obj.build(vector <string>(dist, dist + sizeof(dist) / sizeof(string)), T);
            break;
        }
        case 3: {
            string dist[] = {"05789654",
                             "10347583",
                             "65085479",
                             "55602398",
                             "76590934",
                             "57939045",
                             "12345608",
                             "68647640"
                            };
            int T = 3;
            _expected = 40;
            _received = _obj.build(vector <string>(dist, dist + sizeof(dist) / sizeof(string)), T);
            break;
        }
        /*case 4:
        {
        	string dist[] = ;
        	int T = ;
        	_expected = ;
        	_received = _obj.build(vector <string>(dist, dist+sizeof(dist)/sizeof(string)), T); break;
        }*/
        /*case 5:
        {
        	string dist[] = ;
        	int T = ;
        	_expected = ;
        	_received = _obj.build(vector <string>(dist, dist+sizeof(dist)/sizeof(string)), T); break;
        }*/
        /*case 6:
        {
        	string dist[] = ;
        	int T = ;
        	_expected = ;
        	_received = _obj.build(vector <string>(dist, dist+sizeof(dist)/sizeof(string)), T); break;
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
