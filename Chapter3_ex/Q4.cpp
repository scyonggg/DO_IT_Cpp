#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void ShowArray(const int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << ' ';
    }
    cout << '\n';
}

void ShowStep() {

}

int BinarySearch(const int arr[], int target, int n) {
    int reps = 0;
    int nl = 0, nr = n - 1, nc = n / 2;
    do {
        reps++;
        cout << "Reps : " << reps << "\t left boundary : " << nl << "\t center : " << nc << "\t right boundary : " << nr << '\n';
        if (arr[nc] == target) {
            cout << "Repeated " << reps << "times" << '\n';
            return nc;
        }
        else if(arr[nc] < target) {
            nl = nc + 1;
            nc = (nl + nr) / 2;
        }
        else if(arr[nc] > target) {
            nr = nc - 1;
            nc = (nl + nr) / 2;
        }
    } while(nl <= nr);
    
    return -1;
}

int main() {
    srand(time(NULL));

    int n;  // number of elements
    cout << "Enter the number of elements :";
    cin >> n;
    
    int *arr = new int[n];
    for(int i = 0; i < n; i++) {
        cout << "Enter the elements :";
        cin >> arr[i];
    }
    ShowArray(arr, n);
    
    int target;
    cout << "Enter the target to search :";
    cin >> target;

    int result = BinarySearch(arr, target, n);
    if (result == -1)   cout << "Search failed" << '\n';
    else                cout << "Search result : index " << result << '\n';

    delete [] arr;
    

}