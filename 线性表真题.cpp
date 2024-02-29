#include "线性表.h"

void fun10(SeqList &L, int p){
    reverse(L, 1, L.length);
    reverse(L, 1, p);
    reverse(L, p+1, L.length);
}


elemType fun11(SeqList &L1, SeqList &L2){
    int mid = 0;
    int i = 0;
    int j = 0;
    while(i < L1.length && j < L2.length){
        if(L1.data[i] <= L2.data[j]){
            i++;
            mid++;
        }else{
            j++;
            mid++;
        }
    }
    if(i < j)
        return L1.data[i];
    return L2.data[j];
}


elemType fun12(SeqList &L){
    SeqList L2;
    initSeqList(L2);
    for(int i = 0; i < L.length; i++){
        insertElem(L2, i + 1, 0);
    }
    for(int i = 0; i < L.length; i++){
        insertElem(L2, L.data[i] - 1, L2.data[i] + 1);
    }
    int max = 0;
    elemType ans = -1;
    for(int i = 0; i < L.length; i++){
        if(L2.data[i] > max){
            ans = i;
        }
    }
    if(ans > L.length/2)
        return ans;
    return -1;
}


elemType fun13(SeqList &L){
    SeqList L2;
    initSeqList(L2);
    for(int i = 0; i < L.length; i++){
        insertElem(L2, i + 1, 0);
    }
    for(int i = 0; i < L.length; i++){
        if(L.data[i] > 0 && L.data[i] < L.length)
            insertElem(L2, L.data[i] - 1, L2.data[i] + 1);
    }
    for(int i = 1; i < L2.length; i++){
        if(L2.data[i] == 0)
            return i;
    }
    return L2.length;
}


elemType fun14(SeqList &L1, SeqList &L2, SeqList &L3){
    int i = 0, j = 0, k = 0;
    elemType min = 99999;
    while(i < L1.length && j < L2.length && k < L3.length){
        elemType len = abs(L1.length - L2.length) + abs(L2.length - L3.length) + abs(L3.length - L1.length);
        if(len < min)
            min = len;
        if(L1.data[i] <= L2.data[j] && L1.data[i] <= L3.data[k])
            i++;
        else if(L2.data[j] <= L1.data[i] && L2.data[j] <= L3.data[k])
            j++;
        else if(L3.data[k] <= L2.data[j] && L3.data[k] <= L1.data[i])
            k++;
    }
    return min;
}