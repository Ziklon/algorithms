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
#define INF 1<<20
typedef long long ll; 
bool G[50][50]={0};
int D[50][50],N,M;
int T[10];
ll dist(ll x1, ll y1, ll x2, ll y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
int target(int idx, vector<int>& X, vector<int>& Y){
     ll myCapDist=dist(X[0],Y[0],X[idx],Y[idx]);
     vector<int> candidates;
     REP(i,N){
        ll capDist=dist(X[i],Y[i],X[0],Y[0]);
        if(capDist<myCapDist)candidates.push_back(i);
     }
     int best=-1;
     ll bestDist=1LL<<60;
     REP(i,candidates.size()){
         int p=candidates[i];
         ll d=dist(X[p],Y[p],X[idx],Y[idx]);
         if(d<bestDist){
            best=p;
            bestDist=d;
         }else if(d==bestDist){
            if(X[p]<X[best] || (X[p]==X[best] && Y[p]<Y[best]))best=p;
         }   
     }
     return best;       
}
int inconv(int p){
    int res=D[p][0];
    REP(i,M)res=min(res,D[p][T[i]]);
    return res;
}
int kingdomInconv(){
    int res=0;
    REP(i,N)res=max(res,inconv(i));
    return res;
}
int ans=1<<20;
void backTrack(int idx, int limit){
    if(idx==M){
        ans=min(ans,kingdomInconv());
    }else{
        for(int i=limit;i<N;i++){
            T[idx]=i;
            backTrack(idx+1,i+1);
        }
    }
}


struct TeleportsNetwork {
   int distribute( int teleportCount, vector <int> citiesX, vector <int> citiesY ) {
		N=citiesX.size();
		M=teleportCount;
		REP(i,N)if(i>=1){
            int j=target(i,citiesX,citiesY);
            G[i][j]=G[j][i]=1;
		}
		
		REP(i,50)REP(j,50)D[i][j]=INF;
		REP(i,N)REP(j,N){
            if(G[i][j])D[i][j]=1;
            if(i==j)D[i][j]=0;            
		}
		REP(k,N)REP(i,N)REP(j,N)D[i][j]=min(D[i][j],D[i][k]+D[k][j]);
		backTrack(0,0);
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
		cout << "Testing TeleportsNetwork (1000.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1368142149;
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
		TeleportsNetwork _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int teleportCount = 2;
				int citiesX[] = {0,1,1,1,2,2};
				int citiesY[] = {1,0,1,2,0,2};
				_expected = 1;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}
			case 1:
			{
				int teleportCount = 1;
				int citiesX[] = {0,1,1,1,2,2};
				int citiesY[] = {1,0,1,2,0,2};
				_expected = 2;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}
			case 2:
			{
				int teleportCount = 0;
				int citiesX[] = {0,1,1,1,2,3,3,4};
				int citiesY[] = {1,1,2,0,0,0,2,1};
				_expected = 5;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}
			case 3:
			{
				int teleportCount = 1;
				int citiesX[] = {0,1,2,3,4};
				int citiesY[] = {0,0,0,0,0};
				_expected = 1;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}
			case 4:
			{
				int teleportCount = 4;
				int citiesX[] = {64,200,384,294,175,107,303,374,224,220,223,99,442};
				int citiesY[] = {79,161,83,281,344,217,184,336,431,262,75,474,257};
				_expected = 1;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}
			/*case 5:
			{
				int teleportCount = ;
				int citiesX[] = ;
				int citiesY[] = ;
				_expected = ;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int teleportCount = ;
				int citiesX[] = ;
				int citiesY[] = ;
				_expected = ;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
			}*/
			/*case 7:
			{
				int teleportCount = ;
				int citiesX[] = ;
				int citiesY[] = ;
				_expected = ;
				_received = _obj.distribute(teleportCount, vector <int>(citiesX, citiesX+sizeof(citiesX)/sizeof(int)), vector <int>(citiesY, citiesY+sizeof(citiesY)/sizeof(int))); break;
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
