#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;

pair<int,int> P[110];
bool seen[110];
int N,add=0,T,x,y;
int main(){
    scanf("%d",&N);
    REP(i,N){
        scanf("%d %d %d",&T,&x,&y);
        if(T==1){
            P[++add]=make_pair(x,y);
        }else{
            memset(seen,0,sizeof seen);
            queue<int> Q;
            seen[x]=1;
            Q.push(x);
            bool found=0;
            while(!Q.empty()){
                x=Q.front();Q.pop();
                if(x==y){
                    found=1;
                    break;
                }
                REP(j,add){                
                    
                    int xx=j+1;
                    if(seen[xx])continue;
                    
                    if(P[xx].first< P[x].first && P[x].first<P[xx].second){
                        Q.push(xx);
                        seen[xx]=1;
                    }
                    if(P[xx].first< P[x].second && P[x].second<P[xx].second){
                        Q.push(xx);
                        seen[xx]=1;
                    }
                }
            }
            puts(found?"YES":"NO");
        }
    }      
    return 0;      
}
