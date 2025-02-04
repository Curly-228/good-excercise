#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
    char s[500], t[500];
    while(scanf("%s%s",s,t)!=EOF)
    {
        char* ps=s;
        int n1,n2;
        n1 = strlen(s);
        n2 = strlen(t);
        int i;
        for (i = 0; i < n2;i++)
        {
            if(t[i]==*ps)
                ps++;
        }
        ps--;
        if(*ps==s[n1-1])
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}