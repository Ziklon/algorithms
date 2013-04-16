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

int B[5000];

struct CrazyCompetition {
   double differenceTemperature( int daysSummer, int daysWinter, vector <string> temperature ) {
		vector<int> temp;
		REP(i,temperature.size())REP(j,temperature[i].size()){
            if(temperature[i][j]>='a' && temperature[i][j]<='z')temp.push_back(temperature[i][j]-'a'+1);
            else if(temperature[i][j]>='A' && temperature[i][j]<='Z')temp.push_back(-1*(temperature[i][j]-'A'+1));
            else temp.push_back(0);            
		}
		B[0]=0;
		double ans=-1000000000;
		REP(i,temp.size()+1)if(i>=1)B[i]=B[i-1]+temp[i-1];
		
		for(int i=0;i+daysSummer<=temp.size();i++){
           //summer
           //i to i+daySummer
           double summer=(B[i+daysSummer]-B[i]+0.0)/daysSummer;
           for(int j=i+daysSummer;j+daysWinter<=temp.size();j++){
                double winter=(B[j+daysWinter]-B[j]+0.0)/daysWinter;
                ans=max(ans,summer-winter);
           }
           for(int j=0;j+daysWinter<=i;j++){                   
                double winter=(B[j+daysWinter]-B[j]+0.0)/daysWinter;
                ans=max(ans,summer-winter);
           }
                       
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
		cout << "Testing CrazyCompetition (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1365442923;
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
		CrazyCompetition _obj;
		double _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int daysSummer = 1;
				int daysWinter = 1;
				string temperature[] = {"aa"};
				_expected = 0.0;
				_received = _obj.differenceTemperature(daysSummer, daysWinter, vector <string>(temperature, temperature+sizeof(temperature)/sizeof(string))); break;
			}
			case 1:
			{
				int daysSummer = 1;
				int daysWinter = 1;
				string temperature[] = {"ba"};
				_expected = 1.0;
				_received = _obj.differenceTemperature(daysSummer, daysWinter, vector <string>(temperature, temperature+sizeof(temperature)/sizeof(string))); break;
			}
			case 2:
			{
				int daysSummer = 1;
				int daysWinter = 1;
				string temperature[] = {"az"};
				_expected = 25.0;
				_received = _obj.differenceTemperature(daysSummer, daysWinter, vector <string>(temperature, temperature+sizeof(temperature)/sizeof(string))); break;
			}
			case 3:
			{
				int daysSummer = 2;
				int daysWinter = 3;
				string temperature[] = {"aaaa","x"};
				_expected = 11.5;
				_received = _obj.differenceTemperature(daysSummer, daysWinter, vector <string>(temperature, temperature+sizeof(temperature)/sizeof(string))); break;
			}
			case 4:
			{
				int daysSummer = 2;
				int daysWinter = 3;
				string temperature[] = {"a","a","a","a","x"};
				_expected = 11.5;
				_received = _obj.differenceTemperature(daysSummer, daysWinter, vector <string>(temperature, temperature+sizeof(temperature)/sizeof(string))); break;
			}
			case 5:
			{
				int daysSummer = 4;
				int daysWinter = 1;
				string temperature[] = {"00A00"};
				_expected = -0.25;
				_received = _obj.differenceTemperature(daysSummer, daysWinter, vector <string>(temperature, temperature+sizeof(temperature)/sizeof(string))); break;
			}
			/*case 6:
			{
				int daysSummer = ;
				int daysWinter = ;
				string temperature[] = ;
				_expected = ;
				_received = _obj.differenceTemperature(daysSummer, daysWinter, vector <string>(temperature, temperature+sizeof(temperature)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				int daysSummer = ;
				int daysWinter = ;
				string temperature[] = ;
				_expected = ;
				_received = _obj.differenceTemperature(daysSummer, daysWinter, vector <string>(temperature, temperature+sizeof(temperature)/sizeof(string))); break;
			}*/
			/*case 8:
			{
				int daysSummer = ;
				int daysWinter = ;
				string temperature[] = ;
				_expected = ;
				_received = _obj.differenceTemperature(daysSummer, daysWinter, vector <string>(temperature, temperature+sizeof(temperature)/sizeof(string))); break;
			}*/
			default: return 0;
		}
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		double _elapsed = (double)(clock()-_start)/CLOCKS_PER_SEC;
		if (abs(_expected-_received) < 1e-9 || (_received > min(_expected*(1.0-1e-9), _expected*(1.0+1e-9)) && _received < max(_expected*(1.0-1e-9), _expected*(1.0+1e-9))))
			cout << "#" << _tc << ": Passed (" << _elapsed << " secs)" << endl;
		else
		{
			cout << "#" << _tc << ": Failed (" << _elapsed << " secs)" << endl;
			cout.precision(10);
			cout << "           Expected: " << _expected << endl;
			cout << "           Received: " << _received << endl;
		}
	}
}

// END CUT HERE
