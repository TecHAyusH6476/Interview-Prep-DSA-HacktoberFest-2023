// Algorithm:
// The problem can be solved using dynamic programming. We create a 2D matrix (dp) where dp[i][j] represents
// the minimum edit distance between the first i characters of word1 and the first j characters of word2.
// We initialize the first row and first column of the matrix to represent the minimum edit distance when one
// of the words is empty. Then, we fill in the matrix using the following rules:
//
// 1. If the current characters of word1 and word2 match, no operation is needed. So, we take the value
//    from the diagonal cell (dp[i-1][j-1]).
//
// 2. If the characters don't match, we have three options:
//    a. Replace the character in word1 with the character in word2, which corresponds to taking the diagonal
//       value and adding 1 (dp[i-1][j-1] + 1).
//    b. Delete the character in word1, which corresponds to taking the value above and adding 1 (dp[i-1][j] + 1).
//    c. Insert the character from word2 into word1, which corresponds to taking the value to the left and adding 1 (dp[i][j-1] + 1).
//    We choose the minimum of these three options.
//
// 3. The final value in dp[m][n] represents the minimum edit distance between the two input words.

// Intuition:
// To find the minimum edit distance between two words, we build a matrix where each cell represents the
// minimum edit distance for a substring of the two words. By comparing characters and considering the
// three possible operations (insertion, deletion, and substitution), we incrementally fill the matrix.
// The final value in the bottom-right corner of the matrix represents the minimum edit distance.

class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.length();
        int n = word2.length();

        // Create a 2D vector dp to store minimum edit distance values.
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));

        // Initialize the first row and column of dp to represent empty word cases.
        for (int i = 1; i <= m; i++)
            dp[i][0] = i;
        for (int j = 1; j <= n; j++)
            dp[0][j] = j;

        // Fill in dp using dynamic programming.
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    // If characters match, no operation is needed.
                    dp[i][j] = dp[i - 1][j - 1];
                else {
                    // If characters don't match, choose the minimum of three possible operations:
                    // 1. Replace: dp[i-1][j-1] + 1
                    // 2. Delete: dp[i-1][j] + 1
                    // 3. Insert: dp[i][j-1] + 1
                    dp[i][j] = min({ dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1] }) + 1;
                }
            }
        }

        // The final value in dp[m][n] represents the minimum edit distance.
        return dp[m][n];
    }
};


