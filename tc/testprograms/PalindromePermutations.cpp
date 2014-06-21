#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

int seq[26] = {};

ll fact[55];


ll dp[55][55];

struct PalindromePermutations {
    double palindromeProbability(string word) {
        long double ans = 1;
        fact[0] = 1;

        for(int i = 1; i < 55; ++i)fact[i] = fact[i - 1] * i;

        for(int i = 0; i < 55; ++i) {
            dp[i][i] = 1;
            dp[i][0] = 1;
        }

        for(int i = 2; i < 55; ++i)
            for(int j = 1; j < i; ++j) {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
            }
        for(char s : word)seq[s - 'a']++;
        int N = word.size();
        int tam = N;
        long double cntAll = 1;
        for(int i = 0; i < 26; ++i)if(seq[i] > 0) {
                cntAll *= dp[tam][seq[i]];
                tam -= seq[i];
            }
        
        int odds = 0;
        tam = N >> 1;
        for(int i = 0; i < 26; ++i)if(seq[i]) {
            odds += (seq[i] & 1);
            if(odds >= 2)return 0;
            ans *= dp[tam][seq[i] >> 1];
            tam -= (seq[i] >> 1);
        }
        ans = ans / cntAll;
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
        cout << "Testing PalindromePermutations (250.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1403175606;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 250.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        PalindromePermutations _obj;
        double _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            string word = "haha";
            _expected = 0.3333333333333333;
            _received = _obj.palindromeProbability(word);
            break;
        }
        case 1: {
            string word = "xxxxy";
            _expected = 0.2;
            _received = _obj.palindromeProbability(word);
            break;
        }
        case 2: {
            string word = "xxxx";
            _expected = 1.0;
            _received = _obj.palindromeProbability(word);
            break;
        }
        case 3: {
            string word = "abcde";
            _expected = 0.0;
            _received = _obj.palindromeProbability(word);
            break;
        }
        case 4: {
            string word = "hhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhff";
            _expected = 0.025641025641025637;
            _received = _obj.palindromeProbability(word);
            break;
        }
        case 5: {
            string word = "abcdefhijkthmoperabcdefhijkthmoperijkthmoperijkth" ;
            _expected = 55.6;
            _received = _obj.palindromeProbability(word);
            break;
        }
        /*case 6:
        {
        	string word = ;
        	_expected = ;
        	_received = _obj.palindromeProbability(word); break;
        }*/
        /*case 7:
        {
        	string word = ;
        	_expected = ;
        	_received = _obj.palindromeProbability(word); break;
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
