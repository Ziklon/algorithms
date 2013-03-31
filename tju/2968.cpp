#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int o,a,r;
long long k,p;
int main(){
   //freopen("in.txt","r",stdin);
  //freopen("out.txt","w",stdout);
	while(scanf("%d %d\n",&o,&a)==2){
		vector<long long> V;		
		p=o*o;
		while(a<=p){
			V.push_back(a);
			if(a%o==0)break;
			a=a+o+1;
		}
		int i;
		for(i=0;i+1<V.size();i++)
			printf("%lld ",V[i]);
		printf("%lld\n",V[i]);	
	}
	return 0;
}
