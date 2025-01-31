#include<stdio.h>
#include<string.h>
int probability(char a[80],int i,int n)
{
    int j;
    if(a[i]=='.')
            return 100;
        if(a[i]=='_')
            return 0;
        if(a[i]=='/')
        {
            for (j = i-1;j>=0;j--)
                {
                    if(a[j]=='.')
                        return 100;
                    if(a[j]=='/'||a[j]=='\\'||a[j]=='|')
                        return 0;
                }
            if(j==-1)
                    return 100;
        }
        if(a[i]=='\\')
        {
            for (j = i+1;j<n;j++)
                {
                    if(a[j]=='.')
                        return 100;
                    if(a[j]=='/'||a[j]=='\\'||a[j]=='|')
                        return 0;
                }
            if(j==n)
                    return 100;
        }
        int score=0;
        if(a[i]=='|')
        {
            for (j = i+1;j<n;j++)
                {
                    if(a[j]=='.')
                    {
                        score += 50;
                        break;
                    }
                    if(a[j]=='/'||a[j]=='\\'||a[j]=='|')
                    {
                        score += 0;
                        break;
                    }
                }
            if(j==n)
                score+=50;
            for (j = i-1;j>=0;j--)
                {
                    if(a[j]=='.')
                    {
                        score += 50;
                        break;
                    }
                    if(a[j]=='/'||a[j]=='\\'||a[j]=='|')
                    {
                        score += 0;
                        break;
                    }
                }
            if(j==-1)
                score+=50;
            return score;
        }    
}
int main()
{
    char a[80];
    int i,n;
    scanf("%s", a);
    while(strcmp(a,"#"))
    {
        n=strlen(a);
        int p=0;
        for (i = 0; i < n;i++)
            p += probability(a,i, n);
        p = (int)(p / n );
        printf("%d\n", p);
        scanf("%s", a);
    }
    return 0;
}