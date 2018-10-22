// __author__ : Kumar shubham
// __date__   : 22-10-2018
// __desc__   : implementation of best first seach for adjacency matrix and adjacency list

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




void bfsAdjacencyMatrix(int startNode,int endNode, vector<vector<int> >& adjMatrix, vector<bool>& visited, const int noNode, vector<int>& previousNode ){
 	queue<int> nodeQueueList;

 	nodeQueueList.push(startNode); // pushing the startNode in the queue 
 	visited[startNode] = true;

 	while(!nodeQueueList.empty()){ 
 		int nodeToTravel = nodeQueueList.front();
 		nodeQueueList.pop();

 		for (int i =0;i <noNode;i++ ){
 			if (adjMatrix[nodeToTravel][i])
 			{
 				if (!visited[i]){
 					visited[i] = true;
 					nodeQueueList.push(i);
 					previousNode[i] = nodeToTravel;

 					if (endNode ==i) return;
 				}
 			}
 		}
 	}


}



void bfsAdjacencyList(int startNode, int endNode, vector<vector <int> >& adjVectorList, vector<bool>& visited, const int noNode, vector<int>& previousNode ){
	queue<int> nodeQueueList;

 	nodeQueueList.push(startNode); // pushing the startNode in the queue 
 	visited[startNode] = true;
	
	while(!nodeQueueList.empty()){
		int startNode = nodeQueueList.front();
		nodeQueueList.pop();
		tr(adjVectorList[startNode],i){
			if (!visited[*i]){
				visited[*i] = true;
				nodeQueueList.push(*i);
				previousNode[*i] = startNode;
				if (endNode==*i) return;
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
		adjMatrix[edge2][edge1] = 1;
		adjVectorList[edge1].push_back(edge2);
		
		


	}

	cout << "enter the start  and end node (-1{end node} for full traversal)" <<endl;
	int root,end;
	cin >>root >>end;

	// // traversal across all the edges in the graph
	// vector<bool> visitedList(noOfNodes,false);
	// vector<int> previousNode(noOfNodes,-1);
	// // setting the value true in the given graph Adjacency matrix 
	// bfsAdjacencyMatrix(root,end,adjMatrix, visitedList, noOfNodes,previousNode);

	// cout << visitedList.size()<<endl;

	// // cout printing the path of all the traversed element in the queue 
	//  for (int i =0;i<previousNode.size();i++){
	//  	cout<<"element : "<< i<<" previous:  "<< previousNode[i]<<endl;
	//  }



	 //################################################## code for adjacency list based analysis###########################


	

	vector<bool> visitedList(noOfNodes,false);
	vector<int> previousNode(noOfNodes,-1);
	// setting the value true in the given graph Adjacency matrix 
	bfsAdjacencyList(root,end,adjVectorList, visitedList, noOfNodes,previousNode);

	cout << visitedList.size()<<endl;

	// cout printing the path of all the traversed element in the queue 
	 for (int i =0;i<previousNode.size();i++){
	 	cout<<"element : "<< i<<" previous:  "<< previousNode[i]<<endl;
	 }





	 //#####################################################################################################################



}
