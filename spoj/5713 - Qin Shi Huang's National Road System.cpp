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
#define NMAX 1000
typedef long long ll;
int N,T;
int X[NMAX];
int Y[NMAX];
int P[NMAX];


int U[NMAX];

void make(int n){
    REP(i,n)U[i]=i;
}

int find(int u){
    if(U[u]==u)return u;
    return U[u]=find(U[u]);
}

void join(int p, int q){
    U[find(p)]=find(q);
}

struct Node{
   int u,v;
   double d;   
   Node(int _u,int _v, double _d){
        u=_u;
        v=_v;
        d=_d;
   }     
};


bool comp(Node p, Node q){
    return p.d<q.d; 
}


int main(){
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d",&T);
   REP(t,T){
        scanf("%d",&N);
        REP(i,N){
            scanf("%d %d %d",&X[i],&Y[i],&P[i]);
        }
        vector<Node> v;
        for(int i=0;i<N;i++)for(int j=0;j<i;j++){                
            double dist=hypot(X[i]-X[j],Y[i]-Y[j]);
            v.push_back(Node(i,j,dist));
        }
        sort(v.begin(),v.end(),comp);
        double ans=0;
        double disMax=0;
        make(N);
        int idxMx=-1;
        
        vector<int> path;         
        REP(i,v.size()){
            Node p=v[i];            
            if(find(p.u)!=find(p.v)){                    
                if(disMax<p.d){    
                    disMax=p.d;
                    idxMx=i;
                }
                path.push_back(i);
                ans+=p.d;
                join(p.u,p.v);
            }        
        }        
        double dist=ans-disMax;
        ans=0;
        //cout<<disMax<<" "<<ans<<" "<<dist<<endl;
        for(int i=0;i<path.size();i++){
            int sum=P[v[path[i]].u]+P[v[path[i]].v];
            if(idxMx==path[i])continue;            
            //cout<<sum<<" "<<v[path[i]].u<<" "<<v[path[i]].v<<endl;
            ans=max(ans,sum/dist);
        }               
        printf("%.2f\n",ans);
   } 
   return 0;      
}
