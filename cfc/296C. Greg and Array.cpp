#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
#define MAXN 100005
int N,M,K;
ll F[MAXN];


long long sum[4 * MAXN],childSum[4 * MAXN];


long long query(int node, int l, int r, int a, int b){
    if(l > b || r < a) return 0;
    long long ret = (min(b,r) - max(a,l) + 1) * sum[node];    
    if(a <= l && r <= b) ret += childSum[node];
    else{
        int mi = (l + r) >> 1;        
        ret += query(2 * node + 1,l,mi,a,b) + query(2 * node + 2,mi + 1,r,a,b);
    }    
    return ret;
}

void update(int node, int l, int r, int a, int b, ll x){
    if(l > b || r < a) return;
    
    if(a <= l && r <= b) sum[node] += x;
    else{
        int mi = (l + r) >> 1;        
        update(2 * node + 1,l,mi,a,b,x);
        update(2 * node + 2,mi + 1,r,a,b,x);        
        childSum[node] = childSum[2 * node + 1] + childSum[2 * node + 2] + (mi - l + 1) * sum[2 * node + 1] + (r - mi) * sum[2 * node + 2];
    }
}

int main(){
   scanf("%d %d %d",&N,&M,&K);
   memset(childSum,0,sizeof childSum);
   memset(sum,0,sizeof sum);
   int x,y;
   REP(i,N){
       scanf("%d",&x);
       update(0,0,N-1,i,i,x); 
   }  
      
   vector<pair<int,pair<int,int> > >  operations(M);
   REP(i,M)scanf("%d %d %d",&operations[i].second.first,&operations[i].second.second,&operations[i].first);
   memset(F,0,sizeof F);   
   ll suma=0,c;
   REP(i,K){
      scanf("%d %d",&x,&y);x--;
      F[x]+=1;
      F[y]-=1;  
   }
   REP(i,M){
        suma+=F[i];
        c=suma*operations[i].first;        
        x=operations[i].second.first-1;
        y=operations[i].second.second-1;
        update(0,0,N-1,x,y,c);
   }
    REP(i,N){
      if(i)cout<<" ";
      cout<<query(0,0,N-1,i,i);  
   }        
   return 0;      
}

