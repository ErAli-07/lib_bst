#ifndef _BST_LIB_H_
#define _BST_LIB_H_

#include <iostream>

using namespace std;

class Node {                                        // Definizione di Classe
private:
	int data;                                     // Key
	int weight;                                  // Dimensione
	Node* lchild;                               // Puntatore Sinistro
	Node* rchild;                              // Puntatore Destro
public:
	Node(int val);                           // Inizializzazione dei altri membri
	void increaseWeight();                 // Aumento del peso di un Nodo
	void inOrder();                      // ATTRAVERSAMENTO DI UN BST di tipo inorder
	void preOrder();                     // ATTRAVERSAMENTO DI UN BST di tipo preorder
	void postOrder();                    // ATTRAVERSAMENTO DI UN BST di tipo postorder
	int height();                        // CALCOLO DELL'ALTEZZA del albero BST
	bool isBST(int min, int max);        // CONTROLLO VALIDITA' di un albero BST
	Node* insertR(int k);                // INSERIMENTO DEI NUOVI NODI in maniera ricorsiva
	Node* searchR(int k);                //	RICERCA DEI NODI TRAMITE IL KEY in maniera ricorsiva (funziona solo per i BST)
	Node* deleteNode(int k);             // RIMOZIONE DEI NODI in maniera
	Node* insertI(int k);                // INSERIMENTO DEI NUOVI NODI in maniera iterativa
	Node* searchI(int k);                // RICERCA DEI NODI TRAMITE IL KEY in maniera iterativa (funziona solo per i BST)
};
#endif
