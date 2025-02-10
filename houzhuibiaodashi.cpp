#include<stdc++.h>
#include <iostream>
using namespace std;
int main()
{
    stringstream streamer;
    string str;
    getline(cin, str, '@');
    stack<int> sta;
    for(auto &c :str)
    {
        if(c=='.')
        {
            int val;
            streamer >> val;
            sta.push(val);
            
            streamer.clear();
        }
        else if(isdigit(c))
            streamer << c;
        else
        {
            int a, b;
            a = sta.top();
            
            sta.pop();
            b = sta.top();
            
            sta.pop();
            switch(c)
            {
                case '+':
                    sta.push(a + b);
                    break;
                case '-':
                    sta.push(b - a);
                    break;
                case '*':
                    sta.push(a * b);
                    break;
                case '/':
                    sta.push(b / a);
                    break;
            }
        }
    }
    printf("%d", sta.top());
    return 0;
}