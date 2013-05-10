#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
#define MAXN 100005
int N,M,V;
pair<int,int> A[MAXN];
int idx=0,tim=0;

int func(){
    while(idx<=N){
        if(tim+(A[idx].first*A[idx].second)<V){
                tim+=A[idx].first*A[idx].second;
                idx++;
        }
        else{
            return idx+1;            
        }      
    }

}


int main(){
   scanf("%d %d",&N,&M);
   REP(i,N)scanf("%d %d",&A[i].first,&A[i].second);
   
   REP(i,M){
        scanf("%d",&V);
        printf("%d\n",func());
   }
   
   
   return 0;      
}
