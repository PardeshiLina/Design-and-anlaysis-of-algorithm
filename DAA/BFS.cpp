#include <iostream>
#include <cstdlib>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
using namespace std;

int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph();
void BF_traversal();
void BFS(int F);
int queue[MAX], front = -1, rear = -1;
void insert_el(int first_el);
int delete_el();
int isempty_queue();

int main() {
    create_graph();
    BF_traversal();
    return 0;
}

void BF_traversal() {
    int F;
    for (F = 0; F < n; F++)
        state[F] = initial;
    cout << "Enter starting vertex for Breadth First Search: ";
    cin >> F;
    BFS(F);
}

void BFS(int F) {
    int i;
    insert_el(F);
    state[F] = waiting;
    while (!isempty_queue()) {
        F = delete_el();
        cout << F << " ";
        state[F] = visited;
        for (i = 0; i < n; i++) {
            if (adj[F][i] == 1 && state[i] == initial) {
                insert_el(i);
                state[i] = waiting;
            }
        }
    }
    cout << endl;
}

void insert_el(int first_el) {
    if (rear == MAX - 1)
        cout << "Queue overflow" << endl;
    else {
        if (front == -1)
            front = 0;
        rear = rear + 1;
        queue[rear] = first_el;
    }
}

int isempty_queue() {
    if (front == -1 || front > rear)
        return 1;
    else
        return 0;
}

int delete_el() {
    int d;
    if (front == -1 || front > rear) {
        cout << "Queue underflow" << endl;
        exit(1);
    }
    d = queue[front];
    front = front + 1;
    return d;
}

void create_graph() {
    int i, max_e, o, d;
    cout << "Enter number of vertices: ";
    cin >> n;
    max_e = n * (n - 1);
    for (i = 1; i <= max_e; i++) {
        cout << "Enter edge " << i << ": ";
        cin >> o >> d;
        if ((o == -1) && (d == -1))
            break;
        if (o >= n || d >= n || o < 0 || d < 0) {
            cout << "Invalid edges" << endl;
            i--;
        } else
            adj[o][d] = 1;
    }
}

/* OUTPUT

Enter number of vertices: 4
Enter edge 1: 1
0
Enter edge 2: 2
0
Enter edge 3: 1
2
Enter edge 4: 3
0
Enter edge 5: 2
3
Enter edge 6: 3
0
Enter edge 7: 0
1
Enter edge 8: -1
-1
Enter starting vertex for Breadth First Search: 0
0 1 2 3  */
