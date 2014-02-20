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

int dp[1<<10][10];

int go(int mask,int pos,  int &curMask, int& q, vector<string>& v){
    if(pos>=v.size())return __builtin_popcount(mask)==q;
    int& ref = dp[mask][pos];
    if(ref!=-1)return ref;
    ref = 0;
    for(int i=0;i<q;i++){
        if( (curMask&(1<<i)) ==0 && v[pos]=="No")ref += go(mask|(1<<i), pos+1, curMask,q, v);
        if( (curMask&(1<<i)) !=0 && v[pos]=="Yes")ref +=go(mask|(1<<i), pos+1, curMask,q, v);     
    } 
    return ref;


}

struct TheQuestionsAndAnswersDivOne {
    int find(int questions, vector <string> answers) {
       int ans = 0;
       for(int mask = 0; mask < (1<<questions) ; mask++){
            memset(dp,-1,sizeof dp);
            ans +=go(0, 0,mask,questions,answers);
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
		cout << "Testing TheQuestionsAndAnswersDivOne (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392861798;
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
		TheQuestionsAndAnswersDivOne _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int questions = 2;
				string answers[] = {"No", "Yes"};
				_expected = 2;
				_received = _obj.find(questions, vector <string>(answers, answers+sizeof(answers)/sizeof(string))); break;
			}
			case 1:
			{
				int questions = 2;
				string answers[] = {"No", "No", "No"};
				_expected = 6;
				_received = _obj.find(questions, vector <string>(answers, answers+sizeof(answers)/sizeof(string))); break;
			}
			case 2:
			{
				int questions = 3;
				string answers[] = {"Yes", "No", "No", "Yes"};
				_expected = 12;
				_received = _obj.find(questions, vector <string>(answers, answers+sizeof(answers)/sizeof(string))); break;
			}
			case 3:
			{
				int questions = 3;
				string answers[] = {"Yes", "Yes", "Yes", "No"};
				_expected = 18;
				_received = _obj.find(questions, vector <string>(answers, answers+sizeof(answers)/sizeof(string))); break;
			}
			/*case 4:
			{
				int questions = ;
				string answers[] = ;
				_expected = ;
				_received = _obj.find(questions, vector <string>(answers, answers+sizeof(answers)/sizeof(string))); break;
			}*/
			/*case 5:
			{
				int questions = ;
				string answers[] = ;
				_expected = ;
				_received = _obj.find(questions, vector <string>(answers, answers+sizeof(answers)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int questions = ;
				string answers[] = ;
				_expected = ;
				_received = _obj.find(questions, vector <string>(answers, answers+sizeof(answers)/sizeof(string))); break;
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
