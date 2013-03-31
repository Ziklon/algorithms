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
int A[1001],B[1001];
int dp[105][105];
int path[105][105];
int dx[]={-1,0,-1};
int dy[]={-1,-1,0};
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int m,n,c=1;
    //10066
    while(cin>>m>>n && m&& n){
       fill(dp,0);
       fill(dp,0);
       for(int i=0;i<m;i++)cin>>A[i];  
       for(int i=0;i<n;i++)cin>>B[i];
       for(int i=1;i<=m;i++)
         for(int j=1;j<=n;j++)
            if(A[i-1]==B[j-1]){   
               dp[i][j]=dp[i-1][j-1]+1;
               path[i][j]=1;
            }
            else if(dp[i][j-1]>=dp[i-1][j]){
               dp[i][j]=dp[i][j-1];
               path[i][j]=2;
            }else{
                  dp[i][j]=dp[i-1][j];
                  path[i][j]=3;
               }
      int x=m;
      int y=n;
      while(path[x][y]!=0){
         if(path[x][y]==1)cout<<A[x-1]<<endl;
         x=x+dx[path[x][y]-1];
         y=y+dy[path[x][y]-1];
      }
      printf("Twin Towers #%d\n",c);
      printf("Number of Tiles : %d\n",dp[m][n]);
      printf("\n");
      c++;
    }    
    return 0;
}
