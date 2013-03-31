#include <iostream>
#include <cstdio>
#include <fstream>
#include <vector>
using namespace std;
#define REP(i,a,b) for(int i=int(a);i<int(b);i++)
int main(){
	//freopen("in.txt","r",stdin);
	int n,m=0,x;
	vector<int> v;
	cin>>n;
	REP(i,0,7){
		cin>>x;
		v.push_back(x);
	}
  	int ans=0;
	int read=0;
	
	while(read<n){
		REP(i,0,7){
			read+=v[i];
			if(read>=n)break;					
			ans=(ans+1)%7;			
			//cout<<ans<<" "<<read<<endl;
			
		}
	}
	cout<<(ans+1)<<endl;
	return 0;

}	