/*
QUESTION NAME : EDIT DISTANCE
PROLEM STATEMENT:
Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.

You have the following three operations permitted on a word:

Insert a character
Delete a character
Replace a character

Example:
Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation:
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')

Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation:
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
*/

/*
Intuition :
Here we have to find the minimum edit distance problem between two strings word1 and word2.
The minimum edit distance is defined as the minimum number of operations required to transform one string into another.

Approach :
The approach here that I am using is dynamic programming. The idea is to build a 2D matrix dp where dp[i][j] represents
the minimum number of operations required to transform the substring word1[0...i-1] into the substring word2[0...j-1].

Complexity
Time complexity : O(mn)
Space complexity : O(mn)
*/
#include<bits/stdc++.h>
using namespace std;

int minDistance(string word1, string word2)
{
    const int m = word1.length(); // first word length
    const int n = word2.length(); // second word length
    // dp[i][j] := min # of operations to convert word1[0..i) to word2[0..j)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 1; i <= m; ++i)
        dp[i][0] = i;

    for (int j = 1; j <= n; ++j)
        dp[0][j] = j;

    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= n; ++j)
            if (word1[i - 1] == word2[j - 1]) // same characters
                dp[i][j] = dp[i - 1][j - 1];  // no operation
            else
                dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
    // replace       //delete        //insert
    return dp[m][n];
}
