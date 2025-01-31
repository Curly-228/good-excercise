#include<stdio.h>
struct location
{
    int x, y, d;
}loc, loc1;

char orientation()
{
    int i;
    i = loc.d % 4;
    switch(i)
    {
        case 0 :
            return 'W';
        case 1:case -1:
            return 'N';
        case 2:case -2:
            return 'E';
        case 3:case -3:
            return 'S';
    }
}
void direction(char *order)
{
    if(*order=='R')
        (loc.d)++;
    if(*order=='L')
        (loc.d)--;
    if(*order=='F')
    {
        if(orientation()=='W')
            (loc.x)--;
        if(orientation()=='N')
            (loc.y)--;
        if(orientation()=='E')
            (loc.x)++;
        if(orientation()=='S')
            (loc.y)++;
    }
}
int main()
{
    int M, N, i, j;
    char order;
    
    
        loc.d = 1;

        while(scanf("%d%d", &M, &N)!=EOF)
        {   getchar(); 
            char a[M][N];
        for (i = 0; i < M;i++)
            {for (j = 0; j < N;j++)
                scanf("%c", &a[i][j]);
            getchar();
            }
        scanf("%d%d", &loc.y, &loc.x);
        getchar();
        while((order=getchar())!='Q')
        {
            if(order=='\n'||order==' ')
                continue;
            loc1 = loc;
            direction(&order);
            if(a[loc.y-1][loc.x-1]=='*')
                loc = loc1;
        }

        printf("%d %d %c", loc.y, loc.x, orientation());
        }
        return 0;
}//RRFLFF FFR
//FF
//RFFQ