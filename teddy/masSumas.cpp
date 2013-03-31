#include <iostream>

using namespace std;

int main(){
 freopen("data.in","r",stdin);
 freopen("data.out","w",stdout);
 int nC=0,a,b,c;
 cin>>nC;
 for(int i=0;i<nC;i++){
   cin>>a>>b>>c;
   cout<<(a+b+c)<<endl;
 }
 return 0;
}
