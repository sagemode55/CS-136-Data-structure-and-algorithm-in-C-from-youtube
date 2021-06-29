
//  Created by Sitthiphol Yuwanaboon 
//  CS 136 Lab 7 Graph
//
// 
/****Intructor feedback DO NOT DELETE:

****/
#include "QueType.h"
template<class VertexType>
// Assumption: VertexType is a type for which the "=", 
// "==", and "<<" operators are defined
class GraphType
{
public:
  GraphType();                  // Default of 50 vertices
  GraphType(int maxV);          // maxV <= 50
  ~GraphType();
//  void MakeEmpty();
//  bool IsEmpty() const;
//  bool IsFull() const;
  void AddVertex(VertexType);
  void AddEdge(VertexType, VertexType, int);
  int WeightIs(VertexType, VertexType);
  void GetToVertices(VertexType, QueType<VertexType>&);
  bool EdgeExists(VertexType, VertexType);
  void DeleteEdge(VertexType, VertexType);
//  void ClearMarks();
//  void MarkVertex(VertexType);
//  bool IsMarked(VertexType);
private:
  int numVertices;
  int maxVertices;
  VertexType* vertices;
  int edges[50][50];
  bool* marks;	// marks[i] is mark for vertices[i].
};
