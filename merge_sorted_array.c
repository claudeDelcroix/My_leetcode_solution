#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

void tri_a_bulle(int *t, int n)
{
   int j = 0;
   int tmp = 0;
   int en_desordre = 1;
   while(en_desordre)
   {
      en_desordre = FALSE;
      for(j = 0 ; j < n- 1 ; j++){
           if(t[j] > t[j+1]){
               tmp = t[j+1];
               t[j+1] = t[j];
               t[j] = tmp;
              en_desordre = TRUE;
          }
       }
    }
}


void merge(int* nums1, int nums1Size,int m,int* nums2, int nums2Size, int n){

     for(int i = m,j = 0;i<nums1Size;i++,j++){
        nums1[i] = nums2[j];
     }

     tri_a_bulle(nums1,m + n);

     for(int i = 0;i<nums1Size;i++){
        printf("%d      ",nums1[i]);
     }
}


int main()
{
    int t[3] = {2,5,6};
    int q[6] = {1,2,3,0,0,0};
    merge(q,6,3,t,3,3);
    return 0;
}
