#include "graph.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ArrayGraph::ArrayGraph(int maxVertexCount, int type) {
	int i = 0, j = 0;
	if (maxVertexCount > 0) {
		this->graphType = type; //0 = nodirection 1=direction
		this->maxVertexCount = maxVertexCount;
	}
	else {
		printf("최대 노드의 개수는 0보다 커야합니다.");
	}
	
	this->pVertex = new int[maxVertexCount];
	this->ppAdjEdge = new int*[maxVertexCount];

	for (i = 0; i < maxVertexCount; i++) {
		this->ppAdjEdge[i] = new int[maxVertexCount];
		if (this->ppAdjEdge[i] == nullptr) {
			printf("메모리 할당 오류\n");
			for (j = 0; j < i - 1; j++) {
				if (this->ppAdjEdge[j] != nullptr) delete this->ppAdjEdge[j];
			}
			if (this->ppAdjEdge != nullptr) delete this->ppAdjEdge;
			if (this->pVertex != nullptr) delete this->pVertex;
		}
	}
		memset(this->pVertex, 0, sizeof(int) * maxVertexCount);
		for (i = 0; i < maxVertexCount; i++) {
			memset(this->ppAdjEdge[i], 0, sizeof(int) * maxVertexCount);
		}

	

}

int ArrayGraph::addVertexAG(int vertexID) {
	int ret = true;

	if (vertexID < this->maxVertexCount) {
		if (this->pVertex[vertexID] == 0) {
			this->pVertex[vertexID] = 1;
			this->currentVertexCount++;
		}
	}
	else {
		printf("최대 노드개수 초과\n");
		ret = false;
	}
	return ret;
}

int ArrayGraph::addEdgewithWeightAG(int fromVertexID, int toVertexID, int weight) {
	int ret = true;
	if (this->checkVertexValid(fromVertexID) != true) {
		ret = false;
		return ret;
	}

	if (checkVertexValid(toVertexID) != true) {
		ret = false;
		return ret;
	}
	this->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (this->graphType == 0) {
		this->ppAdjEdge[toVertexID][fromVertexID] = weight;
	}
	return ret;
}

int ArrayGraph::checkVertexValid(int vertexID) {
	int ret = true;

	if (vertexID >= this->maxVertexCount || this->pVertex[vertexID] == 0) {
		printf("노드정보 오류");
		ret = false;
	}
	return ret;

}

int ArrayGraph::addEdgeAG(int fromVertexID, int toVertexID) {
	return this->addEdgewithWeightAG(fromVertexID, toVertexID, 1);
}

int ArrayGraph::removeEdgeAG(int fromVertexID, int toVertexID) {
	int ret = true;

	if (this->checkVertexValid(fromVertexID) != true) {
		ret = false;
		return ret;
	}
	if (this->checkVertexValid(toVertexID) != true) {
		ret = false;
		return ret;
	}
	this->ppAdjEdge[fromVertexID][toVertexID] = 0;
	if (this->graphType == 0) {
		this->ppAdjEdge[toVertexID][fromVertexID] = 0;
	}
	return ret;
}

int ArrayGraph::removeVertexAG(int vertexID) {
	int ret = true;
	int i = 0;
	if (this->checkVertexValid(vertexID) != true) {
		ret = false;
		return ret;
	}
	for (i = 0; i < this->maxVertexCount; i++) {
		this->removeEdgeAG(vertexID, i);
		this->removeEdgeAG(i, vertexID);
	}
	this->pVertex[vertexID] = 0;
	return ret;
}

void ArrayGraph::displayArrayGraph() {
	for (int i = 0; i < this->maxVertexCount; i++)
	{
		for (int j = 0; j < this->maxVertexCount; j++) {
			printf("%d ", this->ppAdjEdge[i][j]);
		}
		printf("\n");
	}
}


int main() {
	int i = 0;
	ArrayGraph temp(6,0);
	for (i = 0; i < 6; i++) {
		temp.addVertexAG(i);
	}
	temp.addEdgeAG(0, 1);

	temp.addEdgeAG(0, 2);
	temp.addEdgeAG(1, 2);
	temp.addEdgeAG(2, 3);
	temp.addEdgeAG(3, 4);
	temp.addEdgeAG(3, 5);
	temp.addEdgeAG(4, 5);
	temp.displayArrayGraph();
	
}
