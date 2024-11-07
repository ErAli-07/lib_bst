#include <iostream>

using namespace std;

struct Node {                                      //definizione di struct
	int data;                                     //key
	int weight{ 1 };                             //dimensione
	Node* lchild;                               //puntatore sinistro
	Node* rchild;                              //puntatore destro
	Node(int val) {                           //inizializzazione dei altri membri
		data = val;
		lchild = rchild = nullptr;
	}
};

int height(Node* r) {                        //CALCOLO DELL'ALTEZZA del albero BST
	if (r == nullptr)
		return 0;
	int left = height(r->lchild);
	int right = height(r->rchild);
	return max(left, right) + 1;
}

bool Is_BST(Node* r, int min, int max) {     //CONTROLLO VALIDITA' di un albero BST
	if (r == nullptr)
		return true;

	if (r->data <= min || r->data >= max) {
		return false;
	}

	return Is_BST(r->lchild, min, r->data) && Is_BST(r->rchild, r->data, max);
}

void preOrder(Node* r) {                     //ATTRAVERSAMENTO DI UN BST di tipo preorder
	if (r == nullptr)
		return;
	cout << r->data << " ";
	preOrder(r->lchild);
	preOrder(r->rchild);
}

void inOrder(Node* r) {                      //ATTRAVERSAMENTO DI UN BST di tipo inorder
	if (r == nullptr)
		return;
	inOrder(r->lchild);
	cout << r->data << " ";
	inOrder(r->rchild);
}

void postOrder(Node* r) {                    //ATTRAVERSAMENTO DI UN BST di tipo postorder
	if (r == nullptr)
		return;
	postOrder(r->lchild);
	postOrder(r->rchild);
	cout << r->data << " ";
}

Node* create(Node* r, int k) {               //INSERIMENTO DEI NUOVI NODI in maniera ricorsiva
	if (r == nullptr) {
		return new Node(k);
	}
	if (k == r->data) {
		r->weight++;
		return r;
	}
	if (k < r->data) {
		r->lchild = create(r->lchild, k);
	}
	else {
		r->rchild = create(r->rchild, k);
	}
	return r;
}


bool check{ true };
Node* search(Node* r, int k) {                //RICERCA DEI NODI TRAMITE IL KEY in maniera ricorsiva (funziona solo per i BST)
	if (r == nullptr) {
		check = false;
		return nullptr;
	}
	else {
		if (k == r->data) {
			check = true;
			return r;
		}
		else {
			if (k < r->data) {
				search(r->lchild, k);
				if (check == true)
					return r;
				else
					return nullptr;
			}
			if (k > r->data) {
				search(r->rchild, k);
				if (check == true)
					return r;
				else
					return nullptr;
			}
			return r;
		}
	}
}

Node* remove(Node* r, int k) {                //RIMOZIONE DEI NODI in maniera ricorsiva
	Node* temp{ nullptr };
	if (r == nullptr) {
		return r;
	}

	if (k < r->data) {
		r->lchild = remove(r->lchild, k);
	}
	else if (k > r->data) {
		r->rchild = remove(r->rchild, k);
	}
	else {
		if (r->lchild == nullptr && r->rchild == nullptr) {
			delete r;
			return nullptr;
		}
		if (r->lchild == nullptr) {
			temp = r->rchild;
			delete r;
			return temp;
		}
		else if (r->rchild == nullptr) {
			temp = r->lchild;
			delete r;
			return temp;
		}
		temp = r->rchild;
		while (temp->lchild != nullptr) {
			temp = temp->lchild;
		}
		r->data = temp->data;
		r->rchild = remove(r->rchild, temp->data);
	}
	return r;
}

Node* iter_create(Node* r, int k) {             //INSERIMENTO DEI NUOVI NODI in maniera iterativa
	if (r == nullptr) {
		return new Node(k);
	}

	Node* current = r;
	Node* father = nullptr;
	while (current != nullptr) {
		if (k < current->data) {
			father = current;
			current = current->lchild;
		}
		else {
			if (k == current->data) {
				current->weight++;
				return r;
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
	return r;
}

Node* iter_search(Node* r, int k) {             //RICERCA DEI NODI TRAMITE IL KEY in maniera iterativa (funziona solo per i BST)
	Node* current{ r };
	if (r == nullptr) {
		return nullptr;
	}
	if (k < r->data) {
		while (current != nullptr) {
			if (k == current->data) {
				return current;
			}
			current = current->lchild;
		}
	}
	else if (k > r->data) {
		while (current != nullptr) {
			if (k == current->data) {
				return current;
			}
			current = current->rchild;
		}
	}
	return nullptr;
}