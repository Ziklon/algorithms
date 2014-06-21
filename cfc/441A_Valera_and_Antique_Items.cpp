#include <bits/stdc++.h>
#define all(v)  v.begin() , v.end()
using namespace std;
typedef long long ll;
int n,v,ki,ti;
int main() {
    scanf("%d %d",&n,&v);
    vector<int> ans;
    for(int i=0;i<n;++i){
        scanf("%d",&ki);
        bool can=0;
        for(int j=0;j<ki;++j){
            scanf("%d",&ti);
            if(v>ti)can=1;
        }
        if(can)ans.push_back(i+1);
    }
    printf("%d\n",ans.size());
    for(int i=0;i<ans.size();++i){
        if(i)printf(" ");
        printf("%d",ans[i]);        
    }
    return 0;
}
