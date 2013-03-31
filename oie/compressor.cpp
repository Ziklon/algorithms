#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
#define pb push_back
#define mp make_pair
#define cpresent(V,e) (find(all(V),(e))!=(V).end())
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
using namespace std;

int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  string s;
  while(getline(cin,s)){
  	bool ok=0;
  	string res="";
	for(int i=s.sz/2;i>=1&&!ok;i--){
	   for(int j=0;j+i<=s.sz&&!ok;j++){
	      string a=s.substr(j,i);
		  for(int k=j+i;k<s.sz&&!ok;k++){
		  	 string b=s.substr(k,i);
		  	 if(a==b){
			 	ok=1;
			 	res=a;
			 }
		  }	
	   }	
	}
	cout<<res<<endl;
  }

  return 0;
}
