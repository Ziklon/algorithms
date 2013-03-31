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
#define MOD 10007
using namespace std;

int expoFast(int a, int n){
  if(n==1)return a;
  int ans=expoFast(a,n/2)%MOD;
  ans=(ans*ans)%MOD;
  if(n&1)
    ans=(ans*a)%MOD;
  return ans;  
}

int main(){
    
    cout<<expoFast(2,5)<<endl;
    system("pause");
    return 0;
}
