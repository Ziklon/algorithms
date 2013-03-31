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

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,p,q,x,y,r=1;
    scanf("%d\n",&n);
    REP(i,0,n){
        scanf("%d %d\n",&p,&q);
        bool ok=1;
        REP(j,0,q){
          scanf("%d %d\n",&x,&y);
          if(x==y)ok=0;
        }
        printf("Scenario #%d:\n",r++);
        if(!ok || q>=p)
          printf("Suspicious bugs found!\n");
        else
          printf("No suspicious bugs found!\n");
        printf("\n");
        
    }
    //system("pause");
    return 0;
}
