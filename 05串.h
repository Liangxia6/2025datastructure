#include<iostream>
#include<cmath>
#include<algorithm>

#define maxcSize 50
#define initSize 100
#define elemType int


// 定长串的定义
typedef struct SStr
{
    char str[maxcSize+1];
    int length;
}SStr;

// 变长串的定义
typedef struct Str
{
    char *ch;
    int length;
}Str;


// 串的赋值操作
bool initStr(Str &str, char* ch){
    if(str.ch){
        free(str.ch);
    }
    int len = 0;
    char *c = ch;
    while(*c){
        len++;
        c++;
    }
    if(len == 0){
        str.ch = nullptr;
        str.length = 0;
        return true;
    }else{
        str.ch = (char*)malloc(sizeof(char)*(len+1));
        if(str.ch == nullptr)
            return false;
        for(int i = 0; i <= len; ++i, ++c)
            str.ch[i] = *c;
        str.length = len;
        return true;
    }
}


// 求串长
int getLen(Str &str){
    return str.length;
}


// 串的比较
int compareStr(Str &s1, Str &s2){
    int i = 0;
    for(; i < s1.length && i < s2.length; i++){
        if(s1.ch[i] != s2.ch[i])
            return s1.ch[i] - s2.ch[i];
    }
    return (s1.ch[i] - s2.ch[i]);
}


//求子串
int subStr(Str &substr, Str str, int pos, int len) {
    if (pos < 0 || pos >= str.length || len < 0 || len > str.length-pos) 
        return 0;
    if (substr.ch) {
        free(substr.ch);
        substr.ch = nullptr;
    }
    if (len == 0) {
        substr.ch = nullptr;
        substr.length = 0;
        return 1;
    } else {
        substr.ch = (char*)malloc(sizeof(char)*(len+1));
        int i = pos;
        int j = 0;
        while (i<pos+len) {
            substr.ch[j++] = str.ch[i++];
        }
        substr.ch[j] = '\0';
        substr.length = len;
        return 1;
    }
}


// 串的匹配(暴力匹配)
int index(Str &str, Str &substr){
    int i = 1, j = 1, k = i;
    while(i <= str.length && j <= substr.length){
        if(str.ch[i] == substr.ch[j]){
            i++;
            j++;
        }else{
            j = 1;
            i = ++k;
        }
    }
    if(j > substr.length)
        return k;
    else
        return 0;
}


// 串的匹配(KMP)
void getNext(Str &str, Str &next){
    int i = 1;
    int j = 0;
    next.ch[1] = 0;
    while(i < str.length){
        if(j == 0 || str.ch[i] == str.ch[i]){
            i++;
            j++;
            next.ch[i] = j;
        }
        j = next.ch[j];
    }
}
void getNextval(Str &str, Str &nextval){
    int i = 1;
    int j = 0;
    nextval.ch[1] = 0;
    while(i < str.length){
        if(j == 0 || str.ch[i] == str.ch[i]){
            i++;
            j++;
            if(str.ch[i] != str.ch[j])
                nextval.ch[i] = j;
            else
                nextval.ch[i] = nextval.ch[j];
        }
        j = nextval.ch[j];
    }
}
int KMP(Str &str, Str &substr, Str &next){
    int i = 1, j = 1, k = i;
    while(i <= str.length && j <= substr.length){
        if(str.ch[i] == substr.ch[j]){
            i++;
            j++;
        }else{
            j = next.ch[j];
            i = ++k;
        }
    }
    if(j > substr.length)
        return k;
    else
        return 0;
}
