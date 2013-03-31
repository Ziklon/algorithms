#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
int A[110];
int main(){
	ios::sync_with_stdio(false);
	int N;
	cin>>N;
	for(int i=0;i<N;i++)cin>>A[i];
	
	int ans=0;
	int neg=0;
	vector<int> v;
	int cnt=0;
	for(int i=0;i<N;i++){
		if(A[i]<0)neg++;	
		if(neg==3){			
			v.push_back(cnt);
			neg=0;
			cnt=0;
			i--;
			continue;
		}
		cnt++;	
	}
	if(cnt>0)v.push_back(cnt);
	
	cout<<v.size()<<endl;
	for(int i=0;i<v.size();i++)
		cout<<v[i]<<endl;
	
	return 0;
}
