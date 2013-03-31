#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;
int T,N,M,P,X;
char line[20];

inline int binarySearch(const vector<int> &v, int& n){
	int a=0,b=v.size()-1,mid;
	while(a<=b){
		mid=(a+b)/2;
		if(n>v[mid])
			a=mid+1;		
		else if(n<v[mid])
				b=mid-1;
		else return mid;	
	}
	return (a+b+1)/2;	
}

int main(){
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		vector<int> dat(N);
		for(int i=0;i<N;i++)
			scanf("%d",&dat[i]);
		scanf("%d",&M);
		sort(dat.begin(),dat.end());
		for(int i=0;i<M;i++){
			scanf("%s",line);
			if(line[0]=='a'){
				scanf("%d",&P);
				X=binarySearch(dat,P);
				dat.insert(dat.begin()+X,P);				
			}else{
				X=dat[(dat.size()-1)/2];
				printf("%d\n",X);
			}	
		}
	}
	return 0;

}

