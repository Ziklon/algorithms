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
int num[10]={},k;

ll backtrack(int pos, int mid, int start, int prev){
    if(pos==6)return 1LL;
    ll ans =0;
    for(int i=0;i<k;i++)if(num[i]>0){
        if(pos==5 && i==start)continue;
        if(i==prev || i==mid)continue;
        num[i]--;
        ans +=backtrack(pos+1,mid,start,i)*(num[i]+1);
        num[i]++;    
    }
    return ans;

}



struct TheHexagonsDivTwo {
    long long count(int n, int k) {
       ::k=k; 
       for(int i=1;i<=n;i++)num[i%k]++;
       ll ans=0;
       for(int mid = 0; mid<k;mid++)
           for(int start=0;start<k;start++) if(mid!=start){
               num[start]--;
               ans+=backtrack(1,mid,start,start)*(num[mid])*(num[start]+1);
               num[start]++;               
           }
        return ans/6;


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
		cout << "Testing TheHexagonsDivTwo (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392685996;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 1000.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheHexagonsDivTwo _obj;
		long long _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int n = 7;
				int k = 3;
				_expected = 0LL;
				_received = _obj.count(n, k); break;
			}
			case 1:
			{
				int n = 8;
				int k = 3;
				_expected = 24LL;
				_received = _obj.count(n, k); break;
			}
			case 2:
			{
				int n = 8;
				int k = 4;
				_expected = 256LL;
				_received = _obj.count(n, k); break;
			}
			case 3:
			{
				int n = 20;
				int k = 5;
				_expected = 4692480LL;
				_received = _obj.count(n, k); break;
			}
			/*case 4:
			{
				int n = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(n, k); break;
			}*/
			/*case 5:
			{
				int n = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(n, k); break;
			}*/
			/*case 6:
			{
				int n = ;
				int k = ;
				_expected = LL;
				_received = _obj.count(n, k); break;
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
