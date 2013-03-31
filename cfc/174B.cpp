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
string cad;
vector<string> v;
bool flag=1;

bool go(int pos){
	if(pos>=cad.sz)return 1;
	string aux="";
	while(pos<cad.sz&& isalpha(cad[pos]))aux+=cad[pos],pos++;
	if(aux.sz>8 ||aux.sz==0)return 0;
	int ubi=cad.find(".",pos+1);
	int que=cad.sz-pos-1;
	int nums=ubi-pos-1;
	int usa=1;	
	if(ubi!=-1 && 	((nums)>11 || nums<2))return 0;
	if(ubi== -1 && (que<1 || que>3))return 0;
	
	if(ubi!=-1){
		nums--;
		while(nums>8){
			usa++;
			nums--;
		}
	}
	if(ubi==-1 && que>=1 && que<=3)usa=que;
	v.push_back(aux+cad.substr(pos,usa+1));
	pos=pos+usa+1;
	return go(pos);
}
void solve(){
	cin>>cad;
	if(go(0)){
		printf("YES\n");
		REP(i,0,v.sz)printf("%s\n",v[i].c_str());
	}
	else
		puts("NO");
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

