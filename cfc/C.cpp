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
#define MAXN 200000
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

void update(int node, int l, int r, int a, int b, int x){
    if(l > b || r < a) return;    
    if(a <= l && r <= b) sum[node] += x;
    else{
        int mi = (l + r) >> 1;        
        update(2 * node + 1,l,mi,a,b,x);
        update(2 * node + 2,mi + 1,r,a,b,x);        
        childSum[node] = childSum[2 * node + 1] + childSum[2 * node + 2] + (mi - l + 1) * sum[2 * node + 1] + (r - mi) * sum[2 * node + 2];
    }
}

int A[MAXN],x,y,N,Q;

int main(){
    
   #ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
   #endif
   scanf("%d %d",&N,&Q);
   REP(i,N)scanf("%d",&A[i]);
   
   sort(A,A+N);
   reverse(A,A+N);
   memset(childSum,0,sizeof childSum);
   memset(sum,0,sizeof sum);
   
   REP(i,Q){
        scanf("%d %d",&x,&y);
        update(0,0,N-1,x-1,y-1,1);
   }
   vector<int>vi;
   for(int i=0;i<N;i++){
        x=query(0,0,N-1,i,i);        
        vi.push_back(x);               
   }
   sort(vi.rbegin(),vi.rend());
   ll ans=0;
   for(int i=0;i<N;i++){
        ans+=vi[i]*1LL*A[i];    
   }
   cout<<ans<<endl;   
   return 0;      
}
