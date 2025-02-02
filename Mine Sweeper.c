#include<stdio.h>
#define R(i,j) i>=0&&j>=0&&i<n&&j<n
int cal(int x,int y,int n,char a[10][10])
{
    int count=0;
    if(R(x-1,y-1)&&a[x-1][y-1]=='*')
        count++;
    if(R(x,y-1)&&a[x][y-1]=='*')
        count++;
    if(R(x+1,y-1)&&a[x+1][y-1]=='*')
        count++;
    if(R(x-1,y)&&a[x-1][y]=='*')
        count++;
    if(R(x+1,y)&&a[x+1][y]=='*')
        count++;
    if(R(x-1,y+1)&&a[x-1][y+1]=='*')
        count++;
    if(R(x,y+1)&&a[x][y+1]=='*')
        count++;
    if(R(x+1,y+1)&&a[x+1][y+1]=='*')
        count++;
    return count;
}
int main()
{
    int n, i, j,flag;
    while(scanf("%d",&n)!=EOF)
    {
        flag = 0;
        char a[10][10],b[10][10],result[10][10];
        for (i = 0; i < n;i++)
        {
            getchar();
            for (j = 0; j < n;j++)
                {
                    a[i][j] = getchar();
                    result[i][j] = '.';
                }
        }
        for (i = 0; i < n;i++)
        {
            getchar();
            for (j = 0; j < n;j++)
            {
                if((b[i][j] = getchar()) =='x')
                    {
                        result[i][j] =(char)(cal(i, j,n, a)+'0');
                        if(a[i][j]=='*')
                             flag = 1;
                    }
            }
        }
        if(flag==0)
        {
        for (i = 0; i < n;i++)
        {
            for (j = 0; j < n;j++)
                putchar(result[i][j]);
            putchar('\n');
        }
        }
        else
        {
            for (i = 0; i < n;i++)
            {
                for (j = 0; j < n;j++)
                {
                    if(a[i][j]=='*')
                        printf("*");
                    else if(b[i][j]=='.')
                        printf(".");
                    else
                    printf("%c", result[i][j]);
                        
                }
                printf("\n");
            }
        }
        printf("\n");
    }
    return 0;
}