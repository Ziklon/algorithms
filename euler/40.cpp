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

int len(int n){
	int ans=0;
	while(n>0){
		ans+=1;
		n/=10;
	}
	return ans;
}
pair<int,int> enesimo(int n){
	int val=0;
	int aux=0;
	int res=0;
	int num=0;
	for(int i=1;;i*=10){
		aux=(i)*9*len(i);		
		if(val+aux>n){
			res=n-val;			
			aux=res/len(i);
			num+=aux;
			val+=aux*len(i);
			//cout<<val<<" "<<num<<endl;
			return make_pair(val,num);			
		}
		num+=(i*9);
		val+=aux;		
	}
	
}
vector<int> parse(int n){
	vector<int> v;
	while(n){
		v.push_back(n%10);
		n/=10;
	}
	reverse(all(v));
	return v;
}
int main(){
    clock_t tStart = clock();
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int ans=1;
	for(int i=10;i<=1000000;i*=10){
		pair<int,int> p=enesimo(i);
		int a=p.first;
		int b=p.second;
		int t=i-a;
		if(b==i){
			ans*=(a%10);
		}else{
			b++;
			vector<int> v =parse(b);
			ans*=(v[t-1]);
		}	
	}
	cout<<ans<<endl;
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
