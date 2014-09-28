#include <cstdio>
#include <cstring>

using namespace std;

bool P[500];

int T, N;

int main() {
    
    //freopen("in.txt","r",stdin);
    
    for(int i=0;i<500;++i)P[i]=0;
    
    
    for(int i = 2; i * i <= 400; ++i)
        if(!P[i])
            for(int j = i * i; j <= 400; j+=i)
                P[j] = 1;


    scanf("%d", &T);

    for(int t = 1; t <= T; ++t) {
            
        scanf("%d", &N);
        int ans = 0;
        for(int p = 2; p*2 <=N; ++p)if(!P[p]) {    
                int q = (N - p);
                if(q >= 2 && P[q]==0) ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}
