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
int dp[10000][900];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int T,c,M;
    cin>>T;
    
    REP(i,0,T){
        vector<int> cars;
        cin>>M;
        while(1){
            cin>>c;
            if(c==0)break;
            cars.push_back(c);
        }
        
        REP(i,0,cars.sz){
            REP(j,0,M+1){
            
            }
        }
            
    }
    system("pause");
    return 0;
}
