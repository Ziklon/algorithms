#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int N,S;
    while(cin>>N>>S){
      if(N==0&&S==0)break;
      vector<int>v(N,0);
      int dev=0,mask=0;
      bool ok=0;
      for(int i=0;i<N;i++)
        cin>>v[i];
      for(int i=0;i<(1<<N);i++){
        int suma=0;
        for(int j=0;j<N;j++){
          if((i&(1<<j))!=0){
            suma+=v[j];
          }
        }
        if(suma==S){
          ok=1;
          break;
        }
      }
      if(ok)cout<<"Yes"<<endl;
      else cout<<"No"<<endl;      
    }
    return 0;
}

