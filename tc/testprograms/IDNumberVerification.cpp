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
#include <cstdio>
using namespace std; 
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++) 
#define FOREACH(i,c) for (typeof((c).end()) i = (c).begin(); i != (c).end(); ++i)
typedef long long ll; 
int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeap(int y){
    return (y%400==0 || (y%4==0 && y%100!=0));
}

int toi(string s){
    istringstream is(s);
    int res;
    is>>res;
    return res;
}
bool checkDate(string s){
    int yy=toi(s.substr(0,4));
    int mm=toi(s.substr(4,2));
    int dd=toi(s.substr(6,2));
    if(yy<1900 || mm<1 || dd<1 || dd>31  || mm>12 || yy>2011)return 0;
    
    if(isLeap(yy))days[1]++;
    
    if(days[mm-1]<dd)return 0;
    return 1;
}

struct IDNumberVerification {
   string verify( string id, vector <string> regionCodes ) {
		string region=id.substr(0,6);
		sort(regionCodes.begin(),regionCodes.end());
		if(binary_search(regionCodes.begin(),regionCodes.end(),region)==0)return "Invalid";
		string birthday=id.substr(6,8);
		if(checkDate(birthday)==0)return "Invalid";
		
		int checkSum=id[17]-'0';
		if(id[17]=='X')checkSum=10;
		
		REP(i,17){
           checkSum+=((id[i]-'0')*(1<<(17-i)));
           checkSum%=11;
        }
        if(checkSum!=1)return "Invalid";
		
		int type=toi(id.substr(14,3));
		
		if(type==0)return "Invalid";
		
		if((type&1)==0)return "Female";
		return "Male";	
		
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
		cout << "Testing IDNumberVerification (550.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1371690070;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 550.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		IDNumberVerification _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string id = "441323200312060636";
				string regionCodes[] = {"441323"};
				_expected = "Male";
				_received = _obj.verify(id, vector <string>(regionCodes, regionCodes+sizeof(regionCodes)/sizeof(string))); break;
			}
			case 1:
			{
				string id = "62012319240507058X";
				string regionCodes[] = {"620123"};
				_expected = "Female";
				_received = _obj.verify(id, vector <string>(regionCodes, regionCodes+sizeof(regionCodes)/sizeof(string))); break;
			}
			case 2:
			{
				string id = "321669197204300886";
				string regionCodes[] = {"610111","659004"};
				_expected = "Invalid";
				_received = _obj.verify(id, vector <string>(regionCodes, regionCodes+sizeof(regionCodes)/sizeof(string))); break;
			}
			case 3:
			{
				string id = "230231198306900162";
				string regionCodes[] = {"230231"};
				_expected = "Invalid";
				_received = _obj.verify(id, vector <string>(regionCodes, regionCodes+sizeof(regionCodes)/sizeof(string))); break;
			}
			case 4:
			{
				string id = "341400198407260005";
				string regionCodes[] = {"341400"};
				_expected = "Invalid";
				_received = _obj.verify(id, vector <string>(regionCodes, regionCodes+sizeof(regionCodes)/sizeof(string))); break;
			}
			case 5:
			{
				string id = "520381193206090891";
				string regionCodes[] = {"532922","520381"};
				_expected = "Invalid";
				_received = _obj.verify(id, vector <string>(regionCodes, regionCodes+sizeof(regionCodes)/sizeof(string))); break;
			}
			/*case 6:
			{
				string id = ;
				string regionCodes[] = ;
				_expected = ;
				_received = _obj.verify(id, vector <string>(regionCodes, regionCodes+sizeof(regionCodes)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string id = ;
				string regionCodes[] = ;
				_expected = ;
				_received = _obj.verify(id, vector <string>(regionCodes, regionCodes+sizeof(regionCodes)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				string id = ;
				string regionCodes[] = ;
				_expected = ;
				_received = _obj.verify(id, vector <string>(regionCodes, regionCodes+sizeof(regionCodes)/sizeof(string))); break;
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
