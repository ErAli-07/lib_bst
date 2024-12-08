#include <iostream>
#include "bst_lib.h"

using namespace std;

Node::Node(int val)
	:data{ val }, lchild{ nullptr }, rchild{ nullptr }, weight{ 1 } {};

Node* Node::getLeft() {
	return lchild;
}

Node* Node::getRight(){
	return lchild;
}

void Node::increaseWeight() {
	weight++;
}

void Node::preOrder() {
	if (this == nullptr)
		return;
	cout << this->data << " ";
	this->lchild->preOrder();
	this->rchild->preOrder();
}

void Node::inOrder() {
	if (this == nullptr)
		return;
	this->lchild->inOrder();
	cout << this->data << " ";
	this->rchild->inOrder();
}

void Node::postOrder() {
	if (this == nullptr)
		return;
	this->lchild->postOrder();
	this->rchild->postOrder();
	cout << this->data << " ";
}

int Node::height() {
	if (this == nullptr)
		return 0;
	int left = this->lchild->height();
	int right = this->rchild->height();
	return max(left, right) + 1;
}

bool Node::isBST(int min, int max) {
	if (this == nullptr)
		return true;

	if (this->data <= min || this->data >= max) {
		return false;
	}

	return this->lchild->isBST(min, this->data) && this->rchild->isBST(this->data, max);
}

Node* Node::insertR(int k) {
	if (this == nullptr) {
		return new Node(k);
	}
	if (k == this->data) {
		increaseWeight();
		return this;
	}
	if (k < this->data) {
		this->lchild = this->lchild->insertR(k);
	}
	else {
		this->rchild = this->rchild->insertR(k);
	}
	return this;
}

bool check{ true };
Node* Node::searchR(int k) {
	if (this == nullptr) {
		check = false;
		return nullptr;
	}
	else {
		if (k == this->data) {
			check = true;
			return this;
		}
		else {
			if (k < this->data) {
				this->lchild->searchR(k);
				if (check == true)
					return this;
				else
					return nullptr;
			}
			if (k > this->data) {
				this->rchild->searchR(k);
				if (check == true)
					return this;
				else
					return nullptr;
			}
			return this;
		}
	}
}

Node* Node::deleteNode(int k) {
	Node* temp{ nullptr };
	if (this == nullptr) {
		return this;
	}

	if (k < this->data) {
		this->lchild = this->lchild->deleteNode(k);
	}
	else if (k > this->data) {
		this->rchild = this->rchild->deleteNode(k);
	}
	else {
		if (this->lchild == nullptr && this->rchild == nullptr) {
			delete this;
			return nullptr;
		}
		if (this->lchild == nullptr) {
			temp = this->rchild;
			delete this;
			return temp;
		}
		else if (this->rchild == nullptr) {
			temp = this->lchild;
			delete this;
			return temp;
		}
		temp = this->rchild;
		while (temp->lchild != nullptr) {
			temp = temp->lchild;
		}
		this->data = temp->data;
		this->rchild = this->rchild->deleteNode(temp->data);
	}
	return this;
}


Node* Node::insertI(int k) {
	if (this == nullptr) {
		return new Node(k);
	}

	Node* current = this;
	Node* father = nullptr;
	while (current != nullptr) {
		if (k < current->data) {
			father = current;
			current = current->lchild;
		}
		else {
			if (k == current->data) {
				current->weight++;
				return this;
			}
			father = current;
			current = current->rchild;
		}
	}

	if (k < father->data) {
		father->lchild = new Node(k);
	}
	if (k > father->data) {
		father->rchild = new Node(k);
	}
	return this;
}

Node* Node::searchI(int k) {
		Node* current{ this };
	if (this == nullptr) {
		return nullptr;
	}
	if (k < this->data) {
		while (current != nullptr) {
			if (k == current->data) {
				return current;
			}
			current = current->lchild;
		}
	}
	else if (k > this->data) {
		while (current != nullptr) {
			if (k == current->data) {
				return current;
			}
			current = current->rchild;
		}
	}
	return nullptr;
}

ostream& operator<<(ostream& os, Node* r) {
	if (r == nullptr) {
		os << "Nodo Nullo" << endl;
		return os;
	}
	os << "Key - Nodo Corrente: " << r->data << endl;
	os << "Peso - Nodo Corrente: " << r->weight << endl;

	if (r->lchild == nullptr) {
		os << "Nodo Sinistro Nullo" << endl;
	}
	else {
		os << "Key - Nodo Sinistro: " << r->lchild->data << endl;
	}

	if (r->rchild == nullptr) {
		os << "Nodo Destro Nullo" << endl;
	}
	else {
		os << "Key - Nodo Destro: " << r->rchild->data << endl;
	}
	return os;
}

istream& operator>>(istream& is, Node* r) {
	if (r == nullptr) {
		cout << "Nodo Nullo" << endl;
		return is;
	}
	is >> r->data;
	return is;
}
