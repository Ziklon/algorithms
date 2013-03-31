/*
ID: winftc2
PROG: ride
LANG: C++
*/
#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
using namespace std;
int mul(string s){
   int ans=1;
   for(int i=0;i<s.sz;i++)
      ans=((s[i]-'A'+1)*ans)%47;
   return ans;
}
int main(){
    freopen("ride.in","r",stdin);
    freopen("ride.out","w",stdout);
    string a,b;
    cin>>a>>b;
    if(mul(a)==mul(b))
      cout<<"GO"<<endl;
   else
      cout<<"STAY"<<endl;
    return 0;
}
