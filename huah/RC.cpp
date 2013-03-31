#include <iostream>
#include <vector>
#include <queue>
#include<cmath>
using namespace std;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int M,H,W,caso=1;
	int dx[4]={0,0,-1,1};
	int dy[4]={-1,1,0,0};	 
	cin>>M;
	while(M){
	  cin>>H>>W;
	  bool vis[W][H];
	  queue<pair<pair<int,int>,int> >que;
	  int xr,yr,xc,yc;
	  string mps[H];
	  memset(vis,0,sizeof(vis));
	  for(int i=0;i<H;i++)
	    cin>>mps[i];
	  for(int i=0;i<H;i++){
	    for(int j=0;j<W;j++){
			if(mps[i][j]=='R')
				xr=i,yr=j;
			if(mps[i][j]=='C')
				xc=i,yc=j;
		 }
	  }
	  que.push(make_pair(make_pair(xr,yr),0));
	  vis[xr][yr]=1;
	  int dev=-1;
	  while(!que.empty()){
	    pair<pair<int,int>,int >p=que.front();
	    que.pop();
	    if(p.first.first==xc && p.first.second==yc){
				dev=p.second;
				break;		 
		 }
		 for(int j=0;j<4;j++){
		 	int X=p.first.first+dx[j];
		 	int Y=p.first.second+dy[j];
		 	if(X>=0 && X<W && Y>=0 && Y<H &&!vis[X][Y] && mps[X][Y]!='#'){
				 vis[X][Y]=1;
				 que.push(make_pair(make_pair(X,Y),p.second+1));
			}
		 }
	  }
	  if(dev!=-1)
	  		printf("Caso #%d: %d\n",caso++,dev);
	  else
	  		printf("Caso #%d: FML\n",caso++);	  
	  M--;
	}
	
	
}
