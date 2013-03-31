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


int N,nC,a,b,ubi,dev,A,B,C;
bool adj[32][32],visit[32];
map<string,int> M;
string XY,MN;
int main(){
  //freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
  nC=1;
  cin>>N;
  printf("SHIPPING ROUTES OUTPUT\n\n");
  while(N--){
  	printf("DATA SET  %d\n\n",nC++);
	cin>>A>>B>>C;   	
	ubi=0;
	M.clear();
	for(int i=0;i<A;i++){
	    cin>>XY;
	    M[XY]=ubi++;
	}
  	memset(adj,0,sizeof adj);
  	for(int i=0;i<B;i++){
		cin>>XY>>MN;
		adj[M[XY]][M[MN]]=1;
		adj[M[MN]][M[XY]]=1;
	}
	for(int i=0;i<C;i++){
		cin>>B>>XY>>MN;
	   memset(visit,0,sizeof visit);
	   queue<pair<int,int> >Q;
	   Q.push(mp(M[XY],0));
	  // cout<<B*100<<endl;
	   visit[M[XY]]=1;
	   dev=-1;  
	   while(!Q.empty()){
	   	 	pair<int,int> cur=Q.front();
	   	 	Q.pop();
	   	 	if(M[MN]==cur.first){
				dev=cur.second;
				break;
			}
	   	 	for(int i=0;i<ubi;i++){
				if(adj[cur.first][i] && !visit[i]){
					Q.push(mp(i,cur.second+1));
					visit[i]=1;
				}
			}
	   }
	   if(dev!=-1)dev=(dev*B)*100;
	  if(dev==-1)printf("NO SHIPMENT POSSIBLE\n");
	   else printf("$%d\n",dev);
	}
	printf("\n");
  }
  printf("END OF OUTPUT\n");
  return 0;
}
