#include<stdio.h>
void kmp(char *s,int *w,int n,int *a)
{
    int count, max,i;
    for (i = 0; i < n;i++)//n个右括号都匹配一次
    {
        count = 1;
        max = 1;
        do
        {
            if(s[a[i]-1]==')')
                {count++;
                max++;
            } else
                count--;
            a[i]--;
        } while (count);
        w[i] = max;
    }
}
int main()
{
    int x,n,i,j,m,k1,k2,a1;
    scanf("%d", &x);
    for (i = 0; i <x; i++)
    {
        scanf("%d", &n);
        int p[n],w[n],a[n];//a数组的作用是记住右括号在s数组里的位置
        for (j = 0; j < n;j++)
            scanf("%d", &p[j]);
        char s[2*n];
        m = 0;
        k1 = 0;
        a1 = 0;
        for (j = 0; j < n;j++)//n个数 n个右括号
        {
            for (k2 = 0; k2 < p[j] - m;k2++)
            {
                s[k1+k2] = '(';
            }  // 第k-1个元素
            s[k1+k2] = ')';
            a[a1] = k1 + k2;
            a1++;
            k1+=(p[j]-m+1);
            m = p[j];
        }
        //for (j = 0; j < 2*n;j++)
        //    printf("%c", s[j]);
        kmp(s, w, n,a);
        for (j = 0; j < n;j++)
            printf("%d ", w[j]);
        printf("\n");
    }
        return 0;
}