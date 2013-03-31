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
string line;
int toi(string s){
	int ans=0;
	for(int i=0;i<s.sz;i++)ans=(ans*10)+(s[i]-'0');
	return ans;
}


int main(){
	freopen("output","w",stdout);
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	string op="*+-/";
	
	for(int i=0;i<N;i++){
		cin>>line;
		int index=-1;
		int tip=0;
		while(index==-1){
			index=line.find(op[tip]);
			tip++;
		}
		int sa=toi(line.substr(0,index));
		int sb=toi(line.substr(index+1));
		int ans=sa/sb;
		if(tip==1)ans=sa*sb;
		if(tip==2)ans=sa+sb;
		if(tip==3)ans=sa-sb;

		cout<<ans<<endl;
		
	} 	
	return 0;
}
