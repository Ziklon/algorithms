#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstring>
#include <ctime>
#include <cstdio>
#define MAX 1000000
#define all(V) (V).begin(),(V).end()
#define sz size()
using namespace std;

long long toi(string s){long long dev; istringstream is(s); is>>dev;return dev;}
string tos(long long n){stringstream ss; ss<<n;return ss.str();}
bool sieve[1000001];

bool truncatable(int n){
	if(!sieve[n])return 0;
	string s=tos(n),a,b;
	int T=s.sz;
	for(int i=1;i<T;i++){
		a=s.substr(0,i);
		b=s.substr(T-i);
		if(!sieve[toi(a)] || !sieve[toi(b)])
			return 0;
	}
	return 1;
}

int main(){
    clock_t tStart = clock();
    memset(sieve,1,sizeof sieve);
    sieve[1]=0;
    sieve[0]=0;
    for(int i=2;i*i<=MAX;i++)
       if(sieve[i])
          for(int j=i*i;j<=MAX;j+=i)
               sieve[j]=0;
	int dev=0;
	int peki=0;
	
    for(int i=8;i<=MAX;i++){
		if(truncatable(i) && dev<11){
			dev++;
			peki+=i;
		}

	}
	cout<<dev<<" "<<peki<<endl;
	printf("Time taken: %.2fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
	return 0;
}
