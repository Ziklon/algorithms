#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define sz size()
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define oo 1<<30
using namespace std;
string expre,aux;
vector<string> text;
int N;
int toint(string str){
	int ans=0;
	REP(i,0,str.sz)ans=(ans*10)+(str[i]-'0');
	return ans;
}

void split(string str){
	text.clear();
	int i=0;
	int j=0,a=0;
	while(i<str.sz){
		if(str[i]=='(')a++;
		if(str[i]==')')a--;		
		if(a==0 && str[i]==')'){
			text.push_back(str.substr(j,i-j+1));
			j=i+1;
		}
		i++;
	}	
}

int check(int p,int q,int sum){
	p++;
	q--;
	if(q<=p)return 0;
	int a=0;
	aux="";
	while(isdigit(expre[p])){
		aux+=expre[p];
		p++;
	}
	sum+=toint(aux);
	if((q-p)==3){
		return sum==N;
	}
	int k=p;
	do{
		if(expre[k]=='(')a++;
		if(expre[k]==')')a--;
		k++;
	}while(a!=0);
	return max(check(p,k-1,sum),check(k,q,sum));	
	return 0;
}

void solve(){
	expre="";
	while(getline(cin,aux)) expre+=aux;
	aux=expre;
	expre="";
	REP(i,0,aux.sz)if(aux[i]!=' ')expre+=aux[i];
	
	split(expre);
	bool ok=0;
	REP(i,0,text.sz){
		int ubi=text[i].find("(");
		N=toint(text[i].substr(0,ubi));
		expre=text[i].substr(ubi);;
		int tam=expre.sz;
		//expre+=string(100,' ');
		ok=check(0,expre.sz-1,0);
		if(ok)printf("yes\n");
		else printf("no\n");
	}

}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}


