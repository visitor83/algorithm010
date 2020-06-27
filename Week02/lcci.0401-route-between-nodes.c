#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/* typedef struct tagEdge {
 *     int from, to;
 *     int next;
 * } Edges;
 */

typedef struct tagEdge {
    int to;
    struct tagEdge *next;
} Edges;

#define NVERTEX 100100
#define VISITED 2
#define NOVISITED 0xff

Edges g_edges[NVERTEX];
int g_edgesnum;
int g_head[NVERTEX];

int g_queue[NVERTEX + 1];
int g_rear, g_front;

void Enq(int data)
{
    if ((g_rear + 1) % NVERTEX == g_front) {
        printf("Full\n");
        return ;
    }
    g_queue[g_rear] = data;
    g_rear = (g_rear + 1) % NVERTEX;
}

int Deq()
{
    int popdata;
    popdata = g_queue[g_front];
    g_front = (g_front + 1) % NVERTEX;
    return popdata;
}

bool IsEmpty()
{
    return (g_front == g_rear) ? true : false;
}

void AddEdge(int from, int to) 
{
    Edges *e = calloc(1, sizeof(Edges));
    e->to = to;
    e->next = g_edges[from].next;
    g_edges[from].next = e; 
}

/* if u 's adj have the same v vertex, there are parallel edge, skip it */
bool IsParallel(int u, int v)
{
    Edges *e = g_edges[u].next;

    while (e != NULL) { 
        if (e->to == v) {
            return true;
        }
        e = e->next;
    }  
    return false;
}

bool findWhetherExistsPath(int n, int** graph, int graphSize, int* graphColSize, int start, int target)
{
    bool haveCycle = false;
    bool found = false;
    int adjvertex, edgesCnt;
    char *vis;

    g_rear = 0;
    g_front = 0;

    edgesCnt = 0;
    memset(g_edges, 0, sizeof(Edges) *n);
    for (int i = 0; i < graphSize; i++) {
        if (!IsParallel(graph[i][0], graph[i][1])) {
            AddEdge(graph[i][0], graph[i][1]);
            edgesCnt++;
        }
    }

    vis = calloc(n, sizeof(char));
    Enq(start);
    vis[start] = VISITED;

    while (!IsEmpty()) {
        int next = Deq();
        // shoot the target
        if (next == target) {
            printf("Found next %d\n", next);
            return true;
        }
        Edges *e = g_edges[next].next;
        while (e != NULL) {
            adjvertex = e->to;
            // is there have cycle ??       
            if (!vis[adjvertex]) {
                Enq(adjvertex);
                vis[adjvertex] = VISITED;
            } 
            e = e->next;
        }
    }

    return false;
}