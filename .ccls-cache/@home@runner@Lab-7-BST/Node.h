#pragma once
#include "NodeInterface.h"
using namespace std;

class Node : public NodeInterface {
	friend class BST;
public:
	Node(int value) {
		data = value; 
		leftChild = NULL; 
		rightChild = NULL;
		}
	~Node() {}

	int getData() const;
	
	NodeInterface * getLeftChild() const;
	NodeInterface * getRightChild() const;
	Node *&getRight();
	Node *&getLeft();
	void setLeftChild(Node *ptr);
	void setRightChild(Node *ptr);

protected:
	Node *leftChild;
	Node *rightChild;
	int data;

};