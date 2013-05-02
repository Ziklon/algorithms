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

struct ComputerExpert {
   vector <string> operate( vector <string> facts, vector <string> rules ) {
        vector<pair<string,vector<vector<string> > > >rule;
        vector<string> ans;
		REP(i,rules.size()){
            int idx = rules[i].find("->");
            string fact=rules[i].substr(idx+3);
            string text=rules[i].substr(0,idx-1);
            REP(j,text.size())if(text[j]==',')text[j]=' ';            
            string tmp1,tmp2;
            stringstream ss1(text);
            vector<vector<string> >cur;
            while(ss1>>tmp1){
                REP(j,tmp1.size())if(tmp1[j]=='/')tmp1[j]=' ';
                stringstream ss2(tmp1);
                vector<string> v;
                while(ss2>>tmp2)v.push_back(tmp2);
                cur.push_back(v);                
            }
            rule.push_back(make_pair(fact,cur));
		}
		set<string> S(facts.begin(),facts.end());
		while(1){
            bool found=0;            
            REP(i,rule.size())
                if(S.count(rule[i].first)==0){
                   vector<vector<string> >cur=rule[i].second; 
                   bool ok=1;
                   REP(j,cur.size()){
                      int flag=0; 
                      REP(k,cur[j].size())if(S.count(cur[j][k]))flag=1;                      
                      if(flag==0)ok=0;  
                   }
                   if(ok){
                       S.insert(rule[i].first);
                       ans.push_back(rule[i].first);
                       found=1;
                       break; 
                   }
                        
                }
            if(found==0)break;
            
		}
		sort(ans.begin(),ans.end());
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
		cout << "Testing ComputerExpert (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367285507;
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
		ComputerExpert _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string facts[] = {"SKY_IS_CLOUDY","HAVE_MONEY"};
				string rules[] = {"HAVE_MONEY,BAD_WEATHER -> WATCH_MOVIE","SKY_IS_CLOUDY -> BAD_WEATHER",
				                 "GOOD_WEATHER -> PLAY_SOCCER"};
				string __expected[] = {"BAD_WEATHER", "WATCH_MOVIE" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.operate(vector <string>(facts, facts+sizeof(facts)/sizeof(string)), vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}
			case 1:
			{
				string facts[] = {"NEEDLE_LEAF","KEEPS_LEAVES"};
				string rules[] = {"KEEPS_LEAVES -> EVERGREEN","NEEDLE_LEAF -> GYMNOSPERM",
				                 "EVERGREEN,GYMNOSPERM -> PINE_TREE"};
				string __expected[] = {"EVERGREEN", "GYMNOSPERM", "PINE_TREE" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.operate(vector <string>(facts, facts+sizeof(facts)/sizeof(string)), vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}
			case 2:
			{
				string facts[] = {"I"};
				string rules[] = {"I -> I","P -> CONSONANT", "Z -> CONSONANT", "A/E/I/O/U -> VOWEL"};
				string __expected[] = {"VOWEL" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.operate(vector <string>(facts, facts+sizeof(facts)/sizeof(string)), vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}
			case 3:
			{
				string facts[] = {"Y","W","L","T","H","J","G","T","F","P","T","P","P","N"};
				string rules[] = {"C/V,J,F/T,N,W,L -> M","N/L,F,B/N/E,Y -> C",
				                 "M,G,G,S/F/Q,G,S/G,H/Z,W,F,C,Q/F,M -> E"};
				string __expected[] = {"C", "E", "M" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.operate(vector <string>(facts, facts+sizeof(facts)/sizeof(string)), vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}
			case 4:
			{
				string facts[] = {"G","H"};
				string rules[] = {"A/B/C/D/E/F,G/Z -> Y", "H,H,H,H,H,H,H,H -> Z"};
				string __expected[] = {"Z" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.operate(vector <string>(facts, facts+sizeof(facts)/sizeof(string)), vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}
			case 5:
			{
				string facts[] = {"A","B","_X", "X_"};
				string rules[] = {"A/B,C -> D","A,B,C -> D","X -> Y","_X_ -> Y"};
				string __expected[] = { };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.operate(vector <string>(facts, facts+sizeof(facts)/sizeof(string)), vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}
			/*case 6:
			{
				string facts[] = ;
				string rules[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.operate(vector <string>(facts, facts+sizeof(facts)/sizeof(string)), vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string facts[] = ;
				string rules[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.operate(vector <string>(facts, facts+sizeof(facts)/sizeof(string)), vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string facts[] = ;
				string rules[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.operate(vector <string>(facts, facts+sizeof(facts)/sizeof(string)), vector <string>(rules, rules+sizeof(rules)/sizeof(string))); break;
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
