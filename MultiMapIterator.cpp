#include "MultiMapIterator.h"
#include "MultiMap.h"


MultiMapIterator::MultiMapIterator(const MultiMap& c): col(c) {
	//TODO - Implementation
	currentNode = col.head;
	if (currentNode != NULL)
	{
		currentVal = currentNode->first;
	}
	else
	{
		currentVal = NULL;
	}
}

TElem MultiMapIterator::getCurrent() const{
	//TODO - Implementation
	if (valid() == true)
	{
		TKey c = currentNode->cheie;
		TValue v = currentVal->val;
		return make_pair(c, v);
	}
	else
	{
		return NULL_TELEM;
	}
}

bool MultiMapIterator::valid() const {
	//TODO - Implementation
	if (currentNode == col.head || currentNode == col.tail || currentNode != NULL)
		return true;
	if(col.isEmpty()==true)
		return false;
}

void MultiMapIterator::next() {
	//TODO - Implementation
	while (valid() == true)
	{
		if (currentVal->next)
		{
			currentVal=currentVal->next;
		}
	}

}

void MultiMapIterator::first() {
	//TODO - Implementation
	currentNode = col.head;
	if (currentNode != NULL)
	{
		currentVal = currentNode->first;
	}
	else
	{
		currentVal = NULL;
	}
}

