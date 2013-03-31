/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int x;
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int N;
    while(scanf("%d",&N)==1 && N){
      vector<int>a(N+1),b(N+1);
      REP(i,1,N+1){
         scanf("%d",&x);
         a[i]=x;
         b[x]=i;;
      }
      if(a==b)
         cout<<"ambiguous"<<endl;
      else
         cout<<"not ambiguous"<<endl;
           
    }  
    //system("pause");
    return 0;
}
