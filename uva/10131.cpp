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

struct node{
	int W,S,I;
	node(){}
	node(int _W, int _S, int _I){
		W=_W;
		S=_S;
		I=_I;
	}

};

bool cmp(node p, node q){
	if(p.W!=q.W)return p.W<q.W;
	return p.S>q.S;
}
node A[1010];
int x,y,dp[1001],B[1001],pt;
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n=0,ans=0;
    //10131
    while(scanf("%d %d",&x,&y)==2){
      A[n]=node(x,y,n+1);
      n++;
    }
	sort(A,A+n,cmp);
    fill(B,-1);
	fill(dp,1);
	for(int i=0;i<n;i++)dp[i]=1;
	
    for(int i=0;i<n;i++){      
      for(int j=i+1;j<n;j++){
         if(A[j].W>A[i].W && A[j].S<A[i].S)
            if(dp[j]<(dp[i]+1)){
               dp[j]=dp[i]+1;
               B[j]=i;
			   //cout<<B[j]<<endl;
            }
		}
    }
	// for(int i=0;i<n;i++){
		// cout<<i<<" "<<dp[i]<<" "<<B[i]<<" , "<<A[i].I<<endl;
	// }
    for(int i=0;i<n;i++)if(ans<=dp[i]){
            ans=dp[i];
            pt=i;
    }
   // cout<<pt<<endl;
   vector<int> str;
   while(pt!=-1){
      str.push_back(A[pt].I);
	  //if(pt==B[pt])break;
      pt=B[pt];
   }
   // cout<<pt<<endl;
   reverse(all(str));   
   cout<<ans<<endl;
   for(int i=0;i<str.sz;i++)cout<<str[i]<<endl;
   return 0;
}
