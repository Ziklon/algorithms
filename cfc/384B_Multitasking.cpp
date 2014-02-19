#include <bits/stdc++.h>

using namespace std;
int n,m,k, A[1000][100];
int main(){
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&A[i][j]);
    printf("%d\n", (m*(m-1))/2);
    for(int i=0;i<m;i++)for(int j=0;j<i;j++){
        if(k)printf("%d %d\n",i+1,j+1);
        else printf("%d %d\n",j+1,i+1);
    }
    return 0;
}
