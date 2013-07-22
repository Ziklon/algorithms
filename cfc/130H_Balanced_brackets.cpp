#include<bits/stdc++.h>
#define REP(i,n)for (int i=0;i<n;i++)
#define first fst
#define second snd
#define all(v) (v).begin(), (v).end()
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
char s[200];
int N;
int main(){
    scanf("%s",s);
    N=strlen(s);
    bool flag=1;
    int cnt=0;
    REP(i,N){
        if(s[i]=='(')cnt+=1;
        else if(s[i]==')')cnt-=1;
        if(cnt<0)flag=0;
    }
    if(cnt!=0)flag=0;
    puts(flag?"YES":"NO");
    return 0;
}
