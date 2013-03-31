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
int A[1000];
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int N;
    scanf("%d",&N);
    REP(i,0,N)scanf("%d",&A[i]);
    int dif=1<<29;
    int res=0;
    int i,j,s;
    for(i=0;i<N;i++){
        j=(i+1)%N;
        s=abs(A[i]-A[j]);
        if(s<dif){
            res=i;
            dif=s;
        }
    }
    j=(res+1)%N;
    res++;
    j++;
    cout<<res<<" "<<j<<endl;
    //system("pause");
    return 0;
}
