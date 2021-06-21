
//  Created by Sitthiphol Yuwanaboon 
//  CS 136 Lab 7 Graph
//
// 



#include "GraphType.h"
#include <iostream>
using namespace std;

// function definition of EdgeExists
// bool EdgeExists(VertexType, VertexType);

// function definition of DeleteEdge
// void DeleteEdge(VertexType, VertexType);

template<class VertexType>
GraphType<VertexType>::GraphType()
// Post: Arrays of size 50 are dynamically allocated for  
//       marks and vertices.  numVertices is set to 0; 
//       maxVertices is set to 50.
{
  numVertices = 0;
  maxVertices = 50;
  vertices = new VertexType[50];
  marks = new bool[50];
}

template<class VertexType>
GraphType<VertexType>::GraphType(int maxV)
// Post: Arrays of size maxV are dynamically allocated for  
//       marks and vertices.  
//       numVertices is set to 0; maxVertices is set to maxV.
{
  numVertices = 0;
  maxVertices = maxV;
  vertices = new VertexType[maxV];
  marks = new bool[maxV];
}

template<class VertexType>
// Post: arrays for vertices and marks have been deallocated.
GraphType<VertexType>::~GraphType()
{
  delete [] vertices;
  delete [] marks;
}
const int NULL_EDGE = 0;

template<class VertexType>
void GraphType<VertexType>::AddVertex(VertexType vertex)
// Post: vertex has been stored in vertices.
//       Corresponding row and column of edges has been set 
//       to NULL_EDGE.
//       numVertices has been incremented.
{
  vertices[numVertices] = vertex;

  for (int index = 0; index < numVertices; index++)
  {
    edges[numVertices][index] = NULL_EDGE;
    edges[index][numVertices] = NULL_EDGE;
  }
  numVertices++;
}
template<class VertexType>
int IndexIs(VertexType* vertices, VertexType vertex)
// Post: Returns the index of vertex in vertices.
{
  int index = 0;

  while (!(vertex == vertices[index]))
    index++;  
  return index;
}       

template<class VertexType>
void GraphType<VertexType>::AddEdge(VertexType fromVertex,
     VertexType toVertex, int weight)
// Post: Edge (fromVertex, toVertex) is stored in edges.
{
  int row;
  int col;

  row = IndexIs(vertices, fromVertex);
  col = IndexIs(vertices, toVertex);
  edges[row][col] = weight;
}

template<class VertexType>
int GraphType<VertexType>::WeightIs
     (VertexType fromVertex, VertexType toVertex)
// Post: Returns the weight associated with the edge 
//       (fromVertex, toVertex).
{
  int row;
  int col;

  row = IndexIs(vertices, fromVertex);
  col = IndexIs(vertices, toVertex);
  return edges[row][col];
}

template<class VertexType>
void GraphType<VertexType>::GetToVertices(VertexType vertex, 
     QueType<VertexType>& adjVertices)
// Post: 
{
  int fromIndex;
  int toIndex;

  fromIndex = IndexIs(vertices, vertex);
  for (toIndex = 0; toIndex < numVertices; toIndex++)
    if (edges[fromIndex][toIndex] != NULL_EDGE)
      adjVertices.Enqueue(vertices[toIndex]);
}     

template<class VertexType>
bool GraphType<VertexType>::EdgeExists(VertexType fromVertex, VertexType toVertex)
// POST: checks if an edge exists between 2 vertices and return a boolean value
{
  if(WeightIs(fromVertex, toVertex) != 0)
	return true;
  return false;
}

template<class VertexType>
void GraphType<VertexType>::DeleteEdge(VertexType fromVertex, VertexType toVertex)
// POST: removes an edge between 2 vertices
{
  AddEdge(fromVertex, toVertex, 0);
}

int main(){

	GraphType<int> g(4);
	
	g.AddVertex(1);
	g.AddVertex(2);
	g.AddVertex(3);
	g.AddVertex(4);
	
	g.AddEdge(1, 2, 5);
	g.AddEdge(2, 3, 7);
	g.AddEdge(3, 4, 8);
	
	cout<<g.WeightIs(1, 2)<<endl;
	cout<<g.WeightIs(2, 3)<<endl;
	cout<<g.WeightIs(3, 1)<<endl;
	
	if(g.EdgeExists(1, 4)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	g.DeleteEdge(1, 2);
	
	if(g.EdgeExists(1, 2)) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	
	return 0;
}
