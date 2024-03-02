#include"01顺序表.h"

int fun1(SeqList &L){
    if(L.length == 0)
        return -1;
    elemType min = L.data[0];
    int sub = 0;
    for(int i = 1; i < L.length; i++){
        if(L.data[i] < min){
            min = L.data[i];
            sub = i;
        }
    }
    L.data[sub] = L.data[L.length-1];
    return min;
}


void fun2(SeqList &L){
    for(int i = 0; i < L.length / 2; i++){
        elemType temp = L.data[i];
        L.data[i] = L.data[L.length - 1 - i];
        L.data[L.length - 1 - i] = temp;
    }
}


void fun3(SeqList &L, elemType x){
    int seg = 0;
    for(int i = 0; i < L.length; i++){
        if(L.data[i] != x){
            L.data[seg] = L.data[i];
            seg++;
        }
    }
    L.length = seg;
}


void fun4(SeqList &L, elemType s, elemType t){
    int seg = 0;
    if(L.length == 0 || s >= t)
        return;
    for(int i = 0; i < L.length; i++){
        if(L.data[i] <= t & L.data[i] >= s){
            L.data[seg] = L.data[i];
            seg++;
        }
    }
    L.length = seg;
}

void fun5(SqList &L){
    int seg = 0;
    for(int i = 1; i < L.length; i++){
        if(L.data[i] != L.data[seg]){
            L.data[seg+1] = L.data[i];
            seg++;
        }
    }
    L.length = seg + 1;
}


SeqList fun6(SqList &L1, SqList &L2){
    SeqList L;
    initSeqList(L);
    increaseSeqList(L, L1.length + L2.length);
    int i = 0;
    int j = 0;
    while(i != L1.length || j != L2.length){
        if(L1.data[i] < L2.data[j]){
            insertElem(L, L.length-1, L1.data[i]);
            i++;
        }else{
            insertElem(L, L.length-1, L2.data[j]);
            j++;
        }
    }
    if(i == L1.length){
        while(j != L2.length){
            insertElem(L, L.length-1, L2.data[j]);
            j++;
        }
    }
    if(j == L2.length){
        while(i != L1.length){
            insertElem(L, L.length-1, L1.data[i]);
            i++;
        }
    }
    return L;
}


void fun7(SeqList &L, int m , int n){
    reverse(L, 1, L.length);
    reverse(L, 1, m);
    reverse(L, n+1, L.length);
}


void fun8(SeqList &L, elemType x){
    int low = 0;
    int high = L.length - 1;
    int mid = (low + high) / 2;
    while(low < high){
        if(L.data[mid] == x)
            break;
        if(L.data[mid] < x){
            low = mid + 1;
        }else{
            high = mid -1;
        }
        mid = (low + high) / 2;
    }
    if(L.data[mid] == x && mid + 1 != L.length)
        reverse(L, mid+1, mid+2);
    else
        insertElem(L, mid + 1, x);
}

void fun9(SeqList &L1, SeqList &L2, SeqList &L3, int n){
    int i = 0, j = 0, k = 0;
    while(i < n && j < n && k < n){
        if(L1.data[i] == L2.data[j] == L3.data[k]){
            std::cout << L1.data[i];
            i++;j++;k++;
        }else{
            int maxnum = std::max(L1.data[i], std::max(L2.data[j], L3.data[k]));
            while(L1.data[i] < maxnum)
                i++;
            while(L2.data[j] < maxnum)
                j++;
            while(L3.data[k] < maxnum)
                k++;
        }
    }
}