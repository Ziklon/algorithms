#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
#define INF 1<<30
typedef long long ll;

struct TheNumbersWithLuckyLastDigit {
    int find(int n) {
        int ans = INF;

        for(int i = 0; i <= 10; ++i)
            for(int j = 0; j <= 10; ++j) {
                if(i+j == 0 )continue;    
                ll rest = (4 * i) + (j * 7);
                if(rest % 10 == (n % 10)  && rest <= n)
                    ans = min(ans, i + j);
            }
        if(ans == INF)return -1;
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
        cout << "Testing TheNumbersWithLuckyLastDigit (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1403385509;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        TheNumbersWithLuckyLastDigit _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int n = 99;
            _expected = 4;
            _received = _obj.find(n);
            break;
        }
        case 1: {
            int n = 11;
            _expected = 2;
            _received = _obj.find(n);
            break;
        }
        case 2: {
            int n = 13;
            _expected = -1;
            _received = _obj.find(n);
            break;
        }
        case 3: {
            int n = 1234567;
            _expected = 1;
            _received = _obj.find(n);
            break;
        }
        case 4: {
            int n = 10 ;
            _expected = -1;
            _received = _obj.find(n);
            break;
        }
        /*case 5:
        {
        	int n = ;
        	_expected = ;
        	_received = _obj.find(n); break;
        }*/
        /*case 6:
        {
        	int n = ;
        	_expected = ;
        	_received = _obj.find(n); break;
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
