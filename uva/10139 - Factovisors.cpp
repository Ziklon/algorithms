#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;
int n,m;

vector<pair<int,int> >factors(int n){
    vector<pair<int,int> >ans;
    int r=sqrt(n);
    for(int i=2;i<=r;i++){
        int cn=0;
        while(n%i==0){
            cn++;
            n/=i;
        }
        if(cn>0)ans.push_back(make_pair(i,cn));
    }
    if(n>1)ans.push_back(make_pair(n,1));
    return ans;
}

int main(){
   #ifdef LocalHost
      freopen("input","r",stdin);
   #endif
   while(scanf("%d %d",&n,&m)==2){
        vector<pair<int,int> > v=factors(m);
        bool can=1;
        REP(i,v.size()){
            int cn=0;
            int tmp=n;
            while(tmp){
                cn+=tmp/v[i].first;
                tmp/=v[i].first;
            }
            if(cn<v[i].second)can=0;
        }
        if(can==0)printf("%d does not divide %d!\n",m,n);
        else printf("%d divides %d!\n",m,n);
   }
   return 0;      
}

