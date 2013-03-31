#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;

int memo[1001];
vector<int> v;

int dp(int ps){
  if(memo[ps]!=-1)
    return memo[ps];
  int dev=0;
  for(int i=ps+1;i<v.size();i++)
    if(v[i]>v[ps])
      dev=max(dev,1+dp(i));      
  memo[ps]=dev;
  return dev;
}

int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int nC,n;
    v.clear();
    v.push_back(-1);
    cin>>nC;
    memset(memo,-1,sizeof(memo));
    for(int i=0;i<nC;i++){
      cin>>n;
      v.push_back(n);
    }          
    cout<<dp(0)<<endl;
    return 0;
}
