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
long long L,H;
int getZeros(long long n){
	int dev=0;
	while(n){
		if(n%10==0)
			dev++;
		n/=10;
	}
	return dev;
}
long long dfs(long long n){
	if(n>H)return 0;
	long long dev=0;
	if(n>=L && n<=H)
		dev+=getZeros(n);
	for(int i=0;i<10;i++){
		dev+=dfs(n*10+ i);
	}
	return dev;
}
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  while(cin>>L>>H){
	if(min(L,H)<0)break;
  	cout<<dfs(1)<<endl;
  }
  //system("pause");
  return 0;
}
