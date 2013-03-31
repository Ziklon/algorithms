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
int N,top;
string start,end,line;
int dist[201][201],res;
inline int diff(string& s, string& k){
	int dev=0;
	if(s.sz!=k.sz)return 100;
	for(int i=0;i<s.sz;i++)
	    dev+=(s[i]!=k[i]);
	return dev;
}

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  
  scanf("%d",&N);
  getline(cin,line);
  while(N--){
	vector<string> dic;
	map<string,int>M;
	top=0;
	memset(dist,0,sizeof(dist));
  	while(getline(cin,start)){
		if(start=="*")break;
		if(M.find(start)==M.end()){
			M[start]=top++;
			dic.pb(start);
		}		
	}
	for(int i=0;i<top;i++){
		for(int j=i+1;j<top;j++){
			res=diff(dic[i],dic[j]);
			dist[i][j]=res;
			dist[j][i]=res;	
		}
	}
	scanf("\n");
	while(getline(cin,line)){
		if(line=="")break;
		stringstream ss(line);
		ss>>start>>end;
		vector<bool> visit(top,0);
		queue<pair<int,int> >Q;
		Q.push(mp(M[start],0));
		visit[M[start]]=1;
		int dev=0,fin=M[end];
		while(!Q.empty()){
			pair<int,int> P=Q.front();
			Q.pop();
			if(P.first==fin){
				dev=P.second;
				break;
			}
			int aux=P.first;
			for(int i=0;i<dic.sz;i++){
				if(visit[i]==0 && dist[i][aux]==1){
					Q.push(mp(i,P.second+1));
					visit[i]=1;
				}	
			}
			
		}
		printf("%s %s %d\n",start.c_str(),end.c_str(),dev);
	}
	if(N)printf("\n");
  }
  //system("pause");
  return 0;
}
