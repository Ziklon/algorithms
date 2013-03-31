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

int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int t;
   long long n,m,ans;
   cin>>t;
   for(int i=0;i<t;i++){
      map<long long,int>M;
      cin>>n>>m;
      ans=0;      
      for(int i=1;i*i<=n;i++)
         if(n%i==0){
            M[i]++;
            if(n/i!=i)M[n/i]++; 
         }
      for(int i=1;i*i<=m;i++)
         if(m%i==0){
            M[i]++;
            if(m/i!=i)M[m/i]++; 
         }
     foreach(M,it)
      if((*it).second==2)ans++;
     cout<<ans<<endl;         
   }
   //system("pause");
   return 0;
}
