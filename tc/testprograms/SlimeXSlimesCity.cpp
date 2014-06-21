#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

struct SlimeXSlimesCity {
    int merge(vector <int> population) {
        int ans = 0, N = population.size();

        sort(all(population));

        for(int town = 0; town < N; ++town) {
            ll sum = population[town];
            bool can = 1;
            for(int i = 0; i < N; ++i) {
                if(i == town)continue;
                if(population[i] <= sum) {
                    sum += population[i];
                } else can = 0;
            }
            if(can)ans++;
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
        cout << "Testing SlimeXSlimesCity (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1403384801;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        SlimeXSlimesCity _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int population[] = {2, 3, 4};
            _expected = 2;
            _received = _obj.merge(vector <int>(population, population + sizeof(population) / sizeof(int)));
            break;
        }
        case 1: {
            int population[] = {1, 2, 3};
            _expected = 2;
            _received = _obj.merge(vector <int>(population, population + sizeof(population) / sizeof(int)));
            break;
        }
        case 2: {
            int population[] = {8, 2, 3, 8};
            _expected = 2;
            _received = _obj.merge(vector <int>(population, population + sizeof(population) / sizeof(int)));
            break;
        }
        case 3: {
            int population[] = {1000000000, 999999999, 999999998, 999999997};
            _expected = 3;
            _received = _obj.merge(vector <int>(population, population + sizeof(population) / sizeof(int)));
            break;
        }
        case 4: {
            int population[] = {1, 1, 1};
            _expected = 3;
            _received = _obj.merge(vector <int>(population, population + sizeof(population) / sizeof(int)));
            break;
        }
        case 5: {
            int population[] = {1, 2, 4, 6, 14, 16, 20};
            _expected = 3;
            _received = _obj.merge(vector <int>(population, population + sizeof(population) / sizeof(int)));
            break;
        }
        /*case 6:
        {
        	int population[] = ;
        	_expected = ;
        	_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
        }*/
        /*case 7:
        {
        	int population[] = ;
        	_expected = ;
        	_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
        }*/
        /*case 8:
        {
        	int population[] = ;
        	_expected = ;
        	_received = _obj.merge(vector <int>(population, population+sizeof(population)/sizeof(int))); break;
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
