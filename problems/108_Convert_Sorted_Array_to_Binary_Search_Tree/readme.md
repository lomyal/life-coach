# 108_Convert_Sorted_Array_to_Binary_Search_Tree

Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

## Solution

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

时间复杂度：O(n)

空间复杂度：O(logn)