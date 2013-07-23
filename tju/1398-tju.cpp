#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

int T,N,P[25],M;
bool C[1<<20];

int sum, lado,tmp;
bool found;

int S[1<<20],add;

int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        sum=0;
        for(int i=0;i<N;i++){
            scanf("%d",&P[i]);
            sum+=P[i];
        }
        found=0;
        if(sum%4==0){
        lado=sum/4;
        M=1<<N;
        add=0;
        for(int mask=0;mask<M;mask++){
            C[mask]=0;
            tmp=0;
            for(int i=0;i<N;i++)if(mask&(1<<i))tmp+=P[i];
            if(tmp==lado){
                S[add++]=mask;
            }
        }
        found=0;
        for(int i=0;i<add;i++){            
            for(int j=i+1;j<add;j++){
                if((S[i] & S[j])==0){
                    tmp=(S[i]|S[j]);
                    C[tmp]=1;
                    tmp=(M-1)^(tmp);
                    if(C[tmp]==1){
                        found=1;
                        break;
                    }
                }
            }
            if(found==1)break;
        }
        }

        printf(found?"yes\n":"no\n");
    }
    return 0;
}

