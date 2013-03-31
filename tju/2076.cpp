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
#define fill(x,i) memset(x,i,sizeof(x))
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;
int cell[105];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,m,ans;
    scanf("%d\n",&n);
    REP(i,0,n){
       scanf("%d\n",&m);
       fill(cell,0);
       ans=0;
       REP(j,1,m+1){
          for(int k=j;k<m+1;k+=j)
            cell[k]=cell[k]^1;
       }
       REP(j,1,m+1)ans+=cell[j];
       printf("%d\n",ans);
        
    }
    //system("pause");
    return 0;
}
