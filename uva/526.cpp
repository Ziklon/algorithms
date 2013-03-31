#include <cstdio>
#include <iostream>
#define all(v) (v).begin(),(v).end()
#define sz size()
using namespace std;
int A[110],dp[110][110][110],N,T;

int go(int p, int a, int b){
   if(p>=N) return abs(a-b);
   int ans=1<<29;
   if(a>=b)ans=min(ans,go(p+1,a-b,A[p]));
   if(a<=b)ans=min(ans,go(p+1,A[p],b-a));
   return ans;     
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
    while(T--){
      cin>>N;
      for(int i=0;i<N;i++)cin>>A[i];
      cout<<go(0,0,0)<<endl;
    }
    return 0;
}
