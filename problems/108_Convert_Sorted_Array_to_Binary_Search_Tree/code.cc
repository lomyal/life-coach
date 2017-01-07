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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty()) return NULL;
        return helper(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* helper(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        int middle = start + ((end - start) >> 1);  // 防溢出，注意 >> 的运算优先级很低，需要用括号
        TreeNode* node = new TreeNode(nums[middle]);
        node->left = helper(nums, start, middle - 1);
        node->right = helper(nums, middle + 1, end);
        return node;
    }
};

