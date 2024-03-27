#include "03栈.h"

bool fun3(int* a, int len){
    int p = 0;
    for(int i = 0; i < len; i++){
        if(a[i] == 'I')
            p++;
        if(a[i] == 'O'){
            p--;
            if(p < 0)
                return false;
        }
    }
    return (p == 0);
}


bool fun4(int* a, int len){
    int stack[10];
    int p = 0;
    int i = 0;
    for(; i < len/2; i++){
        stack[p] = a[i];
        p++;
    }
    if(len % 2 == 1)
        i++;
    for(; i < len; i++){
        if(a[i] != stack[p--])
            return false;
    }
    return true;
}


// 共享栈的定义
typedef struct ShareStack{
    elemType data[maxcSize];
    int top1;
    int top2;
}ShareStack;

bool initShareStack(ShareStack &S){
    S.top1 = -1;
    S.top2 = maxcSize;
}

bool S1push(ShareStack &S, elemType e){
    if(S.top1+1 == S.top2)
        return false;
    S.data[++S.top1] = e;
    return true;
}

bool S2push(ShareStack &S, elemType e){
    if(S.top1+1 == S.top2)
        return false;
    S.data[--S.top2] = e;
    return true;
}

elemType S1pop(ShareStack &S){
    if(S.top1 == -1)
        return false;
    return S.data[S.top1--];
}

elemType S2pop(ShareStack &S){
    if(S.top2 == maxcSize)
        return false;
    return S.data[S.top2++];
}