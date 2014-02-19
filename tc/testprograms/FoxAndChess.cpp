#include <iostream>  
#include <sstream>
#include <vector>
#include <cstdio>  
#include <set>  
#include <map>  
#include <algorithm> 
#include <cmath> 
#include <cstring> 
using namespace std;  
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)  
typedef long long ll;

struct FoxAndChess {
	string ableToMove(string s, string t) {
		int j=-1;
		int N=s.size();
		REP(i,N)if(s[i]!='.'){
		    bool found = 0;
		    for(int k=j+1;k<N;k++){
               if(t[k]!='.'){
                  if(t[k]!=s[i])break;
                  if(s[i]=='R' && k>=i)found=1;
                  if(s[i]=='L' && k<=i)found=1;                  
                  j=k;
                  break;  
               }     
		    }
		    if(found==0)return "Impossible";                          
                        
		}
		for(int k = j+1;k<N;k++)if(t[k]!='.')return "Impossible";
		return "Possible";	
		
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
		cout << "Testing FoxAndChess (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391472481;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 250.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		FoxAndChess _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string begin = "R...";
				string target = "..R.";
				_expected = "Possible";
				_received = _obj.ableToMove(begin, target); break;
			}
			case 1:
			{
				string begin = "..R.";
				string target = "R...";
				_expected = "Impossible";
				_received = _obj.ableToMove(begin, target); break;
			}
			case 2:
			{
				string begin = ".L.R.R.";
				string target = "L...R.R";
				_expected = "Possible";
				_received = _obj.ableToMove(begin, target); break;
			}
			case 3:
			{
				string begin = ".L.R.";
				string target = ".R.L.";
				_expected = "Impossible";
				_received = _obj.ableToMove(begin, target); break;
			}
			case 4:
			{
				string begin = "LRLLRLRLLRLLRLRLRL";
				string target = "LRLLRLRLLRLLRLRLRL";
				_expected = "Possible";
				_received = _obj.ableToMove(begin, target); break;
			}
			case 5:
			{
				string begin = "L";
				string target = ".";
				_expected = "Impossible";
				_received = _obj.ableToMove(begin, target); break;
			}
			/*case 6:
			{
				string begin = ;
				string target = ;
				_expected = ;
				_received = _obj.ableToMove(begin, target); break;
			}*/
			/*case 7:
			{
				string begin = ;
				string target = ;
				_expected = ;
				_received = _obj.ableToMove(begin, target); break;
			}*/
			/*case 8:
			{
				string begin = ;
				string target = ;
				_expected = ;
				_received = _obj.ableToMove(begin, target); break;
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

//END CUT HERE
