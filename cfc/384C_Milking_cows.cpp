#include <bits/stdc++.h>

using namespace std;
int a[1<<20],n;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",&a[i]);
    long long ans=0,cnt=0;

    for(int i=0;i<n;i++){
        cnt+=a[i];
        if(a[i]==0)ans+=cnt;
    }
    printf("%I64d\n",ans);

    return 0;
}
