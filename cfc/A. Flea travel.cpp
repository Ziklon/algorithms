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

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int init=0,num=1;
    int mod;
    cin>>mod;
    set<int>S;
    S.insert(0);
    while(1){
        init=(init+num)%mod;
        num++;
        S.insert(init);
        if(init==0)break;
        
    }
    if(S.sz==mod)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    //system("pause");
    return 0;
}
