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
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}

int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   int n;
   string line;
   cin>>n;
   for(int i=0;i<n;i++){		
		int A=1,B=1,X,dev=0,nc;
		int T=0,R=0,aux;
		char cur;
		cin>>nc;
		for(int j=0;j<nc;j++){
			cin>>cur>>X;
			if(cur=='O'){
				aux=max(0,abs(A-X)-R)+1;
				dev+=aux;
				T+=aux;			
				R=0;
				A=X;
			}else{
				aux=max(0,abs(B-X)-T)+1;
				dev+=aux;
				R+=aux;			
				T=0;
				B=X;
			}
		}
		printf("Case #%d: %d\n",(i+1),dev);
	}
   return 0;
}
