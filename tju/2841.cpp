#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define all(x) (x).begin(),(x).end()
#define sz size()


int tam(int n){
	int ans=0;
	while(n){
		ans++;
		n/=2;
	}
	return ans;
}

int main(){

//freopen("in.txt","r",stdin);	
  int N,ans,siz,ubi,bit;
   while(cin>>N){
      if(N==0)break;
      ans=0;
	  siz=tam(N);
	  ubi=0;
	  while(N>0){
		bit=(N&1);
		ans|=(bit<<(siz-ubi-1));		
		ubi++;
		N=N>>1;
	  }
	  printf("%d\n",ans);
	  
   }
   return 0;
}
