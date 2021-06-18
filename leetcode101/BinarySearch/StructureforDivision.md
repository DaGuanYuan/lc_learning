int left;
int right;
int mid;
// here we consider left '<=' right to ensure operating even only one element exists
while (left <= right) {
    mid = left + ((right - left) >> 1); // using mid to divide, for example
    if (arr[mid] <-> val) {left = mid + 1;} // since '<=', here left should be mid + '1'
    else {right = mid - 1;} // since '<=', here right should be mid - '1'
}

# how to determine '<' or '<=' || +1 or not +1
# consider boundaries! In fact, you can only try array who has only 2 elements and 1 elements
# Not drop into stereotype! See leetcode 154!