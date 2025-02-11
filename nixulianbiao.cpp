/*#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int data;
    struct ListNode *next;
};

struct ListNode *createlist()
{
    struct ListNode* p=(struct ListNode*)malloc(sizeof(struct ListNode));
    p->next = NULL;
    while(1)
    {
        scanf("%d", &p->data);
        if(p->data==-1)
            return p->next;
        struct ListNode* q=(struct ListNode*)malloc(sizeof(struct ListNode));
        q -> next = p;
        p = q;
    }
}

int main()
{
    struct ListNode *p, *head = NULL;

    head = createlist();
    for ( p = head; p != NULL; p = p->next )
        printf("%d ", p->data);
    printf("\n");
    return 0;
}
*/
/* 你的代码将被嵌在这里 */


/* 你的代码将被嵌在这里 */
#include <stdio.h>
#include <stdlib.h>

struct link
{
    int data;
    struct link *next;
};

struct link *AppendNode(struct link *head,int data);
void DisplyNode(struct link *head);
void DeleteMemory(struct link *head);
struct link *AppendNode(struct link *head,int data)
{
    struct link* q = (struct link*)malloc(sizeof(struct link));
    q->next = NULL;
    q->data = data;
    if (head == NULL) // 如果链表为空，新节点就是头节点
    {
        return q;
    }
    struct link* p = (struct link*)malloc(sizeof(struct link));
    p=head;
    while(p->next!=NULL)
    {
        p = p->next;
    }
    p->next = q;
    return head;
}
void DisplyNode(struct link *head)
{
    struct link* p = (struct link*)malloc(sizeof(struct link));
    p = head;
    while (p->next != NULL)
    {
        printf("%d->", p->data);
        p = p->next;
    }
    printf("%d", p->data);
}
void DeleteMemory(struct link *head);
int main()
{
    char    c;
    int data = 0;
    struct link *head = NULL;      /* 链表头指针 */
    while (1)
    {
        scanf("%d",&data);
        if (data==-1)
            break;

        head = AppendNode(head,data);/* 向head为头指针的链表末尾添加节点 */
    }
    DisplyNode(head);        /* 显示当前链表中的各节点信息 */
    DeleteMemory(head);           /* 释放所有动态分配的内存 */
    return 0;
}
/*在此实现 void DeleteMemory(struct link *head);*/
void DeleteMemory(struct link *head)
{
    struct link *p, *pnext;
    p = head;
    while (p != NULL)
    {
        pnext = p->next;
        free(p);
        p = pnext;
    }

}

/*在此实现 struct link *AppendNode(struct link *head,int data); */

/*在此实现 void DisplyNode(struct link *head); */


/* 请在这里填写答案 */