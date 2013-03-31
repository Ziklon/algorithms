#include <iostream>

using namespace std;

struct lista{
  int info;
  struct lista *next;
};

int main(){
  struct lista *L,*U;
  struct lista *P;
  L=NULL;
  for(int i=1;i<10;i++){
    P=(struct lista *)malloc(sizeof(struct lista));
    P->info=i;
    P->next=L;
    if(i==1)
      U=L=P;
    else
      U->next=P, U=P;    
  }
  P=L;  
  while(P!=U){
    printf("%d - ",P->info);
    P=P->next;
  }
  printf("%d - ",L->info);
  system("pause");

}
