<------ 1 ------!>

// Maximum sum path in matrix
// https://practice.geeksforgeeks.org/problems/path-in-matrix3805/1

// time -> O(n^2)
// space -> O(n^2)

int recursion(int row, int col, vector<vector<int>> &matrix, vector<vector<int>> &t)
{
    int n=matrix.size();
    
    if(row==n-1)
        return 0;
        
    if(t[row][col]!=-1)
        return t[row][col];
    
    if(col>0 && col<n-1)
        return t[row][col] = max( recursion(row+1,col,matrix,t)+matrix[row+1][col] , max ( recursion(row+1, col+1,matrix,t)+matrix[row+1][col+1] , recursion(row+1, col-1,matrix,t)+matrix[row+1][col-1] ) );
        
    if(col>0)
        return t[row][col] = max( recursion(row+1,col,matrix,t)+matrix[row+1][col] , recursion(row+1, col-1,matrix,t)+matrix[row+1][col-1]);
    
    if(col<n-1)
        return t[row][col] = max( recursion(row+1,col+1,matrix,t)+matrix[row+1][col+1] , recursion(row+1, col,matrix,t)+matrix[row+1][col]);
    
}
int maximumPath(int N, vector<vector<int>> Matrix)
{
    if(N==1)
        return Matrix[0][0];
        
        
    vector<vector<int>> t(N,vector<int> (N,-1));
        
    int max_ans = INT_MIN;
    for(int i=0;i<N;i++)
    {
        int temp = recursion(0,i,Matrix,t);
        temp += Matrix[0][i];
        max_ans = max( max_ans , temp );
    }
    return max_ans;
}



<------ 2 ------!>

// Coin change
// https://practice.geeksforgeeks.org/problems/coin-change2448/1

// time -> O(n*m)
// space -> O(n*m)

vector<vector<long long int>> t;
long long int recursion( int n, int s[], long long int sum, int target)
{
    if(sum==target)
        return 1;
    
    if(n<0)
        return 0;
        
    if(t[n][sum]!=-1)
        return t[n][sum];
    
    if(sum+s[n] > target)
        return t[n][sum] = recursion(n-1,s,sum,target);

    else
        return t[n][sum] = recursion(n-1,s,sum,target) + recursion(n,s,sum+s[n],target);
}

long long int count( int S[], int m, int n )
{
    t.resize(m, vector<long long int> (n,-1));
    return recursion(m-1,S,0,n);
}



<------ 3 ------!>

// Subset Sum
// https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1/

// time -> O(n*sum)
// space -> O(n*sum)

vector<vector<int>> t;
bool recursion(int n, int arr[], int sum)
{
    if(sum==0)
        return true;
        
    if(n<0)
        return false;
        
    if(t[n][sum]!=-1)
        return t[n][sum];
        
    if(arr[n] > sum)
        return t[n][sum] = recursion(n-1,arr,sum);
    else
        return t[n][sum] = recursion(n-1,arr,sum) || recursion(n-1,arr,sum-arr[n]);
        
}
bool isSubsetSum(int N, int arr[], int sum)
{
    t.resize(N, vector<int> (sum+1,-1));
    return recursion(N-1,arr,sum);
}



<------ 4 ------!>

// Rod Cutting
// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1

// time -> O(n^2)
// space -> O(n)

vector<int> t;
int recursion(int price[], int n)
{
    if(n<=0)
        return 0;
    
    if(t[n]!=-1)
        return t[n];
        
    int max_ans = INT_MIN;
    for(int i=0;i<n;i++)
    {
        max_ans = max( max_ans , recursion(price, n-i-1) + price[i] );
    }
    return t[n] = max_ans;
}
int cutRod(int price[], int n)
{
    t.resize(n+1,-1);
    return recursion(price,n);
}



<------ 5 ------!>

// Egg Dropping
// https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1

// time -> O(e*log(f))
// space -> O(e*f)

vector<vector<int>> t;
int recursion(int e, int f)
{
    if(t[e][f]!=-1)
        return t[e][f];
    
    if(e==0 || f==0)
        return t[e][f] = 0;
    
    if(e==1 || f==1)
        return t[e][f] = f;
    
    int min_ans = INT_MAX;        
    int l=1,h=f;

    // Used binary search insted of linear search
    while(l<=h)
    {
        int mid = l+(h-l)/2;
                    
        int low = recursion(e-1,mid-1);
        int high = recursion(e,f-mid);
        
        int temp = 1+max(low,high);            
        min_ans = min( min_ans, temp );            
        
        if(low>high)
            h = mid-1;
        else
            l = mid+1;
    }
    return t[e][f] = min_ans;
}

int superEggDrop(int k, int n)
{
    t.resize(k+1, vector<int> (n+1 ,-1));
    
    return recursion(k,n);
}



<------ 6 ------!>

// Word Break 
// https://leetcode.com/problems/word-break/

// time -> O(n*n)
// space -> O(n)

bool ans=false;
unordered_map<string, int> mp;
vector<int> t;

bool recursion(string s,int index)
{    
    string curr="";
    
    if(index>=s.length())
    {        
        ans|=true;
        return ans;
    }
    
    if(t[index]!=-1)
        return t[index];    
    
    for(int i=index;i<s.length();i++)
    {
        curr+=s[i];
        if(mp.find(curr) != mp.end())
        {           
            ans |= recursion(s,i+1);
            t[index] = ans;
        }
    }
    ans|=false;
    return ans;    
}
bool wordBreak(string s, vector<string>& wordDict)
{
    int n =wordDict.size();
    for(int i=0;i<n;i++)    
        mp[wordDict[i]]++;
    
    t.resize(s.length()+1,-1);
                        
    return ans|= recursion(s,0);
}



<------ 7 ------!>

// Palindrome Partitioning (MCM Variation)
// https://leetcode.com/problems/palindrome-partitioning-ii/

1.
// time -> O(n^3)
// space -> O(n^2)

bool isPalin(string &s, int i, int j)
{
    while(i<j)
    {
        if(s[i]!=s[j])
            return false;
        i++;
        j--;            
    }
    return true;
}
vector<vector<int>> t;
int recursion(string &s, int i, int j)
{
    if(i>=j)
        return 0;
    
    if(isPalin(s,i,j))
        return 0;
    
    if(t[i][j]!=-1)
        return t[i][j];
    
    int min_ans = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int left,right;
                    
        if(t[i][k]!=-1)
            left = t[i][k];
        else
        {
            left = recursion(s,i,k);
            t[i][k] = left;
        }
        
        if(t[k+1][j]!=-1)
            right = t[k+1][j];
        else
        {
            right = recursion(s,k+1,j);
            t[k+1][j] =right;
        }
        
        int temp = left+right+1;
        
        min_ans = min(min_ans , temp);
    }        
    return t[i][j] = min_ans;
}
int minCut(string s)
{
    int n=s.length();
    t.resize(n, vector<int> (n,-1));
    
    return recursion(s,0,n-1);
}

2.
// time -> O(n^2)
// space -> O(n)

int minCut(string s)
{
    int n=s.length();
    
    vector<int> cuts(n+1);
    
    for(int i=0;i<=n;i++)
        cuts[i] = i-1;
    
    for(int i=0;i<n;i++)
    {
        //odd
        for(int j=0; i+j<n && i-j>=0 && s[i+j]==s[i-j]; j++)            
            cuts[i+j+1] = min( cuts[i+j+1] , cuts[i-j]+1 );
        
        //even
        for(int j=1; i+j<n && i-j+1>=0 && s[i+j]==s[i-j+1]; j++)            
            cuts[i+j+1] = min( cuts[i+j+1] , cuts[i-j+1]+1 );
    }
    return cuts[n];        
}



<------ 8 ------!>

// Maximum profit in Job scheduling
// https://practice.geeksforgeeks.org/problems/job-sequencing-problem-1587115620/1

1.
// time -> O(nlogn)
// space -> O(n)

static bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}
vector<int> JobScheduling(Job arr[], int n) 
{ 
    sort(arr, arr+n, comp);
    
    int max_dead = INT_MIN;
    for(int i=0;i<n;i++)
        max_dead = max(max_dead, arr[i].dead);
        
    vector<int> res (max_dead+1, -1);
    int cnt=0, profit=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=arr[i].dead; j>0; j--)
        {
            if(res[j]==-1)
            {
                cnt++;
                profit+=arr[i].profit;
                res[j]=i;
                break;
            }
        }
    }
    return vector<int> {cnt,profit};
} 