#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}


int N,nC,a,b,ubi,dev;
bool adj[32][32],visit[32];
map<int,int> M;
 
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  nC=1;
  while(scanf("%d",&N)){
  	if(N==0)break;
  	ubi=1;
  	memset(adj,0,sizeof adj);
  	M.clear();
  	for(int i=0;i<N;i++){
		scanf("%d %d",&a,&b);
		if(M[a]==0)
			M[a]=ubi++;
		if(M[b]==0)
			M[b]=ubi++;
		adj[M[a]][M[b]]=1;
		adj[M[b]][M[a]]=1;
	}
	while(scanf("%d %d",&a,&b)==2){
		if(a==0 && b==0)break;
	   memset(visit,0,sizeof visit);
	   vector<int>tme(ubi+1,0);
	   queue<int>Q;
	   Q.push(M[a]);
	   visit[M[a]]=1;
	   tme[M[a]]=b+1;
	   while(!Q.empty()){
	   	 	int cur=Q.front();
	   	 	Q.pop();
	   	 	for(int i=1;i<ubi;i++){
				if(adj[cur][i] && !visit[i]){
					Q.push(i);
					tme[i]=tme[cur]-1;
					visit[i]=1;
				}
			}
	   }
	   dev=0;
	   
	   for(int i=1;i+1<tme.sz;i++)
	   		if(tme[i]<=0)
	   			dev++;
	   printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",nC++,dev,a,b);
	}
  }
  return 0;
}
