<------ 1 ------!>

// Clone a graph
// https://leetcode.com/problems/clone-graph/

// time -> O(v+e)
// space -> O(v)    // v=vertex  e=edge

unordered_map<Node*, Node*> mp;
    
Node* cloneGraph(Node* node)
{
    if(!node)
        return NULL;
    if(mp.find(node)==mp.end())    
    {
        mp[node] = new Node(node->val);
        for(Node* child : node -> neighbors)
        {
            (mp[node] -> neighbors).push_back( cloneGraph(child) );
        }
    }
    return mp[node];
}



<------ 2 ------!>

// DFS
// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1

// time -> O(v+e)
// space -> O(v)

vector<int> ans;
vector<bool> vis;
void dfs(int node, vector<int> adj[])
{
    vis[node]=true;
    ans.push_back(node);
    for(int child: adj[node])
    {
        if(!vis[child])
            dfs(child, adj);
    }
}

vector<int>dfsOfGraph(int V, vector<int> adj[])
{
    vis.resize(V, false);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
            dfs(i, adj);
    }
    return ans;
}



<------ 3 ------!>

// BFS
// https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1

// time -> O(v+e)
// space -> O(v)

void bfs(int src)
{
    queue<int> q;
    q.push(src);
    vis[src]=true;
    // dist[src]=0;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();

        for(int child : arr[cur])
        {
            if(vis[child] == false)
            {
                q.push(child);
                vis[child] = true;
                // dist[child] = dist[cur]+1;
            }
        }
    }
}



<------ 4 ------!>

// Detect A cycle in a Graph

1. Undirected
// https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

// time -> O(v+e)
// space -> O(v)

vector<int> arr[MAX];
bool vis[MAX];

bool dfs(int node,int pare)
{
    vis[node]=true;
    for(int child : arr[node])
    {
        if(vis[child]==false)
        {
            if(dfs(child,node)==true)
                return true;
        }
        else if(child != pare)
            return true;
    }
    return false;
}

2. Directed

// time -> O(v+e)
// space -> O(v)

vector<bool> vis;
vector<bool> dfsvis;
bool dfs(int node,int pare, vector<int>arr[])
{
    vis[node]=true;
    dfsvis[node]=true;
    for(int child : arr[node])
    {
        if(vis[child]==false)
        {
            if(dfs(child,node, arr)==true)
                return true;
        }
        else if(dfsvis[child])
            return true;
    }
    dfsvis[node]=false;
    return false;
}



<------ 5 ------!>

// Topological Sort
// https://practice.geeksforgeeks.org/problems/topological-sort/1

// time -> O(v+e)
// space -> O(v)

1. Using DFS

stack<int> st;
vector<bool> vis;
void dfs(int node, vector<int> adj[])
{
    vis[node]=true;
    for(int child: adj[node])
    {
        if(!vis[child])
            dfs(child, adj);
    }
    st.push(node);
} 
vector<int> topoSort(int V, vector<int> adj[]) 
{
    vis.resize(V, false);
    for(int i=0;i<V;i++)
    {
        if(!vis[i])
            dfs(i, adj);
    }
    vector<int> topo;
    while(!st.empty())
    {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

2. Using BFS (Kanh Algo)

vector<int> arr[MAX];
bool vis[MAX];
int in[MAX];
vector<int> result;

vector<int> topoSort(int V, vector<int> adj[]) 
{
    queue<int> pq;
    vector<int> in(V);
    
    for(int i=0;i<V;i++)
    {
        for(int child:adj[i])
            in[child]++;
    }
    
    for(int i=0;i<V;i++)
        if(in[i]==0)
            pq.push(i);
    
    vector<int> ans;
    while(!pq.empty())
    {
        int curr=pq.front();
        ans.push_back(curr);
        pq.pop();
        for(int child : adj[curr])
        {
            in[child]--;
            if(in[child]==0)
                pq.push(child);
        }
    }
    return ans;
}



<------ 6 ------!>

// Number of islands
// https://leetcode.com/problems/number-of-islands/
(bfs approch is also possible done in leetcode)

// time -> O(v^2)
// space -> O(v)

int vis[301][301];
int n,m;    
bool isValid(int x,int y, vector<vector<char>>& grid)
{
    if(x<0 || x>n-1 || y<0 || y>m-1)
        return false;
    if(vis[x][y] || grid[x][y]=='0')
        return false;
    return true;
}
void dfs(int x,int y, vector<vector<char>>& grid)
{
    vis[x][y]=true;
    if(isValid(x-1,y,grid))
        dfs(x-1,y,grid);
    if(isValid(x,y-1,grid))
        dfs(x,y-1,grid);
    if(isValid(x,y+1,grid))
        dfs(x,y+1,grid);
    if(isValid(x+1,y,grid))
        dfs(x+1,y,grid);
}

int numIslands(vector<vector<char>>& grid)
{
    n=grid.size();
    m=grid[0].size();
    int cnt=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(!vis[i][j] && grid[i][j]!='0')
            {
                cnt++;
                dfs(i,j,grid);
            }
        }
    }
    return cnt;
}



<------ 7 ------!>

// Bipartite Check
// https://practice.geeksforgeeks.org/problems/bipartite-graph/1

// time -> O(v+e)
// space -> O(v)

bool dfs(int node,int color, vector<int>& color_arr, vector<int>arr[])
{
    color_arr[node]=color;
    for(int child : arr[node])
    {
        if(color_arr[child]==-1)
        {
            if(dfs(child,color^1,color_arr,arr)==false)
                return false;
        }
        else if(color_arr[node]==color_arr[child])
            return false;        
    }
    return true;
}

bool isBipartite(int V, vector<int> adj[])
{
    vector<int> color_arr(V,-1);
    
    for(int i=0;i<V;i++)    
    {
        if(color_arr[i]==-1)
        {
            if(!dfs(i,0,color_arr, adj))
                return false;
        }
    }
    return true;
}
