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

string tos(int n){
    stringstream ss;
    ss<<n;
    return ss.str();
}
struct FractionSplit {
   vector <string> getSum( int n, int d ) {
        vector<string> ans;
        int m=__gcd(n,d);
        n/=m;
        d/=m;
		while(n>1){
            int b=2;
            while(1){
               if(n*b>d){                  
                  int m=__gcd(d,b);
                  ans.push_back("1/"+tos(b));
                  int dd=(d*b)/m;
                  n=((dd/d)*n - (dd/b));
                  d=dd;
                  m=__gcd(n,d);
                  n/=m;
                  d/=m;
                  break;                    
               }
               b++; 
            }
            
		}
		ans.push_back("1/"+tos(d));
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
		cout << "Testing FractionSplit (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367216660;
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
		FractionSplit _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 4;
				int d = 5;
				string __expected[] = {"1/2", "1/4", "1/20" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSum(n, d); break;
			}
			case 1:
			{
				int n = 2;
				int d = 3;
				string __expected[] = {"1/2", "1/6" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSum(n, d); break;
			}
			case 2:
			{
				int n = 1;
				int d = 2;
				string __expected[] = {"1/2" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSum(n, d); break;
			}
			case 3:
			{
				int n = 15;
				int d = 16;
				string __expected[] = {"1/2", "1/3", "1/10", "1/240" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSum(n, d); break;
			}
			case 4:
			{
				int n = 14;
				int d = 15;
				string __expected[] = {"1/2", "1/3", "1/10" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSum(n, d); break;
			}
			/*case 5:
			{
				int n = ;
				int d = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSum(n, d); break;
			}*/
			/*case 6:
			{
				int n = ;
				int d = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSum(n, d); break;
			}*/
			/*case 7:
			{
				int n = ;
				int d = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getSum(n, d); break;
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

// END CUT HERE
