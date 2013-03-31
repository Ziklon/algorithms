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
int A[2002];
int P[2002];

int find(int u){
    if(P[u]==u)return u;
    return P[u]=find(P[u]);
}
void join(int a, int b){
    P[find(a)]=find(b);
}

bool dfs(int x, int y, int n){
    if(n>=2 || x<0)return 0;
    if(A[x]==y)return 1;
    return dfs(A[x],y,n+1);
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int N;
    scanf("%d",&N);
    REP(i,0,N)P[i]=i;
    REP(i,0,N){
        scanf("%d",&A[i]);
        if(A[i]!=-1)
            A[i]--;
    }
    set<int> S;
    
    REP(i,0,N)
        REP(j,i+1,N){
            if(!dfs(i,j,0) && !dfs(j,i,0)){
               join(i,j); 
               
            }
        }
    REP(i,0,N)S.insert(find(i));
    cout<<S.sz<<endl;    
    //system("pause");
    return 0;
}
