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
    ListNode *findNewTail(ListNode *head, int k)
    {
        int count=1;
        while(head!=NULL)
        {
            if(count==k)
                return head;
            count++;
            head=head->next;
        }
        return head;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)
            return head;
        ListNode *tail=head;
        int len=1;
        while(tail->next!=NULL)
        {
            len++;
            tail=tail->next;
        }
        if(k%len==0)
            return head;
        k=k%len;
        tail->next=head;
        ListNode *newTail = findNewTail(head, len-k);
        head=newTail->next;
        newTail->next=NULL;
        return head;
    }
};