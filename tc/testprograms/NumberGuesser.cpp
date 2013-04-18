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
int toi(string s){
    int ans=0;
    REP(i,s.size())ans=ans*10+(s[i]-'0');
    return ans;
}
vector<int> parse(int n){
   vector<int> v(10,0);
   while(n){
        v[n%10]++;
        n/=10;
   }
   return v; 
}
bool check(string num){
    int val=toi(num);
    for(int i=1;i<=9998;i++){
        int j=val+i;
        if(j<=9998){
            vector<int> a=parse(i);
            vector<int> b=parse(j);
            bool can=1;
            REP(k,10)if(k>=1 && a[k]!=b[k])can=0;
            if(can)return 1;
        }
    }
    return 0;
}

struct NumberGuesser {
   int guess( string leftOver ) {
        
        int idx=0;
        while(idx<leftOver.size() && leftOver[idx]=='0')idx++;
		for(char c='1';c<='9';c++){
		
           for(int j=0;j<=leftOver.size();j++){
               string bb=leftOver.substr(0,j)+c+leftOver.substr(j);
               if(check(bb))return c-'0'; 
           }
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
		cout << "Testing NumberGuesser (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366129387;
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
		NumberGuesser _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string leftOver = "087";
				_expected = 3;
				_received = _obj.guess(leftOver); break;
			}
			case 1:
			{
				string leftOver = "099";
				_expected = 9;
				_received = _obj.guess(leftOver); break;
			}
			case 2:
			{
				string leftOver = "191";
				_expected = 7;
				_received = _obj.guess(leftOver); break;
			}
			case 3:
			{
				string leftOver = "689";
				_expected = 4;
				_received = _obj.guess(leftOver); break;
			}
			/*case 4:
			{
				string leftOver = ;
				_expected = ;
				_received = _obj.guess(leftOver); break;
			}*/
			/*case 5:
			{
				string leftOver = ;
				_expected = ;
				_received = _obj.guess(leftOver); break;
			}*/
			/*case 6:
			{
				string leftOver = ;
				_expected = ;
				_received = _obj.guess(leftOver); break;
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
