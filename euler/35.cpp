#include <iostream>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <cstring>
#define MAX 1000000
#define all(V) (V).begin(),(V).end()

using namespace std;

long long toi(string s){long long dev; istringstream is(s); is>>dev;return dev;}
string tos(long long n){stringstream ss; ss<<n;return ss.str();}
bool sieve[1000001];

bool isTheme(int n){
	if(!sieve[n])return 0;
	string s=tos(n),aux;
	int k=0;
	int T=s.size();
	for(int i=1;i<T;i++){
		aux=string(T,'0');
		for(int j=0;j<T;j++){
			int index=(j+i)%T;
			aux[index]=s[j];
		}
		if(!sieve[toi(aux)])return 0;
	}
	return 1;
}



int main(){
    
    memset(sieve,1,sizeof sieve);
    sieve[1]=0;
    sieve[0]=0;
    for(int i=2;i*i<=MAX;i++)
       if(sieve[i])
          for(int j=i*i;j<=MAX;j+=i)
               sieve[j]=0;
	int dev=0;
	
	
    for(int i=2;i<=MAX;i++){
		if(isTheme(i)){
			dev++;
		}

	}
	cout<<dev<<endl;
	return 0;
}
