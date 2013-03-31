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

bool complete(string& s, vector<string>&v){
	if(s.sz<2)return 0;
	string cad=s.substr(s.sz-2,2);
	string aux=cad,othe;
	reverse(all(aux));
	int p=s.sz;
	for(int i=0;i<v.sz;i++){
		othe=v[i].substr(0,2);
		if(othe==cad || othe==aux){
			s=s.substr(0,max(p-2,0))+v[i][2];	
			return 1;
		}
	}
	return 0;
}

bool cleani(string& s, vector<string>&v){
	if(s.sz<2)return 0;
	for(int i=0;i<v.sz;i++){
		int p=s.find(v[i][0]);
		int q=s.find(v[i][1]);
		if(min(p,q)>=0){
			if(p>q)
				swap(p,q);
			s=s.substr(q+1);
			return 1;
		}
	}
	return 0;
}


int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   int T;
   string aux,cur,a,b,c,res;
   cin>>T;
   for(int i=1;i<=T;i++){
		vector<string> vc,vd;
		int C,D,N;
		cin>>C;
		for(int j=0;j<C;j++){
			cin>>aux;
			vc.push_back(aux);
		}
		cin>>D;
		for(int j=0;j<D;j++){
			cin>>aux;
			vd.push_back(aux);
		}
		cin>>N>>cur;
		cur=cur.substr(0,N);
		res="";
		for(int j=0;j<cur.sz;j++){
			res=res+cur[j];
			if(!complete(res,vc))
				cleani(res,vd);
		}
		printf("Case #%d: [",i);
		stringstream ss;
		for(int j=0;j<res.sz;j++)
			ss<<res[j]<<", ";
		cur=ss.str();
		if(cur.sz>1)cur=cur.substr(0,cur.sz-2);
		printf("%s]\n",cur.c_str());
	}
   return 0;
}
