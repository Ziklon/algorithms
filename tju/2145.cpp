#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#define foreach(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)

using namespace std;
int Z;
int main(){
	int N,Q,p,q;
	Z=1;
	while(cin>>N){
		if(N==0)break;
		vector<int> dat(N+1);
		map<int,int> M;
		for(int i=1;i<=N;i++){
			dat[i]=i;
			M[dat[i]]=i;
		}
		cin>>Q;		
		for(int i=0;i<Q;i++){
			scanf("%d %d",&p,&q);			
			swap(dat[p],dat[q]);
			M[dat[p]]=p;
			M[dat[q]]=q;		
		}
		cin>>Q;
		for(int i=1;i<=N;i++)
			cout<<dat[i]<<" ";
		cout<<endl;
		printf("Genome %d\n",Z);	
		for(int i=0;i<Q;i++){
			scanf("%d",&p);
			printf("%d\n",M[p]);
		}		
		Z++;	
	}
	return 0;
}
