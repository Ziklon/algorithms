/*
ID: winftc
PROG: palsquare
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
map<int,char>M;
bool ispal(int n, int b){
   string ans="",othe;
   while(n){
      ans=string(1,'0'+n%b)+ans;
      n/=b;
   }
   othe=ans;
   reverse(all(othe));
   return othe==ans;   
}
int main(){
   freopen("palsquare.in","r",stdin);
   freopen("palsquare.out","w",stdout);
   int B,cur;
   
   cin>>B;
   for(int i=10;i<=20;i++)M[i]='A'+i-10;   
   for(int i=0;i<10;i++)M[i]='0'+i;
   for(cur=1;cur<=300;cur++){
      if(ispal(cur,B) && ispal(cur*cur,B))
         cout<<cur<<" "<<cur*cur<<endl;
   }
    
   //system("pause");
   return 0;
}
