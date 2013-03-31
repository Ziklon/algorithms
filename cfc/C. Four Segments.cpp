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
typedef long long ll;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    map<pair<int,int> ,int >M;
    bool ok=1;
    int v=0;
    int h=0;
    REP(i,0,4){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(!((a==c)^(b==d)))ok=0;
        if(a==c)v++;
        else h++;
        M[make_pair(a,b)]++;
        M[make_pair(c,d)]++;
    }
    if(v!=2 && h!=2)ok=0;
    foreach(M,it){
        if(it->second!=2)ok=0;
    }        
    if(ok)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    //system("pause");
    return 0;
}
