class Solution {
private:
    vector<int> max;
    int output=0;

private:
    void treeSearch(TreeNode* input){
        if(input->val>=max[max.size()-1]){
            output++;
            max.push_back(input->val);
        }

        if(input->left!=NULL){
            treeSearch(input->left);
        }
        if(input->right!=NULL){
            treeSearch(input->right);
        }
        if(input->val==max[max.size()-1]){
                max.pop_back();
        }
    }

public:
    int goodNodes(TreeNode* root) {
        if(!root) return 0;

        max.push_back(INT_MIN);
        treeSearch(root);
        return output;
    }
};