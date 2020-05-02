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

struct Array* Union(struct Array *arr1, struct Array *arr2 ) //Similar to merge but same elements are copied once
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr1->A[i]>arr2->A[j])
            arr3->A[k++]=arr2->A[j++];
        else
        {
          arr3->A[k++]=arr1->A[i++];
            j++;
        }

    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    for(;j<arr2->length;j++)
        arr3->A[k++]=arr2->A[j];
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Intersection(struct Array *arr1, struct Array *arr2 ) //Similar to merge but only gives same elements
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            i++;
        else if(arr1->A[i]>arr2->A[j])
            j++;
        else
        {
          arr3->A[k++]=arr1->A[i++];
            j++;
        }

    }
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Difference(struct Array *arr1, struct Array *arr2 ) //Similar to merge but gives difference of array 1 from array 2 (A-B) != (B-A)
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
            arr3->A[k++]=arr1->A[i++];
        else if(arr1->A[i]>arr2->A[j])
            j++;
        else
        {
            i++;
            j++;
        }

    }
    for(;i<arr1->length;i++)
        arr3->A[k++]=arr1->A[i];
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

int main()
{
    int ch;
    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,4,6,18,20},10,5};
    struct Array *arr3;

    do
    {
    printf("Menu\n");
    printf("1. Union\n");
    printf("2. Intersection\n");
    printf("3. Difference\n");
    printf("4. Exit\n");

    printf("Enter your Choice ");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1:
        arr3=Union(&arr1,&arr2);
        Display(*arr3);
        break;
    case 2:
        arr3=Intersection(&arr1,&arr2);
        Display(*arr3);
        break;
    case 3:
        arr3=Difference(&arr1,&arr2);
        Display(*arr3);
        break;
    }
}while(ch<4);


    return 0;
}
