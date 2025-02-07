#include<stdc++.h>
#include<stdio.h>
int main()
{
    char a[200][30];
    long long int x;
    while(1)
    {
        int i=0;
        while(1)
        {
            scanf("%s", a[i]);
            if(strcmp(a[i],"\n"))
                break;
        }
        for (i--; i >= 0;i--)
            puts(a[i]);
    }
    return 0;
}