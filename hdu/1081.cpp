#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <functional>
#include <numeric>
using namespace std;
#define all(V) (V).begin(),(V).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a, long long b){return a*(b/gcd(a,b));}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int dm=0;
    cin>>dm;
    int mm[dm][dm];
    for(int i=0;i<dm;i++)
      for(int j=0;j<dm;j++)
        cin>>mm[i][j];
    
    
    return 0;
}
