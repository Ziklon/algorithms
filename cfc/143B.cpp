#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstring>
#include <sstream>
#include <queue>
#include <set>
#include <map>
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(v) (v).begin(),(v).end()
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define sz size()
using namespace std;
int main(){
	//freopen("in.txt","r",stdin);	
	string line;
	cin>>line;
	if(line.find(".")==-1)line=line+".00";
	else line=line+"00";
	bool ok=0;
	if(line[0]=='-'){
		ok=1;
		line=line.substr(1);
	}
	int indexp=line.find(".");
	string aux=line.substr(0,indexp);
	string text="";
	reverse(all(aux));
	for(int i=0;i<aux.sz;i++){			
			if(i%3==0 && i>1)text+=",";
			text+=aux[i];					
	}
	reverse(all(text));
	string pri=text+"."+line.substr(indexp+1,2);
	if(ok)
		printf("($%s)\n",pri.c_str());
	else
		printf("$%s\n",pri.c_str());
	
	return 0;
}