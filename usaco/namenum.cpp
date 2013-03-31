/*
ID: winftc
PROG: namenum
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
string A[11];
set<string> S;
string num;
bool check(string puede){
   int nu=0;
   for(int i=0;i<puede.sz;i++){
       nu=num[i]-'0';
       if(A[nu].find(puede[i])==-1)
         return false;    
   }
   return true;
}
int main(){
   freopen("namenum.in","r",stdin);
   freopen("namenum.out","w",stdout);
   FILE *fin  = fopen ("dict.txt", "r");
   char text[50];   
   cin>>num;
   for(int i=0;i<11;i++)A[i]="-";
   A[2]="ABC";
   A[3]="DEF";
   A[4]="GHI";
   A[5]="JKL";
   A[6]="MNO";
   A[7]="PRS";
   A[8]="TUV";
   A[9]="WXY";
   vector<string> vs;
   while(fscanf(fin,"%s",text)==1)
      vs.push_back(string(text));
   int ans=0;
   for(int i=0;i<vs.sz;i++){
      if(vs[i].sz!=num.sz)continue;
      if(check(vs[i])){
         cout<<vs[i]<<endl;
         ans++;   
      }
   }
   if(ans==0)cout<<"NONE"<<endl;
   //system("pause");
   return 0;
}
