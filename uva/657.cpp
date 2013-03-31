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
int di[8]={0,0,1,-1,1,-1,1,-1};
int dj[8]={1,-1,0,0,1,-1,-1,1};
string data[55],res;
bool visit[55][55];
int W,H,nC;
int dfsA(int x, int y);

int dfs(int x, int y){
	visit[x][y]=1;
	for(int i=0;i<4;i++){
	    int X=di[i]+x;
	    int Y=dj[i]+y;
	    if(X>=0 && Y>=0 && X<W && Y<H && !visit[X][Y])
	    	dfs(X,Y);
	}
	return 0;
}

int dfsA(int x, int y){
	visit[x][y]=1;
	int dev=0;
	if(data[x][y]=='X'){
		dfs(x,y);
		dev++;	
	}
	for(int i=0;i<4;i++){
	    int X=di[i]+x;
	    int Y=dj[i]+y;
	    if(X>=0 && Y>=0 && X<W && Y<H && !visit[X][Y]){
			if(data[X][Y]=='X'){
				dfs(X,Y);
				dev++;				
			}
			if(data[X][Y]=='*')
				dev=dev+dfsA(X,Y);
		}
	    	
	}
	return dev;
}




int main(){
  
  nC=1;
  while(cin>>H>>W){
  	if(W==0 && H==0)break;
  	char line[H+2];
  	for(int i=0;i<W;i++){
		scanf("%s\n",line);
		data[i]=line;
	}
	int dev=0;
	memset(visit,0,sizeof visit);
	vector<int>v;
	for(int i=0;i<W;i++)
		for(int j=0;j<H;j++)
			if(!visit[i][j] && (data[i][j]=='*' || data[i][j]=='X'))
				v.pb(dfsA(i,j));
			
	
	sort(all(v));
	stringstream ss;
	for(int i=0;i<v.sz;i++){
	   ss<<" "<<v[i];
	}
	res=ss.str().substr(1);
	printf("Throw %d\n",nC++);
	printf("%s\n\n",res.c_str());
	
  }
  //system("pause");
  return 0;
}
