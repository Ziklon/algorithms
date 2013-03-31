#include <iostream>
using namespace std;
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    string line="";
    while(getline(cin,line)){
      int pts=0;
      int N=1,nl=0;
      for(int i=0;i<line.size();i++){        
        if(nl>=N*10){
          N++;
        }
        nl+=line[i]-'0';
        switch(line[i]){
          case '1':
               pts+=N;
               break;
          case '2':
               pts+=3*N;
               break;
          case '3':
               pts+=N*6;
               break;
          case '4':
               pts+=10*N;
               break;
          default:
              break;
        }      
      }
      cout<<pts<<endl;
    }  
}
