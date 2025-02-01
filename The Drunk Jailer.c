#include<stdio.h>
int main()
{

    int z,i,j,count;//0是开着，1是关着
    scanf("%d", &z);
    int a[z];
    for (i = z-1; i >=0;i--)
        scanf("%d", &a[i]);
    while(z--)
    {
        int b[101] = {0};
        count = 0;
        for (i = 2; i <= a[z];i++)
            for (j = 1; i*j <=a[z];j++)
                b[i * j-1] = 1 - b[i * j-1];
        for (i = 0; i < a[z];i++)
        if(b[i]==0)
            count++;
        printf("%d\n", count);
    }
        return 0;
}