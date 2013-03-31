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
int N,F;
int A[44];
int dp[44][45009][2];


int go(int p, int s, int n){
    int S=s;
    if(n)S*=-1;
    if(S==0 && p==N)return 1;
    if(p>=N)return 0;
    int& ref=dp[p][s][n];
    if(ref!=-1)return ref;
    ref=0;
    ref+=go(p+1,abs(S+A[p]),(S+A[p])<0);
    ref+=go(p+1,abs(S-A[p]),(S-A[p])<0);
    return ref;      
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while(scanf("%d %d",&N,&F)==2 && (N!=0 && F!=0)){
        fill(dp,-1);
        
        REP(i,0,N)
            scanf("%d",&A[i]);

        if(go(0,F,0)){
            REP(i,0,N){
                int a=0;
                int b=0;
                a=go(0,abs(F-A[i]),(F-A[i])<0);
                b=go(0,abs(F+A[i]),(F+A[i])<0);
                if(a && b)
                    printf("?");
                else if(a)
                    printf("-");
                else 
                    printf("+");
            }
            printf("\n");
        }else{
            printf("*\n");
        } 
    }
    //system("pause");
    return 0;
}
