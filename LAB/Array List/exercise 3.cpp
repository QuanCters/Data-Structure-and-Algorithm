/*
Given an array of integers.
Your task is to implement a function with following prototype:
                int equalSumIndex(vector<int>& nums);
The function returns the smallest index i such that
 the sum of the numbers to the left of i is equal to the sum of the numbers to the right.
If no such index exists, return -1.

Note:
- The iostream and vector libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.

For example:
_______________________________________________
Test	                             |   Result
_____________________________________|_________
vector<int> nums {3, 5, 2, 7, 6, 4}; |   3
cout << equalSumIndex(nums);         |
_____________________________________|_________
*/
int equalSumIndex(vector<int> &nums)
{
    // STUDENT ANSWER
    if (nums.size() == 0)
    {
        return -1;
    }
    if (nums.size() == 1)
    {
        return 0;
    }
    int total = 0;
    for (int &x : nums)
    {
        total += x;
    }
    int leftSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int rightSum = total - leftSum - nums[i];
        if (leftSum == rightSum)
        {
            return i;
        }
        leftSum += nums[i];
    }
    return -1;
}