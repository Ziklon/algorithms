#include <cstdio>
#include <vector>
#include <algorithm>


using namespace std;

int N, P;



int main() {
    //freopen("in.txt", "r", stdin);

    while(scanf("%d", &N) == 1) {
        if(N == 0)break;
        scanf("%d", &P);
        vector<int> ans;
        for(int p = 1; p * 2 <= N; p += 2) {
            vector<int> tmp;
            tmp.push_back(p);
            tmp.push_back(p + 1);            
            tmp.push_back(N-p);
            tmp.push_back(N-p+1);
            if(binary_search(tmp.begin(),tmp.end(), P)){
                ans = tmp;
                break;
            }
        }
        bool printed = 0;
        for(int i = 0; i < 4; ++i) {
            if(ans[i] == P)continue;
            if(printed)printf(" ");
            printf("%d", ans[i]);
            printed = 1;
        }
        printf("\n");
    }
    return 0;
}
