#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

string cad;
int flow[40][40];
int cap[40][40];
int prev[40];
int cnFlow=0;
void augment( int v, int minEdge, int& s){
    if(v==s){
        cnFlow=minEdge;
        return;
    }else{
        augment(prev[v],min(cap[prev[v]][v]-flow[prev[v]][v],minEdge),s );
        flow[v][prev[v]]-=cnFlow;
        flow[prev[v]][v]+=cnFlow;        
    }
}

int maxFlow(int s, int t){
    memset(prev,-1,sizeof prev);
    queue<int> Q;
    Q.push(s);
    prev[s]=-2;
    bool found=0;
    while(!Q.empty()){
        int u=Q.front();Q.pop();
        if(u==t){
            found=1;
            break;                
        }
        for(int i=0;i<40;i++){
            if(cap[u][i]>flow[u][i] && prev[i]==-1){
                prev[i]=u;
                Q.push(i);    
            }            
        }        
    }
    if(found==0)return 0;
    cnFlow=0;
    augment(t,1<<20,s);
    return 1;    
}


int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   bool endTest=0;
   while(endTest==0){
       memset(flow,0,sizeof flow);
       memset(cap,0,sizeof cap);
       endTest=1;
       int sum=0;
       while(getline(cin,cad)){
           if(cad==""){
                endTest=0;
                break; 
           }
           int u=cad[0]-'A'+2;
           int n=cad[1]-'0';
           cap[0][u]+=n;
           sum+=n;           
           for(int j=3;j+1<cad.size();j++){
               int v=cad[j]-'0'+28;
               cap[u][v]=1;
               cap[v][1]=1; 
           }                
       }
       int ansFlow=0;
       string ans=string(10,'_');
       while(maxFlow(0,1))ansFlow+=cnFlow;
       if(ansFlow!=sum)printf("!\n");
       else{
            for(int i=28;i<=38;i++){
                for(int j=2;j<28;j++){
                    if(flow[j][i]){
                        ans[i-28]=j+'A'-2;
                        break;
                    }
                }
            }
            printf("%s\n",ans.c_str());
       }
       
   }
   return 0;      
}
