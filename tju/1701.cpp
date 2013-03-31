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
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
int N,M,K,aux,sm,nC;
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  cin>>N;
  nC=1;
  while(N--){
  	cin>>M>>K;
  	vector<int> v;
  	sm=0;
  	for(int i=0;i<K;i++){
		cin>>aux;
		v.pb(aux);
	}
	sort(rall(v));
	printf("Scenario #%d:\n",nC++);
	int i;
	for(i=0;i<v.sz && sm<M;i++)sm+=v[i];
	if(sm>=M)
		printf("%d\n",i);
	else
		printf("impossible\n");
	printf("\n");
  }      
  //system("pause");
  return 0;
}
