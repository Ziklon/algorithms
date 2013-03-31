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
int dp[1000005];

int go(int n){
  if(n<0)return 1<<20;
  if(n==0)return 0;
  
  int& ref=dp[n];
  if(ref==-1)
    ref=1+min(go(n-4),go(n-7));
  return ref;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int num,ans,t;
    fill(dp,-1);
    cin>>num;
    ans=go(num);
    string dev="";
    if(ans<(1<<20)){      
      t=ans;
      for(int i=0;i<ans;i++){
        if(go(num-4)==t-1){
          dev+="4";
          num-=4;
        }else{
          dev+="7";  
          num-=7;
        }
        t--;    
      }
    }else{
        dev="-1";
    }
    cout<<dev<<endl; 
    //system("pause");   
    return 0;
}
