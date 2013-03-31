#include <iostream>
#include <vector>
using namespace std;

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
	vector<pair<int,int> > v=primeFact(18);
	cout << 'a'-'A'<<endl;
	system("pause");
}
