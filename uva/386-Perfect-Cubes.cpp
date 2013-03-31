#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;

int main(){
	ios::sync_with_stdio(false);
	freopen("output.txt","w",stdout);
	vector<int> cubes;
	map<int,int> M;
	for(int i=6;i<=200;i++){
		int a=i*i*i;
		cubes.push_back(a);
		M[a]=i;
	}
	vector<pair<int,pair<int,pair<int,int> > > > ans;
	for(int b=2;b<=200;b++)
		for(int c=b+1;c<=200;c++)
			for(int d=c+1;d<=200;d++){
				int a=200*200*200;
				int tmp=(b*b*b)+(c*c*c)+(d*d*d);
				if(tmp>a)break;
				if(binary_search(cubes.begin(),cubes.end(),tmp)){
					ans.push_back(make_pair(M[tmp],make_pair(b,make_pair(c,d))));	
					break;
				}
			}
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		printf("Cube = %d, Triple = (%d,%d,%d)\n",ans[i].first,ans[i].second.first,ans[i].second.second.first,ans[i].second.second.second);		
	}
			
	return 0;
}
