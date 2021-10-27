    <------ 1 ------!>

// Level order Traversal

// time -> O(n)
// space -> O(n)


1. //https://leetcode.com/problems/binary-tree-inorder-traversal/

vector<int> levelOrder(Node* root)
{
    if(!root)
        return {};

    vector<int> ans;
                       
    queue<Node *> q;    
    q.push(root);

    while(!q.empty())
    {
    	Node *node = q.front();
		ans.push_back(node->data);
		q.pop();
	        
        if (node->left)
            q.push(node->left);
 	        
        if (node->right)
            q.push(node->right);
    }
           
    return ans;
}


2. //https://leetcode.com/problems/binary-tree-inorder-traversal/

vector<int> findSpiral(Node *root)
{
    if(!root)
        return {};

    vector<int> ans;
                       
    stack<Node *> s1;
    stack<Node *> s2;
    
    s1.push(root);
    
    while(!s1.empty() || !s2.empty())
    {    	
    	while(!s1.empty())
    	{
    		Node *node = s1.top();
    		ans.push_back(node->data);
    		s1.pop();
 	        
 	        if(node->right)
	            s2.push(node->right);

	        if(node->left)
	            s2.push(node->left);	 	        	       
    	}
    	while(!s2.empty())
    	{
    		Node *node = s2.top();
    		ans.push_back(node->data);
    		s2.pop();
 	        
 	        if(node->left)
	            s1.push(node->left);

 	        if(node->right)
	            s1.push(node->right);
    	}    	
    }
           
    return ans;
}



<------ 2 ------!>

// Height of a Binary Tree
// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

// time -> O(n)
// space -> O(1)  // Aux space = O(h) for stack due to recursion
(h = logn) (approx)

int height(struct Node* node)
{
    if(!node)
        return 0;
        
    int lheight = height(node->left);
    int rheight = height(node->right);
    
    return max(lheight,rheight)+1;
    
}



<------ 3 ------!>

// Diameter of Binary Tree
// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

// time -> O(n)
// space -> O(1)

int diameter(Node* root)
{
    int d=0;
    calculate(root,d);
    return d;
}
int calculate(Node* root,int& d)
{
    if(!root)
        return 0;
    
    int ldia = calculate(root->left,d);
    int rdia = calculate(root->right,d);
    
    d=max(d,ldia+rdia+1);
    
    return max(ldia,rdia)+1;
}



<------ 4 ------!>

// Check if Binary tree is height balanced or not 
// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

// time -> O(n)
// space -> O(h)  // auxiliary

int height(Node* node, bool& isIt)
{
    if(!node)
        return 0;
        
    int lheight = height(node->left, isIt);
    int rheight = height(node->right, isIt);
    
    isIt &= (abs(lheight-rheight) <= 1);
    
    return max(lheight,rheight)+1;
    
}
bool isBalanced(Node *root)
{
    bool isIt=true;
    height(root, isIt);
    
    return isIt;
}



<------ 5 ------!>

// LCA in Binary Tree 
// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1

// time -> O(n)
// space -> O(h)

Node* lca(Node* root ,int n1 ,int n2 )
{
    if(!root)
        return NULL;
    
    if(root->data==n1 || root->data==n2)
        return root;
        
    Node* left = lca(root->left, n1, n2);
    Node* right = lca(root->right, n1, n2);
    
    if(left && right)
        return root;
    
    if(!left && !right)
        return NULL;
        
    return (left ? left : right);
}



<------ 6 ------!>

// Check if two trees are identical or not
// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1

// time -> O(n)
// space -> O(n)

1. Recursion
bool isIdentical(Node *p, Node *q)
{
    if (p==NULL || q==NULL)
        return q == p;
    
    return p->data == q->data && isIdentical(p->left, q->left) && isIdentical(p->right, q->right);
}

2. Iterative
bool isIdentical(TreeNode* r1, TreeNode* r2)
{        
    stack<TreeNode*> s1,s2;
    s1.push(r1);
    s2.push(r2);

    while(!s1.empty() || !s2.empty())
    {
        TreeNode* node1 = s1.top();
        TreeNode* node2 = s2.top();
        s1.pop();
        s2.pop();

        if(!node1 && !node2)
            continue;

        if(!node1 || !node2)
            return false;

        if(node1->val != node2->val)
            return false;

        s1.push(node1->right);
        s1.push(node1->left);
        s2.push(node2->right);
        s2.push(node2->left);
    }
    if(s1.size() != s2.size())
        return false;
    return true;    
}
