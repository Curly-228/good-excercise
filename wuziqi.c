#include<stdc++.h>
//白棋 1 黑棋 0
int chess[5][5];
void get_chess(int n)
{
    int i,j;
    for(i = 0; i < 5;i++)
    {
        for (j = 0; j < 5;j++)
        {
            chess[i][j] = n % 2;
            n /= 2;
        }
    }
}
int win(int a)
{
    int i,j;
    for (i = 0; i < 5;i++)
    {
        for (j = 0; j<5&&chess[i][j] == a;j++)
            ;
        if(j==5)
            return 1;
        for (j = 0; j<5&&chess[j][i] == a;j++)
            ;
        if(j==5)
            return 1;
    }
    for (i = 0; i < 5 && chess[i][i] == a;i++)
        ;
    if(i==5)
        return 1;
    for (i = 0; i < 5 && chess[i][4-i] == a;i++)
        ;
    if(i==5)
        return 1;
    return 0;
}
int main()
{
    long int i,j,k,count1,count0,count=0;
    for (k = 0; k < pow(2, 25) - 1;k++)
    {
        count1 = 0;
        count0 = 0;
        get_chess(k);
        for(i = 0; i < 5;i++)
        {
            for (j = 0; j < 5;j++)
            {
                if(chess[i][j] ==1)
                    count1++;
                else
                    count0++;
            }
        }
        if(count1<count0||count1>count0+1)
            continue;
        else 
        {
            if(win(1)||win(0))
                continue;
            else
                count++;
        }
    }
    printf("%ld", count);
}