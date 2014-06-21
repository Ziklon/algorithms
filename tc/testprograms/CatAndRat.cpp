#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
#define PI atan(1)*4
using namespace std;
typedef long long ll;

struct CatAndRat {
    double getTime(int R, int T, int Vrat, int Vcat) {
        double dt = PI * R;
        double pos = min(1.*Vrat * T, dt);
        if(Vcat <= Vrat)return -1;
        return pos / (Vcat - Vrat);
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
        cout << "Testing CatAndRat (450.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1402537980;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 450.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        CatAndRat _obj;
        double _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int R = 10;
            int T = 1;
            int Vrat = 1;
            int Vcat = 1;
            _expected = -1.0;
            _received = _obj.getTime(R, T, Vrat, Vcat);
            break;
        }
        case 1: {
            int R = 10;
            int T = 1;
            int Vrat = 1;
            int Vcat = 2;
            _expected = 1.0;
            _received = _obj.getTime(R, T, Vrat, Vcat);
            break;
        }
        case 2: {
            int R = 10;
            int T = 1;
            int Vrat = 2;
            int Vcat = 1;
            _expected = -1.0;
            _received = _obj.getTime(R, T, Vrat, Vcat);
            break;
        }
        case 3: {
            int R = 1000;
            int T = 1000;
            int Vrat = 1;
            int Vcat = 1000;
            _expected = 1.001001001001001;
            _received = _obj.getTime(R, T, Vrat, Vcat);
            break;
        }
        case 4: {
            int R = 1;
            int T = 1000;
            int Vrat = 1;
            int Vcat = 2;
            _expected = 3.141592653589793;
            _received = _obj.getTime(R, T, Vrat, Vcat);
            break;
        }
        /*case 5:
        {
        	int R = ;
        	int T = ;
        	int Vrat = ;
        	int Vcat = ;
        	_expected = ;
        	_received = _obj.getTime(R, T, Vrat, Vcat); break;
        }*/
        /*case 6:
        {
        	int R = ;
        	int T = ;
        	int Vrat = ;
        	int Vcat = ;
        	_expected = ;
        	_received = _obj.getTime(R, T, Vrat, Vcat); break;
        }*/
        /*case 7:
        {
        	int R = ;
        	int T = ;
        	int Vrat = ;
        	int Vcat = ;
        	_expected = ;
        	_received = _obj.getTime(R, T, Vrat, Vcat); break;
        }*/
        default:
            return 0;
        }
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        double _elapsed = (double)(clock() - _start) / CLOCKS_PER_SEC;
        if (abs(_expected - _received) < 1e-9 || (_received > min(_expected * (1.0 - 1e-9), _expected * (1.0 + 1e-9)) && _received < max(_expected * (1.0 - 1e-9), _expected * (1.0 + 1e-9))))
            cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
        else {
            cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
            cout.precision(10);
            cout << "           Expected: " << _expected << endl;
            cout << "           Received: " << _received << endl;
        }
    }
}

// END CUT HERE
