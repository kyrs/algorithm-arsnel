// __author__ : Kumar shubham
// __date__   : 22-10-2018
// __desc__   : topological sort is used  to find the dependency list in a graph (e.g. courses dependencyin college, program sub routine dependency)

/*
Defn : A topological ordering is an ordering of nodes in a directed graph. where for each edge from node A to node B
node A appear before node B

Note: It is not unique e.g. there could be different way of enrolling in a course

 TOPOLOGICAL ORDER IS ONLY VALID FOR DAG(DIRECTED ACYCLIC GRAPH). BECAUSE FOR A GRAPH WITH CYCLE THERE IS NO START POINT TO BEGIN WITH. 
 A graph being DAG or not can be identified using  Tarjan's strongly  connected component algorithm. 

 it can be used with tree as tree doesn't have a cycle 


*/
// complexity O(V+E)

#include <bits/stdc++.h>
using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

void topOrderAdjMatrix(vector<vector<int> >& adjMatrix,int noOfNodes,vector<int>& topologicalOrderingList){
	// implementing topological ordering with dfs 
	bool visitedNode[noOfNodes] = {false};

	for (int i =0;i<noOfNodes;i++){
		// picking non visitedList
		if (!visitedNode[i]){
			stack<int> nodeTracker;
			nodeTracker.push(i);
			visitedNode[i] = true;
			while(!nodeTracker.empty()){
				int topElm = nodeTracker.top();
				bool foundChild =false;
				for (int i = 0; i<noOfNodes;i++){
					if (adjMatrix[topElm][i]){
						// identifying the connected component
						if (!visitedNode[i]){
							visitedNode[i] = true;
							nodeTracker.push(i);
							foundChild = true;
						}

					}
				}
				if (!foundChild){
					topologicalOrderingList.push_back(nodeTracker.top());
					nodeTracker.pop();

				}

			}


		}
	}
}


int main(){

	int noOfNodes;
	cout << "enter no of nodes : "<<endl;

	cin >> noOfNodes; // input the no of nodes in a graph

	int noEdges; 

	cout << "enter no of edges : "<<endl;
	cin >> noEdges;

	cout << "enter the edge connection : "<<endl;

	// graph definition based on adjacency matrix.
	vector<vector<int> > adjMatrix(noOfNodes, vector <int >(noOfNodes, 0) );

	// adjacency List 
	vector<vector <int> > adjVectorList(noOfNodes);


	while(noEdges--){
		int edge1, edge2;
		cin >>edge1>>edge2;

		// adding nodes in the graph 
		adjMatrix[edge1][edge2] = 1;
		adjVectorList[edge1].push_back(edge2);
		
		


	}

	// traversal across all the edges in the graph
	vector<bool> visitedList(noOfNodes,false);
	vector<int> topologicalOrderingList;
	// setting the value true in the given graph Adjacency matrix 
	topOrderAdjMatrix(adjMatrix,noOfNodes,topologicalOrderingList);

	
	// cout printing the path of all the traversed element in the queue 
	 for (int i =0;i<topologicalOrderingList.size();i++){
	 	cout<<topologicalOrderingList[i] << endl;
	 }


}