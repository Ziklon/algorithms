#include <stdio.h>
#include <iostream>

using namespace std ;

long long exp(long long a,long long b,long long c){
    if(b==0)return 1;
    long long dev=exp(a,b/2,c);
    dev=(dev*dev)%c;
    if(b&1)
		dev=(dev*a)%c;
    return dev;
}
char s[6000000];
int main(){
	//freopen("in.txt","r",stdin);
  	//freopen("out.txt","w",stdout);
    long long a=0;
    long long mod=0;
    while(cin>>a){
        scanf("%s",s);
        cin>>mod;
        long long h[10]; // a^b
        h[0]=1;
        for(int i=1;i<10;i++)
            h[i]=(h[i-1]*a)%mod;
        long long dev=1;
        int t=strlen(s);
        for(int i=0;i<t;i++){
            dev=exp(dev,10,mod);
        	dev=(dev*h[s[i]-'0'])%mod;        
    	}
    	cout<<dev<<endl;
	}
	return 0;
}
