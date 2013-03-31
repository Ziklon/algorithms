#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
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
#define sz size()
using namespace std;

string mapa[1001];
int dx[4]={-1,1,0,0};
int dy[4]={0,0,-1,1};
string dir="NSWE";
int main(){
	freopen("in.txt","r",stdin);
	int n,m,q;
	scanf("%d %d",&n,&m);
	char dc;
	vector<pair<char,pair<int,int> > >v;
	REP(i,0,n)
		cin>>mapa[i];
		
		REP(j,0,m){
			if(isalpha(mapa[i][j]))
				v.push_back(make_pair(map[i][j],make_pair(x,y)));
		}
	
	sort(all(v));
	scanf("%d",&q);
	
	int len;
	int p;
	vector<pair<char,int> >Q;
	REP(i,0,q){
		scanf("%c %d",&dc,&len);
		Q.push_back(make_pair(dc,len));
	}
	string peki="";
	REP(i,0,v.sz){
		bool ok=1;
		int X=v[i].second.first;
		int Y=v[i].second.first;
		REP(j,0,q){
			if(!ok)break;
			p=dir.find(Q[j].first);
			len=Q[j].second;
			X+=dx[p]*len;
			Y+=dy[p]*len;
			if(X>=0 && Y>=0 && X<n && Y<m && mapa[X][Y]!='#')
				continue;
			else 
				ok=0;
			
		}
		if(ok)peki+=v[i].first;
	}
	if(peki.sz>0)printf("%s\n",peki.c_str());
	else printf("no solution\n");
	return 0;
}