#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *p,*q;
    int i;
    p=(int *)malloc(5*sizeof(int));
    p[0]=1;p[1]=5;p[2]=5;p[3]=9;p[4]=1;
    q=(int *)malloc(10*sizeof(int)); // new array in heap of increased size

    for(i=0;i<5;i++)
        q[i]=p[i]; // transfer elements

    free(p); // delete p memory
    p=q;  // point p to q  elements
    q=NULL; // point q to null

    for(i=0;i<5;i++){
        printf("%d has the address - " , p[i]);
        printf("%u \n", &p[i]); //printing address of the elements %u,& is for address
    }
    return 0;
}
