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
using namespace std;
bool data[101][101],vis[101];
int N,aux,p,q,dev;
string line;
void dfs(int x,int c){
	vis[x]=1;
	int dev=0;
	for(int i=1;i<=N;i++){
		if(i==c)continue;
		if(data[i][x] &&!vis[i])
			dfs(i,c);	
	}
}

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  while(1){
  	scanf("%d\n",&N);
  	memset(data,0,sizeof data);
  	memset(vis,0,sizeof vis);
  	dev=0;
  	if(N==0)break;
  	while(getline(cin,line)){	  	
		istringstream is(line);
		is>>p;
		if(p==0)break;
		while(is>>q)
		   data[p][q]=data[q][p]=1;
	}
	aux=0;
	for(int i=1;i<=N;i++)
		if(!vis[i]){
			dfs(i,0);
			aux++;
		}
	for(int i=1;i<=N;i++){
		memset(vis,0,sizeof vis);
		int x=0;
		for(int j=1;j<=N;j++)
			if(j!=i && !vis[j]){
				dfs(j,i);
				x++;
			}
			
		if(x!=aux)
			dev++;
	}
	printf("%d\n",dev);
	}	
  

  return 0;
}
