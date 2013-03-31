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


string ternary(long long val){
    string ans="";
    while(val){
        ans=string(1,'0'+val%3)+ans;
        val/=3;
    }
    int num=100-ans.sz;   
    return string(num,'0')+ans;
}

long long toDec(string st){
    long long ans=0;
    REP(i,0,st.sz){
        ans=ans*3+(st[i]-'0');
    }
    return ans;
}


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long a,c;
    string p,q="",r;
    cin>>a>>c;
    p=ternary(a);
    r=ternary(c);
    
    REP(i,0,p.sz){
        int x=p[i]-'0';
        int z=r[i]-'0';
        int y=0;
        REP(j,0,3){
            if((x+j)%3==z){
                y=j;
                break;
            }
        }
        q+=string(1,'0'+y);
    }
    cout<<toDec(q)<<endl;
    //system("pause");
    return 0;
}
