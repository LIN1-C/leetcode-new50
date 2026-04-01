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
一：反链表
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       
    // 1. 初始化虚拟头节点
    ListNode* dummy = new ListNode();
    ListNode* curr = dummy;
    int carry = 0; // 进位标志

    // 2. 循环条件：两个链表至少有一个不为空，或者还有进位
    while (l1 != nullptr || l2 != nullptr || carry != 0) {
        int sum = carry; // 初始值加上进位
        
        // 累加 l1 的值
        if (l1 != nullptr) {
            sum += l1->val;
            l1 = l1->next;
        }
        
        // 累加 l2 的值
        if (l2 != nullptr) {
            sum += l2->val;
            l2 = l2->next;
        }

        // 3. 处理当前位和进位
        curr->next = new ListNode(sum % 10); // 创建新节点存当前位
        carry = sum / 10;                    // 更新进位
        
        // 4. 指针后移
        curr = curr->next;
    }
    return dummy->next; // 返回虚拟头节点的下一个节点（真实头）
}
};

二：正链表：用栈的思想
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
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1 -> val);
            l1 = l1 -> next;
        }
        while (l2) {
            s2.push(l2 -> val);
            l2 = l2 -> next;
        }
        int carry = 0;
        ListNode* ans = nullptr;
        while (!s1.empty() or !s2.empty() or carry != 0) {
            int a = s1.empty() ? 0 : s1.top();
            int b = s2.empty() ? 0 : s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            auto curnode = new ListNode(cur);
            curnode -> next = ans;
            ans = curnode;
        }
        return ans;
    }
};

