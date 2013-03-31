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
int N,g,low,hight;
string line;
bool sal[501];
char op;
int main(){
  //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
  cin>>N;
  while(N>0){
	low=1;
	hight=500;
	memset(sal,0,sizeof sal);
	for(int i=0;i<9;i++){
		cin>>g>>op;
		sal[g]=1;
	  if(op=='-')
	  	hight=g-1;
	  if(op=='+')
	    low=g+1;
	}
	vector<int> v;
	for(int i=low;i<=hight;i++)
	    if(!sal[i])
	    	v.pb(i); 
	if(v.size()==1)
		cout<<v.front()<<endl;
	else
		cout<<"?"<<endl;  	
	N--;
  } 
  return 0;
}
