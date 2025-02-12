#include<stdio.h>
char a[3][3];
int judge(char c)
{
    int i,j;
    for (i = 0; i < 3;i++)
    {
        for (j = 0; j<3&&a[i][j] == c;j++)
            ;
        if(j==3)
            return 1;
        for (j = 0; j<3&&a[j][i] == c;j++)
            ;
        if(j==3)
            return 1;
    }
    for (i = 0; i < 3 && a[i][i] == c;i++)
        ;
    if(i==3)
        return 1;
    for (i = 0; i < 3 && a[i][2-i] == c;i++)
        ;
    if(i==3)
        return 1;
    return 0;
}
int main()
{
    int n,i,j,cnx,cno;
    scanf("%d", &n);
    while(n--)
    {
        cnx = 0;
        cno = 0;
        
        getchar();
        for (i = 0; i < 3;i++)
        {
            for (j = 0; j < 3;j++)
            {
                a[i][j]=getchar();
                if(a[i][j]=='X')
                    cnx++;
                if(a[i][j]=='O')
                    cno++;
            }
            getchar();
        }
    if(cnx<cno||cnx>cno+1||judge('X')&&cno==cnx||judge('O')&&cnx==cno+1||judge('X')&&judge('O'))
        printf("no\n");
    else
    printf("yes\n");    
    }
    return 0;
}