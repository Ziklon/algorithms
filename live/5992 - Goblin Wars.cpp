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
#define MAXN 505
char G[MAXN][MAXN];
int B[MAXN][MAXN];
int R,C,T;

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};

int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d\n",&T);
   REP(t,T){
        scanf("%d %d\n",&R,&C);
        REP(i,R){
            REP(j,C)scanf("%c",&G[i][j]);
            scanf("\n");
        }        
        queue<pair<int,int> >Q;
                
        REP(i,R)REP(j,C)if(G[i][j]>='a' && G[i][j]<='z'){            
            Q.push(make_pair(i,j));
        }
        while(!Q.empty()){            
            vector<pair<int,int> >v;
            while(!Q.empty()){
                int x=Q.front().first;
                int y=Q.front().second;
                v.push_back(make_pair(x,y));
                Q.pop();
            }            
            map<pair<int,int>,int >M1;
            map<pair<int,int>,char>M2;                        
            REP(i,v.size()){            
                REP(j,4){
                    int X=v[i].first+dx[j];
                    int Y=v[i].second+dy[j];
                    char cc=G[v[i].first][v[i].second];                    
                    if(min(X,Y)>=0 && X<R && Y<C && G[X][Y]=='.'){                                                
                        if(M1.count(make_pair(X,Y))==0){
                            M1[make_pair(X,Y)]=1;
                            M2[make_pair(X,Y)]=cc;
                        }else{                            
                            if(M2[make_pair(X,Y)]!=cc){
                                M1[make_pair(X,Y)]=2;
                            }     
                        }
                    }
                }            
            }
            vector<pair<pair<int,int>,int> > vp(M1.begin(),M1.end());
            REP(i,vp.size()){
                int x=vp[i].first.first;
                int y=vp[i].first.second;
                if(vp[i].second>1){
                    G[x][y]='*';
                }else{
                    char cc=M2[vp[i].first];
                    G[x][y]=cc;
                    Q.push(make_pair(x,y));
                }
            }                      
        }
        REP(i,R){
            REP(j,C)printf("%c",G[i][j]);
            printf("\n");
        }        
        printf("\n");        
   
   }
   return 0;      
}
