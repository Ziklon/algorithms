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


string maxi(string a, string b){
   if(count(all(a),' ')>=count(all(b),' '))
      return a;
   return b;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(1){
       vector<string>a,b;
       string dp[105][105];       
       string aux;
       bool ok=0;
       while(cin>>aux && aux!="#")a.push_back(aux),ok=1;
       while(cin>>aux && aux!="#")b.push_back(aux);
       if(!ok)break;
       for(int i=0;i<105;i++)
         for(int j=0;j<105;j++)
            dp[i][j]="";
       for(int i=1;i<=a.sz;i++){
         for(int j=1;j<=b.sz;j++){
            if(a[i-1]==b[j-1])
               dp[i][j]=dp[i-1][j-1]+" "+a[i-1];
            else
               dp[i][j]=maxi(dp[i-1][j],dp[i][j-1]);
         }
       }
       if(dp[a.sz][b.sz].sz>0)
         cout<<dp[a.sz][b.sz].substr(1)<<endl;
      else
         cout<<""<<endl;        
   }
    return 0;
}
