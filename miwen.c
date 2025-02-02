#include<stdio.h>
#include<string.h>
void encode(char a[201])
{
    int i,n;
    n=strlen(a);
    for (i = 0; i < n;i++)
        if(a[i]>='A'&&a[i]<='Z')
        {
            a[i] -= 5;//a[i]+26-5
            if(a[i]<'A')
                a[i] = a[i] + 26;
        }
}//共用首地址，不用返回值
int main()
{
    int i;
    while(1)
    {
        char input[3][201];
        gets(input[0]);
        if(!strcmp(input[0],"ENDOFINPUT"))
            break;
        gets(input[1]);
        gets(input[2]);
        encode(input[1]);
        printf("%s\n", input[1]);
    }
    return 0;
}