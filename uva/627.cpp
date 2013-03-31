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
#define GI ({int _t; scanf("%d", &_t); _t;})
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
typedef long long ll;
bool data[301][301];
int n,top,id,nlk,net,c,start,end;
string line;
char cad;
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  while(cin>>n){
	  cout<<"-----"<<endl;
	  memset(data,0,sizeof data);
	  for(int i=0;i<n;i++){
	     cin>>id; 	     
	     getline(cin,line);
	     istringstream is(line);
	     while(is>>cad>>net){
		   data[id][net]=1;
		 }
	  }
	  cin>>c;
	  for(int i=0;i<c;i++){
	  	 cin>>start>>end;
	  	 vector<bool>vis(n+1,0);
	  	 bool ok=0;
	  	 vector<int>father(n+1,-1);
	  	 queue<int>Q;
	  	 Q.push(start);
	  	 vis[start]=1;
	  	 while(!Q.empty()){
		    int cur=Q.front();
		    Q.pop();
		    if(cur==end){
				ok=1;
				break;
			}
		    for(int j=1;j<=n;j++){
				if(!vis[j] && data[cur][j]){
					vis[j]=1;
					Q.push(j);
					father[j]=cur;
				}
			}
		 }
			 if(!ok)
			 	cout<<"connection impossible"<<endl;
			else{
			 vector<int> path;
			 path.pb(end);
			 while(father[end]!=-1){
			 	path.pb(father[end]);
			 	end=father[end];
			 }
			 
			 reverse(all(path));
			 cout<<path[0];
			 for(int j=1;j<path.sz;j++)
			     cout<<" "<<path[j];
			cout<<endl;
		}	  	 
	  }	
	  		
  
  }
  return 0;
}
