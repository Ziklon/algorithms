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

struct PerfectSequences {
    string fixIt(vector <int> seq) {
        
        int N = seq.size();
        if(N==1)return "Yes";

        for(int i = 0 ; i < N ; i++ ){
            
            ll sum = 0;
            ll prod = 1;
            for(int j = 0 ; j < N; j++ ) if(i!=j){
                
                sum += seq[j];
                prod *= seq[j];
                if(prod < 0 ) break;
            }

            if(sum==0 && prod==0  && seq[i]!=0)return "Yes";

            if(prod > 1 ){
                ll x  = sum / (prod-1);
                if(x!=seq[i] &&  sum + x == prod*x )return "Yes";
            
            }
            

            
        }

        
        return "No";

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
		cout << "Testing PerfectSequences (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391037368;
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
		PerfectSequences _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int seq[] = {1,3,4};
				_expected = "Yes";
				_received = _obj.fixIt(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 1:
			{
				int seq[] = {1,2,3};
				_expected = "No";
				_received = _obj.fixIt(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 2:
			{
				int seq[] = {1,4,2,4,2,4};
				_expected = "No";
				_received = _obj.fixIt(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 3:
			{
				int seq[] = {1000000,1,1,1,1,2};
				_expected = "Yes";
				_received = _obj.fixIt(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 4:
			{
				int seq[] = {8};
				_expected = "Yes";
				_received = _obj.fixIt(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			case 5:
			{
				int seq[] = {2,0,2};
				_expected = "No";
				_received = _obj.fixIt(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}
			/*case 6:
			{
				int seq[] = ;
				_expected = ;
				_received = _obj.fixIt(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int seq[] = ;
				_expected = ;
				_received = _obj.fixIt(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
			}*/
			/*case 8:
			{
				int seq[] = ;
				_expected = ;
				_received = _obj.fixIt(vector <int>(seq, seq+sizeof(seq)/sizeof(int))); break;
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
			cout << "           Expected: " << "\"" << _expected << "\"" << endl;
			cout << "           Received: " << "\"" << _received << "\"" << endl;
		}
	}
}

// END CUT HERE
