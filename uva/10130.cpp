/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

int dp[1005][35];


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
     int T,N,P,W,G,x,y,ans;
     scanf("%d\n",&T);
     for(int i=0;i<T;i++){
        scanf("%d\n",&N);
        vector<pair<int,int> >vo;
        vector<int> vp;
        for(int j=0;j<N;j++){
          scanf("%d %d\n",&P,&W);
          vo.push_back(make_pair(P,W));
        }
        scanf("%d\n",&G);
        for(int j=0;j<G;j++){
          scanf("%d\n",&x);
          vp.push_back(x);
        }
        ans=0;
        
        fill(dp,0);
        
        for(int j=1;j<=N;j++){          
           for(int k=1;k<=33;k++){
               dp[j][k]=dp[j-1][k];
               if(k>=vo[j-1].second)
                  dp[j][k]=max(dp[j][k],vo[j-1].first+ dp[j-1][k-vo[j-1].second]);
           } 
        }
            
        for(int j=0;j<G;j++){
          ans+=dp[N][vp[j]];
        }
        cout<<ans<<endl;        
        
     }
    //system("pause");
    return 0;
}
