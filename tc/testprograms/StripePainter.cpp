#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;
#define MAXN 55
int dp[MAXN][MAXN];
string s;
int go(int first, int last) {
    if(first > last)return 0;
    if(first == last)return 1;
    int& ref = dp[first][last];
    if(ref != -1)return ref;
    ref = 1 << 20;
    if(s[first] == s[last])
        ref = min(ref, go(first + 1, last));
    for(int k = first; k < last; ++k)
        ref = min(ref, go(first, k) + go(k + 1, last));
    return ref;
}


struct StripePainter {
    int minStrokes(string stripes) {
        memset(dp, -1, sizeof dp);
        s = stripes;
        return go(0,s.size()-1);
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
        cout << "Testing StripePainter (500.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1402968815;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 500.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        StripePainter _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            string stripes = "RGBGR";
            _expected = 3;
            _received = _obj.minStrokes(stripes);
            break;
        }
        case 1: {
            string stripes = "RGRG";
            _expected = 3;
            _received = _obj.minStrokes(stripes);
            break;
        }
        case 2: {
            string stripes = "ABACADA";
            _expected = 4;
            _received = _obj.minStrokes(stripes);
            break;
        }
        case 3: {
            string stripes = "AABBCCDDCCBBAABBCCDD";
            _expected = 7;
            _received = _obj.minStrokes(stripes);
            break;
        }
        case 4: {
            string stripes = "BECBBDDEEBABDCADEAAEABCACBDBEECDEDEACACCBEDABEDADD";
            _expected = 26;
            _received = _obj.minStrokes(stripes);
            break;
        }
        /*case 5:
        {
        	string stripes = ;
        	_expected = ;
        	_received = _obj.minStrokes(stripes); break;
        }*/
        /*case 6:
        {
        	string stripes = ;
        	_expected = ;
        	_received = _obj.minStrokes(stripes); break;
        }*/
        /*case 7:
        {
        	string stripes = ;
        	_expected = ;
        	_received = _obj.minStrokes(stripes); break;
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
