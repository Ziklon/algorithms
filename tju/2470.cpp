#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;
int w,h,n;
int di[4]={0,-1,0,1};
int dj[4]={1,0,-1,0};
string adj[105];
bool vis[105][105][6];
struct node{
   int x,y,d,c;
   node(int _x, int _y, int _c, int _d){
      x=_x;
      y=_y;
      d=_d;
      c=_c;  
   }     
};
bool check(int x, int y){
	if(min(x,y)<0)return 0;
	if(x>=h || y>=w)return 0;
	return 1;
}

int bfs(int xs, int ys, int xf, int yf){
	queue<node>Q;
    memset(vis,0,sizeof vis);
    Q.push(node(xs,ys,0,1));
	vis[xs][ys][1]=1;
        
    while(!Q.empty()){
        node cur=Q.front();
        Q.pop();
		//cout<<cur.x<<" "<<cur.y<<" "<<cur.d<<endl;
        if(cur.x==xf && cur.y==yf)return cur.c;   
		int X=cur.x+di[cur.d];
		int Y=cur.y+dj[cur.d];
		if(check(X,Y) && adj[X][Y]!='#' && !vis[X][Y][cur.d]){
			Q.push(node(X,Y,cur.c+1,cur.d));
			vis[X][Y][cur.d]=1;
		}
		int D[2]={(cur.d+1)%4,(cur.d-1+4)%4};
		for(int i=0;i<2;i++){
			if(!vis[cur.x][cur.y][D[i]]){
				Q.push(node(cur.x,cur.y,cur.c+1,D[i]));
				vis[cur.x][cur.y][D[i]]=1;
			}
		}
    }
	return -1;

}

int main(){
	//freopen("in.txt","r",stdin);
   
   cin>>n;
   while(n--){
        cin>>h>>w;
        int xs=-1,ys,xf=-1,yf;
        for(int i=0;i<h;i++)cin>>adj[i];
		
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++){
				if(adj[i][j]=='S'){
                    xs=i;
                    ys=j;
                }
				if(adj[i][j]=='T'){
                    xf=i;
                    yf=j;
                }
			}
                    
		cout<<bfs(xs,ys,xf,yf)<<endl;
   }
   return 0;
             


}
