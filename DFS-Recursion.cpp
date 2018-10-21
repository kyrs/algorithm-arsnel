// code for doing recursion for both adjacency matrix and list
/*

__author__ : Kumar shubham 
__date __  :  20 10 2018 

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





void dfsAdjacencyMatrix(int startNode,vector<vector<int> >& adjMatrix, vector<bool>& visited, const int noNode, vector<int>& previousNode ){

	if (visited[startNode]) return;

	else {
		visited[startNode] = true;
		for (int i =0 ; i<noNode; i++){
			if (adjMatrix[startNode][i] && !visited[i]){
				previousNode[i] = startNode;
				dfsAdjacencyMatrix(i,adjMatrix,visited,noNode,previousNode);

			}
		}
	}
}



void dfsAdjacencyList(int startNode,vector<vector <int> >& adjVectorList, vector<bool>& visited, const int noNode, vector<int>& previousNode ){

	if (visited[startNode]) return;

	else {
		visited[startNode] = true;
		tr(adjVectorList[startNode],i){
			if (!visited[*i]){
				previousNode[*i] = startNode;
				dfsAdjacencyList(*i,adjVectorList,visited,noNode,previousNode);

			}
		}
	}
}

int main(){

	int noOfNodes;
	cin >> noOfNodes; // input the no of nodes in a graph

	int noEdges; 

	cin >> noEdges;

	// graph definition based on adjacency matrix.
	vector<vector<int> > adjMatrix(noOfNodes, vector <int >(noOfNodes, 0) );

	// adjacency List 
	vector<vector <int> > adjVectorList(noOfNodes);


	while(noEdges--){
		int edge1, edge2;
		cin >>edge1>>edge2;

		// adding nodes in the graph 
		adjMatrix[edge1][edge2] = 1;
		adjMatrix[edge2][edge1] = 1;
		adjVectorList[edge1].push_back(edge2);
		
		


	}

	// int root = 0;

	// // traversal across all the edges in the graph
	// vector<bool> visitedList(noOfNodes,false);
	// vector<int> previousNode(noOfNodes,-1);
	// // setting the value true in the given graph Adjacency matrix 
	// dfsAdjacencyMatrix(root,adjMatrix, visitedList, noOfNodes,previousNode);

	// cout << visitedList.size()<<endl;

	// // cout printing the path of all the traversed element in the queue 
	//  for (int i =0;i<previousNode.size();i++){
	//  	cout<<"element : "<< i<<" previous:  "<< previousNode[i]<<endl;
	//  }



	 //################################################## code for adjacency list based analysis###########################


	// traversal across all the edges in the graph
	int root = 0;

	vector<bool> visitedList(noOfNodes,false);
	vector<int> previousNode(noOfNodes,-1);
	// setting the value true in the given graph Adjacency matrix 
	dfsAdjacencyList(root,adjVectorList, visitedList, noOfNodes,previousNode);

	cout << visitedList.size()<<endl;

	// cout printing the path of all the traversed element in the queue 
	 for (int i =0;i<previousNode.size();i++){
	 	cout<<"element : "<< i<<" previous:  "<< previousNode[i]<<endl;
	 }





	 //#####################################################################################################################



}
