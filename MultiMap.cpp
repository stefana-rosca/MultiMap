#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>
//#include <chrono>

using namespace std;


MultiMap::MultiMap() {
	//TODO - Implementation
	this->head = NULL;
	this->tail = NULL;
	lungime = 0;

}


void MultiMap::add(TKey c, TValue v) {
	//TODO - Implementation
	//daca map este gol
	//verificam daca cheia exista deja in map
	MultiMapNode* node = head;
	bool cheie_exista = false;
	while (node != NULL)
	{
		if (node->cheie == c)
		{
			cheie_exista = true;
			break;
		}
		else
		{
			node = node->next;
		}
	}
	//daca cheia nu exista o adaugam la finalul map ului

	if (cheie_exista == false)
	{//daca map ul este gol
		if (head == NULL)
		{
			MultiMapNode* newNode = new MultiMapNode();
			newNode->next = NULL;
			newNode->cheie = c;
			//un nou ValuesNode pt lista de valori
			ValuesNode* newValue = new ValuesNode();
			newNode->first = newValue;
			newNode->last = newValue;
			newValue->next = NULL;
			newValue->prev = NULL;
			newNode->prev = NULL;
			newValue->val = v;
			head = newNode;
			tail = newNode;
			lungime++;
		}
		//daca mai are alte noduri
		else
		{
			MultiMapNode* newNode = new MultiMapNode();
			newNode->cheie = c;
			ValuesNode* newValue = new ValuesNode();
			newNode->first = newValue;
			newNode->last = newValue;
			newValue->val = v;
			newNode->prev = tail;
			tail->next = newNode;
			newValue->next = NULL;
			newValue->prev = NULL;
			newNode->next = NULL;
			tail = newNode;
			lungime++;

		}
	}
	//daca cheia exista in map deja
	else if (cheie_exista == true)
	{
		ValuesNode* newValue = new ValuesNode();
		newValue->prev = node->last;
		node->last->next = newValue;
		newValue->val = v;
		newValue->next = NULL;
		node->last = newValue;
		lungime++;
	}
}


bool MultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
	MultiMapNode* node = head;
	bool found = false;
	while (node != NULL)
	{ //merge si daca head==NULL
		if (node->cheie == c)
		{
			found = true;
			break;
		}
		else
		{
			node = node->next;
		}
	}
	// daca nu am gasit cheia return false
	if (!found)
	{
		return false;
	}
	// altfel cautam valoarea in multimapnode aux
	ValuesNode* vnode = node->first;
	if (vnode->next == NULL)
	{ // avem doar 1 valoare
		if (vnode->val == v)
		{
			//lungime--;
			// atunci stergem si nodul cu cheia
			//pt asta trebuie sa gasim un prev node
			// daca avem doar un multimapnod
			if (head == node)
			{

				delete vnode;
				head = head->next; //poate fi si null
					// testam cand adaugam noul TElem
				//node->next = NULL;
				delete node; // stergem prev head
				lungime--;
				return true;
			}
			MultiMapNode* prev = head;
			while (prev->next != node)
			{
				prev = prev->next;
			}
			prev->next = node->next;
			delete vnode;
			delete node;
			lungime--;
			return true;
		}
		else
		{
			return false;
		}
	}
	//altfel avem mai multe valori
	// daca e prima
	if (vnode->val == v)
	{
		node->first = vnode->next;
		vnode->next->prev = NULL;
		delete vnode;
		lungime--;
		return true;
	}
	ValuesNode* prev = vnode; // daca nu e primul ne trebuie iar prev node sa stergem
	vnode = vnode->next;
	while (vnode != NULL)
	{
		if (vnode->val == v)
		{
			// il stergem
			prev->next = vnode->next;
			delete vnode;
			lungime--;
			return true;
		}
		else
		{
			prev = vnode;
			vnode = vnode->next;
		}
	}
	//daca nu am gasit valoarea
	return false;
}


vector<TValue> MultiMap::search(TKey c) const {
	//TODO - Implementation
	vector<TValue> v = vector<TValue>();
	MultiMapNode* node = head;
	bool cheie_gasita = false;
	while (node != NULL)
	{
		if (node->cheie == c)
		{
			cheie_gasita = true;
			break;
		}
		else
		{
			node = node->next;
		}
	}
	if (cheie_gasita == true)
	{
		ValuesNode* newNode_value = node->first;
		while (newNode_value != NULL)
		{
			v.push_back(newNode_value->val);
			newNode_value = newNode_value->next;
		}
		return v;
	}
	if (isEmpty())
		return {};
	//return vector<TValue>();
}


int MultiMap::size() const {
	//TODO - Implementation
	/*if(isEmpty())
		return 0;
	int lungime = 0;
	ValuesNode* current_value;
	MultiMapNode* current_node;
	for (current_node = head; current_node != NULL; current_node++)
	{
		for (current_value = current_node->first; current_value != NULL; current_value++)
		{
			lungime++;
		}
	}
	return lungime;*/
	//current_node = head;
	//while (current_node != NULL)
	//{
		//current_value = current_node->first;
		//while (current_value != NULL)
		//{
			//lungime++;
			//current_value = current_value->next;
		//}
		//current_node = current_node->next;
	//}
	return lungime;
}


bool MultiMap::isEmpty() const {
	//TODO - Implementation
	if (head == NULL || tail == NULL)
		return true;
	else
		return false;
}

MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}


MultiMap::~MultiMap() {
	//TODO - Implementation
	if (head != NULL)
	{
		MultiMapNode* currentNode = head, *nodeSters;
		ValuesNode* currentValue = NULL, *valueSters;
		while (currentNode != tail)
		{
			valueSters = currentValue = currentNode->first;
			while (currentValue != NULL)
			{
				currentValue = currentValue->next;
				delete currentValue;
				valueSters = currentValue;
			}
			currentNode = currentNode->next;
		}
		nodeSters = currentNode = head;
		while (currentNode != NULL)
		{
			currentNode = currentNode->next;
			delete currentNode;
			nodeSters = currentNode;
		}
	}
}

