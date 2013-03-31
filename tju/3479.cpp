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


bool orden(pair<int,int>a,pair<int,int> b){
	return a.second<b.second;
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int nC;
  vector<pair<int,int> >vp;
  scanf("%d",&nC);
  vp.clear();
  for(int i=0;i<nC;i++){
	int a,b;
	scanf("%d %d",&a,&b);
	vp.pb(mp(a,b));			
  }
  sort(all(vp),orden);
  int J=0;
  int dev=1;
  for(int i=1;i<vp.sz;i++){
	if(vp[i].first>=vp[J].second){
		J=i;
		dev++;
	}	
  }
  cout<<dev<<endl;  
  //system("pause");
  return 0;
}
