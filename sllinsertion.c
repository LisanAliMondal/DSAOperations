#include<stdio.h>
int main()
{
    int a[50],size,i,num,pos;
    printf("enter the size :");
    scanf("%d,&size");
    printf("enter elements of array :\n");
    for (i=0;i<size;i++)
    {
        scanf("%d,a[i]");
    }
    printf("enter data to insert\n");
    scanf("%d",&num);
    printf("enter the pos\n");
    scanf("%d",&pos);
    for(i=size-1;i>=pos-1;i--)
    {
        a[i+1]=a[i];
    }
    a[pos-1]=num;
    size=size++;  
    return 0;

}