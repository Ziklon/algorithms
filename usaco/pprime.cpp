/*
ID: winftc2
PROG: pprime
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <ctime>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define ll long long
using namespace std;
ll a,b;
set<ll>S;

int reverse(ll num){
	int ans=0;
	while(num){
		ans=(ans*10)+num%10;
		num/=10;
	}
	return ans;
}
int numD(ll num){
	int ans=0;
	while(num){
		ans++;
		num/=10;
	}
	return ans;
}
int pow(int n){
	int ans=1;
	for(int i=0;i<n;i++)ans*=10;
	return ans;
	
}

void make(long long num){
	
	ll x=reverse(num);
	ll y=reverse(num/10);
	int e=numD(num);
	ll c=(num*pow(e))+x;
	ll d=(num*pow(e-1))+y;
	
	if(c>b&&d>b)return;
	if(c>=a&& c<=b)S.insert(c);
	if(d>=a&&d<=b)S.insert(d);
	for(int i=0;i<=9;i++)
		make((num*10)+i);
	
}

bool isPrime(ll n){
	if(n<2)return 0;
	if(n==2)return 1;
	if(n%2==0)return 0;
	for(int i=3;i*i<=n;i++)
		if(n%i==0)
			return 0;
	return 1;
}

int main(){
	clock_t start = clock();
    freopen("in.txt","r",stdin);
	//freopen("pprime.out","w",stdout);
	cin>>a>>b;

	for(int i=1;i<=9;i++)make(i);
	vector<int> Pal(all(S));
	
	REP(i,0,Pal.sz)if(isPrime(Pal[i]))printf("%d\n",Pal[i]);
	
	fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
    return 0;
}
