#include <iostream>
#include <sstream>
#include <cstdio>
#define sz size()
using namespace std;

string op;
string sum(string a, string b){
	string dev="";
	int d=0;
	if(b.sz > a.sz)
		swap(a,b);	
	for(int i=a.sz-1,j=b.sz-1;i>=0;i--,j--){
		d=a[i]-'0'+d;
		if(j>=0)
			d+=(b[j]-'0');
		if(d>9){
			dev=string(1,'0'+(d%10))+dev;
			d=1;		
		}else{
			dev=string(1,'0'+d)+dev;
			d=0;		
		}	
	}
	if(d)
		dev=string(1,'0'+d)+dev;
	return dev;
}


string factorial(int n){
	string dev="1";
	for(int i=2;i<=n;i++){
		stringstream ss;
		ss<<i;
		op=ss.str();
		if(dev.sz<op.sz) swap(dev,op);
		string resul="";
		for(int j=op.sz-1,m=0;j>=0;j--,m++){
			string pri=string(m,'0');
			int ll=0;
			for(int k=dev.sz-1;k>=0;k--){
				ll=((dev[k]-'0')*(op[j]-'0')) + ll;
				pri=string(1,'0'+ll%10)+pri;
				if(ll>9)ll=ll/10;
				else ll=0;
			}
			if(ll>0)pri=string(1,'0'+ll)+pri;
			resul=sum(resul,pri);
		}
		dev=resul;		
	}
	return dev;

}

int N;
int main(){
	string nums[10001];
	nums[1]="1";
	for(int i=2;i<=10001;i++){
		nums[i]=
	}
	while(cin>>N)
		printf("%s\n",factorial(N).c_str());
	return 0;
}
