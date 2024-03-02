#include<iostream>
#include<iostream>
#include<cmath>
#include<algorithm>

#define elemType int
#define maxcSize 50

// 单链表的定义
typedef struct LNode{
    elemType data;
    struct LNode* next;
}LNode, *LinkList;


// 单链表的初始化(带头节点)
void initList(LinkList &L){
    L = new LNode;
    //L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
}
// // 单链表的初始化(不带头节点)
// void initList(LinkList &L){
//     L = NULL;
// }


// 尾插法建立单链表
void creatListT(LinkList &L, elemType a[], int n){
    L = new LNode;
    L->next = NULL;
    LNode* s;   //新节点
    LNode* r = L;   //尾指针
    for(int i = 0; i < n; i++){
        s = new LNode;
        s->data = a[i];
        r->next = s;
        r = s;
    }
    r->next = NULL;
}


// 头插法建立单链表
void creatListH(LinkList &L, elemType a[], int n){
    L = new LNode;
    L->next = NULL;
    LNode* s;   //新节点
    for(int i = 0; i < n; i++){
        s = new LNode;
        s->data = a[i];
        s->next = L->next;
        L->next = s;
    }
}


// 链表求表长(单双通用)
template <class Node>
int getLenth(Node &L){
    int len = 0;
    Node temp = L;
    while(temp->next != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}


// 链表按序号查找(单双通用)
template <class Node>
Node getElem(Node &L, int i){
    Node temp = L;
    while(temp->next != NULL && i-- > 0)
        temp = temp->next;
    return temp;
}


// 链表按值查找(单双通用)
template <class Node>
Node findElem(Node &L, elemType e){
    Node temp = L;
    temp->data  = NULL;
    while(temp->next != NULL && temp->data != e)
        temp = temp->next;
    return temp;
}


// 单链表插入节点
void insertElem1(LinkList &L, int i, elemType e){
    LNode* node = getElem(L, i);
    LNode* newnode = new LNode;
    newnode->data = node->data; //深拷贝
    newnode->next = node->next;
    node->next = newnode;
    node->data = e;
    return;
}


// 单链表删除节点
void deleteElem1(LinkList &L, int i){
    LNode* node = getElem(L, i);
    LNode* temp = node->next;
    node->data = node->next->data;
    node->next = node->next->next;
    free(temp);
    return;
}


// 打印链表(单双通用)
template <class Node>
void printList(Node &L){
    Node temp = L->next;
    while(temp != NULL){
        std::cout << temp->data;
        temp = temp->next;
    }
}



void fun3(LinkList &L){
    LNode* begin = L->next;
    LNode* end = L->next->next;
    while(end->next != NULL){
        begin->next = end->next;
        end->next = L->next;
        L->next = end;
        end = begin->next;
    }
}


void fun6(LinkList &L1, LinkList &L2){
    LNode* temp1 = L1;
    LNode* temp2 = L2;
    LNode* t1 = L1->next;
    LNode* t2 = L1->next->next;
    while(t2 != NULL){
        temp2->next = t2;
        temp2 = temp2->next;
        t1->next = t2->next;
        t1 = t1->next;
        t2 = t1->next;
        
    }
}

void fun7(LinkList &L){
    LNode* temp1 = L;
    LNode* temp2 = temp1->next;
    while(temp2 != NULL){
        if(temp1->next->data == temp2->next->data){
            LNode* t = temp2;
            temp1->next = temp2->next;
            free(t);
        }
        temp1 = temp1->next;
        temp2 = temp1->next;
    }
}

void fun9(LinkList &L1, LinkList &L2){
    LNode* temp1 = L1;
    LNode* temp2 = L2;
    while(temp1->next != NULL && temp2->next != NULL){
        while(temp1->next->data < temp2->next->data && temp1->next->next != NULL)
            temp1 = temp1->next;
        while(temp1->next->data > temp2->next->data && temp2->next->next != NULL)
            temp2 = temp2->next;
        if(temp1->next->data != temp2->next->data){
            LNode* t = temp1->next;
            temp1->next = t->next;
            free(t);
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}

LNode* fun5(LinkList &L1, LinkList &L2){
    int len1 = getLenth(L1);
    int len2 = getLenth(L2);
    LNode* temp1 = L1;
    LNode* temp2 = L2;
    if(len1 > len2){
        int dist = len1-len2;
        while(dist-- > 0)
            temp1 = temp1->next;
    }
    if(len1 < len2){
        int dist = len1-len2;
        while(dist++ < 0)
            temp2 = temp2->next;
    }
    while(L1 != NULL){
        if(temp1 == temp2)
            return temp1;
        else{
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return NULL;
}

int main(){
    LinkList L1, L2;
    elemType a[6] = {1,2,2,4,5,5};
    elemType b[4] = {1,3,4,6};
    creatListT(L1, a, 6);
    creatListT(L2, b, 4);
    //initList(L2);
    //fun7(L1);
    fun9(L1,L2);
    printList(L1);
    printList(L2);
    return 0;
}