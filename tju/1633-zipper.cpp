#include<bits/stdc++.h>
#define REP(i,n)for (int i=0;i<n;i++)
using namespace std;
typedef long long ll;
int T;
int dp[205][205];
int N1,N2,N3;
char s1[205],s2[205],s3[405];

int go(int idx1, int idx2){  
    if(idx1+idx2==N3)return 1;
    int& ref=dp[idx1][idx2];
    if(ref!=-1)return ref;
    ref=0;
    if(idx1<N1 && s1[idx1]==s3[idx1+idx2])ref|=go(idx1+1,idx2);
    if(idx2<N2 && s2[idx2]==s3[idx1+idx2])ref|=go(idx1,idx2+1);
    return ref;

}

int main(){
    scanf("%d",&T);
    for(int i=1;i<=T;i++){
        scanf("%s %s %s",s1,s2,s3);
        N1=strlen(s1);
        N2=strlen(s2);
        N3=N1+N2;
        memset(dp,-1,sizeof dp);
        if(go(0,0))
            printf("Data set %d: yes\n",i);
        else
            printf("Data set %d: no\n",i);
    
    }
    return 0;
}

