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
//#include <cmath>
#include <stack>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
string data[1001];
int dis[1001][1001];
int a,b,x0,y0,x1,y1;
int di[8]={0,0,1,-1,1,-1,1,-1};
int dj[8]={1,-1,0,0,1,-1,-1,1};

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);

  while(scanf("%d %d\n",&a,&b)==2){
	if(a==0 && b==0)break;
	char line[b+2];
	for(int i=0;i<a;i++){
		scanf("%s\n",line);
		data[i]=line;
	}
	scanf("%d %d\n",&x0,&y0);
	scanf("%d %d\n",&x1,&y1);
	scanf("\n");
	x0--;y0--;x1--;y1--;
	deque<pair<int,int> >Q;
	memset(dis,-1,sizeof dis);
	Q.push_back(mp(x0,y0));
	int dev=0;	
	dis[x0][y0]=0;
	
	while(!Q.empty()){
		pair<int,int>  cur=Q.front();
		Q.pop_front();
		int x=cur.first;
		int y=cur.second;
		if(x==x1 && y==y1){
		       dev=cur.first;
		    	break;
		}  /*
		if(data[x][y]=='X'){
			stack<pair<int,int> > S;
			S.push(mp(x,y));
			while(!S.empty()){
				pair<int,int> aux=S.top();
				S.pop();
				int mx=aux.first;
				int my=aux.second;
				for(int h=0;h<8;h++){
					int mX=mx+di[h];
					int mY=my+dj[h];
					if(mX>=0 && mY>=0 && mX<a && mY<b&& data[mX][mY]=='X'){
						Q.push_front(mp(mX,mY));
						if((dis[mX][mY]==-1) || dis[mX][mY]<dis[x][y] && dis[mX][mY]!=-1)
							dis[mX][mY]=dis[x][y];
						S.push(mp(mX,mY));
					}	
				}	
			}	
		}    */
		for(int m=0;m<8;m++){
			int X=x+di[m];
			int Y=y+dj[m];
			if(X>=0 && Y>=0 && X<a && Y<b){
				if(dis[X][Y]==-1){
					dis[X][Y]=dis[x][y]+1;
					if(data[X][Y]=='.' ){
                        Q.push_back(make_pair(X,Y));
                        dis[X][Y]=dis[x][y]+1;
                    }else{
                        Q.push_front(make_pair(X,Y));
                        dis[X][Y]=dis[x][y];    
                    }
				}else{
							
					
				}
			}
		} 
	}
	cout<<dev<<endl;		
  }

  return 0;
}
