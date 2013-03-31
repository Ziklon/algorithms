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

string a[]={"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"};
string b[]={"ejp mysljylc kd kxveddknmc re jsicpdrysi",
			"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
			"de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string line;
map<char,char>M;
void solve(){
	int n;
	scanf("%d\n",&n);	
	M['q']='z';
	M['z']='q';
	REP(i,0,3){
		//printf("Case #%d: %s\n",i+1a[i].c_str())
		REP(j,0,b[i].sz){
			if(isalpha(b[i][j]))			
				M[b[i][j]]=a[i][j];			
		}
		
	}
	REP(i,0,n){
		getline(cin,line);	
		printf("Case #%d: ",i+1);
		
		REP(j,0,line.sz){
			if(isalpha(line[j]))
				line[j]=M[line[j]];			
			
		}
		//cout<<line<<endl;
		printf("%s\n",line.c_str());
	}
}
int main(){
	#ifdef LocalHost
		freopen("D:/input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		clock_t start = clock();
	#endif
	solve();	
	#ifdef LocalHost
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start));
	#endif
	return 0;
}

