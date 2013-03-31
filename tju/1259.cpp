#include <iostream>
#include <map>
#include <vector>
#include <math.h>
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int nC,n,dev,pos=0;
    cin>>nC;
    for(int i=0;i<nC;i++){
      cin>>n;
      dev=1;
      pos=1;
      while((pos*(pos+1))<n*2)pos++;
      
      n=n-(((pos-1)*pos)/2);
       
       cout<<n<<endl;
       cout<<pos<<endl;  
        for(int j=1,k=0; k<pos && n>0;j++,k++){
         int tmp=j;
         vector<int> vi;          
         while(tmp){
           vi.push_back(tmp%10);
           tmp/=10;
         }
         for(int k=vi.size()-1;k>=0 && n;k--,n--){
           dev=vi[k];
           cout<<dev<<endl;        
         }
        }        
      //cout<<dev<<endl;
    }
    return 0;
}
