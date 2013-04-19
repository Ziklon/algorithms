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
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++) 
typedef long long ll; 
#define INF 1<<20
vector<string> words;
string goal;
int dp[55][55];

int go(int row, int col){
    if(row>=words.size())return 0;
    int& ref=dp[row][col];
    if(ref!=-1)return ref;
    ref=INF;
    int top=col;
    REP(i,words[row].size())if(i<=col && goal[row]==words[row][i]){
        ref=min(ref,go(row+1,col)+abs(col-i));
    }
    return ref;
}

struct MatchString {
   int placeWords( string matchString, vector <string> matchWords ) {
		goal=matchString;
		words=matchWords;
		memset(dp,-1,sizeof dp);
		int maxi=55;
		int ans=INF;
		REP(i,maxi)ans=min(ans,go(0,i));		
		if(ans>=INF)return -1;
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

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing MatchString (900.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366333815;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		MatchString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string matchString = "TOP";
				string matchWords[] = {"TIK", 
				                       "PPPO", 
				                       "OP"};
				_expected = 5;
				_received = _obj.placeWords(matchString, vector <string>(matchWords, matchWords+sizeof(matchWords)/sizeof(string))); break;
			}
			case 1:
			{
				string matchString = "EEA";
				string matchWords[] = {"GEGA", 
				                       "TOPCODER", 
				                       "TEST"};
				_expected = -1;
				_received = _obj.placeWords(matchString, vector <string>(matchWords, matchWords+sizeof(matchWords)/sizeof(string))); break;
			}
			case 2:
			{
				string matchString = "AB";
				string matchWords[] = {"ABA", 
				                       "ABAB"};
				_expected = 1;
				_received = _obj.placeWords(matchString, vector <string>(matchWords, matchWords+sizeof(matchWords)/sizeof(string))); break;
			}
			case 3:
			{
				string matchString = "FIND";
				string matchWords[] = {"VERYFAST", 
				                       "OPINION", 
				                       "SPENDING", 
				                       "ODD"};
				_expected = 3;
				_received = _obj.placeWords(matchString, vector <string>(matchWords, matchWords+sizeof(matchWords)/sizeof(string))); break;
			}
			case 4:
			{
				string matchString = "TOP";
				string matchWords[] = {"OUTTHERE", 
				                       "FROM", 
				                       "NOPQRSTU"};
				_expected = 0;
				_received = _obj.placeWords(matchString, vector <string>(matchWords, matchWords+sizeof(matchWords)/sizeof(string))); break;
			}
			/*case 5:
			{
				string matchString = ;
				string matchWords[] = ;
				_expected = ;
				_received = _obj.placeWords(matchString, vector <string>(matchWords, matchWords+sizeof(matchWords)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string matchString = ;
				string matchWords[] = ;
				_expected = ;
				_received = _obj.placeWords(matchString, vector <string>(matchWords, matchWords+sizeof(matchWords)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string matchString = ;
				string matchWords[] = ;
				_expected = ;
				_received = _obj.placeWords(matchString, vector <string>(matchWords, matchWords+sizeof(matchWords)/sizeof(string))); break;
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
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
