#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define sz size()

using namespace std;

int main(){
   int n;
   int dev=0;
   string text;
   scanf("%d\n",&n);
   getline(cin,text);
   int k=1000000;
   cout<<text<<endl;
   for(int i=0;i<text.sz;i++){
      if(abs(i-k)>1 &&( text[i]=='?' || text[i]=='!' || text[i]=='.')){
         dev++;
         k=i;
      }
   }
   if(dev>1)printf("%d\n",dev);
   else{
      int j=text.sz-1;
      while(text[j]==' ')j--;
      if(text[j]=='?' || text[j]=='!' || text[j]=='.')
         dev--;
      if(dev==0)printf("Impossible\n");
      else printf("%d\n",dev);
   }
   return 0;
}
