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
vector<string> gets(string s){
	int x;
	node:
	for(int i=0;i<s.sz;i++){
		bool a=0,b=0;
		for(int j=i-1;j>=0;j--){
			if(s[j]==')')break;
			if(s[j]=='('){
				a=1;
				break;
			}
		}
		for(int j=i+1;j<s.sz;j++){
			if(s[j]=='(')break;
			if(s[j]==')'){
				a=1;
				break;
			}
		}
		if(!a && !b){
			s=s.substr(0,i)+'('+s[i]+')'+s.substr(i+1);
			goto node;
		}		
	}
	vector<string> dev;
	for(int i=0;i<s.sz;i++){
		if(s[i]=='(')x=i;
		if(s[i]==')'){
			string aux=s.substr(x+1,i-x-1);
			dev.push_back(aux);
		}
	}
	return dev;
}

int main(){
   freopen("in.txt","r",stdin);
   freopen("out.txt","w",stdout);
   int L,D,N;
  
   cin>>L>>D>>N;
   vector<string> words(D),aux(N);
   for(int i=0;i<D;i++)cin>>words[i];
   for(int i=0;i<N;i++)cin>>aux[i];
   vector<vector<string> >patter;
   for(int i=0;i<aux.sz;i++)
		patter.push_back(gets(aux[i]));
	
	for(int i=0;i<patter.sz;i++){
		int res=0;
		for(int j=0;j<words.sz;j++){
			bool ok=1;
			for(int k=0;k<words[j].sz;k++){				
				if(patter[i][k].find(string(1,words[j][k]))==-1)
					ok=0;
			}
			res+=ok;
		}
		printf("Case #%d: %d\n",(i+1),res);
	}   
   
   
   return 0;
}
