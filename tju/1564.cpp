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
int board[101][101],N,dev,aux;
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  cin>>N;
  dev=0;
  for(int i=0;i<N;i++)
  	for(int j=0;j<N;j++)
  		scanf("%d",&board[i][j]);
  for(int i=1;i<=N;i++)
  	for(int j=1;j<=N;j++){
		for(int x=0;x<N;x++)
  			for(int y=0;y<N;y++){
				if(x+i>N|| y+j>N)break;
				aux=0;
				for(int p=x;p<x+i;p++)
					for(int q=y;q<y+j;q++)
						aux+=board[p][q];
				dev=max(dev,aux);
			}
	}
	cout<<dev<<endl;
    system("pause");
  return 0;
}
