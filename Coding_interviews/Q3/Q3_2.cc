#include "iostream"
#include "vector"

class Solution {
public:
    int Duplicated(std::vector<int>& arr,int n, int start, int end) {
        if (arr.size() != n+1) {return -1;}
        for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
            if (*it > n) {return -2;}
        }
        if (arr.size() == 0) {return -4;}
        int nums = -1;
        while (end > start) {
            int mid = ((end - start) >> 1) + start;
            nums = Count(arr, start, mid);
            if (nums > (mid - start + 1)) {
                end = mid;
                printf("end = %d\n", end);
            }
            else
            {
                start = mid + 1;
            }
            
        }
        return start;
    }

    // start<=a<=mid
    int Count(std::vector<int>& arr, int start, int mid) {
        int nums = 0;
        if (start > mid) {return -3;}
        for (std::vector<int>::iterator it = arr.begin(); it != arr.end(); it++) {
            if ((*it)>=start&&(*it)<=mid) {++nums;} 
        }
        return nums;
    }
};

int main() {
    std::vector<int> arr{2,3,6,3,3,1,4};
    int n = arr.size() - 1;
    int end = n;
    int start = 1;
    Solution s;
    int result = s.Duplicated(arr, n, start, end);
    printf("The duplicated number is %d\n", result);
    return 0;
}
