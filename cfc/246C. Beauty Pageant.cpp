#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
typedef long long ll;
int N,K;
int A[55];

int main(){
   
   scanf("%d %d",&N,&K);
   REP(i,N)scanf("%d",&A[i]);
   
   sort(A,A+N);
   REP(i,N)for(int j=-1;j<i;j++){
        vector<int> tmp;
        REP(k,i+1)if(k!=j)tmp.push_back(A[k]);
        printf("%d",tmp.size());
        REP(k,tmp.size())printf(" %d",tmp[k]);
        printf("\n");
        K--;
        if(K==0)return 0;
   }         
   return 0;      
}
