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
#define  MAX 900000000
set<long long>S;

void dfs(long long num){
   if(num>=MAX)return;
   if(S.count(num))return;
   S.insert(num);
   dfs(num*2);
   dfs(num*3);
   dfs(num*5);
}
int main(){
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   
   long long nc=0;
   S.clear();
   dfs(1);    
   foreach(S,it){
      if(nc==1499){
         nc=(*it);
         break;
      }
      nc++;
   }
   cout<<"The 1500'th ugly number is "<<nc<<"."<<endl;
   system("pause");
   return 0;
}
