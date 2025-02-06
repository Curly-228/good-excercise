#include <math.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[]) {
    long int i, a[8];
    for (i = 0; i <= 7; i++) {
        a[i] = pow(7, i);
    }
    int f[20000]={0};
    int i1, i2, i3, i4, i5, i6, i7, i8;
    long int sum;
    int fenshu;
    i = 0;
    for (i1 = 0; i1 <= 5; i1++) {
 
        for (i2 = 0; i2 <= 5; i2++) {
       
            for (i3 = 0; i3 <= 5; i3++) {
          
                for (i4 = 0; i4 <= 5; i4++) {
               
                    for (i5 = 0; i5 <= 5; i5++) {
                      
                        for (i6 = 0; i6 <= 5; i6++) {
                            
                            for (i7 = 0; i7 <= 5; i7++) {
                               
                                for (i8 = 0; i8 <= 5; i8++) {
                                    sum = i1 * a[0] + i2 * a[1] + i3 * a[2] +
                                          i4 * a[3] + i5 * a[4] + i6 * a[5] +
                                          i7 * a[6] + i8 * a[7];
                                    if(sum>1000000)
                                        break;
                                    fenshu =
                                        i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8;
                                    if(sum==1000000)
                                    {
                                        f[i] = fenshu;
                                        i++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    int j,max=f[0];
    for (j = 1; j < i;j++)
    {
        max = (f[j] > max ? f[j] : max);
    }
    printf("%d", max);
    return 0;
}