/*
ID: winftc
PROG: ariprog
LANG: C++
*/
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
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define GI ({int _t; scanf("%d", &_t); _t;})
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
bool vis[125005];
int main(){
   freopen("ariprog.in","r",stdin);
   freopen("ariprog.out","w",stdout);
   int N,M;
   scanf("%d",&N);
   scanf("%d",&M);
   vector<int> v;
   fill(vis,0);
   REP(i,0,M+1)
	REP(j,i,M+1)
		vis[(i*i)+(j*j)]=1;
   
   int limit=(M*M) +(M*M);
   REP(i,0,limit+1)if(vis[i])v.push_back(i);

   
   
   int i,b,n;
   int num;
   int hh=v.sz-N;
    vector<pair<int,int> >peki;
	

	
	for(i=0;i<=hh;i++){
		bool sigue=1;
		for(b=1;(v[i]+(b*(N-1)))<=limit;b++){
			bool ok=1;			
			for(n=1;n<N;n++){
				num=v[i]+(n*b);
				if(num>limit){
					ok=0;
					sigue=0;
					break;
				}
				if(!vis[num]){
					ok=0;
					break;	
				}
			}
			if(ok)peki.push_back(make_pair(b,v[i]));
		}
	}
	sort(all(peki));
	if(peki.sz==0)
		printf("NONE\n");
	else{
	REP(i,0,peki.sz)
		printf("%d %d\n",peki[i].second,peki[i].first);
	}
		
   //system("pause");
   return 0;
}
