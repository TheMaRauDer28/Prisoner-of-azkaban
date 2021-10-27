<------ 1 ------!>

// Floor and Ceil in a BST
// https://www.geeksforgeeks.org/floor-and-ceil-from-a-bst/

// time -> O(n)
// space -> O(1)

void floor_ceil(Node* root, Node*& f, Node*& c, int key)
{
    if(!root)
        return;
    if(root->data == key)
    {
        f=root;
        c=root;
        return;
    }
    if(root->data > key)
    {
        c=root;
        floor_ceil(root->left, f,c,key);
    }
    else
    {
        f=root;
        floor_ceil(root->right, f,c,key);
    }
}



<------ 2 ------!>

1. 
// Kth Smallest Element in a BST
// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

// time -> O(n)
// space -> O(n)

int kthSmallest(TreeNode* root, int k)
{        
    stack<TreeNode*> st;
    TreeNode* node;
    st.push(root);
    
    while(!st.empty())
    {
        node = st.top();              
        if(node->left)
        {
            st.push(node->left);
            node->left = NULL;
        }
        else
        {
            st.pop();
            k--;
            if(k==0)
            {                
                break;
            }
            if(node->right)
                st.push(node->right);
        }            
    }
    return node->val;    
}

2.
// Kth largest Element in a BST
// https://practice.geeksforgeeks.org/problems/k-largest-elements3736/1

// time -> O(n)
// space -> O(1)

int kthLargest(Node *root, int k)
{
    Node* curr = root;
    int cnt=0;
    while(root)
    {
        if(curr->right == NULL)
        {
            cnt++;
            if(cnt==k)
                break;
            curr = curr->left;
        }
        else
        {
            Node* succ = curr->right;
            
            while(succ->left && succ->left != curr)
                succ = succ->left;
                
            if(succ->left == NULL)
            {
                succ->left = curr;
                curr=curr->right;
            }
            else
            {
                succ->left = NULL;
                cnt++;
                if(cnt==k)
                    break;
                curr = curr->left;
            }
        }
    }
    return curr->data;
}



<------ 3 ------!>

// Find a pair with a given sum in BST
// https://www.geeksforgeeks.org/floor-and-ceil-from-a-bst/

// time -> O(n)
// space -> O(n)

bool findTarget(TreeNode* root, int k)
{        
    unordered_set<int> st;
    return find(root, st, k);
    
}
bool find(TreeNode* root, unordered_set<int>& st, int k)
{
    if(!root)
        return false;
    if(st.find(k - root->val) != st.end())
        return true;
    
    st.insert(root->val);
    
    return find(root->left, st, k) || find(root->right, st, k);
}



<------ 4 ------!>

// BST iterator
// https://leetcode.com/problems/binary-search-tree-iterator/

// time -> O(1)   //for operation
// space -> O(h)

stack<TreeNode*> st;
BSTIterator(TreeNode* root)
{
    add_left(root);
}

int next()
{
    TreeNode* p=st.top();
    st.pop();
    if(p->right)
        add_left(p->right);
    return p->val;
}

bool hasNext()
{
    if(st.empty())
        return false;
    return true;
        
}
void add_left(TreeNode* root)
{        
    while(root)
    {
        st.push(root);
        root=root->left;
    }            
}



<------ 5 ------!>

// Size of the largest BST in a Binary Tree
// https://practice.geeksforgeeks.org/problems/largest-bst/1

1.
// time -> O(n^2)
// space -> O(1)

bool validate(Node* root, Node* minNode, Node* maxNode)
{
    if(!root)    
        return true;
    
    if((minNode && root->data <= minNode->data) || (maxNode && root->data >= maxNode->data))
        return false;
    
    return validate(root->left, minNode, root) && validate(root->right, root, maxNode);
}
int size(Node* root)
{
    if(!root)
        return 0;
    int lsize = size(root->left);
    int rsize = size(root->right);
    
    return lsize+rsize+1;
}

int largestBst(Node *root)
{
    if(validate(root,NULL,NULL))
        return size(root);
        
    return max(largestBst(root->left), largestBst(root->right));
}

2.
// time -> O(n)
// space -> O(n)

struct Info
{
    int size; // Size of subtree
    int max; // Min value in subtree
    int min; // Max value in subtree
    
    bool isBST; // If subtree is BST
};

Info findLargest(Node* root)
{
    if(!root)
        return {0, INT_MIN, INT_MAX, true};
    
    Info l = findLargest(root->left);
    Info r = findLargest(root->right);
    
    if(l.isBST && r.isBST && l.max < root->data && r.min > root->data)
    {
        Info inf;
        inf.min = min(root->data, min(r.min, l.min));
        inf.max = max(root->data, max(r.max, l.max));
        inf.size = l.size + r.size + 1;
        inf.isBST = true;
        
        return inf;
    }
    else
    {
        return {max(l.size, r.size), 0, 0, false};
    }
}

int largestBst(Node *root)
{
    Info inf = findLargest(root);
    return inf.size;
}



<------ 6 ------!>

// Serialize and deserialize Binary Tree
// https://leetcode.com/problems/serialize-and-deserialize-binary-tree/

// time -> O(n)
// space -> O(n)

string serialize(TreeNode* root)
{
    if(!root)
        return "#,";
    
    return to_string(root->val)+","+serialize(root->left)+serialize(root->right);
}

// Decodes your encoded data to tree.
TreeNode* deserialize(string data)
{
    queue<string> q;
    string s="";
    
    for(int i=0;i<data.length();i++)
    {
        if(data[i]==',')
        {
            q.push(s);
            s="";
        }
        else
            s+=data[i];
    }    
    return builder(q);
}

TreeNode* builder(queue<string>& q)
{
    string s=q.front();
    q.pop();
    
    if(s=="#")
        return NULL;
    
    TreeNode* root = new TreeNode(stoi(s));
    
    root->left = builder(q);
    root->right = builder(q);
    
    return root;
}