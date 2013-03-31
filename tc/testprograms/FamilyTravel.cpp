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
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
int adj[51][51];
int dp[51][90];
int N;
int getLength(char c){
	if(c=='0')return -1;
	if(c>='a' && c<='z')return c-'a'+1;
	return c-'A'+27;	
}
int go(int node, int cur){
	if(node==1)return 0;
	int& ref=dp[node][cur];
	if(ref!=-1)return ref;
	ref=1<<29;
	for(int v=0;v<N;v++){
		if(adj[node][v]!=-1 && adj[node][v]<cur)
			ref=min(ref,adj[node][v]+go(v,adj[node][v]));
	}
	return ref;
}

int main(){
   int nv,ta;
   scanf("%d\n",&nv);
   string line;
   for(int i=1;i<=nv;i++){
      scanf("%d\n",&ta);
      for(int j=0;j<ta;j++){
         cin>>line;
         for(int k=0;k<ta;k++)
            adj[j][k]=getLength(line[k]);
      }
      int ans=dp(0,88);
      if(ans>=1<<29)
         printf("Caso #%d: -1\n",i);
      else
         printf("Caso #%d: %d\n",i,ans);
      
   }
   
}
