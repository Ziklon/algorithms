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

bool check(int a, int b, int c, int d){
    if(c>=b*2 && b<=2*c)return true;
    if(d>=a*2 && a<=2*d) return true;
    return false;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int gi,gj,bi,bj;
    cin>>gi>>gj>>bi>>bj;
    if(check(gi,gj,bi,bj))
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
    //system("pause");
    return 0;
}
