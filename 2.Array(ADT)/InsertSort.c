#include <stdio.h>
#include <stdlib.h>
struct Array
{
        int A[10];
        int size;
        int length;
};

void Display(struct Array arr)
 {
            int i;
            printf("\nElements are\n");
            for(i=0;i<arr.length;i++)
                printf("%d ",arr.A[i]);
 }

 void swap(int *x,int *y)
 {
     int temp;
     temp=*x;
     *x=*y;
     *y=temp;
 }

 void InsertSort(struct Array *arr,int x) //insert a value in sorted array
 {
     int i=arr->length-1;
     if(arr->length==arr->size)
        return;
     while(i>=0 && arr->A[i]>x)
     {
         arr->A[i+1]=arr->A[i];
         i--;
     }
     arr->A[i+1]=x;
     arr->length++;
 }

 int isSorted(struct Array arr) //check if array is sorted
 {
     for(int i=0;i<arr.length-1;i++)
     {
         if(arr.A[i]>arr.A[i+1])
            return 0;
     }
     return 1;
 }

 void Rearrange(struct Array *arr) //to put -ve values to left and +ve values to the right
 {
     int i,j;
     i=0;
     j=arr->length-1;

     while(i<j)
     {
         while(arr->A[i]<0)i++;
         while(arr->A[j]>=0)j--;
         if (i<j)swap(&arr->A[i],&arr->A[j]);

     }

 }
int main()
{
    struct Array arr={{2,3,-9,16,-18,21,28,32,35},10,9};
    InsertSort(&arr,20);
    Rearrange(&arr);
    printf("%d\n",isSorted(arr));
    Display(arr);
    return 0;
}
