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
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define rep(i,n) for((i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long _lcm(long long a,long long b){return a*(b/gcd(a,b));}
int N,T,O,q;
int main(){
   char c;
   int v;
   freopen("out.txt","w",stdout);
   cin>>N;
   while(N){
      q=1;
      cin>>O;
      vector<pair<char,int> > M;
      for(int i=0;i<O;i++){
         cin>>c>>v;
         M.push_back(make_pair(c,v));
      }
      cin>>T;
      for(int i=M.sz-1;i>=0;i--){
         if(M[i].first=='+')
            T-=M[i].second;
         else if(M[i].first=='-')
            T+=M[i].second;
         else if(M[i].first=='*')
            T/=M[i].second;
         else if(M[i].first=='/')
            T*=M[i].second;
      }   
      printf("Caso #%d: %d\n",q++,T);
      N--;
   }   
   return 0;
}
