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
int N,dev;
string aux;
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  while(cin>>N){
  	dev=0;
	map<string,bool>M;
	M["NOEL"]=1;
	queue<pair<string,int> >Q;
	Q.push(mp("NOEL",0));
	for(int i=0;i<N;i++){
		cin>>aux;
		while(!Q.empty()){
			pair<string,int> adj=Q.front();
			Q.pop();
			if(adj.first==aux){
				dev+=adj.second;
				break;
			}			
			for(int i=0;i<adj.first.sz;i++){
				char rg=adj.first[i];
				char c='A'+((26+rg-'A'+1)%26);
				char k='A'+((26+rg-'A'-1)%26);
				string test=adj.first;
				test[i]=c;
				cout<<test<<endl;
				if(M[test]==0){
					Q.push(mp(test,adj.second+1));
					M[test]=1;
				}
				test[i]=k;
				if(M[test]==0){ 				
					Q.push(mp(test,adj.second+1));
					M[test]=1;					 
				}
			}
		}
		while(!Q.empty())
			Q.pop();
		Q.push(mp(aux,0));
		M.clear();
		M[aux]=1;			
	}
	cout<<dev<<endl;
	
  }
  //system("pause");
  return 0;
}
