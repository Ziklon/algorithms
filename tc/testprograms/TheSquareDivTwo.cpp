#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;
int R[60]={};
struct TheSquareDivTwo {
   vector <string> solve( vector <string> board ) {
	   int n=board.size();
	   for(int i=0;i<n;i++)for(int j=0;j<n;j++)if(board[i][j]=='C')R[i]++;
	   vector<string> ans=board;
	   for(int i=0;i<n;i++)for(int j=0;j<n;j++)
		   	if(i>=n-R[j])ans[i][j]='C'; 
			else ans[i][j]='.';	   
	   return ans;
   }
};
//BEGIN CUT HERE
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
		cout << "Testing TheSquareDivTwo (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356517513;
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
		TheSquareDivTwo _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string board[] = {"..",
				                  "C."};
				string __expected[] = {"..", ".C" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 1:
			{
				string board[] = {"CC",
				                  ".C"};
				string __expected[] = {"C.", "CC" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 2:
			{
				string board[] = {".C..",
				                  "CC.C",
				                  "..C.",
				                  "CCCC"};
				string __expected[] = {"...C", ".C.C", ".C.C", "CCCC" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 3:
			{
				string board[] = {"...CCC",
				                  "...CCC",
				                  "...CCC",
				                  "CCC...",
				                  "CCC...",
				                  "CCC..."};
				string __expected[] = {"......", "......", "......", "CCCCCC", "CCCCCC", "CCCCCC" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 4:
			{
				string board[] = {".....C",
				                  "....CC",
				                  "...CCC",
				                  "..CCCC",
				                  ".CCCCC",
				                  "CCCCCC"};
				string __expected[] = {".....C", "....CC", "...CCC", "..CCCC", ".CCCCC", "CCCCCC" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			case 5:
			{
				string board[] = {"C.C..C.C..C..C.",
				                  "CCC...C..CCC.C.",
				                  "......CC...CCCC",
				                  ".C..CC.C.C.C.C.",
				                  "C....C.C......C",
				                  ".....C..CCCCC.C",
				                  "CCC.......CCCCC",
				                  "..C.C..C.C...C.",
				                  "CCC....CCC.CC..",
				                  "CC.CCCC.CCCC...",
				                  ".C..C.CC.C.CC.C",
				                  "C.CCCC..CC..C.C",
				                  ".CCCC.CCCCCC...",
				                  "..C...C.CCC.CC.",
				                  "CCCC..CCC.C...."};
				string __expected[] = {"...............", "...............", "...............", "...............", "...............", ".........C..C..", ".........C.CC..", ".C....C.CCCCC.C", ".C.C.CC.CCCCCCC", "CCCC.CC.CCCCCCC", "CCCC.CCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC", "CCCCCCCCCCCCCCC" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}
			/*case 6:
			{
				string board[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string board[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string board[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.solve(vector <string>(board, board+sizeof(board)/sizeof(string))); break;
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
			cout << "           Expected: {";
			for (unsigned i = 0; i < _expected.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

//END CUT HERE
