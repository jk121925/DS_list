#pragma once
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
	int graphType;
	LinkedList** ppAdjEdge;
	int* pVertex;
};