#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;

int N;
int main(){
   scanf("%d",&N);
   vector<int> v(N);
   vector<int> M(1001,0);
   REP(i,N)scanf("%d",&v[i]),M[v[i]]++;
   REP(i,1001)if((M[i])>((N+1)/2)){
        puts("NO");
        return 0;
   }
   puts("YES");
   return 0;      
}
