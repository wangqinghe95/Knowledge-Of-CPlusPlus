/*
链表反转-带头结点
1. 思路：链表反转需要三个参数辅助，一个是前节点 prev 指针，一个当前 curr 节点，一个是下一个节点 next 指针
    先保存 prev->next 节点保存到 next 指针
    然后将 pre->next 指针指向前节点 prev，完成当前节点的反转
    然后指针全部向前移动，将 curr 赋值给 prev，next 赋值给 curr
    curr 指针非空，继续反转
2. leetcode 例题
    // ![单链表反转-带头节点](https://leetcode-cn.com/problems/reverse-linked-list/submissions/)
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