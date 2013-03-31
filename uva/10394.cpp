#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
typedef long long ll;
int n;
bool sieve[20000001];
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  vector<int>primes;
  
  memset(sieve,0,sizeof sieve);
  for(int i=2;i*i<=20000000;i++)
  	if(!sieve[i])
		for(int j=i*i;j<=20000000;j+=i)
	    	sieve[j]=1;
	    
  primes.pb(2);
   for(int j=3;j<=20000000;j+=2)
   			if(!sieve[j])
   				primes.pb(j);
  primes.push_back(0);
  vector<int>nprim;
  for(int i=0;i+1<primes.sz;i++){
	if(primes[i+1]-primes[i]==2)
		nprim.push_back(primes[i]);		
  } 
  while(cin>>n){
  	printf("(%d, %d)\n",nprim[n-1],nprim[n-1]+2);
  }  
  return 0;
}
