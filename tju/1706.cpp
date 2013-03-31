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
vector<bool> A[2005];
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,m,c=1,x,y,ans;
    scanf("%d\n",&n);
    REP(i,1,n+1){
      scanf("%d %d\n",&m,&c);
      fill(A,0);
      REP(j,0,c){
        scanf("%d %d",&x,&y);
        A[x].push_back(y);
      }
      
      
    }
    //system("pause");
    return 0;
}
