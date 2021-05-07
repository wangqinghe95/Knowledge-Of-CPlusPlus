/*
链表反转
*/

struct ListNode
{
    int val;
    ListNode *next;
};

ListNode* reverseList(ListNode* head){
    ListNode* prev = nullptr;
    ListNode* curr = head;
    while (curr)
    {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;    
}

[leetcode](https://leetcode-cn.com/problems/reverse-linked-list/submissions/)