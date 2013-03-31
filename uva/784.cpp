#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define pb push_back
#define mp make_pair
#define mem(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define f(i,n) for(int (i)=0;i<(int)(n);(i)++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
int di[8]={0,0,1,-1,1,-1,1,-1};
int dj[8]={1,-1,0,0,1,-1,-1,1};
string data[101],line;
bool visit[101][101];
int nC,i,W,H;

void dfs(int x, int y){
	visit[x][y]=1;
	data[x][y]='#';	
	for(int i=0;i<8;i++){
	   int X=di[i]+x;
	   int Y=dj[i]+y;
	   if(X>=0 && Y>=0 && X<W && Y<H && !visit[X][Y] && data[X][Y]==' ')			
			dfs(X,Y);
	}	
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  scanf("%d\n",&nC);
  while(nC--){
		W=0;
		H=0;
		i=0;
		memset(visit,0,sizeof visit);
	 string out="";	
	  for(int j=0;j<101;j++)
	  	data[j++]=string(100,'a');
	  while(getline(cin,line)){		
	  	if(line.find("_")!=-1){
		  out=line;
		  break;
		}
	  	data[i++]=line;
	  	H=max(H,(int)line.sz);
	  	W++;
	  }
	  for(i=0;i<W;i++)
	  	for(int j=0;j<H;j++)
		  if(data[i][j]=='*')
		  		dfs(i,j);
		for(i=0;i<W;i++)
			printf("%s\n",data[i].c_str());
		printf("%s\n",out.c_str());	
	}	
  //system("pause");
  return 0;
}
