#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long sum,n;
    while(cin>>n){
      sum=(n*(n+1))/2;
      cout<<sum<<endl<<endl;
    } 
    return 0;
}
