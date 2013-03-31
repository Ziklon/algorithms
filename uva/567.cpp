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
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
typedef long long ll;
bool data[21][21];
int nC;
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  nC=1;
  int n,m;
  while(scanf("%d",&n)==1){
	memset(data,0,sizeof(data));
	for(int j=0;j<n;j++){
			m=GI;
			data[1][m]=1;
			data[m][1]=1;			
	}
    for(int i=2;i<=19;i++){
		n=GI;
		for(int j=0;j<n;j++){
			m=GI;
			data[i][m]=1;
			data[m][i]=1;			
		}
	}
	int N=GI,a,b,dev;
	printf("Test Set #%d\n",nC++);
	for(int i=0;i<N;i++){
		a=GI;
		b=GI;
		queue<int>Q;
		vector<int>dis(21,0);
		vector<bool>vist(21,0);
		Q.push(a);
		while(!Q.empty()){
			int cur=Q.front();
			Q.pop();
			if(cur==b)break;
			for(int j=0;j<21;j++){
				if(data[cur][j] && !vist[j]){
					vist[j]=1;
					Q.push(j);
					dis[j]=dis[cur]+1;
				}
			}			
		}
		printf("%2d to %2d: %d\n",a,b,dis[b]);
		
	}
	printf("\n");
  }
  return 0;
}
