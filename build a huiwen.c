#include <stdio.h>
#include <string.h>
int huiwen(char *a)
{
    int i,n;
    n = strlen(a);
    for (i = n - 1; i > (n - 1) / 2; i--)
            if (a[i] != a[n - i - 1])
                return 0;
    return 1;
}
int main(int argc, char* argv[]) {
    char a[101],x[101];
    int n, i, j,flag;
    while (scanf("%s",a)!=EOF) {
        n = strlen(a);
        if (huiwen(a))
            printf("%s is a palindrome!\n", a);
        else
        {
            n = strlen(a);
            char c=a[n-1];
            char s[101];//在循环里面定义可以重新分配空间，避免了对s初始化。因为s每次的长度可能不同，如果这次比上次短，后面就会多出来一截；
            s[0] = c;
            flag = 0;
            for (i = 2; i <= n;i++)
            {
                s[i - 1] = a[n - i];
                if(a[n-i]==c)
                {
                    flag = 1;
                    s[i] = '\0';
                    break;
                }
            }
            if(flag==1)
            {
                if(huiwen(s))
                {
                    for (j = 1; n - i - j >= 0;j++)
                        x[j-1] = a[n - i - j];
                    x[j - 1] = '\0';
                    printf("%s\n", x);
                }
            }
            else
            {
                    for (i = n - 2; i >= 0;i--)
                        printf("%c", a[i]);
                    printf("\n");
            }
        }
    }

    return 0;
}
