#include <bits/stdc++.h>

using namespace std;
int n;
int main(){
    scanf("%d",&n);
    int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
                if((i+j)%2==0)ans++;
    
    printf("%d\n",ans);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           printf("%c",(i+j)%2==0 ? 'C':'.'); 
        }
        printf("\n");
    }

    return 0;
}
