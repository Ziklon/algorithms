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

bool dp[500000];

struct LoadBalancing {
    int minTime( vector <int> chunkSizes ) {
        ll sum=0;
        int N=chunkSizes.size();
        REP(i,chunkSizes.size()) {
            chunkSizes[i]/=1024;
            sum+=chunkSizes[i];
        }
        memset(dp,0,sizeof dp);
        dp[0]=1;
        for(int i=0; i<N; i++) {
            for(int j=sum/2; j-chunkSizes[i]>=0; j--)
                dp[j]|=dp[j-chunkSizes[i]];
        }
        int ans=0;
        REP(i,(sum/2)+1)if(dp[i])ans=i;
        return 1024*(sum-ans);

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
        cout << "Testing LoadBalancing (900.0 points)" << endl << endl;
        for (int i = 0; i < 20; i++)
        {
            ostringstream s;
            s << argv[0] << " " << i;
            int exitCode = system(s.str().c_str());
            if (exitCode)
                cout << "#" << i << ": Runtime Error" << endl;
        }
        int T = time(NULL)-1366585324;
        double PT = T/60.0, TT = 75.0;
        cout.setf(ios::fixed,ios::floatfield);
        cout.precision(2);
        cout << endl;
        cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
        cout << "Score : " << 900.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
    }
    else
    {
        int _tc;
        istringstream(argv[1]) >> _tc;
        LoadBalancing _obj;
        int _expected, _received;
        time_t _start = clock();
        switch (_tc)
        {
        case 0:
        {
            int chunkSizes[] = {3072, 3072, 7168, 3072, 1024};
            _expected = 9216;
            _received = _obj.minTime(vector <int>(chunkSizes, chunkSizes+sizeof(chunkSizes)/sizeof(int)));
            break;
        }
        case 1:
        {
            int chunkSizes[] = {2048};
            _expected = 2048;
            _received = _obj.minTime(vector <int>(chunkSizes, chunkSizes+sizeof(chunkSizes)/sizeof(int)));
            break;
        }
        case 2:
        {
            int chunkSizes[] = {2048, 1024, 1024, 2048};
            _expected = 3072;
            _received = _obj.minTime(vector <int>(chunkSizes, chunkSizes+sizeof(chunkSizes)/sizeof(int)));
            break;
        }
        case 3:
        {
            int chunkSizes[] = {4194304, 4194304, 4194304, 4194304, 4194304,
                                4194304, 4194304, 4194304, 4194304, 4194304,
                                4194304, 4194304, 4194304, 4194304, 4194304,
                                4194304, 4194304, 4194304, 4194304, 4194304,
                                4194304, 4194304, 4194304, 4194304, 4194304,
                                4194304, 4194304, 4194304, 4194304, 4194304,
                                4194304, 4194304, 4194304, 4194304, 4194304,
                                4194304, 4194304, 4194304, 4194304, 4194304,
                                4194304, 4194304, 4194304, 4194304, 4194304,
                                4194304, 4194304, 4194304, 4194304, 4194304
                               };
            _expected = 104857600;
            _received = _obj.minTime(vector <int>(chunkSizes, chunkSizes+sizeof(chunkSizes)/sizeof(int)));
            break;
        }
        /*case 4:
        {
        	int chunkSizes[] = ;
        	_expected = ;
        	_received = _obj.minTime(vector <int>(chunkSizes, chunkSizes+sizeof(chunkSizes)/sizeof(int))); break;
        }*/
        /*case 5:
        {
        	int chunkSizes[] = ;
        	_expected = ;
        	_received = _obj.minTime(vector <int>(chunkSizes, chunkSizes+sizeof(chunkSizes)/sizeof(int))); break;
        }*/
        /*case 6:
        {
        	int chunkSizes[] = ;
        	_expected = ;
        	_received = _obj.minTime(vector <int>(chunkSizes, chunkSizes+sizeof(chunkSizes)/sizeof(int))); break;
        }*/
        default:
            return 0;
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
