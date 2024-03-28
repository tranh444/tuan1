#include <bits/stdc++.h>

using namespace std;

bool binary_search(vector<int> &arr, int x) {
    int low = 0, high = arr.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return true;
        else if (arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}

vector<int> find_intersection_binary_search(vector<int> &arr1, vector<int> &arr2) {
    vector<int> intersection;
    for (int i : arr1) {1
        if (binary_search(arr2, i)) {
            intersection.push_back(i);
        }
    }
    return intersection;
}

int main() {
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {3, 4, 5, 6, 7};
    vector<int> intersection = find_intersection_binary_search(arr1, arr2);
    for (int i : intersection) {
        cout << i << " ";
    }
    return 0;
}

