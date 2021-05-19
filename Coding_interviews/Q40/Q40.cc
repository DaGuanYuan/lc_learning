#include <iostream>
#include <vector>

class Solution
{
public:
    void mySwap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    void adjustHeap(std::vector<int>& res, int heapSize, int pos) {
        int temp = res[pos];
        for (int i = pos * 2 + 1; i < heapSize; i = i * 2 + 1) {
            if (res[i] < res[i + 1]) {i++;}
            if (temp < res[i]) {
                res[pos] = res[i];
                pos = i;
            } 
            else {break;}
        }
        res[pos] = temp;
    }

    // nlogk if maxHeap, but is extremely useful in big data Top-k questions
    // klogn if minHeap, why not using partition?
    void maxHeapInit(std::vector<int>& arr, std::vector<int>& res, int heapSize) {
        res.assign(arr.begin(), arr.begin() + heapSize);
        for (int i = heapSize / 2 - 1; i >= 0; i--) {
            adjustHeap(res, heapSize, i);
        }
    }

    int Partition(std::vector<int>& arr, int left, int right) {
        int begin = left;
        int pivot = arr[left];
        while (left < right) {
            while (left < right && arr[right] > pivot) {right--;}
            while (left < right && arr[left] <= pivot) {left++;}
            if (left < right) {mySwap(arr[left], arr[right]);}
        }
        mySwap(arr[begin], arr[left]);
        return left;
    }

    void findTheSmallestkNumsUsingPartition(std::vector<int>& arr, std::vector<int>& res, int k) {
        int n = arr.size();
        int left = 0;
        int right = n - 1;
        while (left <= right) {
            int pivotIndex = Partition(arr, left, right);
            if (pivotIndex == k - 1) {
                res.assign(arr.begin(), arr.begin() + k);
                break;
            }
            else if (pivotIndex < k - 1) {left = pivotIndex + 1;}
            else {right = pivotIndex - 1;}
        }
    }

    void findTheSmallestkNumsUsingHeap(std::vector<int>& arr, std::vector<int>& res, int k) {
        maxHeapInit(arr, res, k);
        // using arr[0...k-1] to initialize a maxHeap, storing in vectot res.
        int start = k;
        while (start < arr.size()) {
            if (arr[start++] >= res[0]) {continue;}
            res[0] = arr[start];
            adjustHeap(res, k, 0);
            start++;
        }
    }

    std::vector<int> findTheSmallestkNums(std::vector<int>& arr, int k) {
        std::vector<int> res {};
        if (arr.empty() || k > arr.size() || k <= 0) {return res;}
        findTheSmallestkNumsUsingHeap(arr, res, k);
        findTheSmallestkNumsUsingPartition(arr, res, k);
        return res;
    }
};

int main(int argc, const char** argv) {
    Solution s;
    // k > size || k <= 0 || arr.empty()
    // k = 1 || k = arr.size() - 1
    // normal(has repeated numbers || all unique numbers)
    std::vector<int> arr {5,4,1,8,2,3,7,6};
    int k = 4;
    std::vector<int> res = s.findTheSmallestkNums(arr, k);
    if (res.empty()) {printf("Invalid Input\n");}
    else {
        printf("The smallest %d elements are:\n", k);
        for (std::vector<int>::const_iterator it = res.begin(); it < res.end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
    }

    return 0;
}
