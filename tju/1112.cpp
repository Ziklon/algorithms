#include <iostream>
#include <string>
#define sz size()
using namespace std;

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

int main(){
	string dev="0",tmp;
	while(cin>>tmp){
		if(tmp.size()==1 && tmp[0]=='0')
			break;
		dev=sum(dev,tmp);	
	}
	cout<<dev<<endl;
	return 0;
}


