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
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string line;
    cin>>line;
  
    long long sum=0,aux;
    int ans=0;
    for(int i=0;i<line.sz;i++)
      sum+=(line[i]-'0');
    if(line.sz>1)ans=1;  
    while(sum>9){
       aux=0;
       while(sum>0){
        aux=aux+sum%10;
        sum/=10;
       }
       ans++;
       sum=aux;
    }
    cout<<ans<<endl;    
    return 0;
}
