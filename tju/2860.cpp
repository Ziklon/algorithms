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
int dp[1000000][31][3],A[1000000];
int N;
int go(int p, int m, int ok){
	if(ok>2)return -1<<30;
	if(p>=N && ok<2)return -1<<30;
	if(p>=N && ok>=2)return 0;
	int&ref = dp[p][m][ok];
	if(ref!=-1)return ref;
	ref=0;
	ref=max( go(p+1,m,ok+1)  )	
}

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  
  system("pause");
  return 0;
}
