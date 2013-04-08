#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <deque> 
#include <queue> 
#include <set> 
#include <map> 
#include <algorithm> 
#include <functional> 
#include <utility> 
#include <cmath> 
#include <cstdlib> 
#include <ctime>
#include <cstring>
using namespace std; 
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++) 
typedef long long ll; 

int B[5][5];
int D[5][5];
bool seen[5][5];
vector<vector<int> > isWin(){
    int i,j;
    vector<vector<int> > v;
    REP(i,5){
        bool ok1=1,ok2=1;
        vector<int> v1,v2;
        REP(j,5){
            v1.push_back(D[i][j]);
            v2.push_back(D[j][i]);
            if(seen[i][j]==0)ok1=0;
            if(seen[j][i]==0)ok2=0;
        }
        if(ok1)v.push_back(v1);
        if(ok2)v.push_back(v2);
    }
    bool ok1=1,ok2=1;
    vector<int> v1,v2;
    REP(i,5){
        v1.push_back(D[i][i]);
        v2.push_back(D[i][4-i]);
        if(seen[i][i]==0)ok1=0;
        if(seen[i][4-i]==0)ok2=0;    
    }
    if(ok1)v.push_back(v1);    
    if(ok2)v.push_back(v2);
    REP(i,v.size())sort(v[i].begin(),v[i].end());
    
    sort(v.begin(),v.end());
    return v;
}

struct Bingo {
   string winner( vector <string> card, vector <string> calls ) {
		int i,j,k,tmp,N=calls.size();
		string ans;
		memset(seen,0,sizeof seen);
		seen[2][2]=1;
		set<int> S;
		REP(i,5){
            stringstream ss(card[i+1]);
            REP(j,5){
                if(i==2 && j==2){
                    ss>>ans;
                    B[i][j]=-1;
                    D[i][j]=10000;
                    continue;
                }                
                ss>>tmp;
                B[i][j]=tmp;
                S.insert(tmp);
            }
		}
		REP(i,N){
            stringstream ss(calls[i]);
            char cur;
            ss>>cur>>tmp;
            int idx;
            if(S.count(tmp)){
                string cad="BINGO";
                idx=cad.find(cur);
                REP(j,5)if(B[j][idx]==tmp){
                    D[j][idx]=i;
                    seen[j][idx]=1;
                    break;
                }
                vector<vector<int> > v=isWin();
                if(v.size()>0){
                    ans="";
                    REP(k,v[0].size()){
                        if(v[0][k]>50)continue;
                        ans+=","+calls[v[0][k]];                        
                    }
                    ans=ans.substr(1);
                    return ans;
                }            
            }
		}
		
		return  "YOU LOSE";	
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

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing Bingo (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365108882;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		Bingo _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string card[] = { "  B  I  N  G  O",
				                  " 12 22 33 55 66",
				                  "  9 23 34 52 72",
				                  "  1 24  F 59 71",
				                  "  4 16 40 48 61",
				                  "  3 18 41 49 63"};
				string calls[] = {"B12","B3","I16","N40","B2","O70","B1","B9","O71","B4","B7","B11","O68","BINGO"};
				_expected = "B12,B3,B1,B9,B4";
				_received = _obj.winner(vector <string>(card, card+sizeof(card)/sizeof(string)), vector <string>(calls, calls+sizeof(calls)/sizeof(string))); break;
			}
			case 1:
			{
				string card[] = { "  B  I  N  G  O",
				                  " 12 22 33 55 66",
				                  "  9 23 34 52 72",
				                  "  1 24  F 59 71",
				                  "  4 16 40 48 61",
				                  "  3 18 41 49 63"};
				string calls[] = {"B12","B3","I16","N40","B2","O70","B1","B9","BINGO"};
				_expected = "YOU LOSE";
				_received = _obj.winner(vector <string>(card, card+sizeof(card)/sizeof(string)), vector <string>(calls, calls+sizeof(calls)/sizeof(string))); break;
			}
			case 2:
			{
				string card[] = { "  B  I  N  G  O",
				                  " 12 22 33 55 66",
				                  "  9 23 34 52 72",
				                  "  1 24  F 59 71",
				                  "  4 16 40 48 61",
				                  "  3 18 41 49 63"};
				string calls[] = {"O63","G48","I23","B9","B1","B4","B3","B7","B12","G49","BINGO"};
				_expected = "O63,G48,I23,B12";
				_received = _obj.winner(vector <string>(card, card+sizeof(card)/sizeof(string)), vector <string>(calls, calls+sizeof(calls)/sizeof(string))); break;
			}
			/*case 3:
			{
				string card[] = ;
				string calls[] = ;
				_expected = ;
				_received = _obj.winner(vector <string>(card, card+sizeof(card)/sizeof(string)), vector <string>(calls, calls+sizeof(calls)/sizeof(string))); break;
			}*/
			/*case 4:
			{
				string card[] = ;
				string calls[] = ;
				_expected = ;
				_received = _obj.winner(vector <string>(card, card+sizeof(card)/sizeof(string)), vector <string>(calls, calls+sizeof(calls)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string card[] = ;
				string calls[] = ;
				_expected = ;
				_received = _obj.winner(vector <string>(card, card+sizeof(card)/sizeof(string)), vector <string>(calls, calls+sizeof(calls)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (_received == _expected)
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
