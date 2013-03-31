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

string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}


int A[100010];
int I[100010];
int x,y,dp[100001],B[100001],pt,T;
int INF=1<<30;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n=0,ans=0;
    //10131
		while(scanf("%d",&T)!=EOF){			
			A[n]=T;
			n++;
		}
		for(int i=0;i<=n;i++){
			dp[i]=1;
			B[i]=-1;
			I[i]=INF;
		}
		I[0]=-INF;
		int LisLength=0;
		for(int i=0;i<n;i++){
			int low=0;
			int hih=LisLength;
			while(low<=hih){
				int mid=(low+hih)/2;
				if(I[mid]<A[i])
					low=mid+1;
				else
					hih=mid-1;
			}
			I[low]=A[i];
			dp[i]=low;
			if(LisLength<low){
				LisLength=low;				
			}
		}
		vector<int> v;
		ans=LisLength;
		for(int i=n-1;i>=0;i--){
			if(dp[i]==LisLength){
				v.push_back(A[i]);
				LisLength--;
			}
		}
		//reverse(all(v));
	   printf("%d\n-\n",ans);
	   for(int i=v.sz-1;i>=0;i--)printf("%d\n",v[i]);
  
   // cout<<pt<<endl;
  
   
   
   return 0;
}
