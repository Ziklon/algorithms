/*
ID: winftc2
PROG: proximity
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
using namespace std;

int main(){
    //freopen("in.txt","r",stdin);
    freopen("proximity.in","r",stdin);
    freopen("proximity.out","w",stdout);
    int N,K,tmp;
    scanf("%d %d",&N,&K);
    int ans=0;
    map<int,int> M;
    for(int i=0;i<N;i++){
        scanf("%d",&tmp);
        if(M.count(tmp)){
            int mm=tmp-M[tmp];
            if(mm<=K && ans<tmp)ans=tmp;
        }
        M[tmp]=i;
    }
    printf("%d\n",ans);
    return 0;
}
