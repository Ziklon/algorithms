#include<bits/stdc++.h>
#define REP(i,n)for (int i=0;i<n;i++)
using namespace std;
typedef long long ll;
char type;
#define INF 1<<30

int go(int idx, int ld, int start , vector<vector<int> >& v){
    if(idx==6){
        if(v[5][ld]==v[0][start])return 0;
        return -INF;
    }
    int ans=-INF;
    for(int i=0;i<3;i++){
        int uu=i;
        int vv=(i+2)%3;
        int mm=(i+1)%3;
        if(v[idx][uu]==v[idx-1][ld])
            ans=max(ans,v[idx][mm]+ go(idx+1,vv,start,v));
    
    }
    return ans;

}


int main(){
    while(1){
    
        vector<vector<int> >v(6);
        vector<int> P(6);
        REP(i,6)P[i]=i;
        int ans=-INF;
        REP(i,6){
            vector<int> tmp(3,0);
            REP(j,3)cin>>tmp[j];
            v[i]=tmp;
        }
        do{
            for(int i=0;i<3;i++){
                int vv=(i+2)%3;
                int uu=(i+1)%3;
                ans=max(ans,v[0][uu]+ go(1, vv, i,v));
            }
        
        }while(next_permutation(v.begin(),v.end()));
        if(ans<0)cout<<"none"<<endl;
        else cout<<ans<<endl;
        cin>>type;
        if(type=='$')break;
    }
    return 0;
}

