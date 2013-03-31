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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
using namespace std;
int A[10000+5];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n,s,p;
    scanf("%d\n",&n);
    REP(i,0,n)
      scanf("%d",&A[i]);
    s=A[0];
    sort(A,A+n);
    p=upper_bound(A,A+n,s)-A;
    cout<<(n-(p-1))<<endl;
    //system("pause");
    return 0;
}
