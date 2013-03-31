#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  int n=0;
  while(cin>>n){
    vector<int> v(n);
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
    sort(v.begin(),v.end());
    int mn=v[0],dev=0;
    bool ok=0;
    for(int j=1;j<v.size();j++){
      if(v[j]!=mn){
       dev=v[j];
       ok=1;
       break;
      }
    }
    if(ok)
      cout<<dev<<endl;
    else
      cout<<"NO"<<endl;
  }
}
