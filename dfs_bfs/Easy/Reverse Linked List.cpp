class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *CurrentNode = head;
        ListNode *output = NULL;
        
        if(!head) return head;

        while(head){
            CurrentNode = head->next;
            head->next = output;
            output = head;
            head = CurrentNode;
        }

        return output;
    }
};