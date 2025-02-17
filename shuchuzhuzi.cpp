#include<stdio.h>
#include<stdc++.h>
#include <iostream>
using namespace std;
void print(char **res,char c,int val,int count)
{
    int i;
    for (i = 1; i <= abs(val);i++)
    {
        if(val<0)
            res[15 + i][count] = c;
        else
            res[15 - i][count] = c;
    }
}
int main()
{
    int  i, j,m,val,n=1,flag=0,count=0,max=0,min=0;
    scanf("%d",&m);
    string str;
    stringstream streamer;
    char **res = (char **)malloc(31 * sizeof(char *));
    for (int i = 0; i < 31; i++) 
    {
            res[i] = (char *)malloc((2*m-1) * sizeof(char));
    }
    for (i = 0; i < 31;i++)
        for (j = 0; j < 2 * m - 1;j++)
            res[i][j]=' ';
    for (i = 0; i < 2 * m - 1;i++)
        res[15][i]='-';
    getchar();
    getline(cin,str);
    str += ' ';
    for(auto &c:str)
    {
        if(c<='9'&&c>='0')
        {
            streamer << c;
            streamer >> val;
            streamer.clear();
            val *= n;
            n = 1;
        }
        else if(c=='-')
        {
            n = -1;
        }
        else if(c==' ')
        {
            if(flag==0)
            {
                print(res, '+',val,count);
                if(val<0)
                    min = val < min ? val : min;
                else
                    max = val > max ? val : max;
                count += 2;
            }
            flag = 0;
        }
        else
        {
            print(res, c,val,count);
            if(val<0)
                    min = val < min ? val : min;
                else
                    max = val > max ? val : max;
            count += 2;
            flag = 1;
        }
    }
    for (i = 15-max; i <= 15-min;i++)
    {
        for (j = 0; j < 2 * m - 1;j++)
            printf("%c", res[i][j]);
        cout << endl;
    }
    return 0;
}