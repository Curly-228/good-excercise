#include<stdio.h>
#include<iostream>
#include<stack>
#include<stdc++.h>
using namespace std;
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize) {
    int *result;
    result = (int*)malloc(sizeof(int) * temperaturesSize);
    memset(result, 0, sizeof(int) * temperaturesSize);
    *returnSize = temperaturesSize;
    stack<int> sta;
    sta.push(0);
    int i, j;
    for (i = 1;i<temperaturesSize;i++)
    {
        if(temperatures[sta.top()]<temperatures[i])
        {
            while(!sta.empty()&&temperatures[sta.top()]<temperatures[i])
            {
                result[sta.top()] = i - sta.top();
                sta.pop();
            }
            sta.push(i);
        }
        else 
        {
            sta.push(i);
        }
    }
    return result;
}
int main()
{
    int temperatures[8]={73,74,75,71,69,72,76,73};
    int returnSize;
    int *a;
    a=dailyTemperatures(temperatures, 8, &returnSize);
    printf("[");
    for (int i = 0; i < returnSize; i++) {
        printf("%d", a[i]);
        if (i < returnSize - 1) {
            printf(", ");
        }
    }
    printf("]\n");

}