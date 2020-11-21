#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

void DelSpace(char S[100])
{
    char SNew[100];
    int k = -1;
    int i = 0;
    while (S[i] != '\0')
    {
        if (S[i] != ' ')
        {
            k++;
            SNew[k] = S[i];
        }
        i++;
    }
    k++;
    SNew[k] = S[i];
    i = 0;
    while (SNew[i] != '\0')
    {
        S[i] = SNew[i];
        i++;
    }
    S[i] = '\0';
}

void Push(char S[100], char x)
{
char st[100] = {};
st[0] = x;
strcat(st, S);
strcpy(S, st);
}

char Pop(char S[100])
{
    char res = S[0];
    int i = 0;
    while (S[i] != '\0')
    {
        S[i] = S[i + 1];
        i++;
    }
    return res;
}

char GetPick(char S[100])
{
    return S[0];
}

int GetPriority(char oper)
{
    if (oper == '(') return 9; else
    if (oper == ')') return 0; else
    if (oper == '+') return 1; else
    if (oper == '-') return 1; else
    if (oper == '*') return 3; else
    if (oper == '/') return 3; else
    if (oper == '^') return 6; else
    if (oper == '\0') return -1; else
    return 7;
}

int GetStackPriority(char oper)
{
    if (oper == '(') return 0; else
    if (oper == '+') return 2; else
    if (oper == '-') return 2; else
    if (oper == '*') return 4; else
    if (oper == '/') return 4; else
    if (oper == '^') return 5; else
    return 8;
}

void pol(char S[100])
{
DelSpace(S);
char St[100] = {};
char Res[100] = {};
char ch;

for (int i = 0; i <= strlen(S); i++)
if (GetPriority(S[i]) > GetStackPriority(GetPick(St)))
    {
    Push(St, S[i]);
    }
else
    {
    while ((GetPriority(S[i]) <= GetStackPriority(GetPick(St))) && (GetPick(St) != '\0'))
        {
        ch = Pop(St);
        if (ch != '(')
            {
            char t[2] = {ch, '\0'};
            strcat(Res, t);
            }
        else
        break;
        }
    if (S[i] != ')') Push(St, S[i]);
    }

strcpy(S, Res);
}

void reverse(char s[100])
{
    char newS[100] = {};
    for (int i = strlen(s) - 1; i >= 0; i--)
    {
        if (s[i] == '(') newS[strlen(s) - i - 1] = ')'; else
            if (s[i] == ')') newS[strlen(s) - i - 1] = '('; else
        newS[strlen(s) - i - 1] = s[i];
    }
    strcpy(s, newS);
}

int main()
{
    char S1[100];
    gets_s(S1);
    char S2[100];
    strcpy(S2, S1);
    pol(S1);
    printf("postfix: %s", S1);


    reverse(S2);
    pol(S2);
    reverse(S2);
    printf("\ninfix: %s", S2);
}
