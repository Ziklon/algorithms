/*
ID: winftc2
PROG: in.txt
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
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
bool G[110][110];
vector<int>price(110);

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,x,y;
    int ans=1<<30;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
      scanf("%d",&price[i+1]);
    
    for(int i=0;i<m;i++){
      scanf("%d %d",&x,&y);
      G[x][y]=1;
      G[y][x]=1;
    }
    for(int i=1;i<=n;i++)
      for(int j=i+1;j<=n;j++)
        for(int k=j+1;k<=n;k++){
          int a=G[i][j]+G[j][k]+G[k][i]+0;
          if(a==3){
            ans=min(ans,(price[i]+price[j]+price[k]));
          }
        }
    if(ans==1<<30)cout<<-1<<endl;
    else cout<<ans<<endl;
           
    //system("pause");
    return 0;
}
