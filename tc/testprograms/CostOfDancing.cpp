#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

struct CostOfDancing {
    int minimum(int K, vector <int> danceCost) {
        int ans = 0;
        sort(all(danceCost));
        for(int i = 0; i < K; ++i)ans += danceCost[i];
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
        cout << "Testing CostOfDancing (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1402965227;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        CostOfDancing _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int K = 2;
            int danceCost[] = {1, 5, 3, 4};
            _expected = 4;
            _received = _obj.minimum(K, vector <int>(danceCost, danceCost + sizeof(danceCost) / sizeof(int)));
            break;
        }
        case 1: {
            int K = 3;
            int danceCost[] = {1, 5, 4};
            _expected = 10;
            _received = _obj.minimum(K, vector <int>(danceCost, danceCost + sizeof(danceCost) / sizeof(int)));
            break;
        }
        case 2: {
            int K = 1;
            int danceCost[] = {2, 2, 4, 5, 3};
            _expected = 2;
            _received = _obj.minimum(K, vector <int>(danceCost, danceCost + sizeof(danceCost) / sizeof(int)));
            break;
        }
        case 3: {
            int K = 39;
            int danceCost[] = {973, 793, 722, 573, 521, 568, 845, 674, 595, 310, 284, 794, 913, 93, 129, 758, 108, 433, 181, 163, 96, 932,
                               703, 989, 884, 420, 615, 991, 364, 657, 421, 336, 801, 142, 908, 321, 709, 752, 346, 656, 413, 629, 801
                              };
            _expected = 20431;
            _received = _obj.minimum(K, vector <int>(danceCost, danceCost + sizeof(danceCost) / sizeof(int)));
            break;
        }
        /*case 4:
        {
        	int K = ;
        	int danceCost[] = ;
        	_expected = ;
        	_received = _obj.minimum(K, vector <int>(danceCost, danceCost+sizeof(danceCost)/sizeof(int))); break;
        }*/
        /*case 5:
        {
        	int K = ;
        	int danceCost[] = ;
        	_expected = ;
        	_received = _obj.minimum(K, vector <int>(danceCost, danceCost+sizeof(danceCost)/sizeof(int))); break;
        }*/
        /*case 6:
        {
        	int K = ;
        	int danceCost[] = ;
        	_expected = ;
        	_received = _obj.minimum(K, vector <int>(danceCost, danceCost+sizeof(danceCost)/sizeof(int))); break;
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
