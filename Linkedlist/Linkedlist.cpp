#include <iostream>
#include <string.h>
using namespace std;

class Node 
{
public:
	int noMhs;
	char nama[20];
	Node* next;
};

class List
{
	Node* START;
public:
	List();
	void addNode();
	bool Search(int nim, Node** current, Node** previous);
	bool listEmpty();
	bool delNode(int element);
	void traverse();
};

List::List()
{
	START = NULL;
}
void List::addNode()/*menambah sebuah node kedalam list*/
{
	int nim;
	char nm[20];
	cout << "\nMasukan Nomor Mahasiswa:";
	cin >> nim;
	cout << "\nMasukan nama: ";
	cin >> nm;

	Node* nodeBaru = new Node;
	nodeBaru->noMhs = nim;
	strcpy_s(nodeBaru->nama, nm);
	
	if (START == NULL || nim <= START->noMhs)
	{
		if ((START != NULL) && (nim == START->noMhs)) 
		{
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		nodeBaru->next = START;
		START = nodeBaru;
		return;
	}
	Node* previous, * current;

	current = START;
	previous = START;


	while ((current != NULL) && (nim >= current->noMhs))
	{
		if (nim == current->noMhs)
		{
			cout << "\nDuplikasi noMhs tidak diijinkan\n";
			return;
		}
		previous = current;
		current = current->next;

	}
	/*jika loop diatas dieksekusi, previous dan current akan menempati posisi dimana */
	nodeBaru->next = current;
	previous->next = nodeBaru;
}

bool List::listEmpty()
{
	if (START == NULL)
		return true;
	else
		return false;
}
bool List::delNode(int nim)/*menghapus node dari dalam list*/
{
	Node* current, * previous;
	if (Search(nim, &previous,&current) == false)
		return false;
	previous->next = current->next;
	if (current == START)
		START = START->next;

	delete current;
	return true;
}

/*check apakah node yang dimaksud ada didalam list atau tidak*/
bool List::Search(int nim, Node** previous, Node** current)
{
	*previous = START;
	*current = START;
	while ((*current != NULL) && (nim != (*current)->noMhs))
	{
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

void List::traverse()/*mengunjungi dan membaca data dalam  list*/
{
	if (listEmpty())
		cout << "\nList kosong\n";
	else
	{
		cout << endl << "Data didalam list adalah:" << endl;
		Node* currentNode;
		for (currentNode = START; currentNode != NULL; currentNode = currentNode->next)
		{
			cout << currentNode->noMhs << "  " << currentNode->nama << "/n";
		}
		cout << endl;
	}
}

