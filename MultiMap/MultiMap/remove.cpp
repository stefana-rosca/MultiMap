bool MultiMap::remove(TKey c, TValue v) {
	//TODO - Implementation
	if (isEmpty())
		return  false;
	MultiMapNode* node = head;
	bool gasit = false;
	while (node != NULL)
	{
		if (node->cheie == c)
		{
			gasit = true;
			break;
		}
		else
		{
			node = node->next;
		}
	}
	while (node != NULL)
	{
		if (gasit == true)
		{//cheie cu mai multe val
			ValuesNode* valNode = node->first;
			for (valNode = node->first; valNode != NULL; valNode++)
			{
				if (valNode->val == v)
					delete valNode;
				return true;
			}
			if (node == head)
			{
				delete head;
				head = node->next;
				head->prev = NULL;
				return true;
			}
			else if (head == tail)
			{
				delete tail;
				tail = node->prev;
				tail->next = NULL;
				return true;
			}
		}
		else
		{
			return false;
		}
	}
}


// add
void MultiMap::add(TKey c, TValue v) {
	//TODO - Implementation
	//if(isEmpty())
	//{
	//	MultiMapNode* newNode = new MultiMapNode;
	//	newNode->cheie = c;
	//	newNode->first->val = v;
	//	head = newNode;
	//	tail = newNode;
	//}
	//else
	//{
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
		if (cheie_exista == false)
		{//fac o cheie care are o singura valoare
			//if (head == NULL)
			//{
				//head = new MultiMapNode;
		//		head->next = NULL;
			//	head->prev = tail;
				//head->cheie = c;
		//		head->first = new ValuesNode;
			//	head->first->prev = NULL;
		//		//head->first->next = NULL;
			//	head->first->val = v;
		//	}
			//else
			{
				MultiMapNode* newNode = new MultiMapNode;
				newNode->cheie = c;
				newNode->first = new ValuesNode;
				newNode->first->val = v;
				newNode->prev = tail;
				newNode->first->next = NULL;
				newNode->next = head;
				tail = newNode;
				return;
			}

		}
		else if (cheie_exista == true)
		{
			ValuesNode* newVal = new ValuesNode;
			newVal->prev = node->last;
			newVal->val = v;
			node->last = newVal;
			//return;
		}

	//}
		if (isEmpty() == true)
		{
			MultiMapNode* newNode = new MultiMapNode;
			newNode->cheie = c;
			ValuesNode* newVal = new ValuesNode;
			newVal->val = v;
			newVal->next = NULL;
			head = newNode;
			tail = newNode;
		}
}