#include <cstdio>
#include <iostream>
#define all(v) (v).begin(),(v).end()
#define sz size()
using namespace std;
int main(){
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t,a,b,i,j,ans;
    scanf("%d",&t);
    for(i=1;i<=t;i++){
      scanf("%d %d",&a,&b);
      ans=0;
      for(j=a;j<=b;j++)if(j&1)ans+=j;
      printf("Case %d: %d\n",i,ans);
    }
    return 0;
}
