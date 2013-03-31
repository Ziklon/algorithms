/*
ID: winftc
PROG: friday
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
int day=2,cur;
int Ms[]={31,28,31,30,31,30,31,31,30,31,30,31};
bool islep(int y){
   if(y%400==0 || y%4==0 && y%100!=0)
      return 1;
   return 0;
}
int main(){
   freopen("friday.in","r",stdin);
   freopen("friday.out","w",stdout);
   int N;
   
   cin>>N;
   vector<int> vi(7,0);
   day=1;
   for(int i=0;i<N;i++){
      if(islep(i+1900))Ms[1]=29;
      else Ms[1]=28;
      for(int j=0;j<12;j++){
         cur=(day+13)%7;
         vi[cur]++;
         day=(day+Ms[j])%7;         
      }
   }
   for(int i=0;i<7;i++){
      cout<<vi[i];
      if(i+1<7)cout<<" ";
   }
   cout<<endl;
   //system("pause");
   return 0;
}
