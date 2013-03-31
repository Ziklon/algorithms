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
#define INF 1<<30
using namespace std;

bool isEmail(string s){
	REP(i,0,s.sz)if(!isalpha(s[i]) && !isdigit(s[i]) && s[i]!='@' && s[i]!='.')return 0;	
	if(count(all(s),'@')!=1)return 0;
	if(count(all(s),'.')!=1)return 0;
	int a=s.find("@");
	int b=s.find(".");
	return (a>0 && (a+1)<b && b+1<s.sz);	
}
bool isUser(string s){
	REP(i,0,s.sz)if(!isalpha(s[i]) && !isdigit(s[i]))return 0;
	if(s.sz<5 || s.sz>16)return 0;
	return isalpha(s[0]);
}
bool isCard(string s){
	if(s.sz!=15 && s.sz!=18)return 0;
	REP(i,0,s.sz)if(!isdigit(s[i]) && i+1!=s.sz)return 0;
	if(isdigit(s[s.sz-1]) || s[s.sz-1]=='X')return 1;
	return 0;	
}
void solve(){
	string line;
	while(getline(cin,line)){
		string ans="This is the wrong input.";
		if(isEmail(line))ans="This is an Email.";
		if(isUser(line))ans="This is a username.";
		if(isCard(line))ans="This is the cardID.";
		printf("%s\n",ans.c_str());
		
	
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

