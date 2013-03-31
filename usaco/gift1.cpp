/*
ID: winftc
PROG: gift1
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

int main(){
   freopen("gift1.in","r",stdin);
   freopen("gift1.out","w",stdout);
   int np,cnt,n,sob,div;
   cin>>np;
   vector<string>vs(np);
   map<string,int>M;
   string name,aux;
   for(int i=0;i<np;i++)cin>>vs[i];
   for(int i=0;i<np;i++)M[vs[i]]=0;
   
   while(cin>>name){
      cin>>cnt>>n;
      
      if(n==0)continue;
      //cout<<name<<endl;
      //cout<<cnt<<" "<<n<<endl;
      M[name]=M[name]-cnt+ cnt%n;
      div=cnt/n;      
      for(int i=0;i<n;i++){
         cin>>aux;
         //cout<<aux<<endl;
         M[aux]+=div; 
      }
   }
   for(int i=0;i<vs.sz;i++)
      printf("%s %d\n",vs[i].c_str(),M[vs[i]]);
   //system("pause");
   return 0;
}
