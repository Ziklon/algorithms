#include<bits/stdc++.h>
#define REP(i,n)for (int i=0;i<n;i++)
using namespace std;
typedef long long ll;
#define MAXN 100005
int N,K,tmp;
int tree[MAXN*4],A[MAXN];
char type;
void build_tree(int node, int a, int b){
    if(a==b)tree[node]=A[a];
    else{
        int mid=(a+b)>>1,le=(node*2)+1,ri=(2*node)+2;
        build_tree(le,a,mid);
        build_tree(ri,mid+1,b);
        tree[node]=tree[le]*tree[ri];
    }
}

int query(int x, int y, int node, int a, int b){
    
    if(x<=a && b<=y)return tree[node];
    int mid=(a+b)>>1, le=(node*2)+1,ri=(node*2)+2;
    if(y<=mid)return query(x,y,le,a,mid);
    else if(x>mid)return query(x,y,ri,mid+1,b);
    else{
        int ans1=query(x,y,le,a,mid);
        int ans2=query(x,y,ri,mid+1,b);
        return ans1*ans2;
    }
}

void update(int x, int val , int node, int a, int b){
    if(x<a || x>b)return;
    if(a==b)tree[node]=val;
    else{
        int mid=(a+b)>>1, le=(node*2)+1, ri=(2*node)+2;
        update(x,val,le,a,mid);
        update(x,val,ri,mid+1,b);
        tree[node]=tree[le]*tree[ri];
    }
}

int get_val(int x){
    if(x>0)return 1;
    if(x<0)return -1;
    return 0;
}

char getsign(int x){
    if(x>0)return '+';
    if(x<0)return '-';
    return '0';
}
int idx, val,xi,yi;
int main(){

    while(scanf("%d %d",&N,&K)==2){
        REP(i,N){
            scanf("%d",&tmp);
            A[i]=get_val(tmp);
        }
        scanf("\n");
        build_tree(0,0,N-1);
        REP(i,K){
            scanf("%c",&type);
            if(type=='C'){
                scanf("%d %d\n",&idx,&val);
                update(idx-1,get_val(val),0,0,N-1);
            }else{
                scanf("%d %d\n",&xi,&yi);
                val=query(xi-1,yi-1,0,0,N-1);
                printf("%c",getsign(val));
            }
        }
        printf("\n");                
    }
    return 0;
}

