#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n,k;
    cin>>n;
    for(int i=0;i<n;i++){
      cin>>k;
      vector<int>v(k);
      for(int j=0;j<k;j++)cin>>v[j];
      int dev=0;
      for(int x=1;x<k;x++){
        int y=x;
        while(y>=1 && v[y]<v[y-1]){
         swap(v[y],v[y-1]);
         y--;
         dev++;         
        }
      }
      cout<<"Optimal train swapping takes "<<dev<<" swaps."<<endl;      
    }
    
    return 0;
}
