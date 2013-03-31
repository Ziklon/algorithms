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
int di[8]={1,-1,0,0,1,-1,1,-1};
int dj[8]={0,0,1,-1,1,1,-1,-1};
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int N,M,L;
  string line;
  cin>>N>>M>>L;
  string board[N+2];
  for(int i=0;i<N;i++){
	cin>>line;
	board[i]=line.substr(0,M);
  }
  for(int x=0;x<L;x++){
		vector<pair<char,pair<int,int> > > vp;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				int c=0;
				for(int a=0;a<8;a++){
					int X=i+di[a];
					int Y=j+dj[a];
					if(X>=0 && Y>=0 && X<N && Y<M && board[X][Y]=='*')
						c++;
				}
				if(board[i][j]=='*' && c!=2 && c!=3)
					vp.pb(mp('.',mp(i,j)));
				if(board[i][j]=='.' && c==3)
					vp.pb(mp('*',mp(i,j)));	
			}	
		}
		for(int i=0;i<vp.sz;i++)
			board[vp[i].second.first][vp[i].second.second]=vp[i].first;
  }
  
  for(int i=0;i<N;i++)
  	printf("%s\n",board[i].c_str());	
  	
  return 0;
}
