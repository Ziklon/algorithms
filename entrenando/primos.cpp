#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <sstream>
using namespace std;
//### DETERMINA SI UN NUMERO ES PRIMO ##################################################
bool isPrime(int n)
{
	if(n<=1) return false;
	if(n==2) return true;
	if(n%2==0) return false;
	
	for(int i=3; i*i<=n; i+=2)
		if(n%i==0) return false;
	
	return true;
}

//### GENERA LA CRIBA DE ERASTONES #####################################################
vector <bool> sieve(int n)
{
	vector <bool> prime(n+1, true);
	
	prime[0]=false;
	prime[1]=false;
	
	for(int i=2; i*i<=n; i++)
		if(prime[i])
			for(int j=i*i; j<=n; j+=i)
				prime[j]=false;
	
	return prime;
}

//### FACTORES PRIMOS DE UN NUMERO #####################################################
vector < pair <int, int> > primeFact(int N)
{
	vector < pair <int, int> > V;
	
	for(int i=2; i*i<=N; i++)
	{
		int a=0;
		while(N%i==0)
		{
			N/=i;
			a++;
		}
		if(a!=0) V.push_back(make_pair(i, a));
	}
	if(N>1) V.push_back(make_pair(N, 1));
	
	return V;
}


int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    
    return 0;
}
