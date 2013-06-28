#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)
#define INF 1<<20
using namespace std;
typedef long long ll;

int dist[1<<16],T;
char c;
int dx[]={1,-1,0,0,0};
int dy[]={0,0,1,-1,0};


int check(int mask, int i, int j){
    if(mask&(1<<(4*i+j)))return 1;
    return 0;
}

int main(){
   #ifdef LocalHost
      freopen("input.txt","r",stdin);
      freopen("output.txt","w",stdout);
   #endif
   scanf("%d\n",&T);
   REP(t,T){
        int curMask=0,ans;
        REP(i,4){
            REP(j,4){
                scanf("%c",&c);
                if(c=='1')curMask|=(1<<(4*i+j));
            }
            scanf("\n");
        }
        REP(i,1<<16)dist[i]=INF;
        dist[curMask]=0;
        priority_queue<pair<int,int> >Q;
        Q.push(make_pair(0,curMask));
        while(!Q.empty()){
            int cost=abs(Q.top().first);
            int mask=Q.top().second;Q.pop();
            if(mask==0)break;
            REP(i,4)REP(j,4){
                int cnt=0;
                REP(k,4){
                    int x=dx[k]+i;
                    int y=dy[k]+j;
                    if(min(x,y)>=0 && max(x,y)<4 && check(mask,x,y)==1)cnt++;
                }
                if(cnt>0){
                    int newMask=mask;
                    REP(k,5){
                        int x=dx[k]+i;
                        int y=dy[k]+j;
                        if(min(x,y)>=0 && max(x,y)<4){
                            if(check(mask,x,y))
                                newMask &= ~(1 << (4*x+y));
                            else
                                newMask|=(1<<(4*x+y));                        
                        }
                    }
                    if(dist[newMask]> cost+1){
                        Q.push(make_pair(-(cost+1),newMask));
                        dist[newMask]=cost+1;
                    }               
                }
                if(check(mask,i,j)){
                    int newMask=mask;
                    newMask &= ~(1 << (4*i+j));
                    if(dist[newMask]> cost+2){
                        Q.push(make_pair(-(cost+2),newMask));
                        dist[newMask]=cost+2;
                    }
                }   
            }
            
        }
        
        printf("%d\n",dist[0]);   
   }
   return 0;      
}

