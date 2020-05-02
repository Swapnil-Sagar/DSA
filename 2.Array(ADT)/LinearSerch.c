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

    printf("\nElements are\n");
    for(int i=0;i<arr.length;i++)
        printf("%d ",arr.A[i]);
}

int Linear(struct Array arr,int key) //simple linear search
{
    for (int i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
           return i;
    }
    return -1;
}

void swap(int *x, int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}

int LinearMod(struct Array *arr,int key) //Searched elements will go to 0 position
{
    for (int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);
            return i;
        }
    }
    return -1;
}
int main()
{
    struct Array arr={{2,23,14,5,6,9,8,12},10,8};
    //printf("%d\n", Linear(arr,14));
    printf("%d\n", LinearMod(&arr,14));
    Display(arr);
    return 0;
}
