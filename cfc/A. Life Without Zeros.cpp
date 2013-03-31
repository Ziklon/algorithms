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

long long toi(string s){
    istringstream is(s);
    long long ans;
    is>>ans;
    return ans;    
}
string tos(long long n){
     stringstream ss;
     ss<<n;
     return ss.str();       
}
string quitZero(string s){
    string str="";
    REP(i,0,s.sz)
      if(s[i]!='0')
         str+=s[i];
    return str;   
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string a,b,c,d;
    cin>>a>>b;
    c=tos(toi(a)+toi(b));
    a=quitZero(a);
    b=quitZero(b);
    c=quitZero(c);
    if(tos(toi(a)+toi(b))==c)
       puts("YES");
    else
       puts("NO");
    //system("pause");
    return 0;
}
