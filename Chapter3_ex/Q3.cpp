#include <iostream>


using namespace std;

void ShowArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

int search_idx(const int a[], int n, int key, int idx[]) {
    int j = 0;
    for (int i = 0; i < n; i++) {
        if(key == a[i]) {
            idx[j] = i;
            j++;
            cout << "hi \n";
        }
    }
    return j;
}

int main() {
    
    int n;  // number of elements

    cout << "Enter the number of elements: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Enter the elements: ";
    int j;
    for (int i=0; i<n; i++){
        cin >> j;
        arr[i] = j;
    }

    ShowArray(arr, n);

    int *idx = new int;
    int key = 0;

    cout << "Enter the key: ";
    cin >> key;

    int result = search_idx(arr, n, key, idx);
    cout << "Result :" << result << '\n';
    ShowArray(idx, result);

    delete [] arr;
    delete [] idx;
    
    return 0;
}