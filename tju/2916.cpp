#include <iostream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;
int gcd(int a, int b){
   if(b<=0)return a;
   return gcd(b,a%b);
}
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    long long X,Y,dev,mx;
    while(cin>>X>>Y){
      dev=Y/(gcd(X,Y));
      cout<<dev<<endl;
    }  
    return 0;
}
