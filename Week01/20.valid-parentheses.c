typedef struct tagStack{
    char *elems;
    int top;
} Stack_T;

Stack_T *S_Create(int maxLength)
{
    Stack_T * stk = (Stack_T *) malloc(sizeof(Stack_T));
    stk->elems = (char *)malloc(maxLength);
    stk->top = -1;
    memset(&stk->elems[0], 0, maxLength);
    return stk;
}

void S_Push(Stack_T *stk, char chaf)
{
    stk->elems[++stk->top] = chaf;
}

void S_Pop(Stack_T *stk, char *pch)
{
    *pch = stk->elems[stk->top];
    --stk->top;
}

char S_Peek(Stack_T *stk)
{
    return stk->elems[stk->top];
}

bool S_IsEmpty(Stack_T *stk)
{
    return stk->top == -1 ? true :false;
}

#define IsRight(x)   ((x == ')' ||  x == '}' ||  x== ']') ? true :false)

bool IsMatch(char a, char b)
{
    if ((a == ')' && b == '(') || (a == '}' && b == '{'  ) ||
            (a == ']' && b == '[')) {
        return true;
    }

    return false;
}

bool isValid(char * s)
{
    int length = strlen(s);
    int i;
    Stack_T *stk;

    stk = S_Create(length + 1) ;

    for (i = 0; i < length; i++) {
        if (IsRight (s[i]) == true &&  S_IsEmpty(stk) != true) {
            char left;
            S_Pop(stk, &left);

            if (IsMatch(s[i], left) != true) {
                return false;
            }
        } else {
            S_Push(stk, s[i]);
        }
    }

    return S_IsEmpty(stk) == true ? true: false;
}