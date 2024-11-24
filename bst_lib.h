#include <iostream>

using namespace std;

class Node {                                        //definizione di classe
private:
	int data;                                     //key
	int weight;                                  //dimensione
	Node* lchild;                               //puntatore sinistro
	Node* rchild;                              //puntatore destro
public:
	Node(int val);                           //inizializzazione dei altri membri
	int getData();
	void increaseWeight();
	Node* setLeft();
	Node* setRight();
	Node* insertR(int k);                 // INSERIMENTO DEI NUOVI NODI in maniera ricorsiva
	void inOrder();                      // ATTRAVERSAMENTO DI UN BST di tipo inorder
};
