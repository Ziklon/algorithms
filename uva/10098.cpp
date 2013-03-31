#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define all(v) (v).begin(),(v).end()
#define sz size()
using namespace std;
int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    string line;
    int num;
    char cad[50];
    scanf("%d",&num);
    for(int i=0;i<num;i++){
      scanf("%s",cad);
      line=string(cad);
      sort(all(line));
      do{
         printf("%s\n",line.c_str());
      }while(next_permutation(all(line)));
      printf("\n");
    }
    return 0;
}
