/*
ID: winftc2
PROG: in.txt
LANG: C++
*/
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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long n,x,y,p,q,r;
    cin>>n>>x>>y;
    r=y-(n-1);
    r=r*r;
    r=r+n-1;
    if(y>=n && r>=x){
        cout<<(y-(n-1))<<endl;
        for(int i=1;i<n;i++)puts("1");
    }else
      cout<<"-1"<<endl;
    //system("pause");
    return 0;
}
