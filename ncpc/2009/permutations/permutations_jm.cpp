#include <iostream>
#include <map>

using namespace std;

typedef long long LL;

const LL MOD = (1LL<<31)-1;

LL gcd(LL a, LL b) { return !b?a:gcd(b,a%b); }
LL lcm(LL a, LL b) { return a*b/gcd(a,b); }
LL choose[110][110], fac[110];
LL inv[110];

LL extendedEuclid(LL a, LL b, LL &q, LL &r)
{
	LL p, d;
	if (b == 0) { q = 1; r = 0; return a; }
	d = extendedEuclid(b, a % b, p, q);
	r = p - a / b * q;
	return d;
}

LL modInverse(LL x, LL prime)
{
    LL p, q;
    extendedEuclid(x, prime, p, q);
    return (p+prime)%prime;
}

map<LL, LL> memo;

LL countPerm(int left, int largest, LL order, int k)
{
	if (left == 0) return order == k ? 1 : 0;
	if (largest == 0) return 0;
	if (gcd(order,k) != order) return 0;
	LL cacheKey = (order*110+left)*110+largest;
	if (memo.count(cacheKey) > 0) return memo[cacheKey];
	LL sum = 0, temp = 1;
	for(int i=0;i*largest<=left;i++) {		
		LL temp2 = (temp * countPerm(left-largest*i, largest-1, i ? lcm(order,largest) : order, k)) % MOD;
		sum = (sum + temp2) % MOD;
		
		temp = (temp * choose[left-i*largest][largest]) % MOD;
		temp = (temp * fac[largest-1]) % MOD;
		temp = (temp * inv[i+1]) % MOD;
	}
	memo[cacheKey] = sum;
	return sum;		
}

int main()
{
	fac[0] = 1;
	choose[0][0] = 1;
	for(int i=1;i<110;i++) {
		inv[i] = modInverse(i, MOD);
		fac[i] = (fac[i-1] * i) % MOD;
		choose[i][0]=choose[i][i] = 1;
		for(int j=1;j<i;j++)
			choose[i][j]=(choose[i-1][j-1]+choose[i-1][j])%MOD;
	}
	
	LL n, k;
	cin >> n >> k;
	LL sum = countPerm(n,n,1,k);
	cout << sum << endl;
	return 0;
}
