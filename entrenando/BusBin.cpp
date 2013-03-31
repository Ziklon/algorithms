#include <iostream>
#include <vector>
using namespace std;

bool busBin(int v[],int pri,int ult, int x){
  
  if(pri>=ult)
    return v[ult]==x;
  else{
    int n=(pri+ult)/2;
    if(v[n]==x)
      return 1;
    else if(x<v[n])
        return busBin(v,pri,n-1,x);
    else
       return busBin(v,n+1,ult,x);  
  }
}



int main(){
  int a[]={1,5,9,10,20,33,45,50};
  cout<< busBin(a,0,7,28);
  system("pause");
}
