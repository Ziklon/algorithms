#include <iostream>
#include <cmath>
#define sz size()
using namespace std;

long long gcd(long long a, long long b){return __gcd(a,b);}
long long lcm(long long a, long long b){return a*(b/gcd(a,b));}
int main(){
	double n=M_PI;
	string a="YTCAYCQYP";
	string b="AVECAESAR";
	 int k;
	if(a[a.sz-1]<'R')
		k='Z'-'R'+a[a.sz-1]-'A';
	else
		k=a[a.sz-1]-'R';
	cout<<k<<endl;
	
	for(int i=0;i<b.size();i++)
		cout<<a[i]-b[i]<<endl;
	    
	
	system("pause");	
}

