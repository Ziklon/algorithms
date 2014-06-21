#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;
#define INF 1<<25
int can[55];

int dp[55], n, m;

int go(int idx, vector<string>& v) {
    if(idx >= n)return 0;
    int& ref = dp[idx];
    if(ref != -1)return ref;
    ref = INF;

    int prev = idx - 1;

    vector<set<char> > vs(m);

    for(int k = 0; k < can[idx]; ++k) {

        for(int j = 0; j < m; ++j)vs[j].insert(v[idx + k][j]);

        int need1 = 0, need2 = 0;
        set<char> ss;
        for(int j = 0; j < m; ++j) {
            if(!vs[j].count(v[prev][j]))ss.insert(v[idx][j]);
        }
        ss.erase('?');
        
        need1 = ss.size();
        if(ss.size() == 0)need1 = 1;
        ref = min(ref, go(idx + k + 1, v) + need1 + need2 + 1 + k);
    }

    return ref;
}


struct SwitchingGame {
    int timeToWin(vector <string> states) {
        n = states.size() + 1;
        m = states[0].size();

        states.insert(states.begin(), string(m, '-'));

        for(int i = 0; i < n; ++i) {
            int cnt = 1;
            vector<set<char> > vs(m);
            for(int k = 0; k < m; ++k)vs[k].insert(states[i][k]);

            for(int j = i + 1; j < n; ++j) {
                bool ok = 1;
                for(int k = 0; k < m; ++k) {
                    if(states[j][k] == '+' && vs[k].count('-'))ok = 0;
                    if(states[j][k] == '-' && vs[k].count('+'))ok = 0;
                    vs[k].insert(states[j][k]);
                }
                if(!ok)break;
                cnt++;
            }
            can[i] = cnt;
        }
        memset(dp, -1, sizeof dp);

        return go(1, states);


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
        cout << "Testing SwitchingGame (350.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1402156811;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 350.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        SwitchingGame _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            string states[] = {"++--",
                               "--++"
                              };
            _expected = 5;
            _received = _obj.timeToWin(vector <string>(states, states + sizeof(states) / sizeof(string)));
            break;
        }
        case 1: {
            string states[] = {"+-++",
                               "+-++"
                              };
            _expected = 3;
            _received = _obj.timeToWin(vector <string>(states, states + sizeof(states) / sizeof(string)));
            break;
        }
        case 2: {
            string states[] = {"++",
                               "+?",
                               "?+",
                               "++"
                              };
            _expected = 5;
            _received = _obj.timeToWin(vector <string>(states, states + sizeof(states) / sizeof(string)));
            break;
        }
        case 3: {
            string states[] = {"+",
                               "?",
                               "?",
                               "?",
                               "-"
                              };
            _expected = 7;
            _received = _obj.timeToWin(vector <string>(states, states + sizeof(states) / sizeof(string)));
            break;
        }
        case 4: {
            string states[] = {"+??+++",
                               "++??+-",
                               "?++??+",
                               "?-+-??",
                               "??+?++",
                               "++-?+?",
                               "?++?-+",
                               "?--+++",
                               "-??-?+"
                              };
            _expected = 20;
            _received = _obj.timeToWin(vector <string>(states, states + sizeof(states) / sizeof(string)));
            break;
        }
        /*case 5:
        {
        	string states[] = ;
        	_expected = ;
        	_received = _obj.timeToWin(vector <string>(states, states+sizeof(states)/sizeof(string))); break;
        }*/
        /*case 6:
        {
        	string states[] = ;
        	_expected = ;
        	_received = _obj.timeToWin(vector <string>(states, states+sizeof(states)/sizeof(string))); break;
        }*/
        /*case 7:
        {
        	string states[] = ;
        	_expected = ;
        	_received = _obj.timeToWin(vector <string>(states, states+sizeof(states)/sizeof(string))); break;
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
