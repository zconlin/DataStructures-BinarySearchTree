#include "Node.h" 

	int Node::getData() const 
	{
		return(data);
	}

	NodeInterface * Node::getLeftChild() const 
	{
		return(leftChild);
	}
	Node *& Node::getLeft()  
	{
		return(leftChild);
	}

	NodeInterface * Node::getRightChild() const
	{
		return(rightChild);
	}
	Node *& Node::getRight() 
	{
		return(rightChild);
	}

	void Node::setLeftChild(Node *ptr)
	{
		leftChild = ptr;
	}
void Node::setRightChild(Node *ptr)
	{
		rightChild = ptr;
	}
