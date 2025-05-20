/*Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"

Output: true

Example 2:

Input: s = "()[]{}"

Output: true

Example 3:

Input: s = "(]"

Output: false

Example 4:

Input: s = "([])"

Output: true*/

class Solution {
public:
    bool isValid(string s) {
        int size = s.size();
        unordered_map<char,char> hash{
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        std::stack<char> stack;
        if(size%2!=0) return false;
        
        for (char c : s) {
            if (hash.count(c)) {
                if (!stack.empty() && stack.top() == hash[c]) {
                    stack.pop();
                } else {
                    return false;
                }
            } else {
                stack.push(c);
            }
        }
        return stack.empty();
    }
};