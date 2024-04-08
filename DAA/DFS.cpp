#include <iostream>
#include <cstdlib>
#define max 100
#define initial 1
#define visited 2
using namespace std;

int n;
int adj[max][max];
int state[max];
void df_traversal();
void dfs(int v);
void create_graph();
int stack[max];
int top = -1;
void push(int v);
int pop();
int isempty_stack();

int main() {
    create_graph();
    df_traversal();
    return 0;
}

void df_traversal() {
    int v;
    for (v = 0; v < n; v++)
        state[v] = initial;
    cout << "Enter the starting node for depth first search: ";
    cin >> v;
    dfs(v);
}

void dfs(int v) {
    int i;
    push(v);
    while (!isempty_stack()) {
        v = pop();
        if (state[v] == initial) {
            cout << v << " ";
            state[v] = visited;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (adj[v][i] == 1 && state[i] == initial)
                push(i);
        }
    }
}

void push(int v) {
    if (top == (max - 1)) {
        cout << "Stack overflow\n";
        return;
    }
    top = top + 1;
    stack[top] = v;
}

int pop() {
    int v;
    if (top == -1) {
        cout << "Stack underflow\n";
        exit(1);
    } else {
        v = stack[top];
        top = top - 1;
        return v;
    }
}

int isempty_stack() {
    if (top == -1)
        return 1;
    else
        return 0;
}

void create_graph() {
    int i, max_edges, origin, destin;
    cout << "Enter number of nodes: ";
    cin >> n;
    max_edges = n * (n - 1);

    for (i = 0; i < max_edges; i++) {
        cout << "Enter edge " << i << " (-1 -1 to quit): ";
        cin >> origin >> destin;
        if ((origin == -1) && (destin == -1))
            break;

        if ((origin == -1) || destin >= n || origin < 0 || destin < 0) {
            cout << "Invalid edge!" << endl;
            i--;
        } else
            adj[origin][destin] = 1;
    }
}



/* OUTPUT:
 Enter number of nodes: 5
Enter edge 0 (-1 -1 to quit): 0
1
Enter edge 1 (-1 -1 to quit): 1
2
Enter edge 2 (-1 -1 to quit): 2
3
Enter edge 3 (-1 -1 to quit): 4
3
Enter edge 4 (-1 -1 to quit): 1
4
Enter edge 5 (-1 -1 to quit): 4
0
Enter edge 6 (-1 -1 to quit): 3
1
Enter edge 7 (-1 -1 to quit): 1
4
Enter edge 8 (-1 -1 to quit): 4
0
Enter edge 9 (-1 -1 to quit): -1
-1
Enter the starting node for depth first search: 0
0 1 2 3 4
*/