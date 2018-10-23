// __author__ : Kumar shubaham 
// __date__   : 23 10 2018

/*
	__desc__ : dag shortest and longest path finding 
	__complexity__ : O(V+E)
	
	 this  is the fastest shortest and longest path finding algorithm . second fastest one is Dijkstra's 
	 but that does not work when  edge weight si negetive. This algorithm will work with even the negative weighted edges. 

	 __algo__ : use toplogical sorting algorithm to find the toplogical ordering  and then use that to find the 
	 shortest or longest pat

	 __note__ :THIS ALGORITHM ONLY WORKS IN DAG AND SINCE We ARE USING TOPOLOGICAL ORDERING THERE WON"T BE ANY PATH IN REVERSE DIRECTION
	 			OF THE TOPOLOGICAL ORDER.
	
	finding the longest path in a graph is an NP-HARD problem. but in a DAG it can be done in O(V+E)
	trick :
		 step 1: multiply all edges with -1 in graph .
		 step -2 : run algorithm of shortest path finding.
		 step -3 : once the shortest path is found multipy the output with -1 again   -23*-1 = 23


*/

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
					if (adjMatrix[topElm][i]!=0){
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



void shortestPathInDag(vector<vector<int> >& adjMatrix, vector<long >& weightedShortestVector,int noOfNodes, int startNode){
	// defining the matrix for the calculation of shortest path in dag

	vector<int> topologicalOrderingList;
	
	topOrderAdjMatrix(adjMatrix,noOfNodes,topologicalOrderingList);

	
	// reversing the order of the toplogical order 
	reverse(all(topologicalOrderingList));

	// setting startNode  
	weightedShortestVector[startNode] = 0;

	vector<int>:: iterator it;

	it = find(all(topologicalOrderingList), startNode);

	while(it != topologicalOrderingList.end()){
		
		for (int i=0;i<noOfNodes;i++){
			if (adjMatrix[*it][i]!=0){
				long newScore = weightedShortestVector[*it]+adjMatrix[*it][i];
				weightedShortestVector[i] = min(weightedShortestVector[i],newScore);
			}
		}
		it++;	
	
	}



}

int main(){

	int noOfNodes;
	cout << "enter no of nodes : "<<endl;

	cin >> noOfNodes; // input the no of nodes in a graph

	int noEdges; 

	cout << "enter no of edges : "<<endl;
	cin >> noEdges;

	cout << "enter the edge connection and score : "<<endl;

	// graph definition based on adjacency matrix.
	vector<vector<int> > adjMatrix(noOfNodes, vector <int >(noOfNodes, 0) );

	// adjacency List 
	vector<vector <int> > adjVectorList(noOfNodes);


	while(noEdges--){
		int edge1, edge2,score;
		cin >>edge1>>edge2>>score;

		// adding nodes in the graph 
		adjMatrix[edge1][edge2] = score;
		// adjVectorList[edge1].push_back(edge2);
		
		


	}

	int startNode;
	 cout << "enter start node "<<endl;
	cin>> startNode;


	// traversal across all the edges in the graph
	vector<long>  weightedShortestVector(noOfNodes,1e6);
	// setting the value true in the given graph Adjacency matrix 
	shortestPathInDag(adjMatrix,weightedShortestVector,noOfNodes, startNode);

	
	// cout printing the path of all the traversed element in the queue 
	 for (int i =0;i<weightedShortestVector.size();i++){
	 	if (weightedShortestVector[i] !=1e6)
	 	cout<<"i : "<<i<<" value : " <<weightedShortestVector[i] << endl;
	 	else
	 		cout<<"i : "<<i<<" value : " << "NULL" << endl;
	 }


}