#include <stdio.h>
#include <stdlib.h>
void TOH(int n,int a, int b, int c)
{

    if(n>0)
    {
        TOH(n-1,a,c,b);
        printf("(%d,%d)\n",a,c);
        TOH(n-1,b,a,c);

    }
}
int main()
{
    TOH(3,1,2,3);
    return 0;
}
