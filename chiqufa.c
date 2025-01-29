#include<stdio.h>

int main()
{
    int N, n, S,i,j,length,l,r,sum;
    scanf("%d", &n);
    while(n--)
    {
        
        l = 0;
        r = 1;
        scanf("%d%d", &N, &S);
        int a[N];
        length = N+1;
        for (i = 0; i < N;i++)
            scanf("%d", &a[i]);
        sum = a[0];
        while(1)
        {
            
            if(sum>=S)
            {
                length = (length <= r - l) ? length : r - l;
                sum -= a[l];
                l++;
            }    
            else
            {
                sum += a[r];
                r++;
            }

            if(r>N)
                break;
        }
        printf("%d\n", length);
    }
        return 0;
}