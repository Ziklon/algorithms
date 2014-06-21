#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;


struct IncrementingSequence {
    string canItBeDone(int k, vector <int> A) {
        string ans = "IMPOSSIBLE";

        sort(all(A));
        int N = A.size();
        for(int cur = 1; cur <= N; ++cur) {
            int idx = -1;
            for(int j = 0; j < A.size(); ++j) {
                int remain = cur-A[j];
                if(remain>=0 && remain%k==0){
                    idx=j;
                    break;
                }                
            }            
            if(idx==-1)return ans;
            A.erase(A.begin()+idx);            
        }
        return "POSSIBLE";
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
        cout << "Testing IncrementingSequence (500.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1403184041;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 500.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        IncrementingSequence _obj;
        string _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            int k = 3;
            int A[] = {1, 2, 4, 3};
            _expected = "POSSIBLE";
            _received = _obj.canItBeDone(k, vector <int>(A, A + sizeof(A) / sizeof(int)));
            break;
        }
        case 1: {
            int k = 5;
            int A[] = {2, 2};
            _expected = "IMPOSSIBLE";
            _received = _obj.canItBeDone(k, vector <int>(A, A + sizeof(A) / sizeof(int)));
            break;
        }
        case 2: {
            int k = 1;
            int A[] = {1, 1, 1, 1, 1, 1, 1, 1};
            _expected = "POSSIBLE";
            _received = _obj.canItBeDone(k, vector <int>(A, A + sizeof(A) / sizeof(int)));
            break;
        }
        case 3: {
            int k = 2;
            int A[] = {5, 3, 3, 2, 1};
            _expected = "IMPOSSIBLE";
            _received = _obj.canItBeDone(k, vector <int>(A, A + sizeof(A) / sizeof(int)));
            break;
        }
        case 4: {
            int k = 9;
            int A[] = {1, 2, 3, 1, 4, 5, 6, 7, 9, 8};
            _expected = "POSSIBLE";
            _received = _obj.canItBeDone(k, vector <int>(A, A + sizeof(A) / sizeof(int)));
            break;
        }
        case 5: {
            int k = 2;
            int A[] = {1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2};
            _expected = "POSSIBLE";
            _received = _obj.canItBeDone(k, vector <int>(A, A + sizeof(A) / sizeof(int)));
            break;
        }
        case 6: {
            int k = 1;
            int A[] = {1};
            _expected = "POSSIBLE";
            _received = _obj.canItBeDone(k, vector <int>(A, A + sizeof(A) / sizeof(int)));
            break;
        }
        /*case 7:
        {
        	int k = ;
        	int A[] = ;
        	_expected = ;
        	_received = _obj.canItBeDone(k, vector <int>(A, A+sizeof(A)/sizeof(int))); break;
        }*/
        /*case 8:
        {
        	int k = ;
        	int A[] = ;
        	_expected = ;
        	_received = _obj.canItBeDone(k, vector <int>(A, A+sizeof(A)/sizeof(int))); break;
        }*/
        /*case 9:
        {
        	int k = ;
        	int A[] = ;
        	_expected = ;
        	_received = _obj.canItBeDone(k, vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
