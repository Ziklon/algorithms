#include <iostream>
using namespace std;
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int n=0;
  while((scanf("%d",&n)) && n!=42){
    printf("%d\n",n);
  }
}
