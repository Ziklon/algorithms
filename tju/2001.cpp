#include <iostream>
#include <map>
using namespace std;

int main(void)
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int nC,cs;
    string s;
    cin>>nC;
    for(int i=1;i<=nC;i++){
      cin>>cs;
      map<string,int> mp;
      for(int j=0;j<cs;j++){
       cin>>s;
       mp[s]++;
      }
      printf("Case %d: This list contains %d sheep.\n",i,mp["sheep"]);
      if(i!=nC)
        printf("\n");
    }
    return 0;
}

