/*
Given an array of integers nums and a two-dimension array of integers operations.
Each operation in operations is represented in the form {L, R, X}.
When applying an operation, all elements with index in range [L, R] (include L and R) increase by X.
Your task is to implement a function with following prototype:
vector<int> updateArrayPerRange(vector<int>& nums, vector<vector<int>>& operations);
The function returns the array after applying all operation in operations.

Note:
- The iostream, and vector libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.

For example:
______________________________________________________________________________________________
Test	                                                                Result
______________________________________________________________________________________________
vector<int> nums {13, 0, 6, 9, 14, 16};                                 [21, 8, 14, 9, 14, 32]
vector<vector<int>> operations {{5, 5, 16}, {3, 4, 0}, {0, 2, 8}};
printVector(updateArrayPerRange(nums, operations));
______________________________________________________________________________________________
*/
vector<int> updateArrayPerRange(vector<int> &nums, vector<vector<int>> &operations)
{
    // STUDENT ANSWER
    for (auto &x : operations)
    {
        int left = x[0];
        int right = x[1];
        int plus = x[2];
        for (int i = left; i <= right; i++)
        {
            nums[i] += plus;
        }
    }
    return nums;
}