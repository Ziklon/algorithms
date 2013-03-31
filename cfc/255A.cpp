#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
string ans[]={"chest","biceps","back"};
int main(){
	ios::sync_with_stdio(false);
	vector<int> v(3,0);
	int tmp,n,index,mx=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp;
		v[i%3]+=tmp;
		mx=max(mx,v[i%3]);
	}
	index=0;
	for(int i=0;i<3;i++)if(mx==v[i])index=i;
	
	cout<<ans[index]<<endl;		
	return 0;
}
