/*2. Add Two Numbers

You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = l1;
        ListNode* temp = l2;
        ListNode* out = new ListNode(0);
        ListNode* sol = out;
        int carry=0;
        while (head != nullptr || temp != nullptr) {
            int sum = carry;
            if(head != nullptr){
                sum = sum + head->val;
                head = head->next;
            }
            if(temp != nullptr){
                sum = sum + temp->val;
                temp = temp->next;
            }
            carry = sum / 10;
            sum = sum % 10;
            out->next = new ListNode(sum);
            out=out->next;
        }
        if(carry>0){
            out->next = new ListNode(carry);
        }
        return sol->next;    
    }
};