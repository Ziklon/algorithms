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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
typedef long long ll;
int n,k;
string M[2];
int dis[2][100005];
struct Node{
	int x,y,d;
	Node(int a, int b, int c){
		x=a;y=b;d=c;	
	}
	bool operator < (const Node &p) const{
		if(p.d==d)return y>p.y;
		return d>p.d;
	}
};



int main(){	
	cin>>n>>k;
	cin>>M[0]>>M[1];

	priority_queue<Node>Q;
	Q.push(Node(0,0,0));
	for(int i=0;i<2;i++)
		for(int j=0;j<n;j++)
			dis[i][j]=INF;
	
	dis[0][0]=1;
	
	bool ans=0;
	while(!Q.empty()){
		Node cur=Q.top();Q.pop();
		if(cur.y>=n){
			ans=1;
			break;	
		}
		if(M[cur.x][cur.y]=='X')continue;
		if(cur.y+k>=n || cur.y+1>=n){
			ans=1;
			break;
		}		
		if(dis[cur.x][cur.y+1]>(cur.d+1)){
			dis[cur.x][cur.y+1]=cur.d+1;
			Q.push(Node(cur.x,cur.y+1,cur.d+1));	
		}
		if(cur.x==1){
			if(dis[0][cur.y+k]>(cur.d+1)){
				dis[0][cur.y+k]=cur.d+1;
				Q.push(Node(0,cur.y+k,cur.d+1));
			}				
		}else{
			if(dis[1][cur.y+k]>(cur.d+1)){
				dis[1][cur.y+k]=cur.d+1;
				Q.push(Node(1,cur.y+k,cur.d+1));
			}
		}		
		if(cur.y>=cur.d+2 && dis[cur.x][cur.y-1]>(cur.d+1)){
			dis[cur.x][cur.y-1]=cur.d+1;
			Q.push(Node(cur.x,cur.y-1,cur.d+1));
		}
	}
	
	if(ans)puts("YES");
	else puts("NO");
}

