#include"02链表.h"

void fun1(LinkList &L, elemType e){
    LNode* temp = L;
    while(temp->next != NULL){
        if(temp->next->data == e){
            LNode* t = temp->next;
            temp->next = t->next;
            free(t);
        }
        temp = temp->next;
    }
}


void fun2(LinkList &L){
    LNode* temp = L->next;
    elemType min = temp->data;
    int seg = 1;
    for(int i = 1; temp->next != NULL; i++){
        temp = temp->next;
        if(temp->data < min){
            seg = i + 1;
        }
    }
    deleteElem1(L, seg);
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


void fun4(LinkList &L, elemType e1, elemType e2){
    LNode* temp = L;
    int seg = 1;
    for(int i = 0; temp->next != NULL; i++){
        LNode* t = temp->next;
        if(t->data > e1 && t->data < e2){
            temp->next = t->next;
            free(t);
        }
        temp = temp->next;
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


void fun6(LinkList &L1, LinkList &L2){
    LNode* temp1 = L1;
    LNode* temp2 = L2;
    LNode* t1 = L1->next;
    LNode* t2 = L1->next->next;
    while(t2 != NULL){
        temp2->next = t2;
        t1->next = t2->next;
        t2 = t1->next->next;
        t1 = t1->next;
        temp2 = temp2->next;
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


void fun8(LinkList &L1, LinkList &L2){
    LNode* temp1 = L1->next;
    LNode* temp2 = L2->next;
    LinkList L;
    initList(L);
    LNode* temp = L;
    while(temp1 != NULL && temp2 != NULL){
        while(temp1->data < temp2->data && temp1 != NULL)
            temp1 = temp1->next;
        while(temp1->data > temp2->data && temp2 != NULL)
            temp2 = temp2->next;
        if(temp1->data == temp2->data){
            LNode* t = new LNode;
            t->data = temp1->data;
            t->next = NULL;
            temp->next = t;
            temp = temp->next;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
}


void fun9(LinkList &L1, LinkList &L2){
    LNode* temp1 = L1;
    LNode* temp2 = L2;
    while(temp1->next != NULL && temp2->next != NULL){
        while(temp1->next->data < temp2->next->data && temp1->next != NULL)
            temp1 = temp1->next;
        while(temp1->next->data > temp2->next->data && temp2->next != NULL)
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


bool fun10(LinkList &L1, LinkList &L2){
    LNode* temp1 = L1;
    LNode* temp2 = L2;
    while(L1->next->data != L2->next->data && L1->next != NULL)
        L1 = L1->next;
    if(L2->next == NULL)
        return false;
    while(L2->next != NULL){
        L1 = L1->next;
        L2 = L2->next;
        if(L1->data != L2->data)
            return false;
    }
    return true;
}


bool fun11(DLinkList &L){
    DNode* head = L->next;
    DNode* end = L->prior;
    while(head->next != end){
        if(head->data != end->data)
            return false;
        head = head->next;
        end = end->prior;
    }
    return true;
}


bool fun12(DLinkList &L1, DLinkList &L2){
    DNode* temp1 = L1;
    DNode* temp2 = L2;
    temp1->prior->next = temp2->next;
    temp2->prior->next = temp1;
    temp2->next->prior = temp1->prior;
    temp1->prior = temp2->prior;
}


typedef struct fNode{
    elemType data;
    struct fNode* pre;
    struct fNode* next;
    int freq;
}fNode, *fLinkList;
fNode* fun13(fLinkList &L, elemType e){
    fNode* temp = L->next;
    while( temp != NULL && temp->data != e)
        temp = temp->next;
    temp->pre++;
    fNode* t = temp;
    while(temp->pre != L && temp->pre->pre <= temp->pre)
        temp = temp->pre;
    t->pre->next = t->next;
    t->next->pre = t->pre;
    t->pre = temp->pre;
    t->next = temp;
    temp->pre->next = t;
    temp->pre = t;
}


void fun14(LinkList &L, int k){
    LNode* temp = L->next;
    int i = 1;
    while(temp->next != NULL){
        temp = temp->next;
        i++;
    }
    LNode* t = L->next;
    LNode* t2 = L;
    while(i - k > 0){
        t = t->next;
        t2 = t2->next;
        i--;
    }
    temp->next = L->next;
    L->next = t;
    t2->next = NULL;
}


bool fun15(LinkList &L){
    LNode* temp1 = L->next;
    LNode* temp2 = L->next->next;
    while(temp1 != temp2 && temp2->next != NULL && temp2 != NULL){
        temp1 = temp1->next;
        temp2 = temp2->next->next;
    }
    if(temp2->next == NULL|| temp2 == NULL)
        return false;
    return true;
}

// 不含头节点
elemType fun16(LinkList &L){
    LNode* low = L;
    LNode* high = L;
    while(high->next != NULL){
        low = low->next;
        high = high->next->next;
    }
    reverse(low);
    low = low->next;
    LNode* t = L;
    elemType max = t->data + low->data;
    while(L->next != NULL){
        t = t->next;
        low = low->next;
        if(t->data + low->data > max)
            max = t->data + low->data;
    }
    return max;
}


