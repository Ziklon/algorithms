#include <iostream>  
#include <sstream>
#include <vector>
#include <cstdio>  
#include <set>  
#include <map>  
#include <algorithm> 
#include <cmath> 
#include <cstring> 
using namespace std;  
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)  
typedef long long ll;

int find_index(vector<string> &v,  string &s){
    for(int i=0;i<v.size();i++)if(v[i]==s)return i;
    return -1;
}
struct HuffmanDecoding {
	string decode(string archive, vector <string> dictionary) {
		string ans;
		int N=archive.size();
		//sort(dictionary.begin(),dictionary.end());
		int last = -1;
		for(int i=0;i<N;i++){
            string tmp = archive.substr(last+1,i-last);
            
            int idx =find_index(dictionary,tmp);
            if(idx!=-1){
                ans+=string(1,'A'+idx);
                last=i;
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
		cout << "Testing HuffmanDecoding (450.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391523788;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 450.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		HuffmanDecoding _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string archive = "101101";
				string dictionary[] = {"00","10","01","11"};
				_expected = "BDC";
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 1:
			{
				string archive = "10111010";
				string dictionary[] = {"0","111","10"};
				_expected = "CBAC";
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 2:
			{
				string archive = "0001001100100111001";
				string dictionary[] = {"1","0"};
				_expected = "BBBABBAABBABBAAABBA";
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 3:
			{
				string archive = "111011011000100110";
				string dictionary[] = {"010","00","0110","0111","11","100","101"};
				_expected = "EGGFAC";
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			case 4:
			{
				string archive = "001101100101100110111101011001011001010";
				string dictionary[] = {"110","011","10","0011","00011","111","00010","0010","010","0000"};
				_expected = "DBHABBACAIAIC";
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}
			/*case 5:
			{
				string archive = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}*/
			/*case 6:
			{
				string archive = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
			}*/
			/*case 7:
			{
				string archive = ;
				string dictionary[] = ;
				_expected = ;
				_received = _obj.decode(archive, vector <string>(dictionary, dictionary+sizeof(dictionary)/sizeof(string))); break;
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

//END CUT HERE
