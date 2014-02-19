#include <sstream>
#include <iostream> 
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <algorithm> 
#include <cmath>  
#include <cstdlib>  
#include <cstring> 
using namespace std;
typedef long long ll;

struct SentenceCapitalizerInator {
    string fixCaps(string paragraph) {
        int N = paragraph.size();
        bool ready = true;
        for(int i = 0 ;i < N ;i++ ){
            
            if(isalpha(paragraph[i]) && ready == true){
                paragraph[i] = toupper(paragraph[i]);
                ready = false;
            }

            if(paragraph[i]=='.')ready=true;

        }
        return paragraph;

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
		cout << "Testing SentenceCapitalizerInator (250.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391036914;
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
		SentenceCapitalizerInator _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string paragraph = "hello programmer. welcome to topcoder.";
				_expected = "Hello programmer. Welcome to topcoder.";
				_received = _obj.fixCaps(paragraph); break;
			}
			case 1:
			{
				string paragraph = "one.";
				_expected = "One.";
				_received = _obj.fixCaps(paragraph); break;
			}
			case 2:
			{
				string paragraph = "not really. english. qwertyuio. a. xyz.";
				_expected = "Not really. English. Qwertyuio. A. Xyz.";
				_received = _obj.fixCaps(paragraph); break;
			}
			case 3:
			{
				string paragraph = "example four. the long fourth example. a. b. c. d.";
				_expected = "Example four. The long fourth example. A. B. C. D.";
				_received = _obj.fixCaps(paragraph); break;
			}
			/*case 4:
			{
				string paragraph = ;
				_expected = ;
				_received = _obj.fixCaps(paragraph); break;
			}*/
			/*case 5:
			{
				string paragraph = ;
				_expected = ;
				_received = _obj.fixCaps(paragraph); break;
			}*/
			/*case 6:
			{
				string paragraph = ;
				_expected = ;
				_received = _obj.fixCaps(paragraph); break;
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
