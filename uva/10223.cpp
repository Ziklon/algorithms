#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
int nT,m,n,x,y;
string table[10],path="IEHOVA#";
int dx[]={0,0,-1};
int dy[]={1,-1,0};
string getDir(int j){
	if(j==2)return "forth";
	if(j==1)return "left";
	return "right";
}
bool found;
void dfs(int x, int y, vector<string> v){

	if(v.sz==7){
		cout<<v[0];
		REP(j,1,v.sz)cout<<" "<<v[j];
		cout<<endl;
		found=1;
	}
	if(found)return;
	REP(j,0,3){
		int X=x+dx[j];
		int Y=y+dy[j];
		if(X>=0 && X<m&&Y>=0 && Y<n && path[v.sz]==table[X][Y]){
			vector<string> aux(all(v));
			aux.push_back(getDir(j));
			dfs(X,Y,aux);
		}
	}
}

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	cin>>nT;
	REP(i,0,nT){
		cin>>m>>n;
		REP(j,0,m)cin>>table[j];
		
		
		REP(j,0,m)REP(k,0,n)if(table[j][k]=='@'){
			x=j;
			y=k;
		}
		found=false;
		dfs(x,y,vector<string>());
		
	}
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
