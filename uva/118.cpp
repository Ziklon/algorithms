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
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
int N,M,x,y,K;
char io,seq[124];
int dx[]={0,-1,0,1};
int dy[]={1,0,-1,0};
int A[26];
bool grid[110][110];
char get(int n){
	if(n==0)return 'N';
	if(n==1)return 'W';
	if(n==2)return 'S';
	if(n==3)return 'E';
	
}
void solve(){
	scanf("%d %d\n",&N,&M);
	A['N'-'A']=0;
	A['W'-'A']=1;
	A['S'-'A']=2;	
	A['E'-'A']=3;
	
	fill(grid,0);
	
	
	while(scanf("%d %d %c\n",&x,&y,&io)==3){
		scanf("%s\n",seq);
		K=strlen(seq);
		int init=A[io-'A'];	
		//printf("%d %d %d %c\n",x,y,init,io);
		
		string lost="";
		REP(i,0,K){
			if(lost!="")break;			
			switch(seq[i]){
				case 'R':
					init=(init+1)%4;
					break;
				case 'L':
					init=(init+3)%4;
					break;
				case 'F':
					int xx=x+dx[init];
					int yy=y+dy[init];
					printf("%c %d %d %d %d %c\n",seq[i],x,y,xx,yy,get(init));					
					if(min(xx,yy)<0 || xx>M || yy>N){
						
							
								lost="LOST";
								break;
							
					}else{
						x=xx;
						y=yy;
					}					
					break;
			}
		}
		
		
		printf("%d %d %c",x,y,get(init));
		if(lost!="")printf(" %s",lost.c_str());
		printf("\n");
		//cout<<endl;
	}	
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}


