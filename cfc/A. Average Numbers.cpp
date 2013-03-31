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
int A[1<<20];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,s,x;
    
    cin>>n;
    s=0;
    fill(A,0);
    REP(i,0,n){
        cin>>A[i];
        s+=A[i];
    }
    vector<int> v;
    REP(i,0,n){
        int x=s-A[i];
        int d=x/(n-1);
        int r=x%(n-1);
        
        if(d==A[i] && r==0){
            v.push_back(i+1);
        }
    }
    cout<<v.sz<<endl;
    REP(i,0,v.sz-1)
        cout<<v[i]<<" ";
    if(v.sz>0)cout<<v[v.sz-1];
    
    cout<<endl;
    //system("pause");
    return 0;
}
