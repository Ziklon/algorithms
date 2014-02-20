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

double pw(int n){
    return 1.0*n*n;
}
int func(int w, int h, vector<int> red, vector<int> blue){
   int ans=1;
   if(red[0]*2<h)return 0; 
   double x= sqrt( pw(red[0]) - pw(h/2.0) );  
   for(int i=0;;i++){
       if(x+red[0]>=w)return ans;
       int idx=(i+1)/2;
       if(i&1){
          if(red.size()<idx || red[idx]*2 <h)return 0;

       }else{
          if(blue.size()<idx || blue[idx]*2 <)return 0;  

       }
       ans++;

   }
   return 0;

}


struct ColoringRectangle {
    int chooseDisks(int width, int height, vector <int> red, vector <int> blue) {
        sort(red.rbegin(),red.rend());
        sort(blue.rbegin(),blue.rend());
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
		cout << "Testing ColoringRectangle (300.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392864130;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 300.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		ColoringRectangle _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int width = 11;
				int height = 3;
				int red[] = {5,5};
				int blue[] = {2,5};
				_expected = 3;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 1:
			{
				int width = 30;
				int height = 5;
				int red[] = {4,10,7,8,10};
				int blue[] = {5,6,11,7,5};
				_expected = 4;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 2:
			{
				int width = 16;
				int height = 4;
				int red[] = {6,5,7};
				int blue[] = {5};
				_expected = -1;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 3:
			{
				int width = 4;
				int height = 4;
				int red[] = {5};
				int blue[] = {6};
				_expected = 1;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			case 4:
			{
				int width = 6;
				int height = 2;
				int red[] = {6,6};
				int blue[] = {2};
				_expected = 3;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}
			/*case 5:
			{
				int width = ;
				int height = ;
				int red[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int width = ;
				int height = ;
				int red[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int width = ;
				int height = ;
				int red[] = ;
				int blue[] = ;
				_expected = ;
				_received = _obj.chooseDisks(width, height, vector <int>(red, red+sizeof(red)/sizeof(int)), vector <int>(blue, blue+sizeof(blue)/sizeof(int))); break;
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
