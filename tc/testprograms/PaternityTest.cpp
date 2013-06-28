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
#include <cstdio>
using namespace std; 
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++) 
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
typedef long long ll; 

struct PaternityTest {
   vector <int> possibleFathers( string child, string mother, vector <string> men ) {
		int N=child.size();
		set<int> S;
		REP(mask,1<<N){
            if(__builtin_popcount(mask)*2==N){
                bool ok1=1;
                REP(i,N)if((mask&(1<<i))>0   && mother[i]!=child[i]) ok1=0;
                
                REP(j,men.size()){
                    bool ok2=1;
                    REP(i,men[j].size()) if((mask&(1<<i))==0  && men[j][i]!=child[i])ok2=0;                    
                    if(ok1 && ok2)S.insert(j);                
                }
                
            }
		}
		vector<int> ans;
		FOREACH(it,S)ans.push_back(*it);
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
		cout << "Testing PaternityTest (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1372261487;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		PaternityTest _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string child = "ABCD";
				string mother = "AXCY";
				string men[] = { "SBTD", "QRCD" };
				int __expected[] = { 0 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleFathers(child, mother, vector <string>(men, men+sizeof(men)/sizeof(string))); break;
			}
			case 1:
			{
				string child = "ABCD";
				string mother = "ABCX";
				string men[] = { "ABCY", "ASTD", "QBCD" } ;
				int __expected[] = { 1,  2 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleFathers(child, mother, vector <string>(men, men+sizeof(men)/sizeof(string))); break;
			}
			case 2:
			{
				string child = "ABABAB";
				string mother = "ABABAB";
				string men[] = { "ABABAB", "ABABCC", "ABCCDD", "CCDDEE" };
				int __expected[] = { 0,  1 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleFathers(child, mother, vector <string>(men, men+sizeof(men)/sizeof(string))); break;
			}
			case 3:
			{
				string child = "YZGLSYQT";
				string mother = "YUQRWYQT";
				string men[] = {"YZQLDPWT", "BZELSWQM", "OZGPSFKT", "GZTKFYQT", "WQJLSMQT"};
				int __expected[] = { };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleFathers(child, mother, vector <string>(men, men+sizeof(men)/sizeof(string))); break;
			}
			case 4:
			{
				string child = "WXETPYCHUWSQEMKKYNVP";
				string mother = "AXQTUQVAUOSQEEKCYNVP";
				string men[] = { "WNELPYCHXWXPCMNKDDXD",
				                 "WFEEPYCHFWDNPMKKALIW",
				                 "WSEFPYCHEWEFGMPKIQCK",
				                 "WAEXPYCHAWEQXMSKYARN",
				                 "WKEXPYCHYWLLFMGKKFBB" };
				int __expected[] = { 1,  3 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleFathers(child, mother, vector <string>(men, men+sizeof(men)/sizeof(string))); break;
			}
			/*case 5:
			{
				string child = ;
				string mother = ;
				string men[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleFathers(child, mother, vector <string>(men, men+sizeof(men)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string child = ;
				string mother = ;
				string men[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleFathers(child, mother, vector <string>(men, men+sizeof(men)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string child = ;
				string mother = ;
				string men[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.possibleFathers(child, mother, vector <string>(men, men+sizeof(men)/sizeof(string))); break;
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
				cout << " " << _expected[i];
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " " << _received[i];
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
