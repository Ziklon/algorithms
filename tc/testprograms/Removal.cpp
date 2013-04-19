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
typedef long long ll; 

struct Removal {
   int finalPos( int n, int k, vector <string> remove ) {
		vector<pair<int,int> > v;
		v.push_back(make_pair(1,n)); // inclusive
		REP(i,remove.size()){
            int x,y;
            sort(v.begin(),v.end());
            sscanf(remove[i].c_str(),"%d-%d",&x,&y);
            vector<pair<int,int> > temp;
            vector<bool> seen(v.size(),0); 
            REP(j,v.size()){
                int len=(v[j].second-v[j].first+1);
                if(len<x){
                    x-=len;
                    y-=len;                    
                }else{
                    seen[j]=1;
                    int ver=y-x+1;
                    int tam=min(len,y)-x+1;
                    int aa=v[j].first+x-2;
                    int bb=v[j].first+y;
                    if(aa>=v[j].first)temp.push_back(make_pair(v[j].first,aa));
                    if(bb<=v[j].second)temp.push_back(make_pair(bb,v[j].second));
                    if(tam==y-x+1)break;
                    x=1;
                    y=ver-tam; 
                }                
            }
            REP(j,v.size())if(seen[j]==0)temp.push_back(v[j]);
            v=temp;
		}
		sort(v.begin(),v.end());
		REP(i,v.size()){        
            int len=v[i].second-v[i].first+1;
            if(len>=k){
                return v[i].first+k-1;
            }else
              k-=len;
		}
		return -1;
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
		cout << "Testing Removal (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366263485;
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
		Removal _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 8;
				int k = 3;
				string remove[] = {"3-4","4-5"};
				_expected = 5;
				_received = _obj.finalPos(n, k, vector <string>(remove, remove+sizeof(remove)/sizeof(string))); break;
			}
			case 1:
			{
				int n = 100;
				int k = 13;
				string remove[] = {"19-50","19-50","19-19"};
				_expected = 13;
				_received = _obj.finalPos(n, k, vector <string>(remove, remove+sizeof(remove)/sizeof(string))); break;
			}
			case 2:
			{
				int n = 100;
				int k = 39;
				string remove[] = {"19-50","19-50","19-19"};
				_expected = -1;
				_received = _obj.finalPos(n, k, vector <string>(remove, remove+sizeof(remove)/sizeof(string))); break;
			}
			case 3:
			{
				int n =2000000000 ;
				int k = 30;
				string remove[] ={"30-100","100-200","20-100"} ;
				_expected = 283;
				_received = _obj.finalPos(n, k, vector <string>(remove, remove+sizeof(remove)/sizeof(string))); break;
			}
			/*case 4:
			{
				int n = ;
				int k = ;
				string remove[] = ;
				_expected = ;
				_received = _obj.finalPos(n, k, vector <string>(remove, remove+sizeof(remove)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int n = ;
				int k = ;
				string remove[] = ;
				_expected = ;
				_received = _obj.finalPos(n, k, vector <string>(remove, remove+sizeof(remove)/sizeof(string))); break;
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
