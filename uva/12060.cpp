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
int N,x,a,b,c,m,T;

int gcd(int a, int b){
	return __gcd(a,b);
}
int tam(int n){
	int peki=0;
	while(n){
		peki++;
		n/=10;
	}
	return peki;
}
string space(int n){
	if(n>=0)return "";
	n=abs(n);
	string s=string(n,' ');
	return s;
	
}
int main(){
	freopen("in.txt","r",stdin);
	T=1;
	while(cin>>N && N){
		b=0;
		c=N;
		REP(i,0,N){
			cin>>x;
			b+=x;
		}
		x=gcd(c,b);
		x=abs(x);
		b/=x;
		c/=x;
		m=min(b,c);
		
		if(abs(b)>c && c!=1)
			a=(b/c);
		else
			a=0;
			
		if(abs(a)>0)b-=a*c;
		a=abs(a);
		
		printf("Case %d:\n",T++);
	
		if(c==1){
			if(b<0)printf("- %d\n",abs(b));
			else printf("%d\n",b);
			
			continue;
		}
		
		if(b<0)cout<<space(-2);
		cout<<space(tam(b)-tam(c));
		if(a>0)cout<<space(-1*tam(a));
		cout<<abs(b)<<endl;
		int xx=max(tam(b),tam(c));
		if(b<0)cout<<"- ";
		if(a>0)cout<<a;
		REP(k,0,xx)cout<<"-";
		cout<<endl;
		if(b<0)cout<<space(-2);
		if(a>0)cout<<space(-1*tam(a));
		cout<<space(tam(c)-tam(b))<<c<<endl;
		
		
	}
	return 0; 

}