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
int adj[9][9];
string start,end;
int di[8]={-2,-1,1,2,2,1,-1,-2};
int dj[8]={1,2,2,1,-1,-2,-2,-1};
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  map<string,int>M;
  int zk=0;
  for(int i=0;i<8;i++)
  	for(int j=0;j<8;j++){
		string s=string(1,'a'+i)+string(1,'1'+j);
		M[s]=zk++;		
	}
	
  while(cin>>start>>end){
  	queue<pair<int,int> >Q;
  	vector<bool> visit(65,0);
  	Q.push(mp(M[start],0));
  	visit[M[start]]=1;
  	int dev=0;
  	while(!Q.empty()){
		pair<int,int>P=Q.front();
		Q.pop();
		if(M[end]==P.first){
			dev=P.second;
			break;
		}
		int x=(P.first/8);
		int y=(P.first%8);
		for(int i=0;i<8;i++){
			int X=x+di[i];
			int Y=y+dj[i];
			int lnl=(X*8) + Y;
			if(X>=0 && Y>=0 && X<8 && Y<8 && !visit[lnl]){
				Q.push(mp(lnl,P.second+1));
				visit[lnl]=1;
			}
		}
	}
	printf("To get from %s to %s takes %d knight moves.\n",start.c_str(),end.c_str(),dev);
  }
  //system("pause");
  return 0;
}
