/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == NULL) return NULL;
        int len = 0;
        ListNode* p = head;
        for (; p != NULL;) {
            ++len;
            p = p->next;
        }
        return helper(head, 0, len - 1);
    }
private:
    TreeNode* helper(ListNode*& head, int start, int end) {  // head 为传引用，使得 head 在递归中的变化能被跟踪
        if (start > end) return NULL;
        int middle = start + ((end - start) >> 1);
        TreeNode* left = helper(head, start, middle - 1);  // 完成左子树构造后，head 指向根节点的取值
        TreeNode* node = new TreeNode(head->val);  // 构造根节点
        node->left = left;
        head = head->next;  // 这个移动没有任何多余操作，算法执行完时正好从链表头遍历到了列表尾部
        node->right = helper(head, middle + 1, end);
        return node;
    }
};