#include<iostream>
#include<cmath>
#include<algorithm>
#include"04队列.h"

#define maxcSize 50
#define initSize 100
#define elemType int


// 普通二叉树的定义
typedef struct BTNode{
    elemType data;
    struct BTNode* lchild;
    struct BTNode* rchild;
}BTNode, *BTree;


// 先序遍历 (递归)
void preorder(BTree T){
    if(T != nullptr){
        printf("%c ", T->data);
        preorder(T->lchild);
        preorder(T->rchild);
    }
}


// 中序遍历 (递归)
void inorder(BTree T){
    if(T != nullptr){
        preorder(T->lchild);
        printf("%c ", T->data);
        preorder(T->rchild);
    }
}


// 后序遍历 (递归)
void postorder(BTree T){
    if(T != nullptr){
        preorder(T->lchild);
        preorder(T->rchild);
        printf("%c ", T->data);
    }
}


// 层序遍历
void levelorder(BTree T){
    BTree queue[maxcSize];
    BTree temp = NULL;
    int front = 0, rear = 0;
    rear = (rear+1) % maxcSize;
    queue[rear] = T;
    while(queue[front] != queue[rear]){
        front = (front+1) % maxcSize;
        temp = queue[front];
        printf("%c ", temp->data);
        if(temp->lchild != NULL){
            rear = (rear+1) % maxcSize;
            queue[rear] = T->lchild;
        }
        if(temp->rchild != NULL){
            rear = (rear+1) % maxcSize;
            queue[rear] = T->rchild;
        }
    }
}


// 先序遍历 (非递归)
void preorder2(BTree T){
    BTree stack[maxcSize];
    int top = -1;
    stack[++top] = T;
    BTree temp;
    while(top != -1){
        temp = stack[top--];
        printf("%c ", temp->data);
        if(temp->rchild != NULL)
            stack[++top] = temp->rchild;
        if(temp->lchild != NULL)
            stack[++top] = temp->lchild;
    }
}


// 中序遍历 (非递归)
void inorder2(BTree T){
    BTree stack[maxcSize];
    int top = -1;
    BTree temp = T;
    while (top != -1 || temp != NULL) {
        while (temp != NULL) {
            stack[++top] = temp;
            temp = temp->lchild;
        }
        if (top != -1) {
            temp = stack[top--];
            printf("%c\n", temp->data);
            temp = temp->rchild;
        }
    }
}


// 后序遍历 (非递归)
void postorder2(BTree T){
    BTree stack[maxcSize];
    BTree reverse[maxcSize];
    int top = -1;
    int top2 = -1;
    stack[++top] = T;
    BTree temp;
    while(top != -1){
        temp = stack[top--];
        reverse[++top2] = temp;
        if(temp->lchild != NULL)
            stack[++top] = temp->lchild;
        if(temp->rchild != NULL)
            stack[++top] = temp->rchild;
    }
    while(top2 != -1){
        temp = reverse[top2--];
        printf("%c ", temp->data);
    }
}




// 线索二叉树的定义
typedef struct ThreadNode{
    elemType data;
    int ltag;
    struct ThreadNode* lchild;
    int rtag;
    struct ThreadNode* rchild;
}ThreadNode, *ThreadTree;


// 建立先序线索二叉树 (传入普通二叉树)
void PreThread(ThreadTree &T, ThreadTree &pre){
    if(T != NULL){
        if(T->lchild == NULL){
            T->lchild = pre;
            T->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL){
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;
        PreThread(T->lchild, pre);
        PreThread(T->rchild, pre);
    }
}
void creatPreThread(ThreadTree T){
    ThreadTree pre = NULL;
    PreThread(T, pre);
    pre->rchild = NULL;
    pre->rtag = 1;
}


// 建立中序线索二叉树 (传入普通二叉树)
void InThread(ThreadTree &T, ThreadTree &pre){
    if(T != NULL){
        InThread(T->lchild, pre);
        if(T->lchild == NULL){
            T->lchild = pre;
            T->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL){
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;
        InThread(T->rchild, pre);
    }
}
void creatInThread(ThreadTree T){
    ThreadTree pre = NULL;
    InThread(T, pre);
    pre->rchild = NULL;
    pre->rtag = 1;
}


// 建立后序线索二叉树 (传入普通二叉树)
void PostThread(ThreadTree &T, ThreadTree &pre){
    if(T != NULL){
        PostThread(T->lchild, pre);
        PostThread(T->rchild, pre);
        if(T->lchild == NULL){
            T->lchild = pre;
            T->ltag = 1;
        }
        if(pre != NULL && pre->rchild == NULL){
            pre->rchild = T;
            pre->rtag = 1;
        }
        pre = T;
    }
}
void creatPostThread(ThreadTree T){
    ThreadTree pre = NULL;
    PostThread(T, pre);
    pre->rchild = NULL;
    pre->rtag = 1;
}


// 中序线索二叉树找后继
ThreadTree firstNode(ThreadTree T){
    while(T->ltag == 0)
        T = T->lchild;
        return T;
}
ThreadTree nextNode(ThreadTree T){
    if(T->rtag == 0)
        return firstNode(T->rchild);
    else
        return T->rchild;
}
void inorder3(ThreadTree T){
    for(ThreadTree temp = firstNode(T); temp != NULL; temp = nextNode(temp))
        printf("%c ", temp->data);
}

// 中序线索二叉树找前驱
ThreadTree lastNode(ThreadTree T){
    while(T->rtag == 0)
        T = T->rchild;
        return T;
}
ThreadTree preNode(ThreadTree T){
    if(T->ltag == 0)
        return firstNode(T->lchild);
    else
        return T->lchild;
}
void reinorder3(ThreadTree T){
    for(ThreadTree temp = lastNode(T); temp != NULL; temp = preNode(temp))
        printf("%c ", temp->data);
}