/**
 * 单链表中判断有环
 * 方法一，快慢指针, 使用 map 存储每个节点的指针
*/

/**
 * 方法一，快慢指针
*/

struct ListNode
{
    int data;
    ListNode* next;
};


bool hasCycle(ListNode* head)
{
    if(head == nullptr || head->next == nullptr) {
        return false;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;
    while (slow != fast)
    {
        if(fast == nullptr || fast->next == nullptr) {
            return false;
        }

        slow = slow->next;
        fast = fast->next->next;
    }
    
}

bool hasCycle_2(ListNode* head)
{
    if(head == nullptr || head->next == nullptr) {
        return false;
    }

    map<ListNode*, bool> mp;
    
    ListNode* tmp = head->next;
    while (tmp != nullptr)
    {
        if(mp.find(tmp) == mp.end()) {
            mp[tmp] = true;
        }
        else {
            return true;
        }

        tmp = tmp->next;
    }
    
    return false;
}