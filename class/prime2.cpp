#include<bits/stdc++.h>
#define REP(i,n)for (int i=0;i<n;i++)
#define first fst
#define second snd
#define sz size()
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int t, m, n;
bool criba[100005];
bool S1[100005];


/***
 *-----%%%%%%%------------------------------------**********************-------
 *
 *
 *
 * **/

int main(){
    scanf("%d",&t);
    
    for(int i=2;i*i<=100005;i++)
        if(S1[i]==0)
            for(int j=i*i;j<100005;j+=i)
                S1[j]=1;



    while(t--){
    
        scanf("%d %d",&m,&n);

        
        memset(criba,0,sizeof criba);
        int limit =sqrt(n);
        //N  = 10^9
        for(int i=2;i*i<=n;i++){
           if(S1[i]==0){
               // aca tmb i tiene que ser primos
               //
               
               int mx = max(i*i, (m/i)*i );

              for(int j=mx;j<=n;j+=i){
                  if(j>=m)
                     criba[j-m]=1;
           
               }      
           }
        }

        for(int i=max(2,m);i<=n;i++){
            if(criba[i-m]==0)
                printf("%d\n",i);
        
        }
        if(t>0)printf("\n");
            
    }


    return 0;
}

