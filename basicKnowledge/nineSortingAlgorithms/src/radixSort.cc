#include "../inc/radixSort.h"
#include <cmath>

int maxDigit(const std::vector<int>& arr) {
    int maxVal = -__INT_MAX__;
    int maxdgt = 0;
    for (int val : arr) {
        maxVal = maxVal > val ? maxVal : val;
    }
    while (maxVal) {
        maxVal /= 10;
        maxdgt++;
    }
    return maxdgt;
}

void radixSort(std::vector<int>& arr) {
    int n = arr.size();
    if (n <= 1) {return;}
    int maxDgt = maxDigit(arr);
    std::vector<std::vector<int> > bucket(BUCKETS); //10 buckets for radix 0~9
    //NOTICE, maxVal = 121, maxDgt = 3, 10^2, pos = 2
    for (int pos = 0; pos < maxDgt; pos++) {
        int denominator = static_cast<int>(pow(10, pos));
        for (int temp : arr) {bucket[(temp / denominator) % 10].push_back(temp);} //push into the buckets
        int index = 0;
        //pull from the buckets
        for (auto &theBucket : bucket) {
            for (int k : theBucket) {arr[index++] = k;}
            theBucket.clear();  //clear the bucket, for the next digit!
        }
    }
}