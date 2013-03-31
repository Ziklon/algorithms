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
string line;
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    cin>>line;
    
    long long ans=0;

    vector<long long> v(256,0);
    REP(i,0,line.sz)
        v[line[i]]++;    
    
    REP(i,0,v.sz){
        ans+=(v[i]*v[i]);
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
