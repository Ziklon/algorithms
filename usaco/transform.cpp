/*
ID: winftc
PROG: transform
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
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
vector<string> rotate(vector<string> vs){
   vector<string> ans(all(vs));
   int n=vs.sz;
   for(int i=0;i<vs.sz;i++){
      for(int j=0;j<vs.sz;j++)
         ans[i][j]=vs[n-j-1][i];

   }
   return ans;      
}
vector<string> flip(vector<string> vs){
   vector<string> ans(all(vs));
   int n=vs.sz-1;
   for(int i=0;i<vs.sz;i++){
      reverse(all(ans[i]));
      //for(int j=0;j<vs.sz;j++)
        // ans[i][j]=vs[i][n-j];

   }
   return ans;      
}
void printv(vector<string> v){
   for(int i=0;i<v.sz;i++)cout<<v[i]<<endl;
   cout<<endl;   
}
int main(){
   freopen("transform.in","r",stdin);
   freopen("transform.out","w",stdout);
   int N,ans=7;
   vector<string> va,vb;
   cin>>N;
   va.resize(N);
   vb.resize(N);
   
   for(int i=0;i<N;i++)cin>>va[i];
   for(int i=0;i<N;i++)cin>>vb[i];
   if(va==vb)ans=6;
   
   //printv(va);
   //printv(rotate(va));
   //printv(rotate(va));
   if(rotate(flip(va))==vb || rotate(rotate(flip(va)))==vb
    || rotate(rotate(rotate(flip(va))))==vb) ans=5;  
   if(flip(va)==vb)ans=4; 
   if(rotate(rotate(rotate(va)))==vb)ans=3;
   if(rotate(rotate(va))==vb)ans=2;
   if(rotate(va)==vb)ans=1;
  
   
   
   
   
   cout<<ans<<endl;
   //system("pause");
   return 0;
}
