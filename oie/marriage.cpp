#include <vector>
#include <map>
#include <set>
#include <queue>
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
#define all(v) (v).begin(),(v).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n,R,S;
  cin>>n;
  vector<int>A(n),B(n);
  for(int i=0;i<n;i++)
  	cin>>A[i];
  for(int i=0;i<n;i++)
  	cin>>B[i];
  R=0;S=0;
  sort(all(A));
  sort(all(B));
  
  for(int i=0;i<n;i++)
  	R+=abs(A[i]-B[i]);
  reverse(all(B));
  for(int i=0;i<n;i++)
  	S+=abs(A[i]-B[i]);
  cout<<R<<" "<<S<<endl;  	

  return 0;
}
