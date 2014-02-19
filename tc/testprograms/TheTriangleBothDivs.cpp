#include <sstream>
#include <iostream> 
#include <vector>  
#include <queue>  
#include <set> 
#include <cstdio>
#include <map>  
#include <algorithm> 
#include <cmath>  
#include <cstdlib>  
#include <cstring> 
using namespace std;
typedef long long ll;
string ans = string(10,'9'),cad;
void func(int idx){

    //cout<<cad<<" cad "<<endl;

    if(idx==cad.size()){
        //get hour and save best
        //cout<<"hello"<<endl;
        if(cad[9]=='-' && cad[10]=='0')return;

        int hh,mm,nn;

        sscanf(cad.c_str(),"%d:%d GMT%d",&hh,&mm,&nn);
        if(hh<=23 && mm<=59){
            hh = (hh-nn+24)%24;
            char buff[20];
            sprintf(buff,"%02d:%02d",hh,mm);
            ans = min(ans,string(buff));    
        }        
        return ;
    }
    if(cad[idx]=='?'){
        //paint 
        if(idx==9){
            cad[idx]='+';func(idx+1);
            cad[idx]='-';func(idx+1);
        }else{
            for(int i=0;i<10;i++){
                cad[idx]=('0'+i);
                func(idx+1);
            }
        }
        cad[idx]='?';
        //func(idx+1);
        //unpaint
    }else 
        func(idx+1);
}



struct TheTriangleBothDivs {
    string fix(string _time) {
        cad = _time;
        func(0);
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
		cout << "Testing TheTriangleBothDivs (500.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1392682591;
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
		TheTriangleBothDivs _obj;
		string _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				string time = "17:45 GMT-4";
				_expected = "21:45";
				_received = _obj.fix(time); break;
			}
			case 1:
			{
				string time = "16:?? GMT??";
				_expected = "00:00";
				_received = _obj.fix(time); break;
			}
			case 2:
			{
				string time = "?1:34 GMT-9";
				_expected = "06:34";
				_received = _obj.fix(time); break;
			}
			case 3:
			{
				string time = "??:?? GMT??";
				_expected = "00:00";
				_received = _obj.fix(time); break;
			}
			case 4:
			{
				string time = "00:?? GMT-?";
				_expected = "01:00";
				_received = _obj.fix(time); break;
			}
			/*case 5:
			{
				string time = ;
				_expected = ;
				_received = _obj.fix(time); break;
			}*/
			/*case 6:
			{
				string time = ;
				_expected = ;
				_received = _obj.fix(time); break;
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
