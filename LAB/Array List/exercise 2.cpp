/*
Given an array of integers.
Your task is to implement a function with the following prototype:
                bool consecutiveOnes(vector<int>& nums);
The function returns if all the 1s appear consecutively in nums. If nums does not contain any elements, please return true

Note:
- The iostream and vector libraries have been included and namespace std are being used. No other libraries are allowed.
- You can write helper functions.
- Do not use global variables in your code.

For example:
_______________________________________________
Test	                             |   Result
_____________________________________|_________
vector<int> nums {0, 1, 1, 1, 9, 8}; |   1
cout << consecutiveOnes(nums);       |
_____________________________________|_________
*/
bool consecutiveOnes(vector<int> &nums)
{
    // STUDENT ANSWER
    int pos = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            if (nums[i + 1] == 1)
            {
                continue;
            }
            else
            {
                if (pos == 0)
                {
                    pos = 1;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    return true;
}