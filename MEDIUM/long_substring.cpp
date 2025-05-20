/*3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size = s.size();
        int i,l=0,r=0,maxlength=1,len=0;
        int hash[256];
        if(s == "") return 0;
        for(i=0;i<255;i++) hash[i] = -1;
        while(r<size){
            if(hash[s[r]] != -1){
                if(hash[s[r]] >= 1)
                    l = hash[s[r]] + 1;
            }
            len = r-l + 1;
            maxlength = max(len,maxlength);
            hash[s[r]] = r;
            r++;
        }
        return maxlength;
    }
};