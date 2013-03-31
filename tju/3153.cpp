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

int dp[501][1001][500];
int N,A,nC;
int go(int p, int k, int c){
	if(p/2>N || (2*k)>N)return 0;
	if(2*k==N)return 1;
	if(k>0 && (N-(2*k))>0)return 1;
	int& ref=dp[p][k][c];
	if(ref!=-1)return ref;
	ref=0;
	ref=go(p,p+k,c+1)+go(p+1,k,c);
	return ref;
}

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  
  A=1;
  cin>>nC;
  while(nC--){
		mem(dp,-1);
		cin>>N;
		cout<<A<<" "<<go(1,0,0)<<endl;
		A++;  
  }
  //system("pause");
  return 0;
}
