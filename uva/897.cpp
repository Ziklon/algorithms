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
bool S[10000005];

int toi(string s){
	int ans=0;
	REP(i,0,s.sz)ans=(ans*10)+(s[i]-'0');
	return ans;
}
string tos(int n){
	stringstream ss;ss<<n;
	return ss.str();
}
bool isAna(int n){
	if(S[n])return 0;
	string s=tos(n);
	sort(all(s));
	do{
		if(S[toi(s)])return 0;
	}while(next_permutation(all(s)));
	return 1;
}
bool check(int a, int b){
	int ans=1;
	while(ans<=10000000){
		if(ans>a && b>ans)return 1;
		ans*=10;
	}
	return 0;
	
}

int main(){
    //clock_t start = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	fill(S,0);
	S[1]=1;
	S[0]=1;
	for(int i=2;i*i<=10000000;i++)
		if(!S[i])
			for(int j=i*i;j<=10000000;j+=i)
				S[j]=1;
	vector<int> P;
	
	REP(i,2,10000000)if(isAna(i))P.push_back(i);
	
	int N,index;
	//cout<<P.sz<<endl;
	while(scanf("%d",&N)==1 && N){
		index=upper_bound(all(P),N)-P.begin();
		if(index<P.sz && !check(N,P[index]))cout<<P[index]<<endl;
		else cout<<"0"<<endl;
	}
	
	
	//fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
	return 0;
}
