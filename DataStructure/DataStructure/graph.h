#pragma once
class ArrayGraph {
public:
	int maxVertexCount;
	int currentVertexCount;
	int graphType;
	int** ppAdjEdge;
	int* pVertex;

	ArrayGraph(int maxVertexCount, int type);
	void deleteArrayGraph();
	int isEmptyAG();
	int addVertexAG(int vertexID);
	int addEdgeAG(int fromVertexID, int toVertexID);
	int addEdgewithWeightAG(int fromVertexID, int toVertexID, int weight);
	int checkVertexValid(int vertexID);
	int removeVertexAG(int vertexID);
	int removeEdgeAG(int fromVertexID, int toVertexID);
	void displayArrayGraph();

};
