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
  int x,y,dev;
  
  while(cin>>x>>y){
	  char dat[x][y];
	  for(int i=0;i<x;i++){
	     for(int j=0;j<y;j++)
	     	cin>>dat[i][j];
	  }
	  dev=0;
	  for(int i=0;i<x;i++){
	   int c=0;
	   for(int j=0;j<y;j++){
		 if(dat[i][j]=='x')
		 	c++;
		 else{
			dev=max(dev,c);
			c=0;
		}
	  }
	  dev=max(c,dev);
	}
	for(int i=0;i<y;i++){
	   int c=0;
	   for(int j=0;j<x;j++){
		 if(dat[j][i]=='x')c++;
		 else{
			dev=max(dev,c);
			c=0;
		}
	  }
	  dev=max(c,dev);
	}
	cout<<dev<<endl;
}

  return 0;
}
