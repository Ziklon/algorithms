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
bool orden(pair<int,int> p, pair<int,int> q){
	if(p.second!=q.second)
		return p.second>q.second;
	return p.first<q.first;	
}
bool orden2(pair<int,int> p, pair<int,int> q){
	if(p.first!=q.first)
		return p.first>q.first;
	return p.second>q.second;	
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int nC,N,aux;
  scanf("%d",&nC);
  long long dev=0,res=0;
  while(nC--){
  	  scanf("%d",&N);
	  vector<pair<int,int> > vp(N);
	  for(int i=0;i<N;i++){
	  	scanf("%d",&aux);
	  	vp[i].first=aux;
	  }
	  for(int i=0;i<N;i++){
	  	scanf("%d",&aux);
	  	vp[i].second=aux;
	  }
	  sort(all(vp),orden);
	  aux=0;
	  for(int i=0;i<vp.sz;i++){
			aux+=vp[i].first;
			dev+=(vp[i].second*aux);
	  }
	  aux=0;
	  for(int i=0;i<vp.sz;i++){
			aux+=vp[i].first;
			res+=(vp[i].second*aux);
	  }
	  cout<<min(res,dev)<<endl;	
  	
  }
  //system("pause");
  return 0;
}
