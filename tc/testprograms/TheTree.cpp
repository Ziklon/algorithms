#include <iostream>  
#include <sstream>
#include <vector>
#include <cstdio>  
#include <set>  
#include <map>  
#include <algorithm> 
#include <cmath> 
#include <cstring> 
#include <queue>
using namespace std;  
#define REP(i,n) for(int i=0;(i)<(int)(n);(i)++)  
typedef long long ll;
#define MAXN 50005

vector<int> G[MAXN];
int degree[MAXN],N;

pair<int,int> bfs(int u){
    int dist [MAXN];
    memset(dist,-1,sizeof dist);
    dist[u] = 0;
    queue<int> Q;
    Q.push(u);
    while(!Q.empty()){
        int top = Q.front();
        Q.pop();        
        for(int adj : G[top]){            
            if(dist[adj]==-1){
                dist[adj] =dist[top]+1;
                Q.push(adj);                
            }            
        }     
    }
    int node = 0;
    int maxi = -1;    
    REP(i,MAXN)if(dist[i]>maxi){
        maxi = dist[i];
        node = i;
    } 
    return make_pair(node,maxi);
}



struct TheTree {
	int maximumDiameter(vector <int> cnt) {
	    memset(degree,0,sizeof degree);
	    degree[0]=1,N=cnt.size();
	    int adds = 0;
		REP(i,N){
            int maxi = 0;
            REP(j,MAXN)maxi=max(maxi,degree[j]);            
            vector<int> vertices;
            REP(j,MAXN)if(degree[j]==maxi)vertices.push_back(j);          
            int idx = 0;            
            for(int j=1;j<=cnt[i];j++){
               int newVert = ++adds;            
               G[newVert].push_back(vertices[idx]);
               G[vertices[idx]].push_back(newVert);              
               degree[newVert] = degree[vertices[idx]]+1;      
               idx = (idx+1)%vertices.size();             
            }           
		}
		
		pair<int,int> first = bfs(0);		
		pair<int,int> second = bfs(first.first);
		return second.second;	
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
		cout << "Testing TheTree (275.0 points)" << endl << endl;
		for (int i = 0; i < 20; i++)
		{
			ostringstream s; s << argv[0] << " " << i;
			int exitCode = system(s.str().c_str());
			if (exitCode)
				cout << "#" << i << ": Runtime Error" << endl;
		}
		int T = time(NULL)-1391473744;
		double PT = T/60.0, TT = 75.0;
		cout.setf(ios::fixed,ios::floatfield);
		cout.precision(2);
		cout << endl;
		cout << "Time  : " << T/60 << " minutes " << T%60 << " secs" << endl;
		cout << "Score : " << 275.0*(.3+(.7*TT*TT)/(10.0*PT*PT+TT*TT)) << " points" << endl;
	}
	else
	{
		int _tc; istringstream(argv[1]) >> _tc;
		TheTree _obj;
		int _expected, _received;
		time_t _start = clock();
		switch (_tc)
		{
			case 0:
			{
				int cnt[] = {3};
				_expected = 2;
				_received = _obj.maximumDiameter(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 1:
			{
				int cnt[] = {2, 2};
				_expected = 4;
				_received = _obj.maximumDiameter(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 2:
			{
				int cnt[] = {4, 1, 2, 4};
				_expected = 5;
				_received = _obj.maximumDiameter(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 3:
			{
				int cnt[] = {4, 2, 1, 3, 2, 5, 7, 2, 4, 5, 2, 3, 1, 13, 6};
				_expected = 21;
				_received = _obj.maximumDiameter(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			case 4:
			{
				int cnt[] = {1};
				_expected = 1;
				_received = _obj.maximumDiameter(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}
			/*case 5:
			{
				int cnt[] = ;
				_expected = ;
				_received = _obj.maximumDiameter(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
			}*/
			/*case 6:
			{
				int cnt[] = ;
				_expected = ;
				_received = _obj.maximumDiameter(vector <int>(cnt, cnt+sizeof(cnt)/sizeof(int))); break;
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

//END CUT HERE
