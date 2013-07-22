#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
using namespace std;
typedef long long ll;
int N,K;
pair<int,int> P[1005];
int main(){
   scanf("%d %d",&N,&K);
   
   set<int> S;
   REP(i,K){
       scanf("%d %d",&P[i].first,&P[i].second);
       S.insert(P[i].first);
       S.insert(P[i].second);
    }

   sort(P,P+K);
   int center =-1;
   for(int i=1;i<=N;i++)if(S.count(i)==0){
        center=i;
        break;
   } 
   int cnt=N-1;
   printf("%d\n",cnt);
   for(int i=1;i<=N;i++){
       if(i==center)continue;
       printf("%d %d\n",center,i);   
   }


   return 0;      
}
