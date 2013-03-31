#include <vector>
#include <map>
#include <set>
#include <queue>
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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define REP(i, a) FOR(i, 0, a)
#define GI ({int _t; scanf("%d", &_t); _t;})
#define DBGV(_v) { REP(_i, _v.size()) { cout << _v[_i] << "\t";} cout << endl;}

using namespace std;

int di[4]={0,0,1,-1};
int dj[4]={1,-1,0,0};
 string dat[301];
 bool vis[301][301];
 struct node{
	int x,y,c,n;
	node(int _x, int _y, int _c, int _n){
		x=_x;
		y=_y;
		c=_c;
		n=_n;
	}		
};
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout); 
  int n,w,h;
  GI=n;
  while(n--){
   	scanf("%d %d\n",&w,&h);
   	char line[h+2];
   	int xS=-1,yS=-1,xE=-1,yE=-1;
   	for(int i=0;i<w;i++){
		scanf("%s\n",line);
		dat[i]=line;
		if(xS==-1)
		for(int j=0;j<dat[i].sz;j++)
			if(dat[i][j]=='S'){
				xS=i;
				yS=j;
			}
		if(xE==-1)
		for(int j=0;j<dat[i].sz;j++)
			if(dat[i][j]=='E'){
				xE=i;
				yE=j;
			}
	}
	memset(vis,0,sizeof vis);
	queue<node>Q;
	Q.push_front(node(xS,yS,0,1));
	vis[xS][yS]=1;
	int dev=-1;
	while(!Q.empty()){
		node p=Q.front();
		if(p.x==xE && p.y==yE){
			 dev=p.c;
			 break;			 
		}
		for(int i=0;i<4;i++){
			int X=p.x+di[i]*p.n;
			int Y=p.y+dj[i]*p.n;
			if(X>=0 && Y>=0 && X<w && Y<h && !vis[X][Y]){
				Q.push(node(X,Y,abs(X-p.x)+abs(Y-p.y),p.n+1));
				vis[X][Y]=1;
			}
		}
		
	}
	if(dev!=-1)
	    cout<<dev<<endl;
	else
	    cout<<"NO"<<endl;
	   	
  }
  

  return 0;
}
