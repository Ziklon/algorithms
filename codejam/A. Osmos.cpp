#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
int T;
int go(int idx, int sum, vector<int> &v){
    if(idx>=v.size())return 0;
    int ans=2000;
    if(v[idx]<sum)ans=go(idx+1,sum+v[idx],v);
    else{
        if(sum==1)ans=1+go(idx+1,sum,v);
        else{
            int tmp=sum;
            int adds=0;
            while(tmp<=v[idx]){
                tmp*=2;
                tmp--;
                adds++;
            }
            ans=min(ans,1+go(idx+1,sum,v));
            ans=min(ans,adds+go(idx+1,tmp+v[idx],v));
        }
        
    }
    return ans;
    
}
int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
      freopen("output","w",stdout);
   #endif
   scanf("%d",&T);
   REP(t,T){
      int A,N;
      scanf("%d %d",&A,&N);
      vector<int> v(N);
      REP(i,N)scanf("%d",&v[i]);
      int ans=0;
      int val=A;
      sort(v.begin(),v.end());     
      ans=go(0,A,v);     
      printf("Case #%d: %d\n",t+1,ans);      
        
   }
   return 0;      
}

