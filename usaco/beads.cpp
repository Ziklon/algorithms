/*
ID: winftc
PROG: beads
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
int cback(string& s, int p, char c){
   int nc=0;
   int N=s.sz;
   if(s[p]==c || s[p]=='w')nc++;
   else return 0;
   for(int i=(N+p-1)%N;i!=p;i=(N+i-1)%N)
      if(s[i]==c || s[i]=='w')nc++;
      else break;
   return nc;
}


int cford(string& s, int p, char c){
   int nc=0;
   int N=s.sz;
   p=p%N;
   if(s[p]==c || s[p]=='w')nc++;
   else return 0;
   
   for(int i=(p+1)%N;i!=p;i=(i+1)%N)
      if(s[i]==c || s[i]=='w')nc++;
      else break;
   return nc;
}


int main(){
   freopen("beads.in","r",stdin);
   freopen("beads.out","w",stdout);
   int n;
   string text;
   cin>>n>>text;
   int ans=0;
   for(int i=0;i<text.sz;i++){
      ans=max(ans,max(cback(text,i,'b')+cford(text,i+1,'r'), cback(text,i,'r')+cford(text,i+1,'b') ));
   }
   if(ans>n)ans=n;
   printf("%d\n",ans);
   //system("pause");
   return 0;
}
