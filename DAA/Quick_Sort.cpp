#include <iostream>
using namespace std;

#define Max 100

// Function prototypes
int partition(int arr[], int low, int up);
void quick(int arr[], int low, int up);

int main() {
    int arr[Max];
    int n, i;
    cout << "Enter the number of elements to enter in the array: ";
    cin >> n;
   
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Function call quick
    quick(arr, 0, n - 1);

    cout << "Sorted array:\n";
    for (i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Partition function definition
int partition(int arr[], int low, int up) {
    int temp, i, j, pivot;
    i = low + 1;
    j = up;
    pivot = arr[low];

    while (i <= j) {
        while ((arr[i] < pivot) && (i < up))
            i++;
        while (arr[j] > pivot)
            j--;

        if (i < j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;

            i++;
            j--;
        } else {
            i++;
        }
    }
    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

// Quick function definition
void quick(int arr[], int low, int up) {
    int pvtloc;
    if (low >= up)
        return;
    // Call partition
    pvtloc = partition(arr, low, up);
    quick(arr, low, pvtloc - 1);
    quick(arr, pvtloc + 1, up);
}


/*OUTPUT:
 Enter the number of elements to enter in the array: 5
95
35
64
78
24
Sorted array:
24 35 64 78 95
*/
