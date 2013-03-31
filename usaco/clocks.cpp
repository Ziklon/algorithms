/*
ID: winftc2
PROG: clocks
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

string Mov[9]={"ABDE","ABC","BCEF","ADG","BDEFH","CFI",
	"DEGH","GHI","EFHI",};
	


int get(int mask,int from){
	from*=2;
	int to=from+1;
	int num=((1<<from)&mask)>>from;
	num|=((1<<to)&mask)>>from;
	return num;
}
int put(int mask,int state, int from){
	int anding = (~0) ^ (3 << (2 * from));
	mask &= anding;
	mask |= state << 2 * from;
	return mask;
}
struct node{
	int mask;
	string mov;
	node(){}
	node(int _v, string s){
		mask=_v;
		mov=s;
	}
	
};

bool vis[2<<18];
int main(){
	//clock_t start = clock();
    freopen("in.txt","r",stdin);
	//freopen("clocks.out","w",stdout);
	vector<int> v(9);
	queue<node>Q;
	int num;
	int nstart=0;
	int nend=(1<<18)-1;
    REP(i,0,9){
		scanf("%d",&num);
		num/=3;
		num--;
		nstart=put(nstart,num,i);
	}
	fill(vis,0);
	vis[nstart]=1;
	Q.push(node(nstart,""));
	string ans="";
	while(!Q.empty()){
		node cur=Q.front();
		Q.pop();
		if(cur.mask==nend){			
			ans=cur.mov;
			break;
		}
		REP(i,0,9){
			
			int mask=cur.mask;
			REP(j,0,Mov[i].sz){
				num=(get(mask,Mov[i][j]-'A')+1)%4;
				mask=put(mask,num,Mov[i][j]-'A');			
			}	
			if(!vis[mask]){
				vis[mask]=1;
				Q.push(node(mask,cur.mov+string(1,'0'+i)));
			}
		}
	
	}
	vector<int> peki;
	
	for(int i=0;i<ans.sz;i++)
		peki.push_back(ans[i]-'0'+1);
	if(peki.sz>0)printf("%d",peki[0]);
	REP(i,1,peki.sz)printf(" %d",peki[i]);
	printf("\n");
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
    return 0;
}
