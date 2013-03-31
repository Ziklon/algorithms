#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  map<string,int> mp;
  vector<pair<int,string> >vp;
  map<string,int>::iterator it;
  int nC=0,pt;
  string s;
  cin>>nC;
  while(cin>>s>>pt){
     bool ok=false;
     for(int i=0;i<vp.size();i++){
      if(vp[i].second==s){
        vp[i].first+=pt;
        ok=1;
        break;
      }
    }
    if(!ok)
      vp.push_back(make_pair(pt,s));
  }
  sort(vp.begin(),vp.end());
  int mx=vp[vp.size()-1].first;
  string rs="";
  for(int i=vp.size()-1;i>=0;i--){
    if(vp[i].first==mx)
      rs=vp[i].second;
    else
      break;
  }
  cout<<rs;
  return 0;  
  
}
