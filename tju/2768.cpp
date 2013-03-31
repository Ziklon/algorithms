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
vector<int> coins;
int N,C,aux;

int dp[11][1001];

int go(int p, int c){
	if(c==0)return 0;
	if(c<0 || p>=N)return 1<<30;	
	int& ref=dp[p][c];
	if(ref!=-1)return ref;
	ref=0;
	ref=min(go(p+1,c),1+go(p,c-coins[p]));
	return ref;
}



int main(){

	//freopen("D:/wilber/in.txt","r",stdin);
	//freopen("D:/wilber/out.txt","w",stdout);
	cin>>C>>N;
	coins.clear();
	memset(dp,-1,sizeof dp);
	for(int i=0;i<N;i++){
		cin>>aux;
		coins.push_back(aux);
	}
	sort(all(coins));
	cout<<go(0,C)<<endl;
	return 0;

}