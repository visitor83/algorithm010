/*
 * @lc app=leetcode.cn id=127 lang=c
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。
说明:

如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
示例 1:

输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

输出: 5

解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。
示例 2:

输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

输出: 0

解释: endWord "cog" 不在字典中，所以无法进行转换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 *
 * [127] 单词接龙
 */

// @lc code=start


typedef struct tagNode {
    char *arr;
    struct tagNode *next;
} Node;

typedef struct tagQueue {
    Node *front, *rear;
    int qsize;
} Queue;

Node *g_head;

Queue *QCreate()
{
    Queue *q = calloc(1, sizeof(Queue));
    q->front = q->rear = calloc(1, sizeof(Node));
    q->qsize = 0;
    return q;
}

void QEnq(Queue *q, char *s)
{
    Node *n = calloc(1, sizeof(Node));

    n->arr = s;
    q->rear->next = n;
    q->rear = n;
    ++(q->qsize);
}

Node *QDeq(Queue *q)
{
    Node *n = q->front->next;

    q->front->next = n->next;
    if (q->rear == n) {
        q->rear = q->front;
    }
    --q->qsize;
    return n;
}

bool QIsEmpty(Queue *q)
{
    return (q->qsize == 0) ? true : false;
}

bool WordCmp(char *s1, char *s2)
{
    int cnt = 0;
    for (int i = 0; i < strlen(s1); i++) {
        if (*(s1+i) != *(s2+i)) {
            cnt++;
        }
    }
    return (cnt == 1) ? true :false;
}

int FindLadder(char *beginWord, char *endWord, bool *vis, char **wordList, int wordListSize)
{ 
    bool found = false;
    int level;
    Queue *qhead;

    level = 0;
    qhead = QCreate();
    QEnq(qhead, beginWord);
    while (!QIsEmpty(qhead)) {
        int qsize = qhead->qsize;
        
        while (qsize--) {
            Node *popstr = QDeq(qhead);
            if (!strcmp(popstr->arr, endWord )) {
                //printf("level %d, %s endWord %s\n", level, popstr->arr, endWord);
                found = true;
                break;
            }

            //printf("level %d, popstr %s, qsize %d\n", level, popstr->arr, qsize);
            for (int i = 0; i < wordListSize; i++) {
               if (!vis[i] && WordCmp(wordList[i], popstr->arr)) {
                   QEnq(qhead, wordList[i]);
                   vis[i] = true;
               }
            }
            
        }

        level++;
        if (found) {
            break;
        }
    }

    return found == true ?  level : 0;
}

int ladderLength(char * beginWord, char * endWord, char ** wordList, int wordListSize)
{
    bool found = false;
    bool *vis;

    for (int i = 0; i < wordListSize; i++) {
        if (!strcmp(endWord, wordList[i])) {
            found = true;
        }
    }
    if (!found) {
        return 0;
    }

    vis = calloc(wordListSize, sizeof(bool));
    memset(vis, false, sizeof(bool));

    return FindLadder(beginWord, endWord, vis, wordList, wordListSize);
}

// @lc code=end

