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
    ListNode* reverse_ll(ListNode *head)
    {
        ListNode *prev = NULL, *curr = head;
        while(curr!=NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
   bool isPalindrome(struct ListNode* head) 
   {
    ListNode *slow = head, *fast = head;
    while(fast->next!=NULL && fast->next->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    ListNode *newHead = reverse_ll(slow->next);
    ListNode *temp1 = head; 
    ListNode *temp2 = newHead;
    while(temp2!=NULL)
    {
        if(temp1->val!=temp2->val)
            return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    return true;
   }
};