#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;

struct UniformBoard {
    int getBoard(vector <string> board, int K) {
        int ans = 0;
        int N = board.size();


        int emptyCells = 0;
        int apples = 0;
        int pear = 0;

        for(int i = 0; i < N; ++i)
            for(int j = 0; j < N; ++j) {
                if(board[i][j] == '.')emptyCells++;
                if(board[i][j] == 'A')apples++;
                if(board[i][j] == 'P')pear++;
            }

        for(int w = 1; w <= N; ++w)
            for(int h = 1; h <= N; ++h) {
                
                if(w*h>apples)continue;
                
                
                for(int i = 0; i + w <= N; ++i)
                    for(int j = 0; j + h <= N; ++j) {

                        int curEmpty = 0;
                        int curPear = 0;
                        int curApple = 0;
                        for(int x = 0; x < w; ++x)
                            for(int y = 0; y < h; ++y) {
                                if(board[i + x][j + y] == '.')curEmpty++;
                                if(board[i + x][j + y] == 'P')curPear++;
                                if(board[i + x][j + y] == 'A')curApple++;
                            }
                        
                        //traeManzanas a los vacios
                        int appleOut=apples-curApple;
                        int emptyOut=emptyCells-curEmpty;
                        
                        int moves=0;
                        int pickApple=min(curEmpty,appleOut);
                        
                        appleOut-=pickApple;
                        moves+=pickApple;
                        emptyOut+=pickApple;
                        
                        if(pickApple+curApple< w*h){
                                if(emptyOut>0){
                                    //saca las peras
                                    //int falta = (w*h)-pickApple+curApple
                                    pickApple+=curPear;
                                    moves+=(curPear*2);
                                }
                        }                     
                        if(pickApple+curApple==w*h && moves<=K)ans=max(ans,w*h);                                             
                        
                    }

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
        cout << "Testing UniformBoard (300.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++) {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL) - 1401930007;
        double PT = T / 60.0, TT = 75.0;
        cout.setf(ios::fixed, ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score : " << 300.0 * (.3 + (.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    } else {
        int _tc;
        istringstream(argv[1]) >> _tc;
        UniformBoard _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc) {
        case 0: {
            string board[] = {"AP",
                              ".A"
                             };
            int K = 0;
            _expected = 1;
            _received = _obj.getBoard(vector <string>(board, board + sizeof(board) / sizeof(string)), K);
            break;
        }
        case 1: {
            string board[] = {"AP",
                              ".A"
                             };
            int K = 1;
            _expected = 2;
            _received = _obj.getBoard(vector <string>(board, board + sizeof(board) / sizeof(string)), K);
            break;
        }
        case 2: {
            string board[] = {"PPP",
                              "APA",
                              "A.P"
                             };
            int K = 2;
            _expected = 3;
            _received = _obj.getBoard(vector <string>(board, board + sizeof(board) / sizeof(string)), K);
            break;
        }
        case 3: {
            string board[] = {"AAA",
                              "PPP",
                              "AAA"
                             };
            int K = 10;
            _expected = 3;
            _received = _obj.getBoard(vector <string>(board, board + sizeof(board) / sizeof(string)), K);
            break;
        }
        case 4: {
            string board[] = {"."};
            int K = 1000;
            _expected = 0;
            _received = _obj.getBoard(vector <string>(board, board + sizeof(board) / sizeof(string)), K);
            break;
        }
        case 5: {
            string board[] = {"PPAAPA..AP",
                              "PPA.APAP..",
                              "..P.AA.PPP",
                              "P.P..APAA.",
                              "P.P..P.APA",
                              "PPA..AP.AA",
                              "APP..AAPAA",
                              "P.P.AP...P",
                              ".P.A.PAPPA",
                              "..PAPAP..P"
                             };
            int K = 10;
            _expected = 15;
            _received = _obj.getBoard(vector <string>(board, board + sizeof(board) / sizeof(string)), K);
            break;
        }
        /*case 6:
        {
        	string board[] = ;
        	int K = ;
        	_expected = ;
        	_received = _obj.getBoard(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
        }*/
        /*case 7:
        {
        	string board[] = ;
        	int K = ;
        	_expected = ;
        	_received = _obj.getBoard(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
        }*/
        /*case 8:
        {
        	string board[] = ;
        	int K = ;
        	_expected = ;
        	_received = _obj.getBoard(vector <string>(board, board+sizeof(board)/sizeof(string)), K); break;
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
