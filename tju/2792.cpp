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

int main(){

  int N,K,n,X=1;
  N=GI;
  K=GI;
  vector<int> v;
  map<int,int>M;
  for(int i=0;i<N;i++){
  	n=GI;
  	v.pb(X);
  	M[X]=n;
  	X++;
  }
  sort(all(v));
  int dev=0;
  cout<<"Hello World"<<endl;
  do{
		
		int mx=0;
		for(int i=2;i<=X;i++)
			mx=max(abs(M[v[i]]-M[v[i-1]]),mx);
		if(v.sz>1)
			mx=max(mx,abs(M[v[X]]-M[v[1]]));
		if(mx<=K){
			dev++;		
		}
		for(int i=0;i<v.sz;i++)
			cerr<<v[i]<<" ";
		cerr<<endl;			
	}while(next_permutation(v.begin()+1,v.end()));
  cout<<dev<<endl;
  return 0;
}
