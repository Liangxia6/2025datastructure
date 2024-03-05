#include"02链表.h"

elemType fun17(LinkList &L, int k){
    LNode* temp1 = L;
    LNode* temp2 = L;
    while(--k)
        temp2 = temp2->next;
    while(temp2->next != NULL){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1->data;
}


LNode* fun18(LinkList &L1, LinkList &L2){
    LNode* temp1 = L1;
    LNode* temp2 = L2;
    int i = 0, j = 0;
    while(temp1->next != NULL){
        temp1 = temp1->next;
        i++;
    }
    while(temp2->next != NULL){
        temp2 = temp2->next;
        j++;
    }
    temp1 = L1;
    temp2 = L2;
    if(i > j){
        int dis = i - j;
        while(dis--)
            temp1 = temp1->next;
    }
    if(i < j){
        int dis = i - j;
        while(dis++)
            temp2 = temp2->next;
    }
    while(temp1->data != temp2->data){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}


void fun19(LinkList &L, int n){
    LNode* pre = L;
    LNode* temp = L->next;
    int* num = new int[n+1];
    while(temp->next != NULL){
        if(num[std::abs(temp->data)] == 0){
            num[std::abs(temp->data)]++;
        }else{
            LNode* t = temp;
            pre->next = temp->next;
            temp = temp->next;
            free(t);
        }
    }
    free(num);
}


// error
void fun20(LinkList &L){
    LNode* begin = L->next->next;
    LNode* end = L->next->next->next->next;
    while(end->next->next != NULL){
        begin->next->next = end->next->next;
        end->next->next = L->next->next;
        L->next->next = end;
        end = begin->next->next;
    }
}