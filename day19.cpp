<------ 1 ------!>

// Maximum path sum
// https://leetcode.com/problems/binary-tree-maximum-path-sum/

// time -> O(n)
// space -> O(1)

int max_sum=INT_MIN;                
int calculate(TreeNode* root)        
{
    if(!root)
        return 0;
    
    int lsum = max( calculate(root->left) , 0 );
    int rsum = max( calculate(root->right) , 0 );
    
    max_sum = max( max_sum, lsum+rsum+root->val );
    
    return max(root->val+lsum, root->val+rsum);
}

int maxPathSum(TreeNode* root)
{        
    calculate(root);
    
    return max_sum;
}



<------ 2 ------!>

// Construct Binary Tree from inorder and preorder
// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/

// time -> O(n^2)  // this can be optimized using extra space
// space -> O(1)

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    return builder(0,0,inorder.size()-1,preorder,inorder);
}

TreeNode* builder(int preStart, int inStart, int inEnd, vector<int>& preorder, vector<int>& inorder)
{
    if(preStart>preorder.size() || inStart>inEnd)
        return NULL;
    
    TreeNode* root = new TreeNode(preorder[preStart]);
    int inIndex;
    
    // finding indx (if using map this can be done in log n)
    for(int i=inStart;i<=inEnd;i++)
    {
        if(root->val == inorder[i])
            inIndex=i;
    }
    
    root->left = builder(preStart+1, inStart, inIndex-1, preorder, inorder);
    root->right = builder(preStart + inIndex - inStart + 1, inIndex+1, inEnd, preorder, inorder);
    
    return root;
    
}



<------ 3 ------!>

// Construct Binary Tree from Inorder and Postorder
// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

// time -> O(nlogn)  
// space -> O(n)     // this can be optimized using more complexity

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
{
    int n=inorder.size();
    map<int,int> mp;
    for(int i=0;i<n;i++)
        mp[inorder[i]]=i;
    
    return builder(mp, postorder, n-1, 0, n-1);
}
TreeNode* builder(map<int,int>& mp, vector<int>& postorder, int postEnd, int start, int end)
{
    if(postEnd<0 || start>end)
        return NULL;
    
    TreeNode* root = new TreeNode(postorder[postEnd]);
    
    int indx = mp[postorder[postEnd]];   // this can be done in O(1) space
    
    root->left = builder(mp, postorder, postEnd-end+indx-1, start, indx-1);
    
    root->right = builder(mp, postorder, postEnd-1, indx+1, end);
    
    return root;       
}



<------ 4 ------!>

// Symmetric Binary Tree 
// https://leetcode.com/problems/symmetric-tree/

// time -> O(n)  
// space -> O(n)

bool isSymmetric(Node* root)
{
    if(!root)
        return true;
    
    queue<Node*> q1;
    queue<Node*> q2;
    q1.push(root->left);
    q2.push(root->right);
    
    while(!q1.empty() && !q2.empty())
    {
        Node* node1 = q1.front();
        Node* node2 = q2.front();
        q1.pop();
        q2.pop();
        
        if(!node1 && !node2)
            continue;
        
        if(!node1 || !node2)
            return false;   
        
        if(node1->val != node2->val)
            return false;
                    
        q1.push(node1->right);
        q1.push(node1->left);
        q2.push(node2->left);        
        q2.push(node2->right);                        
                               
    }
    return true;
}



<------ 5 ------!>

// Flatten Binary Tree to LinkedList
// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/

// time -> O(n)  
// space -> O(1)

void flatten(TreeNode* root)
{
    if(!root)
        return;
    
    TreeNode* temp = root->right;
    root->right = root->left;        
    root->left = NULL;
    
    TreeNode* node = root;
    while(node->right)
        node = node->right;
    
    node -> right = temp;
    
    flatten(root->right);
}

<------ 6 ------!>

// Check if Binary Tree is mirror of itself or not
(This is symmetric tree question)