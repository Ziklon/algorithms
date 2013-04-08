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
using namespace std; 
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++) 
typedef long long ll; 
bool seen[55]={0};
int ans;
void dfs(int idx, vector<string> &name, vector<string> boss){
    seen[idx]=1;
    int i,N=name.size();
    vector<int> tmp;
    REP(i,N)if(seen[i]==0 && boss[i]==name[idx]){
        seen[i]=1;
        tmp.push_back(i);
    }
    if(tmp.size()>0){
        ans++;
        REP(i,tmp.size())dfs(tmp[i],name,boss);
    }
}

struct BobTrouble {
   int minSupers( vector <string> name, vector <string> bossName ) {
		ans=0;
		int N=name.size(),i;
		REP(i,N){
            if(bossName[i]=="*"){
                dfs(i,name,bossName);
            }
		}
		REP(i,N)if(seen[i]==0)return -1;		
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
		cout << "Testing BobTrouble (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365107419;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 500.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		BobTrouble _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string name[] = {"BOB","BOB","BOB"};
				string bossName[] = {"BOB","*","BOB"};
				_expected = 1;
				_received = _obj.minSupers(vector <string>(name, name+sizeof(name)/sizeof(string)), vector <string>(bossName, bossName+sizeof(bossName)/sizeof(string))); break;
			}
			case 1:
			{
				string name[] = {"JOHN","AL","DON","BOB"};
				string bossName[] = {"*","*","*","*"};
				_expected = 0;
				_received = _obj.minSupers(vector <string>(name, name+sizeof(name)/sizeof(string)), vector <string>(bossName, bossName+sizeof(bossName)/sizeof(string))); break;
			}
			case 2:
			{
				string name[] = {"BOB","BOB","BOB"};
				string bossName[] = {"*","*","BOB"};
				_expected = 1;
				_received = _obj.minSupers(vector <string>(name, name+sizeof(name)/sizeof(string)), vector <string>(bossName, bossName+sizeof(bossName)/sizeof(string))); break;
			}
			case 3:
			{
				string name[] = {"BOB", "BOB", "JACK"};
				string bossName[] = {"BOB", "BOB", "*"};
				_expected = -1;
				_received = _obj.minSupers(vector <string>(name, name+sizeof(name)/sizeof(string)), vector <string>(bossName, bossName+sizeof(bossName)/sizeof(string))); break;
			}
			/*case 4:
			{
				string name[] = ;
				string bossName[] = ;
				_expected = ;
				_received = _obj.minSupers(vector <string>(name, name+sizeof(name)/sizeof(string)), vector <string>(bossName, bossName+sizeof(bossName)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				string name[] = ;
				string bossName[] = ;
				_expected = ;
				_received = _obj.minSupers(vector <string>(name, name+sizeof(name)/sizeof(string)), vector <string>(bossName, bossName+sizeof(bossName)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string name[] = ;
				string bossName[] = ;
				_expected = ;
				_received = _obj.minSupers(vector <string>(name, name+sizeof(name)/sizeof(string)), vector <string>(bossName, bossName+sizeof(bossName)/sizeof(string))); break;
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
