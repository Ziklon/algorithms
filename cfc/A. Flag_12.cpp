#include <iostream>
using namespace std;
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int m,n;
  while(cin>>m>>n){
    int tb[m][n];
    for(int i=0;i<m;i++)
      for(int j=0;j<n;j++)
        cin>>tb[m][n];
    bool ok=1;
    //row
    for(int i=0;i<m;i++)
     for(int j=1;j<n;j++)
       if(tb[i][j-1]!=tb[i][j-1])
         ok=0;
    for(int i=0;i<n;i++)
      for(int j=1;j<m;j++)
        if(tb[j-1][i]==tb[j][i])
          ok=0;
   if(ok)
    cout<<"YES"<<endl;
   else
    cout<<"NO"<<endl;  
  }
}
