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


short memo[1000001],dev;

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int dev;
    int n;
    mem(memo,-1);
	memo[0]=7;
	memo[1]=11;
	for(int i=2;i<=1000000;i++)
		memo[i]=(memo[i-1]+memo[i-2])%3;	
    while(cin>>n){
      dev=memo[n];     
      if(dev==0)printf("yes\n");
      else printf("no\n");
    }    
    return 0;
}
