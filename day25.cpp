<------ 1 ------!>

// Max Product Subarray
// https://leetcode.com/problems/maximum-product-subarray/

// time -> O(n)
// space -> O(1)

int maxProduct(vector<int>& nums)
{
    int n=nums.size();
    
    int maxtill = nums[0];
    int mintill = nums[0];
    int max_so_far = nums[0];
    
    for(int i=1;i<n;i++)
    {
        int maxhere = max(nums[i], max(maxtill*nums[i] , mintill*nums[i]));
        int minhere = min(nums[i], min(maxtill*nums[i] , mintill*nums[i]));
        
        max_so_far = max(max_so_far , maxhere);
        
        maxtill = maxhere;
        mintill = minhere;
    }
    return max_so_far;
}



<------ 2 ------!>

// Longest Increasing Subsequence
// https://leetcode.com/problems/longest-increasing-subsequence/

// time -> O(nlogn)
// space -> O(n)

1. recursion with DP (minindx & indx)

2.
int lengthOfLIS(vector<int>& nums)
{
    int n=nums.size();
    
    vector<int> t(n,0);
    
    t[0]=nums[0];
    int length = 1;
    
    for(int i=1;i<n;i++)
    {
        auto itr = lower_bound(t.begin(), t.begin()+length , nums[i]);
        
        if(itr == t.begin()+length)
        {
            t[length] = nums[i];
            length++;
        }
        else
            *itr = nums[i];
    }        
    return length;
}



<------ 3 ------!>

// Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/

// time -> O(n*m)
// space -> O(n*m)

1. recursion
vector<vector<int>> t;
int recursion(string &a, string &b, int n, int m)
{
    if(n<0 || m<0)
        return 0;
    
    if(t[n][m]!=-1)
        return t[n][m];
    
    if(a[n]==b[m])
        return t[n][m] = recursion(a,b,n-1,m-1)+1;
    else
        return t[n][m] = max( recursion(a,b,n-1,m) , recursion(a,b,n,m-1) );
}
int longestCommonSubsequence(string text1, string text2)
{
    int n=text1.length();
    int m=text2.length();
    
    t.resize(n, vector<int> (m,-1));
    
    return recursion(text1,text2,n-1,m-1);
}

2. top-down
int longestCommonSubsequence(string text1, string text2)
{
    int n=text1.length();
    int m=text2.length();
    
    vector<vector<int>> t(n+1, vector<int> (m+1));
    
    for(int i=0;i<=n;i++)
        t[i][0] = 0;
    
    for(int j=0;j<=m;j++)
        t[0][j] = 0;
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(text1[i-1] == text2[j-1])
                t[i][j] = t[i-1][j-1]+1;
            else
                t[i][j] = max(t[i-1][j], t[i][j-1]);
        }
    }    
    
    return t[n][m];
}



<------ 4 ------!>

// 0-1 Knapsack
// https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// time -> O(n*W)
// space -> O(n*W)

1. recursion
vector<vector<int>> t;
int recursion(int W, int wt[], int val[], int n)
{
    if(n<0)
        return 0;
       
    if(t[n][W]!=-1)
        return t[n][W];
    
    if(wt[n] > W)
        return t[n][W] = recursion(W,wt,val,n-1);
    else
        return t[n][W] = max( recursion(W,wt,val,n-1) , val[n]+recursion(W-wt[n], wt,val,n-1) );
}
int knapSack(int W, int wt[], int val[], int n) 
{ 
    t.resize(n, vector<int> (W+1,-1));
    
    return recursion(W,wt,val,n-1);
}

2. top-down
int knapSack(int W, int wt[], int val[], int n) 
{ 
    vector<vector<int>> t(n+1, vector<int> (W+1));
    
    for(int i=0;i<=n;i++)
        t[i][0] = 0;
        
    for(int j=0;j<=W;j++)
        t[0][j] = 0;
        
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(wt[i-1] > j)
                t[i][j] = t[i-1][j];
            else
                t[i][j] = max( val[i-1]+t[i-1][j-wt[i-1]] , t[i-1][j]);
        }
    }
        
    return t[n][W];
} 



<------ 5 ------!>

// Edit Distance
// https://leetcode.com/problems/edit-distance/

// time -> O(n*m)
// space -> O(n*m)

int minDistance(string word1, string word2)
{
    int n=word1.length();
    int m=word2.length();
    
    vector<vector<int>> t(n+1, vector<int> (m+1));
    
    for(int i=0;i<=n;i++)
        t[i][0] = i;
    
    for(int j=0;j<=m;j++)
        t[0][j] = j;        
        
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(word1[i-1] == word2[j-1])
                t[i][j] = t[i-1][j-1];
            else
            {                    
                t[i][j] = min( t[i-1][j], min( t[i][j-1], t[i-1][j-1] ) )+1;
            }
        }
    }
    
    return t[n][m];
}



<------ 6 ------!>

// Maximum sum increasing subsequence
// https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1

// time -> O(n^2)
// space -> O(n)

int maxSumIS(int arr[], int n)  
{  
    vector<int> t(n,0);
    
    for(int i=0;i<n;i++)
        t[i]=arr[i];
        
    int max_sum=INT_MIN;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i] > arr[j] && t[i] < t[j]+arr[i])
                t[i] = t[j]+arr[i];
        }
        max_sum = max(max_sum , t[i]);
    }
    return max_sum;
}



<------ 7 ------!>

// Matrix Chain Multiplication
// https://practice.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

// time -> O(n^2)
// space -> O(n^2)

vector<vector<int>> t;
int recursion(int arr[], int i, int j)
{
    if(i>=j)
        return 0;
        
    if(t[i][j]!=-1)
        return t[i][j];
        
    int min_ans = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp = recursion(arr,i,k)
                    + recursion(arr,k+1,j)
                    + arr[i-1]*arr[k]*arr[j];
                    
        min_ans = min(min_ans, temp);    
    }
    return t[i][j] = min_ans;
}
int matrixMultiplication(int n, int arr[])
{
    t.resize(n, vector<int> (n,-1));
    
    return recursion(arr, 1, n-1);
}