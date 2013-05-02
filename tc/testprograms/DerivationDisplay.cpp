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

struct DerivationDisplay {
   vector <string> getDerivation( string input ) {
		vector<string> ans;
		ans.push_back("S");
		int N=input.size();
		string suf="",pre="";
		if(input[0]=='b' && input[N-1]=='a'){
            REP(i,N-2){
               pre+=input[i];
               ans.push_back(pre+"Ua"); 
            }            
		}else{
            int left=0,right=N-1;
            ans.push_back("T");            
            while(left<right && input[left]=='a' && input[right]=='b'){
                pre+="a";
                suf+="b";
                ans.push_back(pre+"T"+suf);   
                left++;
                right--; 
            }
            if(input[left]=='a')
               ans.push_back(pre+"A"+suf);
            else
                ans.push_back(pre+"B"+suf);
            while(left<right){                
                if(input[left]=='a'){
                    pre+="a";
                    ans.push_back(pre+"A"+suf);
                }else{
                    pre+="b";
                    ans.push_back(pre+"B"+suf);
                }
                left++;    
            }            
		}
		ans.push_back(input);
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
		cout << "Testing DerivationDisplay (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367212713;
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
		DerivationDisplay _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string input = "aaabb";
				string __expected[] = {"S", "T", "aTb", "aaTbb", "aaAbb", "aaabb" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getDerivation(input); break;
			}
			case 1:
			{
				string input = "bbba";
				string __expected[] = {"S", "bUa", "bbUa", "bbba" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getDerivation(input); break;
			}
			case 2:
			{
				string input = "baabba";
				string __expected[] = {"S", "bUa", "baUa", "baaUa", "baabUa", "baabba" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getDerivation(input); break;
			}
			case 3:
			{
				string input = "a";
				string __expected[] = {"S", "T", "A", "a" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getDerivation(input); break;
			}
			case 4:
			{
				string input = "b";
				string __expected[] = {"S", "T", "B", "b" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getDerivation(input); break;
			}
			case 5:
			{
				string input = "aabbbbbbbb";
				string __expected[] = {"S", "T", "aTb", "aaTbb", "aaBbb", "aabBbb", "aabbBbb", "aabbbBbb", "aabbbbBbb", "aabbbbbBbb", "aabbbbbbbb" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getDerivation(input); break;
			}
			/*case 6:
			{
				string input = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getDerivation(input); break;
			}*/
			/*case 7:
			{
				string input = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getDerivation(input); break;
			}*/
			/*case 8:
			{
				string input = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.getDerivation(input); break;
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
				cout << " \"" << _expected[i] << "\"";
			}
			cout << " }" << endl;
			cout << "           Received: {";
			for (unsigned i = 0; i < _received.size(); i++)
			{
				if (i) cout << ",";
				cout << " \"" << _received[i] << "\"";
			}
			cout << " }" << endl;
		}
	}
}

// END CUT HERE
