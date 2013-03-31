#include <stdio.h>
int main(){
    int i;
    double sum=0;
    double fc=1;
    printf("n e\n");
    printf("- -----------\n");
    for(i=0;i<=9;i++){
        if(i!=0) fc*=i;
        sum+=1/fc;
        printf("%d %.9f\n",i,sum);
    }
    return 0;
}
