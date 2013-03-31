#include <cstdio>
#include <iostream>
#define all(v) (v).begin(),(v).end()
#define sz size()
using namespace std;
#define MOD 10000000000LL


long long expo(long long a, long long b){
   long long ans=1;   
   for(int i=1;i<=b;i++){
      ans=(ans*a)%MOD;
   }
   return ans;  
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    long long ans=0;
    for(int i=1;i<=1000;i++){
      ans=(ans+ expo(i,i))%MOD;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
