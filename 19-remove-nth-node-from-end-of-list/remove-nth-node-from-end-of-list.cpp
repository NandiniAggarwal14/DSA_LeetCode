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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==NULL)
            return head;
        int count = 0;
        ListNode *temp = head;
        while(temp!=NULL)
        {
            count++;
            temp = temp->next;
        }
        if(count<n)
            return head;
        if(count == n)
        {
            ListNode *temp = head;
            head = head->next;
            delete temp;
            return head;
        }
        temp = head;
        for(int i=0; i<(count-n-1); i++)
            temp=temp->next;
        ListNode *deletion = temp->next;
        temp->next = deletion->next;
        delete deletion;
        return head;
    }
};