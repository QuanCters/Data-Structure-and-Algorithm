/*
Given an array of strings.
Your task is to implement a function with following prototype:
int longestSublist(vector<string>& words);
The function returns the length of the longest subarray where all words share the same first letter.

Note:
- The iostream and vector libraries have been included and namespace std is being used. No other libraries are allowed.
- You can write helper functions.

For example:
_______________________________________________________________________________
Test	                                                             |  Result
_____________________________________________________________________|_________
vector<string> words {"faction", "fight", "and", "are", "attitude"}; |   3
cout << longestSublist(words);                                       |
_____________________________________________________________________|_________
*/
int longestSublist(vector<string> &words)
{
    // STUDENT ANSWER
    if (words.size() == 0)
    {
        return 0;
    }
    int max = 0;
    int count = 0;
    for (int i = 0; i < words.size() - 1; i++)
    {
        if (words[i][0] == words[i + 1][0])
        {
            count++;
        }
        else
        {
            count++;
            if (count > max)
            {
                max = count;
            }
            count = 0;
        }
    }
    count++;
    if (count > max)
    {
        max = count;
    }
    return max;
}