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

struct MagicSpell {
   string fixTheSpell( string spell ) {
		vector<char> v;
		REP(i,spell.size())if(spell[i]=='A' || spell[i]=='Z')v.push_back(spell[i]);
		reverse(v.begin(),v.end());
		int j=0;
		REP(i,spell.size())if(spell[i]=='A' || spell[i]=='Z')spell[i]=v[j++];
		return spell;
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
		cout << "Testing MagicSpell (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1367898233;
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
		MagicSpell _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string spell = "AZ";
				_expected = "ZA";
				_received = _obj.fixTheSpell(spell); break;
			}
			case 1:
			{
				string spell = "ABACADA";
				_expected = "ABACADA";
				_received = _obj.fixTheSpell(spell); break;
			}
			case 2:
			{
				string spell = "AABZCADZA";
				_expected = "AZBACZDAA";
				_received = _obj.fixTheSpell(spell); break;
			}
			case 3:
			{
				string spell = "AZBASGHNAZAHBNVZZGGGAGGZAZ";
				_expected = "ZABZSGHNAZZHBNVAZGGGAGGAZA";
				_received = _obj.fixTheSpell(spell); break;
			}
			/*case 4:
			{
				string spell = ;
				_expected = ;
				_received = _obj.fixTheSpell(spell); break;
			}*/
			/*case 5:
			{
				string spell = ;
				_expected = ;
				_received = _obj.fixTheSpell(spell); break;
			}*/
			/*case 6:
			{
				string spell = ;
				_expected = ;
				_received = _obj.fixTheSpell(spell); break;
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
