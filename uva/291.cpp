#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) (v).begin(),(v).end()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define sz size()
using namespace std;
int G[6];
bool vis[10];
pair<int,int> E[20];


void back(int node,int n){
	if(n==8){		
		return;
	}
	REP(i,0,8){
		if(!vis[i] && (E[i].first==node||E[i].second==node){
			vis[i]=1;
			if(E[i].first==node)
				back(E[i].second,n+1);
			else
				back(E[i].first,n+1);
			vis[i]=0;
		}
	}
}

int main(){
	freopen("in291.txt","r",stdin);
	fill(G,0);
	int N=0,x,y;
	while(cin>>x>>y){
		E[N++].make_pair(x,y);		
	}
	back(1,0);	
	return 0;
}