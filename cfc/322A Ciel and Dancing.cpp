#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (int)n; i++)
#define debug(v) cout<<#v<<" = "<<(v)<<endl;
#define adebug(x,n) cout <<#x<<endl; REP(i,n)cout<<x[i]<<char(i+1==n?10:32)
#define mdebug(x,m,n) cout <<#x<<endl; REP(i,m)REP(j,n)cout<<x[i][j]<<char(j+1==n?10:32)

using namespace std;

int m,n;
int main(){
    scanf("%d %d",&n,&m);
    
    set<int> S1;
    set<int> S2;
    vector<pair<int,int> > v;
    REP(i,n)REP(j,m){
        if(S1.count(i)==0 || S2.count(j)==0){
            S1.insert(i);
            S2.insert(j);
            v.push_back(make_pair(i+1,j+1));
        }
    }
    printf("%d\n",v.size());
    REP(i,v.size())
        printf("%d %d\n",v[i].first,v[i].second);
          
    return 0;      
}
