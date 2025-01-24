#include<stdio.h>
#include<string.h>
int room[5][6];
int room_click[5][6];
int result[5][6];
void get_click(int n,int click[])
{
    int i;
    for(i = 0; i < 6;i++)
    {
        printf("i = %d\n", i); // 调试输出
        click[5 - i] = n % 2;
        n /= 2;
    }
}
void flip_light(int *a,int b)
{
    if(b)
        *a = 1 - *a;
}
int main()
{
    int i, j, n, flag, count ;
    scanf("%d", &count);
    for (i = 0; i < 5;i++)
        for (j = 0; j < 6;j++)
            scanf("%d", &room[i][j]);
            for (i = 0; i < 5;i++)
        for (j = 0; j < 6;j++)
            printf("%3d", room[i][j]);
    for (n = 0; n < 64;i++)
    {
        flag = 0;
        int click[6] = {0};  // 所有元素都是0 click[6]={1,2,3};->{1,2,3,0,0,0}
        get_click(n, click);//n=11=0b001011 click={0,0,1,0,1,1}
        memcpy(room_click, room, sizeof(room));//每试一种方案的时候，不要动room，要不然试下一种的时候，没有初始值了。
        for (i = 0; i < 5;i++)
        {
            memcpy(result[i], click,sizeof(click));
            for (j = 0; j < 6;j++)
            {
                if(j>0)
                    flip_light(&room_click[i][j - 1], click[j]);
                flip_light(&room_click[i][j], click[j]);
                if(j<5)
                    flip_light(&room_click[i][j + 1], click[j]);
                if(i>0)
                    flip_light(&room_click[i - 1][j], click[j]);
                if(i<4)
                    flip_light(&room_click[i + 1][j], click[j]);
            }
            memcpy(click, room_click[i], sizeof(room_click[i]));
        }
        for (i = 0; i < 6;i++)
        if(room_click[4][i]==1)
        {
            flag=1;
            break;
        }
        
        if(flag==0){
            
            printf("PUZZLE #%d", count);
            for (i = 0; i < 5;i++)
            {
                for (j = 0; j < 6;j++)
                    printf("%d ", result[i][j]);
                printf("\n");
            }
        }
    }
    return 0;
}