/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;


struct node{
  int c,i,t;
  node(){}
  node(int _c,int _i, int _t){
    c=_c;
    i=_i;
    t=_t;
  }
};

bool orden(node p, node q){
  return p.i<q.i;
}
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int C,T,W,x,k,tstart,cstart,cend;
    string text,aux;
    while(scanf("%d\n",&C)==1){
        map<string,int>M;
        x=0;
        int G[101][101];
        int dis[105];
        
        char buff[50];
        vector<node> Adj[C];
        for(int i=0;i<C;i++){
          scanf("%s\n",buff);
          M[buff]=x++;
        }
        scanf("%d\n",&K);       
        for(int i=0;i<K;i++){
          scanf("%d\n",&W);
          if(W>0){
             scanf("%d %s\n",&k,buff);
             text=buff;
             for(int j=1;j<W;j++){
                scanf("%d %s\n",&x,buff);
                Adj[M[text]].push_back(node(M[buff],k,x-k));
                text=buff;
                k=x;
            } 
          }                
        }
        scanf("%d\n",&tstart);
        scanf("%s\n",buff);cstart=M[buff];
        scanf("%s\n",buff);cend=M[buff];
        sort(all(Adj[cstart]));
        for(int k=0;k<Adj[cstart].sz;k++){            
            if(Adj[cstart][k].i>=tstart){                
                
                for(int i=0;i<105;i++)dis[i]=INF;
                priority_queue<pair<int,int> >Q;
                Q.push(make_pair(cstart,Adj[cstart][k].i));
                dis[cstart]=0;
                
                while(!Q.empty()){
                    pair<int,int>cur=Q.top();
                    Q.pop();
                    
                }                
            }
        }
                
             
        
    }
    //system("pause");
    return 0;
}
