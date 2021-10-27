<------ 1 ------!>

// SCC(using KosaRaju’s algo)
// Strongly connected component
// https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1

// time -> O(v+e)
// space -> O(v+e)

stack<int> st;
vector<bool> vis;
void topo(int node, vector<int> adj[])
{
    vis[node]=true;
    for(int child: adj[node])
    {
        if(!vis[child])
            topo(child, adj);
    }
    st.push(node);
} 
void dfs(int node, vector<int> adj[])
{
	vis[node]=true;
	for(int child : adj[node])
	{
		if(vis[child]==false)
			dfs(child, adj);
	}
}

int SCC(int n, vector<int> adj[]) 
{
    vis.resize(n, false);

    // find topo logicsl order
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
            topo(i, adj);
    }

    // make transpose graph
    vector<int> transpose[n];
    for(int i=0;i<n;i++)
    {
    	vis[i]=false;  //for next dfs
    	for(int child:adj[i])
    		transpose[child].push_back(i);
    }

	// dfs again in revese order
	int cnt=0;    
    while(!st.empty())
    {
        int node = st.top();        
        st.pop();
        if(!vis[node])
        {
        	cnt++;
        	dfs(node, transpose);
        }
    }
    return cnt;
}



<------ 2 ------!>

// Djisktra’s Algorithm
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// time -> O((v+e)logv)
// space -> O(2*v)

#define INF 1e18
#define MAX 100005

vector<pair<int,int>> arr[MAX];
vector<int> vis(MAX,0);

int32_t main()
{
	int n,m,a,b,w;
	cin>>n>>m;
	while(m--)
	{
		cin>>a>>b>>w;
		arr[a].push_back({b,w});
		arr[b].push_back({a,w});		
	}
	
	set<pair<int,int>> st; // distance, node

	vector<int> dist(n+1,INF);

	st.insert({0,1});
	dist[1]=0;

	while(!st.empty())
	{
		int cnode = st.begin()->second;
		int cdis = st.begin()->first;
		st.erase(st.begin());

		if(vis[cnode])
			continue;
		vis[cnode]=1;


		for(pair<int,int> edge : arr[cnode])
		{
			if(cdis + edge.second < dist[edge.first])
			{
				if(dist[edge.first] != INF)
					st.erase({dist[edge.first],edge.first});				
				dist[edge.first] = cdis+edge.second;
				st.insert({dist[edge.first] , edge.first});
			}
		}
	}
	for(int i=1;i<=n;i++)	
		cout<<dist[i]<<" ";	
}


<------ 3 ------!>

// Bellman Ford Algo

1. // https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
2. // https://practice.geeksforgeeks.org/problems/negative-weight-cycle3504/1

// time -> O((n-1)*e)
// space -> O(n)

vector <int> bellman_ford(int V, vector<vector<int>> adj, int S)
{
    vector<int> dist(V,1e8);
    int m=adj.size();
    
    dist[S]=0;
    
    for(int i=0;i<V-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[adj[j][0]] + adj[j][2] < dist[adj[j][1]])
                dist[adj[j][1]] = dist[adj[j][0]]+adj[j][2]; 
        }
    }
    return dist;
}



<------ 4 ------!>

// Floyd Warshall Algorithm
// https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

void FloydWarshall()
{
	for(int k=0;k<n;k++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
			    if(matrix[i][k]!=INT_MAX && matrix[k][j]!=INT_MAX)
				    matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);				
			}
		}
	}
}



<------ 5 ------!>

// MST using Prim’s Algo 
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// time -> O((v+e)logv)
// space -> O(2*v)

int32_t main()
{
	int n,m,a,b,w;
	cin>>n>>m;
	vector<pair<int,int>> arr[n];

	while(m--)
	{
		cin>>a>>b>>w;
		arr[a].push_back({b,w});
		arr[b].push_back({a,w});		
	}

	int parent[n], key[n];
	bool mstSet[n];

	for(int i=0;i<n;i++)
		key[i]=INT_MAX, mstSet[i]=false, parent[i]=-1;

	set<pair<int,int>> st; // key, index

	key[0]=0;
	st.insert({0,0});

	while(st.size() > 0)    // only n-1 edged in MST
	{
		int cnode = st.begin()->second;				
		st.erase(st.begin());

		mstSet[cnode]=true;

		for(auto itr : arr[cnode])
		{
			int child = itr.first;
			int weight = itr.second;

			if(mstSet[child]==false && weight < key[child])
			{
				parent[child] = cnode;
				key[child] = weight;
				st.insert({key[child], child});
			}
		}
	}

	for(int i=1;i<n;i++)
		cout<<parent[i]<<" "<<i<<endl;
}  
	



<------ 6 ------!>

// MST using Kruskal’s Algo 
// https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

// time -> O(eloge)
// space -> O(n)

vector<int> parent;
vector<int> rank;

struct node{
	int u,v,wt;
	node(u,v,weight) {
		this.u=u;
		this.v=v;
		this.wt=weight;
	}
}
bool comp(node a, node b) {
	return a.wt<b.wt;
}
void unionp(int a,int b, vector<int>& rank)
{
	a=findPar(a);
	b=findPar(b);

	if(rank[a] < rank[b])
		parent[a]=b;

	else if(rank[a] > rank[b])
		parent[b]=a;

	else
	{
		parent[b]=a;
		rank[a]++;
	}
}
int findPar(int n) 
{
	if(parent[n]==n)
		return n;	
	return parent[n] = findPar(parent[n]);
}
int32_t main()
{
	int n,m,a,b,w;
	cin>>n>>m;
	vector<node> edges;

	while(m--)
	{
		cin>>a>>b>>w;
		edges.push_back(node(u,v,w));
	}
	sort(edges.begin(), edges.end(), comp);

	parent.resize(n);
	rank.resize(n,0);
	for(int i=0;i<n;i++)
		parent[i]=i;

	vector<pair<int,int>> mst;  //ans;
	for(auto itr:edges)
	{
		if(findPar(itr.u) != findPar(itr.v)) // if not in same component
		{
			mst.push_back({itr.u, itr.v});
			unionp(itr.u, itr.v, rank);
		}
	}
}



<------ 7 ------!>

// shortest path in undirected with unit weight

void bfs(int src)
{
	queue<int> q;
	q.push(src);
	vis[src]=true;
	dist[src]=0;

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
				dist[child] = dist[cur]+1;
			}
		}
	}
}




<------ 8 ------!>

// Shortest Path in Directed Acyclic Graph (DAG)

// time -> O(v+e)*2
// space -> O(v)*2

1. topo logical sort
2. distance calculate

stack<int> st;
vector<bool> vis;
void topoSort(int node, vector<pair<int,int>> adj[])
{
    vis[node]=true;
    for(int child: adj[node])
    {
        if(!vis[child])
            dfs(child, adj);
    }
    st.push(node);
}
void findDistance(int src, int n, vector<pair<int,int>> adj[])
{
	vis.resize(n);
	for(int i=0;i<n;i++)
	{
		if(!vis[i])
			topoSort(i,adj);
	}
	vector<int> dist(n, INT_MAX);
	dist[src]=0;

	while(!st.empty())
	{
		int node = st.top();
		st.pop();
		if(dist[node] != INT_MAX)
		{
			for(auto child : adj[node])
			{
				if(dist[child.first] < dist[node] + child.second)
					dist[child.first] = dist[node] + child.second;
			}
		}
	}

	for(int i=0;i<n;i++)
		(dist[i]==INT_MAX) ? cout<<"INF " : cout<<dis[i]<<" ";
}



<------ 9 ------!>

// DSU (union by rank and path compression)
(Finding parent will be same if two nodes belong to same component)

// time -> O(4*a)  ~ O(4)
// space -> O(2*v)

int parent[MAX];
int rank[MAX];

int findPar(int n)
{
	if(parent[n]==n)
		return n;

	return parent[n] = findPar(parent[n]);
}
void unionp(int a,int b)
{
	a=findPar(a);
	b=findPar(b);

	if(rank[a] < rank[b])
		parent[a]=b;

	else if(rank[a] > rank[b])
		parent[b]=a;

	else
	{
		parent[b]=a;
		rank[a]++;
	}
}



<------ 10 ------!>

// Bridegs in a Graph

// time -> O(v+e)
// space -> O(2*v)

vector<int> arr[MAX];
bool vis[MAX];
int in[MAX],low[MAX],timer;

void dfs(int node,int parent)
{
	vis[node]=true;
	in[node]=low[node]=timer;
	timer++;	
	for(int child : arr[node])
	{
		if(child==parent)
			continue;
		if(vis[child]==true)
			low[node]=min(low[node],in[child]);
		else 
		{
			dfs(child,node);			
			if(low[child]>in[node])
				cout<<node<<" "<<child<<endl;			
			low[node]=min(low[node],low[child]);
		}
	}	
}



<------ 11 ------!>

// Articulation point in graph

// time -> O(v+e)
// space -> O(v)

vector<int> arr[MAX];
bool vis[MAX];
int in[MAX],low[MAX],timer;

void dfs(int node,int parent)
{
	vis[node]=true;
	in[node]=low[node]=timer;
	timer++;
	int children=0;
	for(int child : arr[node])
	{
		if(child==parent)
			continue;
		if(vis[child]==true)
			low[node]=min(low[node],in[child]);
		else
		{
			dfs(child,node);			
			if(low[child]>=in[node] && parent!=-1)
				cout<<"Articulation Point - "<<node<<endl;
			low[node]=min(low[node],low[child]);
			children++;			
		}
	}
	if(parent==-1 && children>1)
		cout<<"Articulation Point - "<<node<<endl;
}

