#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>


using namespace std;

int main(){
   freopen("out.txt","w",stdout);
   freopen("in","r",stdin);
   int n;
  
   cin>>n;
   for(int i=0;i<n;i++){
      int k;
      cin>>k;
      vector<string> v(k);
      for(int j=0;j<k;j++)cin>>v[j];
      sort(v.begin(),v.end());
      for(int j=0;j<k;j++)cout<<v[j];
      cout<<endl;
   }

}
