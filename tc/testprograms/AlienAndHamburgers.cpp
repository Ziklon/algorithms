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
#define FOREACH(it,c) for (typeof((c).end()) it = (c).begin(); it != (c).end(); ++it) 
#define REP(i,n)for (int i=0;i<n;i++)
#define all(v) (v).begin(), (v).end()
typedef long long ll;

struct AlienAndHamburgers {
            int getNumber(vector <int> type, vector <int> taste) {
                
                int ans = 0;
                map<int,vector<int> >typesTaste; 

                for(int i = 0; i < taste.size(); i++ ){
                    typesTaste[type[i]].push_back(taste[i]);
                }
                
                vector<int> tasteResult ;
                for(auto &q : typesTaste){
                    auto &tmp = q.second;
                    sort(tmp.rbegin(),tmp.rend());
                    int sum = 0,idx = 0;
                    while(idx<tmp.size() && tmp[idx]>=0)
                        sum += tmp[idx++];
                    if(idx==0)
                        sum += tmp[0];

                    tasteResult.push_back(sum);    
                }

                sort(tasteResult.rbegin(),tasteResult.rend());
                int sum =0;

                for(int i = 0 ;i <tasteResult.size(); i++){
                    sum += tasteResult[i];
                    ans = max(ans, (i+1)*sum);
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
		cout << "Testing AlienAndHamburgers (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391032317;
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
		AlienAndHamburgers _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int type[] = {1, 2};
				int taste[] = {4, 7};
				_expected = 22;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 1:
			{
				int type[] = {1, 1};
				int taste[] = {-1, -1};
				_expected = 0;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 2:
			{
				int type[] = {1, 2, 3};
				int taste[] = {7, 4, -1};
				_expected = 30;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 3:
			{
				int type[] = {1, 2, 3, 2, 3, 1, 3, 2, 3, 1, 1, 1};
				int taste[] = {1, 7, -2, 3, -4, -1, 3, 1, 3, -5, -1, 0};
				_expected = 54;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			case 4:
			{
				int type[] = {30, 20, 10};
				int taste[] = {100000, -100000, 100000};
				_expected = 400000;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}
			/*case 5:
			{
				int type[] = ;
				int taste[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int type[] = ;
				int taste[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int type[] = ;
				int taste[] = ;
				_expected = ;
				_received = _obj.getNumber(vector <int>(type, type+sizeof(type)/sizeof(int)), vector <int>(taste, taste+sizeof(taste)/sizeof(int))); break;
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
