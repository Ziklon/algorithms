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
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    vector<string> vs;
    string line;
    int mx=0;
    while(getline(cin,line)){
        vs.push_back(line);
        mx=max(mx,(int)line.sz);
    }
    REP(i,0,vs.sz){
        if(vs[i].sz<mx){
            int res=mx-vs[i].sz;
            int aa=res/2;
            if((i+1)%2==0)
                vs[i]=string(res-aa,' ')+vs[i]+string(aa,' ');
            else
                vs[i]=string(aa,' ')+vs[i]+string(res-aa,' ');
        }
    }
    cout<<string(mx+2,'*')<<endl;
    REP(i,0,vs.sz){
        cout<<"*"<<vs[i]<<"*"<<endl;
    }
     cout<<string(mx+2,'*')<<endl;
    //system("pause");
    return 0;
}
