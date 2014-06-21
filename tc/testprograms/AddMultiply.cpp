#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

struct AddMultiply {
    vector <int> makeExpression(int y) {
        vector <int> ans(3, 2);
        for(int i = 2;; ++i) {
            int yi = y - (i * i);
            if(abs(yi) >= 2) {
                ans[0] = ans[1] = i;
                ans[2]=(yi);
                return ans;
            }
        }
        //return ans;
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
        cout << "Testing AddMultiply (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1403183552;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        AddMultiply _obj;
        vector <int> _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int y = 6;
            int __expected[] = {2, 2, 2 };
            _expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
            _received = _obj.makeExpression(y);
            break;
        }
        case 1: {
            int y = 11;
            int __expected[] = {2, 3, 5 };
            _expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
            _received = _obj.makeExpression(y);
            break;
        }
        case 2: {
            int y = 0;
            int __expected[] = {7, 10, -70 };
            _expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
            _received = _obj.makeExpression(y);
            break;
        }
        case 3: {
            int y = 500;
            int __expected[] = { -400, -3, -700 };
            _expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
            _received = _obj.makeExpression(y);
            break;
        }
        case 4: {
            int y = 2;
            int __expected[] = {2, 2, -2 };
            _expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
            _received = _obj.makeExpression(y);
            break;
        }
        case 5: {
            int y = 5;
            int __expected[] = {5, 2, -5 };
            _expected = vector <int>(__expected, __expected + sizeof(__expected) / sizeof(int));
            _received = _obj.makeExpression(y);
            break;
        }
        /*case 6:
        {
        	int y = ;
        	int __expected[] = ;
        	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
        	_received = _obj.makeExpression(y); break;
        }*/
        /*case 7:
        {
        	int y = ;
        	int __expected[] = ;
        	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
        	_received = _obj.makeExpression(y); break;
        }*/
        /*case 8:
        {
        	int y = ;
        	int __expected[] = ;
        	_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
        	_received = _obj.makeExpression(y); break;
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
            cout << "           Expected: {";
            for (unsigned i = 0; i < _expected.size(); i++) {
                if (i) cout << ",";
                cout << " " << _expected[i];
            }
            cout << " }" << endl;
            cout << "           Received: {";
            for (unsigned i = 0; i < _received.size(); i++) {
                if (i) cout << ",";
                cout << " " << _received[i];
            }
            cout << " }" << endl;
        }
    }
}

// END CUT HERE
