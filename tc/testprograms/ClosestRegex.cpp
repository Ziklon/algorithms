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
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
typedef long long ll; 
typedef pair<int,string> pis; 
string text,regex;
pis dp[51][51];
bool seen[51][51];
int N,M;
pis INF =make_pair(1<<20,string());

pair<int,string> operator + (pis a, pis b){
    return make_pair(a.first+b.first,a.second+b.second);
}
pair<int,string> go(int ia, int ib){    
    if(ib>=M){
        if(ia<N)return INF;
        return make_pair(0,"");
    }        
    if(ia==N){        
        if(regex[ib+1]=='*')return go(ia,ib+2);
        return INF;
    }    
    pair<int,string>&  ref=dp[ia][ib];
    if(seen[ia][ib]==1)return ref;
    ref=INF;    
    if(ib+1<M && regex[ib+1]=='*'){
        int dif=0;        
        for(int i=0;i+ia<=N;i++){
            string cad=string(i,regex[ib]);
            dif=0;
            REP(j,i)if(text[ia+j]!=regex[ib])dif++;
            pis tmp=make_pair(dif,cad)+go(ia+i,ib+2);
            ref=min(ref,tmp);
        }
    }else{
        int dif=0;
        if(text[ia]!=regex[ib])dif++;
        pis tmp=make_pair(dif,regex.substr(ib,1))+go(ia+1,ib+1);
        ref=min(ref,tmp);
    }    
    seen[ia][ib]=1;
    return ref;    
}


struct ClosestRegex {
   string closestString( string _text, string _regex ) {
       text=_text;regex=_regex;
       N=text.size(),M=regex.size();
       memset(seen,0,sizeof seen);
       pis ans=go(0,0);    
       if(ans.first>=1000)return "";        
       return ans.second;
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
		cout << "Testing ClosestRegex (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1368215447;
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
		ClosestRegex _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string text = "abcd";
				string regex = "bcdd";
				_expected = "bcdd";
				_received = _obj.closestString(text, regex); break;
			}
			case 1:
			{
				string text = "topcoder";
				string regex = "t*px*coa*de*";
				_expected = "ttpcodee";
				_received = _obj.closestString(text, regex); break;
			}
			case 2:
			{
				string text = "cmu";
				string regex = "c*m*fm*u*";
				_expected = "cfu";
				_received = _obj.closestString(text, regex); break;
			}
			case 3:
			{
				string text = "aaaaacccc";
				string regex = "a*abc*";
				_expected = "aaaaabccc";
				_received = _obj.closestString(text, regex); break;
			}
			case 4:
			{
				string text = "short";
				string regex = "lo*ts*of*let*ter*s";
				_expected = "";
				_received = _obj.closestString(text, regex); break;
			}
			case 5:
			{
				string text = "qq";
				string regex = "o*ot*a*a*p*a*n*";
				_expected = "oa";
				_received = _obj.closestString(text, regex); break;
			}
			/*case 6:
			{
				string text = ;
				string regex = ;
				_expected = ;
				_received = _obj.closestString(text, regex); break;
			}*/
			/*case 7:
			{
				string text = ;
				string regex = ;
				_expected = ;
				_received = _obj.closestString(text, regex); break;
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
