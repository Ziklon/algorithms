#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n,x=0,tmp;
    scanf("%d",&n);
    
    for(int i=0;i<n;++i){
        scanf("%d",&tmp);
        x^=tmp;
    }
    printf("%d\n",x);    
       
}
