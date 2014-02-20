#include <sstream>
#include <iostream> 
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <algorithm> 
#include <cmath>  
#include <cstdlib>  
#include <cstring> 
using namespace std;
typedef long long ll;
char buf[20];
struct Inequalities {
    int maximumSubset(vector <string> v) {
        int ans = 0, n =  v.size();
        for(int x=-50;x<=5005;x++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                int val ;
                sscanf(v[j].c_str(),"X %s %d",buf, &val);
                val *=2;
                if(v[j].find("<=")!=-1 && x<=val) {cnt++;continue;}
                if(v[j].find(">=")!=-1 && x>=val) {cnt++; continue;}
                if(v[j].find("<")!=-1 && x<val) {cnt++; continue;}
                if(v[j].find(">")!=-1 && x>val) {cnt++;continue;}
                if(v[j].find("=")!=-1 && x==val)cnt++;
            }
            ans = max(ans,cnt);
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

int main(int argc, char* argv[])
{
	if (argc == 1) 
	{
		cout << "Testing Inequalities (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392860141;
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
		Inequalities _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string inequalities[] = {"X <= 12","X = 13","X > 9","X < 10","X >= 14"};
				_expected = 3;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}
			case 1:
			{
				string inequalities[] = {"X < 0","X <= 0"};
				_expected = 2;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}
			case 2:
			{
				string inequalities[] = {"X = 1","X = 2","X = 3","X > 0"};
				_expected = 2;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}
			case 3:
			{
				string inequalities[] = {"X <= 521","X >= 521","X = 521","X > 902","X > 12","X <= 1000"};
				_expected = 5;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}
			/*case 4:
			{
				string inequalities[] = ;
				_expected = ;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string inequalities[] = ;
				_expected = ;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string inequalities[] = ;
				_expected = ;
				_received = _obj.maximumSubset(vector <string>(inequalities, inequalities+sizeof(inequalities)/sizeof(string))); break;
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
