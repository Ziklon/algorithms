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
string table[201];
bool visit[201][201];
int N;
int di[6]={-1,0,1,-1,0,1};
int dj[6]={-1,-1,0,0,1,1};
int dfs(int x, int y, char c){	
	if(c=='w' && y==N-1)return 1;
	if(c=='b' && x==N-1)return 1;
	int dev=0;
	visit[x][y]=1;	
	for(int i=0;i<6;i++){
		int X=x+di[i];
		int Y=y+dj[i];
		if(X>=0 && Y>=0 && X<N && Y<N && !visit[X][Y] && table[X][Y]==c){			
			dev+=dfs(X,Y,c); 				
		}	
	}
	return dev;
}

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int nc=1;
  while(cin>>N){
	if(N==0)break;
	char line[N+2];
	memset(visit,0,sizeof(visit));
	for(int i=0;i<N;i++){
		scanf("%s\n",line);
		table[i]=line;	
	}
	int W=0,B=0;
	for(int i=0;i<N;i++){
	   B+=dfs(0,i,'b'); 	   
	   W+=dfs(i,0,'w'); 	   
	}
	if(B<1)
		cout<<nc<<" "<<"W"<<endl;
	else
		cout<<nc<<" "<<"B"<<endl;
	nc++;			
  
  }
  //system("pause");
  return 0;
}
