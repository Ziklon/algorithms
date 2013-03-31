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
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

int dp[101][1000001],N,C,aux;
vector<int> v;
int go(int p, int c){
	if(c<0)return 1<<30;
	if(c==0)return 0;
	if(p>=N)return 1<<30;
	int& ref=dp[p][c];
	if(ref!=-1)return ref;
	ref=1<<30;
	for(int i=p;i<N;i++){
		ref=min(ref,1+go(i,c-v[i]));
	}
	return ref;
}
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  mem(dp,-1);
  while(cin>>N){
	v.clear();
	 for(int i=0;i<N;i++){
	 	cin>>aux;
	 	v.push_back(aux);
	 }
	 cin>>C;
	 sort(rall(v));
	 int dev=go(0,C);
	 //cout<<dev<<endl;
	 
	 if(dev<(1<<30)){
		 vector<int> res;
		 for(int i=0;i<v.sz;i++){
			while(go(0,C-v[i])==dev-1){
				C-=v[i];
				dev--;
				res.push_back(v[i]);
			}	
		 }
		 for(int i=0;i+1<res.sz;i++){
			cout<<res[i]<<",";
		}
		cout<<res[res.sz-1]<<endl;
	}else
		cout<<-1<<endl;		
	}
	
	system("pause");
  return 0;
}
