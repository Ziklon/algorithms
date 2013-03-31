#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


//### FACTORES PRIMOS DE UN NUMERO #####################################################
vector < pair <int, int> > primeFact(int N)
{
	vector < pair <int, int> > V;
	
	for(int i=2; i*i<=N; i++)
	{
		int a=0;
		while(N%i==0)
		{
			N/=i;
			a++;
		}
		if(a!=0) V.push_back(make_pair(i, a));
	}
	if(N>1) V.push_back(make_pair(N, 1));
	
	return V;
}

int main(){
	int cnt=0;
	int a=0;
	while(cnt<=5){
		a=a+1;
		cnt=1;
		vector<pair<int,int> >v=primeFact(a);
		
		for(int i=0;i<v.size();i++)
			cnt*=(v[i].second+1);
	}
	cout<<a<<endl;
	return 0;
	  
}
