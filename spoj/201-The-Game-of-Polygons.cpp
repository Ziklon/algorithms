#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;
int N,T,a,b,c;
int main(){
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        scanf("%d %d %d",&a,&b,&c);
        bool ok=0;
        int A[3]={a,b,c};
        sort(A,A+3);
        a=A[0];
        b=A[1];
        c=A[2];
        map<int,int> M;
        M[((b-a+N)%N)]++;
        M[((c-b+N)%N)]++;
        M[((c-a+N)%N)]++;

        if(M[2]==1 && M[1]==2)ok=1;

        if(ok==0){
            int tmp=N;
            if((tmp&1)==1)ok=1;
        }
        for(int i=1;i+2<N;i++)
            scanf("%d %d %d",&a,&b,&c);
        
        puts(ok?"YES":"NO");
    }

    return 0;
}

