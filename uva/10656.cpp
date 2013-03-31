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
#define MAX 1010
int num,N,A[MAX];
int main(){
   //10656
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   while(scanf("%d",&N) && N){
      stringstream ss("");
      for(int i=0;i<N;i++){
         scanf("%d",&num);
         if(num>0)ss<<" "<<num;
      }
      if(ss.str().sz==0)printf("0\n");
      else printf("%s\n",ss.str().substr(1).c_str());     
   }
   return 0;
}
