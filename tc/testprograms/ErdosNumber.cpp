#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath> 
#include <set>
#include <map>
#include <sstream>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm> 
using namespace std; 
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
typedef long long ll;

struct ErdosNumber {
   vector <string> calculateNumbers( vector <string> publications ) {
		vector <string> ans;
		map<string,int> M;
		int n=publications.size();
		vector<vector<string> > v(n);
		REP(i,n){
			stringstream ss(publications[i]);
			string tmp;
			while(ss>>tmp)v[i].push_back(tmp);			
			sort(v[i].begin(),v[i].end());
		}
		M["ERDOS"]=0;
		queue<string> Q;
		Q.push("ERDOS");
		while(!Q.empty()){
			string cur=Q.front();Q.pop();
			REP(i,n){
				if(binary_search(v[i].begin(),v[i].end(),cur)){
					REP(j,v[i].size()){
						if(M.count(v[i][j])==0){						
							M[v[i][j]]=M[cur]+1;
							Q.push(v[i][j]);
						}	
					}					
				}			
			}		
		}
		vector<pair<string,int> > vp(M.begin(),M.end());		
		REP(i,vp.size()){
			char buff[1024];
			sprintf(buff,"%s %d",vp[i].first.c_str(),vp[i].second);
			ans.push_back(buff);
		}
		REP(i,n){
			REP(j,v[i].size())if(M.count(v[i][j])==0){
				ans.push_back(v[i][j]);
			}
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
		cout << "Testing ErdosNumber (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1357603749;
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
		ErdosNumber _obj;
		vector <string> _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string publications[] = {"ERDOS"};
				string __expected[] = {"ERDOS 0" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calculateNumbers(vector <string>(publications, publications+sizeof(publications)/sizeof(string))); break;
			}
			case 1:
			{
				string publications[] = {"KLEITMAN LANDER", "ERDOS KLEITMAN"};
				string __expected[] = {"ERDOS 0", "KLEITMAN 1", "LANDER 2" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calculateNumbers(vector <string>(publications, publications+sizeof(publications)/sizeof(string))); break;
			}
			case 2:
			{
				string publications[] = {"ERDOS A", "A B", "B AA C"};
				string __expected[] = {"A 1", "AA 3", "B 2", "C 3", "ERDOS 0" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calculateNumbers(vector <string>(publications, publications+sizeof(publications)/sizeof(string))); break;
			}
			case 3:
			{
				string publications[] = {"ERDOS B", "A B C", "B A E", "D F"};
				string __expected[] = {"A 2", "B 1", "C 2", "D", "E 2", "ERDOS 0", "F" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calculateNumbers(vector <string>(publications, publications+sizeof(publications)/sizeof(string))); break;
			}
			case 4:
			{
				string publications[] = {"ERDOS KLEITMAN", "CHUNG GODDARD KLEITMAN WAYNE", "WAYNE GODDARD KLEITMAN", 
				                         "ALON KLEITMAN", "DEAN GODDARD WAYNE KLEITMAN STURTEVANT"};
				string __expected[] = {"ALON 2", "CHUNG 2", "DEAN 2", "ERDOS 0", "GODDARD 2", "KLEITMAN 1", "STURTEVANT 2", "WAYNE 2" };
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calculateNumbers(vector <string>(publications, publications+sizeof(publications)/sizeof(string))); break;
			}
			/*case 5:
			{
				string publications[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calculateNumbers(vector <string>(publications, publications+sizeof(publications)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string publications[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calculateNumbers(vector <string>(publications, publications+sizeof(publications)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string publications[] = ;
				string __expected[] = ;
				_expected = vector <string>(__expected, __expected+sizeof(__expected)/sizeof(string));
				_received = _obj.calculateNumbers(vector <string>(publications, publications+sizeof(publications)/sizeof(string))); break;
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
