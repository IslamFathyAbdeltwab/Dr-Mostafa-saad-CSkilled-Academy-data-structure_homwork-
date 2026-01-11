#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cassert>
#include <cmath>
using namespace std;
struct TreeNode
{
    int val{};
    TreeNode *left{};
    TreeNode *right{};
    TreeNode(int val) : val(val) {}
};
class BinaryTree
{
public:
    TreeNode *root{};
    BinaryTree(int root_value) : root(new TreeNode(root_value))
    {
    }
    void add(vector<int> values, vector<char> direction)
    {
        assert(values.size() == direction.size());
        TreeNode *current = this->root;
        // iterate on the path, create all necessary TreeNodes
        for (int i = 0; i < (int)values.size(); ++i)
        {
            if (direction[i] == 'L')
            {
                if (!current->left)
                    current->left = new TreeNode(values[i]);
                else
                    assert(current->left->val == values[i]);
                current = current->left;
            }
            else
            {
                if (!current->right)
                    current->right = new TreeNode(values[i]);
                else
                    assert(current->right->val == values[i]);
                current = current->right;
            }
        }
    }
    void print_inorder(TreeNode *current)
    {
        if (!current)
            return;
        print_inorder(current->left);
        cout << current->val << " ";
        print_inorder(current->right);
    }
};
bool is_leaf(TreeNode *root)
{
    return root && !root->left && !root->right;
}
int number_of_nodes(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + number_of_nodes(root->left) + number_of_nodes(root->right);
}
int findNodeDepth(TreeNode *root, int value, int curDepth = 0) {
		if (!root)
			return 0;

		if (root->val == value)
			return curDepth;

		int leftDepth = findNodeDepth(root->left, value, curDepth + 1);
		if (leftDepth != 0)
			return leftDepth;	

		return findNodeDepth(root->right, value, curDepth + 1);
	}

	TreeNode* findParentNode(TreeNode *root, int value) {
		if (!root || root->val == value)	
			return nullptr;

		if ((root->left && root->left->val == value) || 	
			(root->right && root->right->val == value))
			return root;

		TreeNode *leftParent = findParentNode(root->left, value);
		if (leftParent != nullptr)
			return leftParent;

		return findParentNode(root->right, value);;
	}
class Solution
{
public:
    // problem one
    int maxValue(TreeNode *root)
    {

        if (!root)
        {
            return INT_MIN;
        }
        int l = maxValue(root->left);
        int r = maxValue(root->right);
        return max(max(l, r), root->val);
    }
    // problem two
    int maxDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    //  problem three
    bool hasPathSum(TreeNode *root, int target_sum, int cur_sum = 0)
    {
        if (!root)
        {
            return false;
        }
        cur_sum += root->val;
        if (is_leaf(root) && target_sum == cur_sum)
            return true;
        return hasPathSum(root->left, target_sum, cur_sum) || hasPathSum(root->right, target_sum, cur_sum);
    }
    // problem four
    int sumOfLeftLeaves(struct TreeNode *root)
    {
        if (!root)
        {
            return 0;
        }
        int sum = 0;
        if (is_leaf(root->left))
        {
            sum += root->left->val;
        }
        sum += sumOfLeftLeaves(root->left);
        sum += sumOfLeftLeaves(root->right);
        return sum;
    }
    // problem five
    bool isCousins(TreeNode *root, int x, int y)
    {
        if (findNodeDepth(root, x) != findNodeDepth(root, y))
            return false;
        if (findParentNode(root, x) == findParentNode(root, y))
            return false;
        return true;
    }
    // problem six
    // one way
    bool isParfect1(TreeNode *root)
    {
        int h = maxDepth(root) - 1;
        int n = number_of_nodes(root);
        return pow(2, h + 1) - 1 == n;
    }
    // seconde way
    // bool isParfect1(TreeNode *root, int h)
    // {
    //     if (is_leaf(root))
    //         return h == 0;
    //     if (!root->left && root->right || root->left && !root->right)
    //         return false;
    //     return isParfect1(root->left, h - 1) && isParfect1(root->right, h - 1);
    // }
    // 3rd way
    //  pair<bool, int> _isPerfect_cnt(TreeNode* root) { // first refer to perfect or not // seconde refer to number of nodes
    //     if (!root)
    // 		return {false, 0};
    //     if (is_leaf(root))
    // 		return {true, 1};
    //     auto left = _isPerfect_cnt(root->left);
    //     auto right = _isPerfect_cnt(root->right);
    //     // left and right should be perfect and nodes are equal
    //     bool perfect = left.first && right.first && (left.second == right.second);
    //     return {perfect, 1 + left.second + right.second};
    // }
};
int main()
{

    // // test one
    // BinaryTree tree(1);
    // cout << Solution().maxValue(tree.root) << "\n";

    // tree.add({2, 4, 7}, {'L', 'L', 'L'});
    // cout << Solution().maxValue(tree.root) << "\n";

    // tree.add({2, 4, 8}, {'L', 'L', 'R'});
    // cout << Solution().maxValue(tree.root) << "\n";

    // tree.add({2, 5, 9}, {'L', 'R', 'R'});
    // cout << Solution().maxValue(tree.root) << "\n";

    // tree.add({3, 6, 10}, {'R', 'R', 'L'});
    // cout << Solution().maxValue(tree.root) << "\n";

    // ****************************************
    // // test two
    // BinaryTree tree(1);
    // tree.add({2, 4, 7}, {'L', 'L', 'L'});
    // tree.add({2, 4, 8}, {'L', 'L', 'R'});
    // tree.add({2, 5, 9}, {'L', 'R', 'R'});
    // tree.add({3, 6, 10}, {'R', 'R', 'L'});
    // cout << Solution().maxDepth(tree.root) << "\n";

    // ****************************************

    // // test three
    // BinaryTree tree(1);
    // tree.add({2, 4, 7}, {'L', 'L', 'L'});
    // tree.add({2, 4, 8}, {'L', 'L', 'R'});
    // tree.add({2, 5, 9}, {'L', 'R', 'R'});
    // tree.add({3, 6, 10}, {'R', 'R', 'L'});
    // cout << Solution().hasPathSum(tree.root, 17) << "\n";
    // cout << Solution().hasPathSum(tree.root, 170) << "\n";
    // cout << Solution().hasPathSum(tree.root, 0) << "\n";

    // ****************************************
    //// test four
    // BinaryTree tree(1);
    // tree.add({2, 4, 7}, {'L', 'L', 'L'});
    // tree.add({2, 4, 8}, {'L', 'L', 'R'});
    // tree.add({2, 5, 9}, {'L', 'R', 'R'});
    // tree.add({3, 6, 10}, {'R', 'R', 'L'});
    // cout << Solution().sumOfLeftLeaves(tree.root) << "\n"; // 17
    // ****************************************

    // // test five
	// BinaryTree tree(1);
	// tree.add( { 2, 4, 7 }, { 'L', 'L', 'L' });
	// tree.add( { 2, 4, 8 }, { 'L', 'L', 'R' });
	// tree.add( { 2, 5, 9 }, { 'L', 'R', 'R' });
	// tree.add( { 3, 6, 10 }, { 'R', 'R', 'L' });

	// cout << Solution().isCousins(tree.root, 7, 8) << "\n";	// 0
    // ****************************************

    // // test six
    // BinaryTree tree(1);

    // assert(Solution()._isPerfect_cnt(tree.root).first == 1);

    // tree.add({2}, {'L'});
    // assert(Solution()._isPerfect_cnt(tree.root).first == 0);

    // tree.add({3}, {'R'});
    // assert(Solution()._isPerfect_cnt(tree.root).first == 1);

    // tree.add({3, 6}, {'R', 'R'});
    // tree.add({3, 14}, {'R', 'L'});
    // assert(Solution()._isPerfect_cnt(tree.root).first == 0);

    // tree.add({2, 4, 7}, {'L', 'L', 'L'});
    // tree.add({2, 4, 8}, {'L', 'L', 'R'});
    // tree.add({2, 5, 9}, {'L', 'R', 'R'});
    // tree.add({3, 6, 15}, {'R', 'R', 'L'});
    // assert(Solution()._isPerfect_cnt(tree.root).first == 0);

    // tree.add({2, 5, 13}, {'L', 'R', 'L'});
    // tree.add({3, 6, 12}, {'R', 'R', 'R'});
    // assert(Solution()._isPerfect_cnt(tree.root).first == 0);

    // tree.add({3, 14, 15}, {'R', 'L', 'L'});
    // tree.add({3, 14, 16}, {'R', 'L', 'R'});

    // assert(Solution()._isPerfect_cnt(tree.root).first == 1); // now 8 leaf nodes

    // cout << "bye";

    // ****************************************
}