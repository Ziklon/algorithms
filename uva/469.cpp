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
string data[101];
int N,nC,A,B,W,H;
string aux;
int di[8]={0,0,1,-1,1,-1,1,-1};
int dj[8]={1,-1,0,0,1,-1,-1,1};
bool visit[101][101];
int dfs(int x, int y){
   visit[x][y]=1;
   int dev=0; 
   for(int i=0;i<8;i++){
		int X=di[i]+x;
		int Y=dj[i]+y;
		if(X>=0 && Y>=0 && X<W && Y<H && !visit[X][Y] && data[X][Y]=='W')
			dev+=dfs(X,Y)+1;
	}
	return dev;
}


int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  scanf("%d\n",&N);
  while(N--){
  	scanf("\n");
  	nC=0;
  	W=0;
  	bool ok=1;
  	while(getline(cin,aux)){
		if(aux=="")break;
		if(aux.find(" ")!=-1)ok=0;
		if(ok){
			data[nC++]=aux;	
			W++;
			H=aux.sz;	
		}else{
			istringstream ss(aux);
			ss>>A>>B;
			A--;
			B--;
			memset(visit,0,sizeof visit);
			int dev=dfs(A,B);
			if(data[A][B]=='W')dev++;
			cout<<dev<<endl;		
		} 		
	}
	if(N)cout<<endl;

	
  }
  //system("pause");
  return 0;
}
