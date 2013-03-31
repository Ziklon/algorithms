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
string a,b;
bool dat[677][677];
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n,top;
  bool aaa=0;
  while(cin>>n){
  	map<string,int>M;
  	vector<string> vs;
  	vs.pb("---------");
  	if(aaa)printf("\n");
  	aaa=1;
  	top=1;
  	memset(dat,0,sizeof dat);
  	for(int i=0;i<n;i++){
	   cin>>a>>b;
	   if(M[a]==0){
			vs.pb(a);
			M[a]=top++;
		}
	   if(M[b]==0){
			vs.pb(b);
			M[b]=top++;
			
		}
	   dat[M[a]][M[b]]=1;
	   dat[M[b]][M[a]]=1;	   
	}
	cin>>a>>b;
	if(M[a]==0){
		vs.pb(a);
		M[a]=top++;
	}
	if(M[b]==0){
		vs.pb(b);
		M[b]=top++;
	}
	int start=M[a];
	int end=M[b];
	queue<int>Q;
	vector<bool>vis(top+1,0);
	vector<int>parent(top+1,0);
	Q.push(start);
	vis[start]=1;
	bool ok=0;
	while(!Q.empty()){
       int cur=Q.front();
       Q.pop();
       if(cur==end){
			ok=1;
			break;	
	   }
	   for(int j=1;j<=top;j++){
	   	 if(dat[cur][j] && !vis[j]){
		  	Q.push(j);
		  	parent[j]=cur;
		  	vis[j]=1;
		 }
	   }       
	}
	if(ok){
		vector<int> v;
		while(end!=0){
			v.pb(end);
			end=parent[end];
		}
		reverse(all(v));
		for(int i=0;i+1<v.sz;i++)
			printf("%s %s\n",vs[v[i]].c_str(),vs[v[i+1]].c_str());		
	}else
		printf("No route\n");
	
  }

  return 0;
}
