#include <cstdio>
#include <cstring>
#define MAXN 100005
#define HASH 1000003
using namespace std;

int M1[HASH],M2[HASH];
int tree[4*MAXN];

int Q,N,M,idx,ans;
char type;
inline int gcd(int a, int b){
    if(b==0)return a;
    return gcd(b,a%b);
}
int hash(int x){
    return (((x << 1) ^ (x >> 1)) & 0x7fffffff) % HASH;
}

inline void update(int x, int val, int node, int a, int b){
    if(x<a || x>b)return;
    if(a==b)
        tree[node]=val;
    else{
        int mid=(b+a)>>1,le=(node<<1)+1,ri=(node<<1)+2;     
        if(x<=mid)
            update(x,val,le,a,mid);
        else
            update(x,val,ri,mid+1,b);
        tree[node]=gcd(tree[le],tree[ri]);  
    }
}


int main(){

    memset(tree,0,sizeof tree);
    memset(M1,0,sizeof M1);
    scanf("%d\n",&Q);
    N=0;
    int tam=0;
    while(Q--){
        scanf("%c %d\n",&type,&M);
        idx=hash(M);
        if(type=='+'){
            
            if(M1[idx]==0){
                M1[idx]++;
                M2[idx]=N;
                update(N,M,0,0,MAXN-1);
                N++;
            }else 
                M1[idx]++;
        }
        else{
            M1[idx]--;
            if(M1[idx]==0){
                idx=M2[idx];
                update(idx,0,0,0,MAXN-1);
            }
        }
        ans=tree[0];
        if(ans==0)ans=1;
        printf("%d\n",ans);                               
    }
    return 0;

}




