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
#define fill(x,i) memset(x,i,sizeof(x))
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;
long long toi(string s){istringstream is(s);long long x;is>>x;return x;}
string tos(long long t){stringstream st; st<<t;return st.str();}
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
vector<string>todo;
map<string,int>M;

vector<string>bfs(string& a,string& b,int& c){
	vector<string>dev;
	if(a.sz!=b.sz)return dev;
	vector<int>prev(c+5,0);
	vector<int>vis(c+5,0);
	vis[M[a]]=1;
	queue<int>Q;
	Q.push(M[a]);
	while(!Q.empty()){
		int cur=Q.front();
		Q.pop();
		string scur=todo[cur-1];
		if(scur==b){
			int p=cur;
			while(p>0){
				dev.push_back(todo[p-1]);
				p=prev[p];
			}
			return dev;	
		}
		for(int i=0;i<scur.sz;i++)
			for(char x='a';x<='z';x++){
				string aux=scur;
				aux[i]=x;
				int p=M[aux];
				if(p>0 && !vis[p]){
					vis[p]=1;
					Q.push(p);
					prev[p]=cur;
				}
			}
	}
	return dev;
}


int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   
   string line;
   int c=0,k;
   while(getline(cin,line)){
		if(line=="")break;
		todo.push_back(line);
	}
	k=0;
	while(getline(cin,line)){
		if(k>0)printf("\n");
		string a,b;
		stringstream ss(line);
		ss>>a>>b;
		M.clear();
		c=0;
		for(int i=0;i<todo.sz;i++){
			if(todo[i].sz==a.sz){
				M[todo[i]]=i+1;
				c++;				
			}
		}
		vector<string>dev=bfs(a,b,c);
		if(dev.sz==0)printf("No solution.\n");
		else{
			reverse(all(dev));
			for(int i=0;i<dev.sz;i++)printf("%s\n",dev[i].c_str());	
		}				
		k++;
	}
   return 0;
}
