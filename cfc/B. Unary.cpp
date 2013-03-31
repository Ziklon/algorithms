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
#define MOD 1000003
using namespace std;
string keys="><+-.,[]";
string vals[]={"1000","1001","1010","1011","1100","1101","1110","1111"};
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string unary;
    string code="";
    cin>>unary;
    int ans=0,num;
    REP(i,0,unary.sz){
        num=keys.find(string(1,unary[i]));
        code+=vals[num];
        
    }
    REP(i,0,code.sz){
        ans=(ans*2 + (code[i]-'0'))%MOD;
    }
    cout<<ans<<endl;
    //system("pause");
    return 0;
}
