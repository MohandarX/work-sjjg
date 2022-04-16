#include<cstring>
#include<iostream>
using namespace std;
#define MaxSize 255
int Index_BF(char S[], char T[], int pos); //模式匹配，从指定主串S中查找模式串T第一次出现的位置，查找的起始位置为pos
int main()
{
    char S[MaxSize + 1], T[MaxSize + 1];
    char S1[MaxSize], S2[MaxSize];
    cin >> S1 >> S2;
    strcpy(&S[1], S1);
    strcpy(&T[1], S2);
    S[0] = strlen(S1);   //用数组第0个元素主串的长度
    T[0] = strlen(S2);   //用数组第0个元素记录模式串的长度
    cout << Index_BF(S, T, 1);
    return 0;
}
int Index_BF(char S[], char T[], int pos)
{
    int i = pos; 
    int j = 1;
    while (i <= S[0] && j <= T[0])
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }
    if (j > T[0])return i - T[0];
    else return 0;
}
