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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;


int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    printf("n e\n");
    printf("- -----------\n");
    double ans=0,fc=1;
    REP(i,0,10){
       if(i!=0)fc*=i;       
       ans+=(1/fc);
       printf("%d %.10f\n",i,ans); 
    }
      
    //system("pause");
    return 0;
}
