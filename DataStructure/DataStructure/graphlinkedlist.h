#pragma once
#include <vector>
class GraphVertex
{
public:
	int vertexID;
	int weight;
};

class GraphListNode {
public:
	GraphVertex data;
	GraphListNode* pLink;
};

class LinkedGraph {
public:
	int maxVertexCount;
	int currentVertexCount;
	int currentEdgeCount;
	int graphType;
	//vector<int**> ppAdjEdge;
	int* pVertex;
	LinkedGraph(int maxVertexCount);



};