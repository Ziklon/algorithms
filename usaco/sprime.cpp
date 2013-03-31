/*
ID: winftc2
PROG: sprime
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
#include <cmath>
#include <map>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define fill(x,i) memset(x,i,sizeof(x))
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define ll long long
#define MAX 100000000
using namespace std;
bool S[10000002];
int Limit=20000000;
vector<int> v;
int A,B;

bool isPrime(int n){
	if(n%2==0)return 0;
	for(int i=3;i*i<=n;i+=2)
		if(n%i==0)
			return 0;
	return 1;
}

bool get(int n){
	if(n==2)return 1;
	if(n%2==0)return 0;
	if(n<2)return 0;
	if(n<=Limit) return S[n>>1]==0;
	return isPrime(n);
}

void make(int num){
	if(num>=A){
		v.push_back(num);
		return;
	}
	int aux;
	REP(i,1,10){
		aux=(num*10)+i;
		if(aux<B && get(aux))
			make(aux);
	}
	
	
	
}
int main(){
	clock_t start = clock();
    freopen("sprime.in","r",stdin);
	//freopen("in.txt","r",stdin);
	freopen("sprime.out","w",stdout);
	fill(S,0);
	int n;
	cin>>n;
	int i,j;
	for(i=3;i*i<=Limit;i+=2){
		if(!S[i>>1]){
			for(j=i*i;j<=Limit;j+=2*i)
				S[j>>1]=1;
		}
	}
	A=pow(10.0,n-1);
	B=pow(10.0,n);
	make(2);
	make(3);
	make(5);
	make(7);
	sort(all(v));
	REP(i,0,v.sz){
		printf("%d\n",v[i]);
	}
	
	
	
	
	
	fprintf(stderr, "time=%.3lfsec\n", 0.001 * (clock() - start));
    return 0;
}
