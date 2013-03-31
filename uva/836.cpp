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
#define MAX 30
int A[MAX][MAX],dp[MAX][MAX],T,ans;
string line;

int getArea(int x, int y, int p, int q){
   return abs(p-x+1)*abs(q-y+1);
}
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   scanf("%d\n",&T);
   getline(cin,line);
   while(T--){
      int X=0;
      int Y=0;
      ans=-100;
      while(getline(cin,line)){
         if(line=="")break;
         for(int j=0;j<line.sz;j++)
            A[X][j]=line[j]-'0';
         X++;
         Y=line.sz;
      }
      for(int i=0;i<X;i++){
         dp[i][0]=A[i][0];
         for(int j=1;j<Y;j++)
            dp[i][j]=dp[i][j-1]+A[i][j];
      }
            
      for(int i=0;i<X;i++){
         for(int j=i;j<Y;j++){
            int sum=-100;
            for(int k=i;k<X;k++){
               int temp=dp[k][j]-dp[k][i]+A[k][i];
               if(getArea(i,i,k,k)==temp){
                  sum=max(sum+temp,temp);
                  ans=max(sum,ans);
               }
            }
         }
      }
      printf("%d\n",ans);
   }
   return 0;
}
