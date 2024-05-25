#include<stdio.h>
int main()
{

    int n=0, sqr, rem, sum=0;

    // printf("Enter Number: ");
    // scanf("%d",&n);

    for(int i=0;i<10;i++)
    {
        sqr = n*n;
        // printf("%d\n",sqr);
        rem = sqr%10;
        // printf("%d\n",rem);
        sum += rem;
        // printf("%d\n",sum);
        sqr /= 10;
        // printf("%d\n\n\n",sqr);
        sum += sqr;
        // printf("%d\n\n\n",sum);
        if(sum==n)
            printf("%d\n\n",n);
        n++;
        printf("%d\n\n",n);
    }
    // printf("%d",sqr);
    
    return 0;
}