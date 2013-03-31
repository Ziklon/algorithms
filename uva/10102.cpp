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
   //freopen("in.txt","r",stdin);
   //freopen("out.txt","w",stdout);
   int n;
   string line;
   while(scanf("%d\n",&n)==1){
		string dat[n];	
		int dev=0;
		for(int i=0;i<n;i++){
			getline(cin,line);
			dat[i]=line;	
		}
		vector<pair<int,int> >a;
		vector<pair<int,int> >b;
		for(int i=0;i<n;i++)for(int j=0;j<n;j++){
				if(dat[i][j]=='1')a.push_back(make_pair(i,j));
				if(dat[i][j]=='3')b.push_back(make_pair(i,j));
			}
		
		for(int i=0;i<a.sz;i++){
			int aux=1<<30;
			for(int j=0;j<b.sz;j++)
				aux=min(aux,abs(b[j].first-a[i].first) + abs(b[j].second-a[i].first));
			dev=max(dev,aux);
		}
		printf("%d\n",dev);			
	}
   return 0;
}
