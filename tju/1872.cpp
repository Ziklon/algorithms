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
long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a,long long b){return a*(b/gcd(a,b));}
string express;
long long n,A,B;
long long getMin(){
	long long dev=0,llvar;
	string aux=express,s;
	for(int i=0;i<aux.sz;i++)
		if(aux[i]=='+')
			aux[i]=' ';
	vector<string> vs;
	stringstream ss(aux);
	while(ss>>s)vs.pb(s);
	for(int i=0;i<vs.sz;i++){
		string tmp=vs[i];
		llvar=1;
		for(int i=0;i<tmp.sz;i++)
			if(tmp[i]=='*')
				tmp[i]=' ';
		
		istringstream is(tmp);
		while(is>>n)llvar=llvar*n;
		dev+=llvar;		
	}
	return dev;
}

long long getMax(){
	long long dev=1,llvar;
	string aux=express,s;
	for(int i=0;i<aux.sz;i++)
		if(aux[i]=='*')
			aux[i]=' ';
	vector<string> vs;
	stringstream ss(aux);
	while(ss>>s) vs.pb(s);
	for(int i=0;i<vs.sz;i++){
		string tmp=vs[i];
		n=1;
		llvar=0;
		for(int i=0;i<tmp.sz;i++)
			if(tmp[i]=='+')
				tmp[i]=' ';
		istringstream is(tmp);
		while(is>>n)llvar+=n;
		dev*=llvar;		
	}
	return dev;
}
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int nC;
  cin>>nC;
  while(nC--){
	cin>>express;
	A=getMax();
	B=getMin();
	cout<<"The maximum and minimum are "<<A<<" and "<<B<<"."<<endl;
  }
  return 0;
}
