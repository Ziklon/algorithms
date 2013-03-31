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
#define fill(x,i) memset(x,i,sizeof(x))
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define INF 1<<30
using namespace std;
typedef long long ll;

int check(string& a, string& b){
	if(a==b)return 0;
	
	if(a.sz!=b.sz){
		if(a.sz>b.sz)return 1;
		return 2;	
	}
	for(int i=0;i<a.sz;i++)if(a[i]<b[i])return 2;
	
	return 1;
	
}


int main(){
	ios::sync_with_stdio(false);
	string a,b;
	while(cin>>a>>b){
		if(a==b && a=="*")break;
		int i;
		for(i=0;i<a.sz && a[i]=='0';i++);
		a=a.substr(i);
		for(i=0;i<b.sz && b[i]=='0';i++);
		b=b.substr(i);
		
		int rpt=check(a,b);
		if(rpt==1)cout<<">"<<endl;
		else if(rpt==2)cout<<"<"<<endl;
		else cout<<"="<<endl;
		
	} 	
	return 0;
}




