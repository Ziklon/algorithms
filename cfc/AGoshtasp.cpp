#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
#define LIM 10001
bool sieve[LIM];
int main(){
   int n,x;
   cin>>n;
   memset(sieve,1,sizeof sieve);
   for(int i=2;i*i<=n;i++)
      if(sieve[i])
         for(int j=2*i;j<=n;j+=i)
            sieve[j]=0;
   vector<int> v(1,1);
   for(int i=2;i<=n;i++)
      if(sieve[i])
         v.push_back(i);
   reverse(v.begin(),v.end());
   stringstream ss;
   x=n;
   for(int i=0;i<v.size();i++){
      if(v[i]<=n){
         n-=v[i];
         ss<<"+"<<v[i];
      }
      if(n<=0)break; 
   }
   if(n==0)cout<<ss.str().substr(1)<<"="<<x<<endl;
   else cout<<0<<endl;
   return 0;  

}
