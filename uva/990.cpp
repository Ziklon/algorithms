#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;
int D[32],V[32];
int dp[32][1005];
int path[32][1005];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,t,w,nc=0;
    while(cin>>t>>w){
        if(nc>0)cout<<endl;
        cin>>n;
        REP(i,0,n){
            cin>>D[i]>>V[i];
        }
        dp[0][0]=0;
        fill(path,-1);
        REP(i,1,n+1){
            int val=D[i-1]*w*3;
            REP(j,0,t+1){
                dp[i][j]=dp[i-1][j];                
                if(j>=val)
                    if(V[i-1]+dp[i-1][j-val]>dp[i][j]){
                        dp[i][j]=V[i-1]+dp[i-1][j-val];
                        path[i][j]=val;      
                    }else{
                        path[i][j]=-1;
                    }
            }
        }
        cout<<dp[n][t]<<endl;
        int x=n;
        int y=t;
        vector<int> ans;   
        while(x>0 && y>0){
            if(path[x][y]>-1){
                ans.push_back(x-1);
                y=y-path[x][y];
                x--;
            }else{
                x--;
            }
        }
        cout<<ans.sz<<endl;
        reverse(all(ans));
        REP(i,0,ans.sz){
            cout<<D[ans[i]]<<" "<<V[ans[i]]<<endl;
            
        }  
        nc++; 
    }
    
    //system("pause");
    return 0;
}
