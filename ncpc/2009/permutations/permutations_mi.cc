/*
  Sample solution for NCPC 2009: Permutations
  Author: Marcus Isaksson
*/

#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

typedef long long LL;
const LL M=(LL(1)<<31)-1;
int k;
vector<int> primeDiv;

LL fallProd(int n, int i) {
  LL p=1;
  while (--i>=0) p=(p*(n--))%M;;
  return p;
}

// Returns the number of times p divides m
int order(int m, int p) {
  int cnt=0;
  while (m%p==0) {
    cnt++;
    m/=p;
  }
  return cnt;
}

// Return the smallest number r such that
// lcm(r,j)=m
// m should be a divisor of k.
int rem(int m, int j) {
  for (int i=0; i<primeDiv.size(); i++) {
    int p=primeDiv[i];
    int om=order(m,p);
    if (om==order(j,p))
      while (m%p==0) m/=p;
  }
  return m;
}

map<pair<int,int>, LL> mem;

// Returns the number of permutations of [n] of some order o
// such that m divides o and o divides k.
// m should be a divisor of k.
LL permOfOrders(int n, int m) {
  if (n<=1) return (m==1)?1:0;
  pair<int,int> t=make_pair(n,m);
  if (mem[t]) return mem[t]-1;
  
  LL cnt=0;
  for (int j=1; j<=n; j++)
    if (k%j==0) {
      cnt=(cnt+(fallProd(n-1,j-1)*permOfOrders(n-j, rem(m,j)))%M)%M;
    }
  mem[t]=cnt+1;
  return cnt;
}

int main() {
  LL n;
  cin >> n >> k;

  mem.clear();
  primeDiv.clear();
  int m=k;
  for (int p=2; LL(p)*p<=m; p++)
    if (m%p==0) {
      primeDiv.push_back(p);
      while (m%p==0) m/=p;
    }
  if (m!=1) primeDiv.push_back(m);
  cout << permOfOrders(n,k) << endl;
}
