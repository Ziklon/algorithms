/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}



int main(){
    //freopen("in.txt",stdin);
    //freopen("out.txt",stdout);
    int n;
    vector<int> v;
    scanf("%d",&n);
    v.resize(n);
    for(int i=0;i<n;i++){
      scanf("%d",&v[i]);
    }
    set<int> S(all(v));
    vector<int> dev(all(S));
    bool ok=1;
    for(int i=0;i+1<dev.sz && ok;i++){
        long long aux=2*dev[i];
        if(aux>dev[i+1])ok=0;            
    }
    if(ok)printf("NO\n");
    else printf("YES\n");   
    //system("pause");
    return 0;
}
