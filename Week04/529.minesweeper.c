/*
 * @lc app=leetcode.cn id=529 lang=c
 *
 * [529] 扫雷游戏
 */

// @lc code=start

#define DIR_SIZE    8
#define NMAX        50

typedef struct tagNode {
    int val;
    int x, y;
    struct tagNode *next;
} Node;

typedef struct tagQueue{
    Node *front, *rear;
    int qsize;
} Queue;

Queue * QCreate()
{
    Queue *q;
    q = calloc(1, sizeof(Queue));
    q->front = q->rear = calloc(1, sizeof(Node));
    return q;
}

void QEnq(Queue *qhead, Node *n)
{
    qhead->rear->next = n;
    qhead->rear = n;
    qhead->qsize++;
}

Node *QDeq(Queue *qhead)
{
    Node *tn;
    tn = qhead->front->next;
    qhead->front->next = tn->next;
    if (tn == qhead->rear) {
        qhead->rear = qhead->front;
    }
    qhead->qsize--;
    return tn;
}

int QGetSize(Queue *qhead)
{
    return qhead->qsize;
}

bool QIsEmpty(Queue *qhead)
{
    return (qhead->qsize == 0) ? true : false;
}

Node *NewPoint(int x, int y, int val)
{
    Node *np = calloc(1, sizeof(Node));
    np->x = x; np->y = y;
    np->val = val;
    return np;
}

bool IsValid(int row, int col , int x, int y)
{
    if (x < 0 || y < 0 || x >= row || y >= col) {
        return false;
    }
    return true;
}

//char g_board[NMAX][NMAX];
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes)
{
    int dirX[] = {-1, -1, -1, 1, 1, 1, 0,  0};
    int dirY[] = {-1,  0,  1,-1, 0, 1, 1, -1};
    int x, y;
    Queue * qhead;

    qhead = QCreate();
    x = click[0]; y = click[1];
    QEnq(qhead, NewPoint(x, y, board[x][y]));

    //printf("x %d, y %d\n", x, y);
    while (!QIsEmpty(qhead)) {
        int qsize = QGetSize(qhead);

        //printf("qsize %d\n", qsize);
        while (qsize--) {
            Node *popdata = QDeq(qhead);
            x = popdata->x; y = popdata->y;
            if (board[x][y] == 'M') {
                board[x][y] = 'X';
                continue;
            }

            int val = 0;
            for (int i = 0; i < DIR_SIZE; i++) {
                int tX, tY;

                tX = x + dirX[i];
                tY = y + dirY[i];
                if (IsValid(boardSize, boardColSize[0], tX, tY)) {
                    if (board[tX][tY] == 'M' || board[tX][tY] == 'X') {
                        //printf("val %d, (%d, %d)\n", val, tX, tY);
                        val++;
                    }
                }
            }

            if (val > 0 ) {
                // BFS 停止前进, adj vertex not enqueue， 所有入队列元素都是以'B'为起点
                board[x][y] =  (val + '0');
            } else {
                board[x][y] = 'B';
                for (int i = 0; i < DIR_SIZE; i++) {
                    int tX, tY;

                    tX = x + dirX[i];
                    tY = y + dirY[i];
                    if (IsValid(boardSize, boardColSize[0], tX, tY) && board[tX][tY] == 'E') {
                        QEnq(qhead, NewPoint(tX, tY, board[tX][tY]));
                        board[tX][tY] = 'B';
                    }
                }
            }

            free(popdata);
        }
    }

    *returnSize =  boardSize;
    *returnColumnSizes = calloc(boardSize, sizeof(int));
    for (int i = 0; i < boardSize; i++) {
       (*returnColumnSizes)[i] = boardColSize[i];
    }
    // if 'E' flip to 'B'
    return board;
}
// @lc code=end

