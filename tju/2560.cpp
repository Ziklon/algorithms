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
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,j,k) for(int i=j;j<k;i++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

vector<vector<int> >v;
int dp[102][102];
int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};
int X,Y;
int go(int x, int y){
	if(x==X && Y==y)return 1;
	if(x<0 || y<0 || x>=v.sz || y>=v[0].sz)return 1<<30;
	if(v[x][y]==1)return 1<<30;
	int& ref=dp[x][y];
	if(ref!=-1)return ref;
	ref=1<<30;
	for(int i=0;i<4;i++){
		int p=x+di[i];
		int q=y+dj[i];
		ref=min(ref,go(p,q)+1);
	}
	return ref;
}
int main() {
	//freopen("/home/ziklon/in","r",stdin);
	int h,w,xs,ys;
	int t;
	cin>>t;
	while(t--){
		cin>>w>>h;
		v.clear();
		for(int i=0;i<h;i++){
			vector<int>aux(w);
			for(int j=0;j<w;j++)
				cin>>aux[j];
			v.push_back(aux);
		}
		cin>>ys>>xs;
		cin>>Y>>X;
		fill(dp,-1);
		cout<<go(xs,ys)<<endl;
	}
	return 0;
}

