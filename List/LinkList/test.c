#include "LinkList.h"

int main(){
 printf("init a LinkList\n");
 LinkList L;
 InitList_Link(&L);
 printf("init a LinkList sucessfully\n");

 char test[26];
 for(int i=0;i<26;i++){
    test[i]='a'+i;
 }
 printf("insert 26 characters\n");
 for(int i=0;i<26;i++){
   ListInsert_Link(&L,1,test[i]);
 }
 
 printf("testing the func ListTraverse\n");
 ListTraverse(L,&visit);

 printf("testing the func ClearList_Link\n");
 ClearList_Link(&L);

 printf("testing the func DestroyList_Link\n");
 DestroyList_Link(&L);
 return 0;
}
