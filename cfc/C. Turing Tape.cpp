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
string toBin(int n){
    string ans=string(8,'0');
    int pt=7;
    while(n){
        ans[pt]=(n%2)+'0';
        n/=2;
        pt--;
    }
    return ans;
}

int toDec(string s){
    int ans=0;
    REP(i,0,s.sz)
        ans=ans*2 + (s[i]-'0');
    return ans;
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    char cur;
    int ante=0;
    string line;
    getline(cin,line);
    
    REP(i,0,line.sz){
        cur=line[i];
        string aux=toBin(cur-0);
        //cout<<aux<<endl;
        reverse(all(aux));
        int val=toDec(aux);
        int res=(256+ (ante-val))%256;
        ante=val;
        cout<<res<<endl;    
    }  
    //system("pause");
    return 0;
}
