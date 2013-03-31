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
char cad[210][210];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int N,M;
    scanf("%d %d\n",&N,&M);
    REP(i,0,N)
      REP(j,0,M){
         cin>>cad[i][j];
      }
   map<int,int>MM;
   REP(i,0,M){
      int x=0;
      REP(j,0,N){
         if(cad[j][i]=='1'){
            MM[x]++;
            x=0;
         }else
            x++;
      }
      MM[x]++;
   }
   foreach(MM,it){
      if(it->first>0){
         printf("%d %d\n",it->first,it->second);
      }
   }
    //system("pause");
    return 0;
}
