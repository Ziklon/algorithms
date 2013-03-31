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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
bool isPrime(long long n){
	for(int i=2;i*i<=n;i++)if(n%i==0)return 0;
	return 1;
}

int main(){
  //freopen("costo.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  long long peki=-1;
  int n=7;
  do{
	 vector<int> v;
	  for(int i=n;i>=1;i--)v.push_back(i);
	  n--;
	  long long num=0;
	  do{
		num=0;
		REP(i,0,v.sz)num=(num*10LL)+(v[i]);
		if(isPrime(num)){
			peki=num;
			break;
		}
	  }while(prev_permutation(all(v)));
  }while(peki==-1);
  
  
  cout<<peki<<endl;
  return 0;
}
