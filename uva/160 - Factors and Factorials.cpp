#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
int N;
bool sieve[110];

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
      //freopen("output","w",stdout);
   #endif
   vector<int> primes; 
   memset(sieve,0,sizeof sieve);
   for(int i=2;i*i<=100;i++)if(sieve[i]==0)for(int j=i*i;j<=100;j+=i)sieve[j]=1;
   
   REP(i,101)if(i>=2 && sieve[i]==0)primes.push_back(i);
   
   while(scanf("%d",&N)==1 && N>0){
        printf("%3d! =",N);
        int num=0;
        for(int i=0;primes[i]<=N && i<primes.size();i++){
            int cnt=0;
            int tmp=N;
            while(tmp){
                cnt+=tmp/primes[i];
                tmp/=primes[i];
            }
            if(num%15==0 && num>0)printf("\n%6c",' ');
            num++;
            printf("%3d",cnt);
            
        }
        printf("\n");
        
   }
   return 0;      
}

