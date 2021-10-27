<------ 1 ------!>

// Populate Next Right pointers of Tree

// time -> O(n)
// space -> O(1)

1. Perfect binary tree
// https://leetcode.com/problems/populating-next-right-pointers-in-each-node/

Node* connect(Node* root)
{
    if(!root)
        return root;
    
    if(root->left)
        root->left->next = root->right;
    
    if(root->right && root->next)
        root->right->next = root->next->left;
    
    connect(root->left);
    connect(root->right);
    
    return root;
}

2. Not perfect
// https://practice.geeksforgeeks.org/problems/connect-nodes-at-same-level/1

void connect(Node *root)
{
    root->nextRight = NULL;
    connect_build(root);
}

void connect_build(Node *root)
{    
    if(!root)
        return;
    
    if(root->left)
    {
        if(root->right)
            root->left->nextRight = root->right;
        else
        {
            if(root->nextRight)
            {
                if(root->nextRight->left)
                    root->left->nextRight = root->nextRight->left;
                else if(root->nextRight->right)
                    root->left->nextRight = root->nextRight->right;
                else
                    root->left->nextRight = NULL;
            }
            else
                root->left->nextRight = NULL;
        }
    }
                
    if(root->right)
    {
        if(root->nextRight)
        {
            if(root->nextRight->left)
                root->right->nextRight = root->nextRight->left;
            else if(root->nextRight->right)
                root->right->nextRight = root->nextRight->right;
            else
                root->right->nextRight = NULL;
        }
        else
            root->right->nextRight = NULL;
    }
    
    connect_build(root->left);
    connect_build(root->right);
    
    return;
} 



<------ 2 ------!>

// Search given Key in BST
// https://leetcode.com/problems/search-in-a-binary-search-tree/

// time -> O(n)
// space -> O(1)

TreeNode* searchBST(TreeNode* root, int val)
{
    if(!root)    
        return root;
    
    if(val > root->val)
        return searchBST(root->right, val);
    
    else if(val < root->val)
        return searchBST(root->left, val);
    
    else
        return root;
        
}



<------ 3 ------!>

// Construct BST from given keys
// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

// time -> O(n)
// space -> O(1)

TreeNode* sortedArrayToBST(vector<int>& nums) {
    return builder(0,nums.size()-1,nums);
}

TreeNode* builder(int start, int end, vector<int>& nums)
{
    if(start>end)
        return NULL;
    
    int mid=(start+end)/2;
    
    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = builder(start,mid-1,nums);
    root->right = builder(mid+1,end, nums);
    
    return root;        
}



<------ 4 ------!>

// Check is a BT is BST or not
// https://leetcode.com/problems/validate-binary-search-tree/

// time -> O(n)
// space -> O(1)

bool isValidBST(TreeNode* root)
{                
    return validate(root,NULL,NULL);      
}

bool validate(TreeNode* root, TreeNode* minNode, TreeNode* maxNode)
{
    if(!root)    
        return true;
    
    if((minNode && root->val <= minNode->val) || (maxNode && root->val >= maxNode->val))
        return false;
    
    return validate(root->left, minNode, root) && validate(root->right, root, maxNode);
}



<------ 5 ------!>

// Find LCA of two nodes in BST
// https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/

// time -> O(n)
// space -> O(1)

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
{
    if(p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q);
    
    if(p->val <root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);
    
    return root;
}



<------ 5 ------!>

// Find the inorder predecessor/successor of a given Key in BST. 
// https://practice.geeksforgeeks.org/problems/predecessor-and-successor/1

// time -> O(n)
// space -> O(1)

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(!root)
        return;
        
    if(root->key == key)
    {
        if(root->left)
        {
            Node* node=root->left;
            while(node->right)
                node = node->right;
            pre = node;
        }
        if(root->right)
        {
            Node* node=root->right;
            while(node->left)
                node = node->left;
            suc = node;
        }
        return;
    }
    else if(root->key > key)
    {
        suc=root;
        findPreSuc(root->left,pre,suc,key);
    }
    else
    {
        pre=root;
        findPreSuc(root->right,pre,suc,key);
    }

}