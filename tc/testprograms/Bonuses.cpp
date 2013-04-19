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
bool orden(pair<int,int> p, pair<int,int> q){
    if(p.first!=q.first)return p.first>q.first;
    return p.second<q.second;
}

struct Bonuses {
   vector <int> getDivision( vector <int> points ) {
        int N=points.size();
		vector<int> ans(N);
		vector<pair<int,int> >v;
		int sum=0,per=0;
		REP(i,N){
            v.push_back(make_pair(points[i],i));
            sum+=points[i];
        }
        sort(v.begin(),v.end(),orden);
		REP(i,N){
           int cur=100*points[i]/sum;
           ans[i]=cur;
           per+=cur;     
		}		
		REP(i,100-per)ans[v[i].second]+=1;
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
		cout << "Testing Bonuses (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1366292344;
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
		Bonuses _obj;
		vector <int> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int points[] = {1,2,3,4,5};
				int __expected[] = { 6,  13,  20,  27,  34 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 1:
			{
				int points[] = {5,5,5,5,5,5};
				int __expected[] = { 17,  17,  17,  17,  16,  16 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			case 2:
			{
				int points[] = {485, 324, 263, 143, 470, 292, 304, 188, 100, 254, 296,
				                255, 360, 231, 311, 275,  93, 463, 115, 366, 197, 470};
				int __expected[] = { 8,  6,  4,  2,  8,  5,  5,  3,  1,  4,  5,  4,  6,  3,  5,  4,  1,  8,  1,  6,  3,  8 };
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}
			/*case 3:
			{
				int points[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 4:
			{
				int points[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
			}*/
			/*case 5:
			{
				int points[] = ;
				int __expected[] = ;
				_expected = vector <int>(__expected, __expected+sizeof(__expected)/sizeof(int));
				_received = _obj.getDivision(vector <int>(points, points+sizeof(points)/sizeof(int))); break;
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
