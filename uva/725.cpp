/*
ID: winftc2
PROG: in.txt
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
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
set<int>S;
void digits(int n){
  if(n<10000)S.insert(0);
  while(n){
    S.insert(n%10);
    n/=10;
  }
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int N,c,m=0;
    while(scanf("%d",&N)==1 && N){
       c=0;
       if(m)printf("\n");
       for(int num=1234;num*N<=98765;num++){
          int val=num*N;
          S.clear();
          digits(num);
          if(S.sz<5)continue;
          digits(val);
          if(S.sz==10){
              printf("%05d / %05d = %d\n",val,num,N);
              c++;
          }
       } 
       if(c==0)printf("There are no solutions for %d.\n",N);
       m++;
    }
    
    //system("pause");
    return 0;
}
