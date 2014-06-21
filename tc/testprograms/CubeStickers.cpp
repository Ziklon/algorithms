#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

struct CubeStickers {
    string isPossible(vector <string> sticker) {
        
        map<string,int> M;
        int sum =0;
        for(string s : sticker) ++M[s];       
        for(auto u : M)sum +=min(2,u.second);     
        if(sum>=6)return "YES";        
        return "NO";
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
        cout << "Testing CubeStickers (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1403386519;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        CubeStickers _obj;
        string _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            string sticker[] = {"cyan", "magenta", "yellow", "purple", "black", "white", "purple"};
            _expected = "YES";
            _received = _obj.isPossible(vector <string>(sticker, sticker + sizeof(sticker) / sizeof(string)));
            break;
        }
        case 1: {
            string sticker[] = {"blue", "blue", "blue", "blue", "blue", "blue", "blue", "blue", "blue", "blue"};
            _expected = "NO";
            _received = _obj.isPossible(vector <string>(sticker, sticker + sizeof(sticker) / sizeof(string)));
            break;
        }
        case 2: {
            string sticker[] = {"red", "yellow", "blue", "red", "yellow", "blue", "red", "yellow", "blue"};
            _expected = "YES";
            _received = _obj.isPossible(vector <string>(sticker, sticker + sizeof(sticker) / sizeof(string)));
            break;
        }
        case 3: {
            string sticker[] = {"purple", "orange", "orange", "purple", "black", "orange", "purple"};
            _expected = "NO";
            _received = _obj.isPossible(vector <string>(sticker, sticker + sizeof(sticker) / sizeof(string)));
            break;
        }
        case 4: {
            string sticker[] = {"white", "gray", "green", "blue", "yellow", "red", "target", "admin"};
            _expected = "YES";
            _received = _obj.isPossible(vector <string>(sticker, sticker + sizeof(sticker) / sizeof(string)));
            break;
        }
        /*case 5:
        {
        	string sticker[] = ;
        	_expected = ;
        	_received = _obj.isPossible(vector <string>(sticker, sticker+sizeof(sticker)/sizeof(string))); break;
        }*/
        /*case 6:
        {
        	string sticker[] = ;
        	_expected = ;
        	_received = _obj.isPossible(vector <string>(sticker, sticker+sizeof(sticker)/sizeof(string))); break;
        }*/
        /*case 7:
        {
        	string sticker[] = ;
        	_expected = ;
        	_received = _obj.isPossible(vector <string>(sticker, sticker+sizeof(sticker)/sizeof(string))); break;
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
