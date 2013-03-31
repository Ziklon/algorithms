#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <cmath>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;

struct  Node{
	int to, pass;
	Node(int _to,int _pass){
		to=_to;
		pass=_pass;
	}
};


vector<Node> G [101];
int V [101];
int path [101];
int solve(int c,int r,int fromC,int toC,int passenger){
	V[1]=10000;
	path[1]=1;
	for(int i=2;i<=c;i++){
		V[i]=0;
		path[i]=0;
	}
	for(int i=1;i<=c;i++){
	  for(int j=0;j<G[i].size();j++){
	    int _to=G[i][j].to;
		int _pass=G[i][j].pass;
		int m =max(V[_to],min(V[i],_pass));
		if(m!=V[_to]){
			V[_to]=m;
			if(path[i]==1){
				path[_to]=1;
			}else{
				path[_to]=0;
			}
		}else{
				path[i]=0;
			}
	  }
	}
	V[1]=0;
	for(int i=1;i<=c;i++){
		if(path[i]==1)
		cout<<i<<" - "<<path[i]<<" - "<<V[i]<<endl;
	}
	int numPass=V[toC]-1;
	int numTrips=(passenger%numPass==0)?passenger/numPass:(passenger/numPass)+1;
	return numTrips;
}

int main(){
	freopen("D:/inp.txt","r",stdin);
	int numCity;
	int road;
	cin>>numCity;
	cin>>road;
	int i=1;
	while(i<=road){
	int ci;
	int to;
	int pas;
	cin>>ci;
	cin>>to;
	cin>>pas;
	G[ci].push_back(Node(to,pas));
	i++;
	}
	int fromC;
	int toC;
	int passenger;
	cin>>fromC;
	cin>>toC;
	cin>>passenger;
	int res;
	res=solve(numCity,road,fromC,toC,passenger);
	cout<<"RESULTADO ES : "<<res<<endl;
	return 0;
}
