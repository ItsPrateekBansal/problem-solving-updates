/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
 */

// @lc code=start
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
    //RECURSIVE SOLUTION
    // ListNode* reverseList(ListNode* head) {
    //     if(!head || !head->next) {
    //         return head;
    //     }
    //     ListNode* reversed = reverseList(head->next);
    //     ListNode* temp = reversed;
    //     while(temp->next) temp = temp->next;
    //     temp->next = head;
    //     head -> next = NULL;
    //     return reversed;
    // }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* curr=head;
        ListNode* prev = NULL;
        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        } 
        return prev;
    }
};
// @lc code=end

