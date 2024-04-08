#include <iostream>
using namespace std;

void ksack(int n, float w[], float pro[], float cp) {
    float x[20], tp = 0;
    int i, j, u;
    u = cp;
    for (i = 0; i < n; i++)
        x[i] = 0.0;
    for (i = 0; i < n; i++) {

        if (w[i] > u)
            break;

        else {
            x[i] = 1.0;
            tp = tp + pro[i];
            u = u - w[i];
        }
    }

    if (i < n)
        x[i] = u / w[i];
    tp = tp + (x[i] * pro[i]);
    cout << "\nThe result vector is:";
    cout << "Maximum profit is: " << tp << endl;
}

int main() {

    float w[20], pro[20], cp;
    int num, i, j;
    float ratio[20], temp;

    cout << "Enter the number of objects: ";
    cin >> num;
    cout << "Enter the weights and profit of each object: ";
    for (i = 0; i < num; i++) {
        cin >> w[i] >> pro[i];
    }

    cout << "Enter the capacity of knapsack: ";
    cin >> cp;

    for (i = 0; i < num; i++) {
        ratio[i] = pro[i] / w[i];
    }
    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratio[i] < ratio[j]) {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;
                 temp = w[j];
                w[j] = w[i];
                w[i] = temp;

                temp = pro[j];
                pro[j] = pro[i];
                pro[i] = temp;
            }
        }
    }

    ksack(num, w, pro, cp);
    return 0;
   
   
   
   
   
    /*OUTPUT:
     Enter the number of objects: 7
Enter the weights and profit of each object: 2 10
3 5
5 15
7 7
1 6
4 18
1 3
Enter the capacity of knapsack: 15

The result vector is:Maximum profit is: 55.3333
  */
}
