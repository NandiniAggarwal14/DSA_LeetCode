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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *p1 = head->next;
        head->next = p1->next;
        p1->next = head;
        ListNode *p2 = head->next;
        ListNode *p3 = head;
        ListNode *newHead = p1;
        p1 = head;
        int count = 0;
        while(p2!=NULL)
        {
            count++;
            if(count%2==0)
            {
                ListNode *p4 = p2->next;
                p1->next = p4;
                p3->next = p2;
                p2->next = p1;
                p2 = p2->next;
            }
            p3 = p1;
            p1 = p2;
            p2=p2->next;
        }
        return newHead;
    }
};