#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#include <queue>
#include <map>
#define REP(i,a) for(int i=0;i<int(a);i++)
using namespace std;
typedef long long ll;
#define MAXN 100005
int N,Q,T,x,y;
int M[MAXN][17];    
int A[MAXN];

void process(){
    for(int i=0;i<N;i++)M[i][0]=i;
                    
    for(int j=1;(1<<j)<=N;j++){            
        for(int i=0;(i+(1<<j)-1)<N;i++){                
            if (A[M[i][j - 1]] < A[M[i + (1 << (j - 1))][j - 1]])
					M[i][j] = M[i][j - 1];
				else
					M[i][j] = M[i + (1 << (j - 1))][j - 1];
        }       
    } 
}
int RMQ(int i, int j){
    int k=log2(j-i+1);    
    if (A[M[i][k]] <= A[M[j - (1 << k) + 1][k]])
        return M[i][k];
    return M[j - (1 << k) + 1][k];    
}

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
        scanf("%d %d",&N,&Q);
        REP(i,N)scanf("%d",A+i);
        process();
        printf("Case %d:\n",t+1);
        REP(i,Q){
            scanf("%d %d",&x,&y);
            printf("%d\n",A[RMQ(x-1,y-1)]);
        }        
   }
   return 0;      
}
