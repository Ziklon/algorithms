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
int n;
string cad;
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  cin>>n;
  while(n--){
  	cin>>cad;
  	vector<int> v(26,0);
  	string aa="",bb="",res="";
  	int C=0;
  	for(int i=0;i<cad.sz;i++)
  		v[cad[i]-'a']++;
  	for(int i=0;i<26;i++){
		aa+=string(v[i]/2,'a'+i);
		if(v[i]%2==1){
			C++;
			bb=string(1,'a'+i);
		}
	}
	if(C>1)
		printf("NINGUN PALINDROMO\n");
	else{
		res=aa;
		reverse(all(aa));
		res=res+bb+aa;
		printf("%s\n",res.c_str());		
	}  	
  }

  return 0;
}
