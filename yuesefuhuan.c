#include<stdio.h>
#include<stdlib.h>
typedef struct participant
{
    int a;
    struct participant* next;
} par;
par *create(int n)
{
    int i;
    par *head, *p,*q;
    head = (par*)malloc(sizeof(par));
    head->a = 1;
    p = head;
    for (i = 2; i <= n;i++)
    {
        q = (par*)malloc(sizeof(par));
        q->a = i;
        p->next = q;
        p = q;
    }
    p->next = head;
    return head;
}

int main()
{
    int n, m, i, j;
    while(1)
    {
        scanf("%d%d", &n, &m);
        if(n==0)
            break;
        par* head,*x,*p;
        head = create(n);
        
        for (i = 1; i <= n - 1;i++)
        {
            x = head;
            p = head;
            for (j = 0; j < m-2;j++)
                p = p->next;
            x = p->next;
            if(x==head)
                head = head->next;
            p->next = x->next;
            
            free(x);
            head = p->next;
        }
        printf("%d", p->a);
    }
    return 0;
}


/*
循环链表的输出
output(par *head)
{
	par *p;
	p=head;
	do 
	{
		printf("*%d\n",p->a);
		p=p->next;
	}while(p!=head);
}
*/