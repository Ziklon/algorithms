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
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++) 
typedef long long ll; 

string pali;
int dp[150];
int go(int idx, vector<string>& v){
    if(idx>=pali.size())return 1;
    int& ref=dp[idx];
    if(ref!=-1)return ref;
    ref=0;
    for(int i=0;i<v.size();i++){
       if(idx+v[i].size()<=pali.size()){
            string tmp=pali.substr(idx,v[i].size());
            if(tmp==v[i])
                ref=max(ref,go(idx+tmp.size(),v));
       } 
    }
    return ref;
}

struct Palindromist {
   string palindrome( string text, vector <string> words ) {
        int i,j,N=words.size();
        string ans=string(200,'Z');
        sort(words.begin(),words.end());    
        string other=text;
        reverse(other.begin(),other.end());
        vector<string> palis;
        palis.push_back(text+other.substr(1));
        palis.push_back(text+other);
        REP(i,2){
            memset(dp,-1,sizeof dp);
            pali=palis[i];
            int ret=go(0,words);
            if(ret==1){
                string tmp;
                int pos=0;
                while(pos<palis[i].size()){
                    REP(j,N){
                        if(pos+words[j].size()<=pali.size()){
                            string aux=pali.substr(pos,words[j].size());
                            if(aux==words[j] && go(pos+aux.size(),words)){
                                 tmp=tmp+" "+aux;  
                                 pos=pos+aux.size();
                                 break; 
                            }
                        } 
                    }
                }
                tmp=tmp.substr(1);
                ans=min(ans,tmp);
            }
        }
        if(ans.size()==200)return "";
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
		cout << "Testing Palindromist (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365104935;
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
		Palindromist _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string text = "AMANAPLANAC";
				string words[] = { "A", "CANAL", "MAN", "PANAMA", "PLAN" };
				_expected = "A MAN A PLAN A CANAL PANAMA";
				_received = _obj.palindrome(text, vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 1:
			{
				string text = "AAAAA";
				string words[] = { "AA", "A", "AAA" };
				_expected = "A A A A A A A A A";
				_received = _obj.palindrome(text, vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 2:
			{
				string text = "CBA";
				string words[] = { "CBABC", "CBAABC" };
				_expected = "CBAABC";
				_received = _obj.palindrome(text, vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 3:
			{
				string text = "RACEFAST";
				string words[] = { "AR", "CAR", "FAST", "RACE", "SAFE", "CEFA", "ACE", "STTS", "AFEC" };
				_expected = "RACE FAST SAFE CAR";
				_received = _obj.palindrome(text, vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 4:
			{
				string text = "AABAABA";
				string words[] = { "AA", "AAB", "BAA", "BAB" };
				_expected = "AA BAA BAA BAA BAA";
				_received = _obj.palindrome(text, vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 5:
			{
				string text = "STRAWNOTOOSTUPIDAF";
				string words[] = { "WARTS", "I", "TOO", "A", "FAD", "STUPID", "STRAW", "PUT", "NO", "ON", "SOOT" };
				_expected = "STRAW NO TOO STUPID A FAD I PUT SOOT ON WARTS";
				_received = _obj.palindrome(text, vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 6:
			{
				string text = "AAAAA";
				string words[] = { "AAAA" };
				_expected = "";
				_received = _obj.palindrome(text, vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			case 7:
			{
				string text = "A";
				string words[] = { "A", "AA" };
				_expected = "A";
				_received = _obj.palindrome(text, vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}
			/*case 8:
			{
				string text = ;
				string words[] = ;
				_expected = ;
				_received = _obj.palindrome(text, vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 9:
			{
				string text = ;
				string words[] = ;
				_expected = ;
				_received = _obj.palindrome(text, vector <string>(words, words+sizeof(words)/sizeof(string))); break;
			}*/
			/*case 10:
			{
				string text = ;
				string words[] = ;
				_expected = ;
				_received = _obj.palindrome(text, vector <string>(words, words+sizeof(words)/sizeof(string))); break;
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
