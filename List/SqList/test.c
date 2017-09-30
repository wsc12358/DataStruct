#include "SqList.h"

int main(){
   SqList* SL;
   InitList_Sq(SL);
   char test[26];
   for(int i=0;i<26;i++){
     test[i]=(char)('a'+i);
   }

   printf("testing the func ListInsert_Sq\n");
   for(int i=0;i<26;i++){
     ListInsert_Sq(SL,i,test[i]);  
   }

   printf("testing the func ListTraverse_Sq\n");
   ListTraverse_Sq(SL,&visit);
  
   printf("testing the func ListEmpty_Sq\n");
   printf("%d",ListEmpty_Sq(SL));

   printf("testing the func ListLength_Sq\n");
   printf("%d",ListLength_Sq(SL));

   printf("testing the func GetElem_Sq\n");
   ElemType e;
   GetElem_Sq(SL,3,&e);
   printf("the func GetElem_Sq return %c\n",e);

   printf("testing the func LocateElem_Sq\n");
   int t=LocateElem_Sq(SL,'c',&equal);
   printf("the func LocateElem_Sq return %d\n",t);

   printf("testing the func PriorElem_Sq\n");
   ElemType pre_e;
   PriorElem_Sq(SL,'c',&pre_e);
   printf("the func PriorElem_Sq return %c\n",pre_e);

   printf("testing the func NextElem_Sq\n");
   ElemType next_e;
   NextElem_Sq(SL,'c',&next_e);
   printf("the func NextElem_Sq return %c\n",next_e);

   printf("testing the func ListDelete_Sq\n");
   ElemType e1;
   ListDelete_Sq(SL,3,&e1);
   printf("after revoked the func ListDelete_Sq\n");
   ListTraverse_Sq(SL,&visit);
   
   printf("testing the func ClearList_Sq\n");
   ClearList_Sq(SL);
   
   printf("testing the func DestroyList_Sq\n");
   DestroyList_Sq(SL);
   return 0;
}
