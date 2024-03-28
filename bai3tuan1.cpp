#include <iostream>
#include <vector>

std::pair<int, int> find_first_and_last_occurrence(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int first_occurrence = -1;
    int last_occurrence = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            first_occurrence = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    left = 0;
    right = arr.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            last_occurrence = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return {first_occurrence, last_occurrence};
}

int main() {
    std::vector<int> sorted_array = {5,6,7,8,8,15};
    int target_element = 8;
    auto [first, last] = find_first_and_last_occurrence(sorted_array, target_element);

    std::cout << "[" << first << "," << last << "]" << std::endl;

    return 0;
}

