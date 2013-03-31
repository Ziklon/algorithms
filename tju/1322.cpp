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
using namespace std;

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	map<string,string>party;
	int N,M,maxi,cn;
	string name,pary,peki="";
	scanf("%d\n",&N);
	REP(i,0,N){
		getline(cin,name);	
		getline(cin,pary);
		party[name]=pary;
	}
	scanf("%d\n",&M);
	map<string,int>votes;
	REP(i,0,M){
		getline(cin,name);
		votes[name]++;
	}
	maxi=0;
	cn=0;
	
	foreach(party,it){
		int vot=votes[it->first];
		if(vot>maxi){
			peki=it->second;
			maxi=vot;
			cn=1;
		}else if(vot==maxi){
			cn++;
		}
	}
	if(cn==1)printf("%s\n",peki.c_str());
	else printf("tie\n");
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
