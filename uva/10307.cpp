#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#define sz size()
using namespace std;

string maze[55];
string line;
int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};
int vis[51][51];
int dis[51][51];

struct edge{
   int ed,w;
   edge(int n,int m){
      ed=n;
      w=m;
   }

};

bool operator<(edge p,edge q){
    return p.w>q.w;    
}

int oo=1<<30;
vector<edge> v[110];
int dst[110];
bool visited[110];
int prim(int& n){
   for(int i=0;i<n;i++){
      visited[i]=0;
      dst[i]=oo;
   }
   priority_queue <edge>Q;
   dst[0]=0;
   Q.push(edge(0,0));
   while(!Q.empty()){
      edge cur=Q.top();
      Q.pop();
      visited[cur.ed]=1;
      for(int i=0;i<v[cur.ed].sz;i++){
         edge to=v[cur.ed][i];
         if(visited[to.ed])continue;
         if(to.w<dst[to.ed]){
            dst[to.ed]=to.w;
            Q.push(edge(to.ed,dst[to.ed]));         
         }
      }
   
   }
   int dev=0;
   for(int i=1;i<n;i++)dev+=dst[i];
   
   return dev;
    

}

int main(){
   int n,x,y,na;
   int xs,ys;
   scanf("%d\n",&n);
   while(n--){
      scanf("%d %d\n",&x,&y);
      vector<pair<int,int> >va;
      for(int i=0;i<y;i++){
        getline(cin,line);
        maze[i]=line;
        for(int j=0;j<x;j++)
            if(line[j]=='A' || line[j]=='S')
               va.push_back(make_pair(i,j));
      }
      na=va.size();
      for(int i=0;i<na;i++)v[i].clear();
      memset(dis,0,sizeof dis);
      for(int i=0;i<va.sz;i++)
         for(int j=i+1;j<va.sz;j++){
            memset(vis,0,sizeof vis);  
            memset(dis,0,sizeof dis);          
            queue<pair<int,int> >Q;
            Q.push(make_pair(va[i].first,va[i].second));
            vis[va[i].first][va[i].second]=1;
            bool aux=0;
            while(!Q.empty()){
               pair<int,int> cur=Q.front();
               Q.pop();
               
               if(cur.first==va[j].first&& cur.second==va[j].second){
                  aux=1;
                  break;
               }               
               for(int j=0;j<4;j++){
                  int X=di[j]+cur.first;
                  int Y=dj[j]+cur.second;
                  if(X>=0 && Y>=0 && X<x && Y<y && maze[X][Y]!='#' && !vis[X][Y]){
                     Q.push(make_pair(X,Y));
                     dis[X][Y]+=dis[cur.first][cur.second]+1;
                     vis[X][Y]=1;
                  }
               }
            
            }
            int cost=dis[va[j].first][va[j].second];
            if(aux){
               v[i].push_back(edge(j,cost));
               v[j].push_back(edge(i,cost));
            }              
         }
      cout<<prim(na)<<endl;             
   
   }   
   return 0;

}
