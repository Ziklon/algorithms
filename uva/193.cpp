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
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
bool G[105][105],vis[105];
int n,k,a,b,m;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d\n",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d\n",&n,&k);
        for(int i=0;i<k;i++){
          scanf("%d %d\n",&a,&b);
          G[a][b]=1;
          G[b][a]=1;          
        }
    }
    //system("pause");
    return 0;
}
