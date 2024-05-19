#include <iostream>

struct dnode
{
	int key;
	dnode *prev;
	dnode *next;
};

dnode *head, *tail;

void init_dlist()
{
	head = new dnode;
	tail = new dnode;
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

dnode *find_dnode(int k)
{
	dnode *s;
	s = head->next;
	while (s->key != k && s != tail)
		s = s->next;
	return s;
}

bool delete_dnode(int k)
{
	dnode *s;
	s = find_dnode(k);
	if (s != tail)
	{
		s->prev->next = s->next;
		s->next->prev = s->prev;
		delete s;
		return true;
	}
	return false;
}

dnode *insert_dnode(int k, int t)
{
	dnode *s;
	dnode *i = nullptr;
	s = find_dnode(t);
	if (s != tail)
	{
		i = new dnode;
		i->key = k;
		s->prev->next = i;
		i->prev = s->prev;
		s->prev = i;
		i->next = s;
	}
	return i;
}

dnode *ordered_insert(int k)
{
	dnode *s;
	dnode *i;
	s = head->next;
	while(s->key <= k && s != tail)
		s = s->next;
	i = new dnode;
	i->key = k;
	s->prev->next = i;
	i->prev = s->prev;
	s->prev = i;
	i->next = s;
	return i;
}

bool delete_dnode_ptr(dnode *p)
{
	if (p == head || p == tail)
		return false;
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	return true;
}

dnode *insert_dnode_ptr(int k, dnode *t)
{
	dnode *i;
	if (t == head)
		return nullptr;
	i = new dnode;
	i->key = k;
	i->prev = t->prev;
	i->next = t;
	t->prev->next = i;
	t->prev = i;
}

void print_dlist(dnode *p)
{
	std::cout << std::endl;
	while (p != tail)
	{
		std::cout << "\t" << p->key;
		p = p->next;
	}
}

void delete_all()
{
	dnode *p;
	dnode *s;
	p = head->next;
	while (p != tail)
	{
		s = p;
		p = p -> next;
		delete s;
	}
	head->next = tail;
	tail->prev = head;
}

int main()
{
	dnode *t;
	init_dlist();

	ordered_insert(10);
	ordered_insert(5);
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(1);
	ordered_insert(7);
	ordered_insert(8);

	std::cout << std::endl << "Initial Linked list is ";
	print_dlist(head->next);

	std::cout << std::endl << "Finding 4 is " << (find_dnode(4) == tail ? "un" : "") << "successful";

	t = find_dnode(5);
	std::cout << std:: endl << "Finding 5 is " << (find_dnode(5) == tail ? "un" : "") << "successful";

	std::cout << std::endl << "Inserting 7 before 5";
	insert_dnode_ptr(7, t);
	print_dlist(head->next);

	t = find_dnode(3);
	std::cout << std::endl << "Deleting 3 ";
	delete_dnode_ptr(t);
	print_dlist(head->next);

	std::cout << std::endl << "Inserting node 2 before 10";
	insert_dnode(2, 10);
	print_dlist(head->next);

	std::cout << std::endl << "Deleting node 2";
	if (!delete_dnode(2))
		std::cout << std::endl << "Deleting 2 is unsuccessful";
	print_dlist(head->next);

	std::cout << std::endl << "Deleting node 1";
	delete_dnode(1);
	print_dlist(head->next);

	std::cout << std::endl << "Inserting 15 at first";
	insert_dnode_ptr(15, head->next);
	print_dlist(head->next);

	std::cout << std::endl << "Deleting all node";
	delete_all();
	print_dlist(head->next);
}

