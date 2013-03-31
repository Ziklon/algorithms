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
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
bool vis[125005];
int main(){
   freopen("ariprog.in","r",stdin);
   freopen("ariprog.out","w",stdout);
   int N,M;
   cin>>N>>M;
   vector<int> v;
   fill(vis,0);
   REP(i,0,M+1)
	REP(j,i,M+1)
		vis[(i*i)+(j*j)]=1;
   
   REP(i,0,125005)if(vis[i])v.push_back(i);

   int cnt=0;
   vector<pair<int,int> >peki;
	REP(i,0,v.sz){
		
		REP(b,1,10000){
			bool ok=1;
			REP(n,0,N+1){
				int num=v[i]+(n*b);
				if(num>=125005){
					ok=0;
					break;
				}
				if(!vis[v[i]+(n*b)]){
					ok=0;
					break;	
				}
			}
			if(ok)peki.push_back(make_pair(b,v[i]));
		}
	}
	sort(all(peki));
	REP(i,0,peki.sz)
		printf("%d %d\n",peki[i].second,peki[i].first);
		
   //system("pause");
   return 0;
}
