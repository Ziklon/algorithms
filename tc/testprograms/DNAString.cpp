#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define RESET(c,v) memset(c, v, sizeof(c))
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)

typedef long long ll;

struct DNAString {
	int minChanges( int maxPeriod, vector <string> dna ) {
		int ans=1<<20,n=dna.size();
		string text;
		REP(i,n)text+=dna[i];
		n=text.size();
		FOR(p,1,maxPeriod){
			int tmp=0;
			REP(j,p){
				vector<int> M(26,0);
				for(int i=j;i<n;i+=p)M[text[i]-'A']++;
				int tot=0;
				int maxi=0;
				REP(i,26)maxi=max(maxi,M[i]),tot+=M[i];
				tmp+=(tot-maxi);
			}
			ans=min(ans,tmp);
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
		cout << "Testing DNAString (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1356586225;
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
		DNAString _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int maxPeriod = 3;
				string dna[] = {"ATAGATA"};
				_expected = 1;
				_received = _obj.minChanges(maxPeriod, vector <string>(dna, dna+sizeof(dna)/sizeof(string))); break;
			}
			case 1:
			{
				int maxPeriod = 2;
				string dna[] = {"ACGTGCA"};
				_expected = 3;
				_received = _obj.minChanges(maxPeriod, vector <string>(dna, dna+sizeof(dna)/sizeof(string))); break;
			}
			case 2:
			{
				int maxPeriod = 13;
				string dna[] = {"ACGCTGACAGATA"};
				_expected = 0;
				_received = _obj.minChanges(maxPeriod, vector <string>(dna, dna+sizeof(dna)/sizeof(string))); break;
			}
			case 3:
			{
				int maxPeriod = 1;
				string dna[] = {"AAAATTTCCG"};
				_expected = 6;
				_received = _obj.minChanges(maxPeriod, vector <string>(dna, dna+sizeof(dna)/sizeof(string))); break;
			}
			case 4:
			{
				int maxPeriod = 12;
				string dna[] = {"ACGTATAGCATGACA","ACAGATATTATG","ACAGATGTAGCAGTA","ACCA","GAC"};
				_expected = 20;
				_received = _obj.minChanges(maxPeriod, vector <string>(dna, dna+sizeof(dna)/sizeof(string))); break;
			}
			/*case 5:
			{
				int maxPeriod = ;
				string dna[] = ;
				_expected = ;
				_received = _obj.minChanges(maxPeriod, vector <string>(dna, dna+sizeof(dna)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				int maxPeriod = ;
				string dna[] = ;
				_expected = ;
				_received = _obj.minChanges(maxPeriod, vector <string>(dna, dna+sizeof(dna)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int maxPeriod = ;
				string dna[] = ;
				_expected = ;
				_received = _obj.minChanges(maxPeriod, vector <string>(dna, dna+sizeof(dna)/sizeof(string))); break;
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
