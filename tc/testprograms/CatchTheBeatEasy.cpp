#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

struct CatchTheBeatEasy {
    string ableToCatchAll(vector <int> x, vector <int> y) {
        int n = x.size();
        vector<pair<int, int> > v;
        for(int i = 0; i < n; ++i)v.push_back(make_pair(y[i], x[i]));

        sort(all(v));

        int x0 = 0, y0 = 0;
        for(int i = 0; i < n; ++i) {
            int xi = v[i].second, yi = v[i].first;
            if(abs(xi - x0) >  yi - y0)return "Not able to catch";
            x0 = xi;
            y0 = yi;
        }
        return "Able to catch";
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
        cout << "Testing CatchTheBeatEasy (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1402156377;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        CatchTheBeatEasy _obj;
        string _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int x[] = { -1, 1, 0};
            int y[] = {1, 3, 4};
            _expected = "Able to catch";
            _received = _obj.ableToCatchAll(vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)));
            break;
        }
        case 1: {
            int x[] = { -3};
            int y[] = {2};
            _expected = "Not able to catch";
            _received = _obj.ableToCatchAll(vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)));
            break;
        }
        case 2: {
            int x[] = { -1, 1, 0};
            int y[] = {1, 2, 4};
            _expected = "Not able to catch";
            _received = _obj.ableToCatchAll(vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)));
            break;
        }
        case 3: {
            int x[] = {0, -1, 1};
            int y[] = {9, 1, 3};
            _expected = "Able to catch";
            _received = _obj.ableToCatchAll(vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)));
            break;
        }
        case 4: {
            int x[] = {70, -108, 52, -70, 84, -29, 66, -33};
            int y[] = {141, 299, 402, 280, 28, 363, 427, 232};
            _expected = "Not able to catch";
            _received = _obj.ableToCatchAll(vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)));
            break;
        }
        case 5: {
            int x[] = { -175, -28, -207, -29, -43, -183, -175, -112, -183, -31, -25, -66, -114, -116, -66};
            int y[] = {320, 107, 379, 72, 126, 445, 318, 255, 445, 62, 52, 184, 247, 245, 185};
            _expected = "Able to catch";
            _received = _obj.ableToCatchAll(vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)));
            break;
        }
        case 6: {
            int x[] = {0, 0, 0, 0};
            int y[] = {0, 0, 0, 0};
            _expected = "Able to catch";
            _received = _obj.ableToCatchAll(vector <int>(x, x + sizeof(x) / sizeof(int)), vector <int>(y, y + sizeof(y) / sizeof(int)));
            break;
        }
        /*case 7:
        {
        	int x[] = ;
        	int y[] = ;
        	_expected = ;
        	_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
        }*/
        /*case 8:
        {
        	int x[] = ;
        	int y[] = ;
        	_expected = ;
        	_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
        }*/
        /*case 9:
        {
        	int x[] = ;
        	int y[] = ;
        	_expected = ;
        	_received = _obj.ableToCatchAll(vector <int>(x, x+sizeof(x)/sizeof(int)), vector <int>(y, y+sizeof(y)/sizeof(int))); break;
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
            cout << "           Expected: " << "\"" << _expected << "\"" << endl;
            cout << "           Received: " << "\"" << _received << "\"" << endl;
        }
    }
}

// END CUT HERE
