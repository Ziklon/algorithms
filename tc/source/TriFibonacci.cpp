#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath> 
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std; 
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
typedef long long ll;
int B[55];
struct TriFibonacci {
   int complete( vector <int> A ) {
		int n=A.size();
		int index=0;
		REP(i,n)if(A[i]==-1)index=i;
		int left=min(index,3);
		int right=min(3-left,n-index);
		if(left+right<3)return -1;
		int sumleft=0;
		REP(i,left)sumleft+=A[index-i-1];
		REP(i,right-1)sumleft+=A[index+i+1];
		
		if(left==3)
			A[index]=sumleft;
		else
			A[index]=A[index+right]-sumleft;
		if(A[index]<=0)return -1;			
		
		FOR(i,3,n-1){
			B[i]=A[i-1]+A[i-2]+A[i-3];
			if(B[i]!=A[i])return -1;
		}		
		return A[index];			
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
		cout << "Testing TriFibonacci (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1357600602;
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
		TriFibonacci _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int A[] = {1,2,3,-1};
				_expected = 6;
				_received = _obj.complete(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 1:
			{
				int A[] = {10, 20, 30, 60, -1 , 200};
				_expected = 110;
				_received = _obj.complete(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 2:
			{
				int A[] = {1, 2, 3, 5, -1};
				_expected = -1;
				_received = _obj.complete(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 3:
			{
				int A[] = {1, 1, -1, 2, 3};
				_expected = -1;
				_received = _obj.complete(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			case 4:
			{
				int A[] = {-1, 7, 8, 1000000};
				_expected = 999985;
				_received = _obj.complete(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}
			/*case 5:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.complete(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.complete(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int A[] = ;
				_expected = ;
				_received = _obj.complete(vector <int>(A, A+sizeof(A)/sizeof(int))); break;
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
