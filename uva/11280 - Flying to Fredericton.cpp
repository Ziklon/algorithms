#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define INF 1<<30
using namespace std;

vector<vector<pair<int,int> > >Adj;
int T,N,R,cost,QE,stopovers;
int dist[120][120];

struct node{
    int cost, u, steps;
    node(int _u, int _st, int _c){
        u=_u;
        steps=_st;
        cost=_c;
    }
    bool operator <( node p)const{
        return cost>p.cost;
    }
};


int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   cin>>T;
   REP(t,T){
        string city,cada,cadb;
        cin>>N;
        Adj.clear();
        Adj.resize(N);
        map<string,int> M;
        REP(i,N){
            cin>>city;
            M[city]=i;
        }
        cin>>R;
        REP(i,R){
            cin>>cada>>cadb>>cost;
            Adj[M[cada]].push_back(make_pair(M[cadb],cost));
        }
        cin>>QE;
        //dijkstra
        REP(i,120)REP(j,120)dist[i][j]=INF;
        int nstart=M["Calgary"];
        int nend=M["Fredericton"];
        priority_queue<node> Q;
        Q.push(node(nstart,0,0));
        while(!Q.empty()){
            node cur=Q.top();Q.pop();            
            REP(i,Adj[cur.u].size()){
                pair<int,int> to=Adj[cur.u][i];
                if(dist[to.first][cur.steps+1]> (cur.cost+to.second)){
                    dist[to.first][cur.steps+1]=cur.cost+to.second;
                    Q.push(node(to.first,cur.steps+1,dist[to.first][cur.steps+1]));
                }
            }      
        }
        cout<<"Scenario #"<<(t+1)<<endl;
        REP(i,QE){
            cin>>stopovers;
            int ans=INF;
            REP(j,stopovers+1)ans=min(ans,dist[nend][j+1]);
            if(ans<INF)cout<<"Total cost of flight(s) is $"<<ans<<endl;
            else cout<<"No satisfactory flights"<<endl;            
        }
        if(t+1<T)cout<<endl;
            
   }
   return 0;      
}
