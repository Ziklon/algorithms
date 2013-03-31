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
string command;
int curDir=0;
int P[1<<20],n,N=1;
string M[1<<20];

vector<int> list(int cur){
	vector<int> ans;
	REP(i,0,N)if(P[i]==cur)ans.push_back(i);
	return ans;
}
string pwd(int cur){
	string ans=M[cur]+"/";
	cur=P[cur];
	while(cur!=-1){
		ans=M[cur]+"/"+ans;
		cur=P[cur];
	}
	return ans.substr(1);
	
}

int make(int cur,string url){
	REP(i,1,url.sz)
		if(url[i]=='/')
			url[i]=' ';
	stringstream ss(url);
	string aux="";
	vector<int> pek;
	while(ss>>aux){
		if(aux==".."){
			cur=P[cur];
			continue;
		}
		pek=list(cur);
		int next=-1;
		REP(i,0,pek.sz)if(M[pek[i]]==aux)next=pek[i];		
		if(next==-1){
			M[N]=aux;
			P[N]=cur;
			next=N;
			N++;
		}
		cur=next;
	}
	return cur;
}



int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d\n",&n);
	M[0]="/";
	P[0]=-1;
	REP(i,0,1000000)P[i]=-1;
	REP(i,0,n){
		getline(cin,command);
		if(command=="pwd")
			printf("%s\n",pwd(curDir).c_str());
		else{
			command=command.substr(3);
			if(command[0]=='/'){
				curDir=make(0,command.substr(1));			
			}else
				curDir=make(curDir,command);
		}
	}
	
	
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
