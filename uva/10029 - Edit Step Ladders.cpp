#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define MAX_N 25005
using namespace std;
typedef long long ll;
char A[MAX_N][20];
int dp[MAX_N];



int binarySeach(int low, int hih, char* word){
	while(low<=hih){
		int mid=low+(hih-low)/2;
		int res=strcmp(A[mid],word);	
		if(res==0)return mid;
		if(res>0)
			hih=mid-1;
		else 
			low=mid+1;		
	}
	return -1;
}

void dele(char* word, char* res, int pos){
	int len=strlen(word),n=0;
	for(int i=0;i<len;i++){
		if(i==pos)continue;
		res[n++]=word[i];
	}
	res[n]='\0';	
}
void add(char* word, char* res, int pos, char letter){
	int len=strlen(word),n=0;	
	res[pos]=letter;
	for(int i=0;i<len;i++){
		if(i==pos)n++;		
		res[n++]=word[i];
	}
	res[n]='\0';	
}

void replace(char* word, char* res, int pos, char letter){
	int len=strlen(word);
	for(int i=0;i<len;i++)
		if(i==pos)res[i]=letter;
	else
		res[i]=word[i];
	res[len]='\0';	
}

void fun(char* word, int pos){
	int prev=binarySeach(0,pos-1,word);	
	if(prev!=-1)dp[pos]=max(dp[pos],dp[prev]+1);
}

int main(){
	//freopen("input","r",stdin);
	//freopen("output.txt","w",stdout);
	int n=0;
	while(scanf("%s\n",A[n])==1)n++;
	
	memset(dp,0,sizeof dp);
	int ans=0;
	for(int i=1;i<n;i++){
		int len=strlen(A[i]);		
		char tmp[20]={0};			
		for(int j=0;j<=len;j++){			
			for(char k='a';k<='z';k++){
				if(j<len){
					replace(A[i],tmp,j,k);
					fun(tmp,i);	
				}
				add(A[i],tmp,j,k);	
				fun(tmp,i);
			}
			if(j<len){
				dele(A[i],tmp,j);
				fun(tmp,i);
			}	
		}
		ans=max(ans,dp[i]);	
	}
	printf("%d\n",ans+1);
	
	return 0;
}
