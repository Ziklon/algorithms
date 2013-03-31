#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;
typedef long long ll;

ll dp[100005];

ll MOD=1000000009;

// LIS = { 1,2,0,-2,7} =3 
		//{ 1,2,7}
		//{-2,7}
		//{0,7}
	
		
// problema de monedas
//30 {10,20,50,100} =2
//40 =2
//60 = 2

//60 100
//60 50 = 1 = >10
//10 50
//10 20 
//10 10 = 1 => 0
//0 10 

//greedy no es 100% seguro

// 8 { 1,4, 6}=A




int ans=1000000000;



// = 3 monedas
// =  lo optimo es 2 
// greedy no funciona
// dp

//fn(c) c ==0 => 0
//fn(c) c< 0  return 1000000

//fn(c)=fn(c-A[i])


//primeros pasos
//Reconocer estados
// definir la recursion, casos bases
// funcion (x,y,z)




int main(){
	
	dp[0]=0;
	int L[]={1,4,6};
	
		
	
	for(int c=1;c<=10;c++){
		dp[c]=1000000;
		int len=sizeof(L)/sizeof(int);
			
		for(int j=0;j<len;j++){			
			if(c>=L[j])
				dp[c]=min(dp[c],1+dp[c-L[j]]);
		}	
	}
	
	cout<<dp[8]<<endl;
				
	return 0;
}
