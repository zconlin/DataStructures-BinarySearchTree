#include "BST.h"

NodeInterface * BST::getRootNode() const
{
	//cout << "getRootNode" << endl; 
	return this->root;
}

bool BST::add(int data)
{
	return add(data, this->root);
}
bool BST::add(int data, Node *&node) {
	if (node == NULL) {
		node = new Node(data);
		return true;
	}
	else if (node->getData() == data) {
		return false;
	}
	else if (data < node->getData()) {
		return add(data, node->getLeft());
	}
	else {
		return add(data, node->getRight());
	}
}
bool BST::remove(int data)
{
	//cout << "remove" <<endl;
	return remove(data, this->root);
}

bool BST::remove(int data, Node *&node) {
	if (node == NULL) {
		return false;
	}
	else if (node->getData() == data) {
		if (node->leftChild == NULL && node->rightChild == NULL) {
			delete node;
			node = NULL;
			return true;
		}
		if ((node->leftChild !=NULL) && (node->rightChild != NULL)) {
			int newData = replace(node->leftChild);
			node->data = newData;
			return true;
		}
		if ((node->leftChild !=NULL) && (node->rightChild == NULL)) {
			Node* temp = node;
			node = node->leftChild;
			delete temp;
			temp = NULL;
			return true;
		}
		if (node->rightChild != NULL && node->leftChild == NULL) {
			Node* temp = node;
			node = node->rightChild;
			delete temp;
			temp = NULL;
			return true;
		}
		return true;
	}
	else if (data < node->getData()) {
		return remove(data, node->getLeft());
	}
	else {
		return remove(data, node->getRight());
	}
	cout << "remove" << endl;
	return true;
}

void BST::clear()
{
	recursiveClear(this->root);
	this->root = NULL;
	// cout << "clear" << endl;
}

int BST::replace(Node *&node) {
	if (node->rightChild != NULL) {
		return replace(node->rightChild);
	}
	int temp = node->getData();
	remove(node->getData(), node);
	return temp;
}
	
void BST::recursiveClear(Node *node)
{
	if(node != NULL) {
		recursiveClear(node->getLeft());
		recursiveClear(node->getRight());
		delete node;
	}
}