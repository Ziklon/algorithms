#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define sz size()

using namespace std;


#define MAX 110
struct nodo{
    int x;
    double y;
  nodo(int X,double Y)
  {
    x=X;
    y=Y;      
  }  
};

bool operator<(nodo p,nodo q){
    return p.y>q.y;    
}

int n,t;int tc;
double res;
double oo=1e+10;
vector<nodo> v[MAX];
double dis[MAX];
vector<pair<double,double> >vd;
double prim(){
    for(int i=0;i<101;i++){dis[i]=oo;}
    priority_queue <nodo>Q;
    dis[0]=0;
    Q.push(nodo(0,0.0));
    vector<bool>visited(101,0);
    while(!Q.empty()){
        nodo q= Q.top();
        visited[q.x]=1;
        Q.pop();        
        for(int i=0;i<v[q.x].size();i++){
            nodo aux=v[q.x][i];
            if(visited[aux.x])continue;
            if(aux.y<dis[aux.x]){
                dis[aux.x]=aux.y; 
                Q.push(nodo(aux.x,dis[aux.x]));   
            }
        }
    }
    double dev=0;
    for(int i=1;i<n;i++)dev+=dis[i];
    return dev;
}

int main(){
    
   //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
   cin>>tc;
   double x,y,h;
   while(tc--){
      cin>>t;
      vd.clear();
      for(int i=0;i<101;i++)v[i].clear();
      for(int i=0;i<t;i++){
         cin>>x>>y;
         vd.push_back(make_pair(x,y));
      }
      for(int i=0;i<t;i++){
         for(int j=i+1;j<t;j++){
            h=hypot(vd[i].first-vd[j].first,vd[i].second-vd[j].second);
            v[i].push_back(nodo(j,h));
            v[j].push_back(nodo(i,h));
         }
      }     
      n=t;
      res=prim();
      printf("%.2lf\n",res);
      if(tc)
         printf("\n");
   }
    return 0;
}
