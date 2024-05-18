#include <iostream>

struct node
{
	int key;
	node *next;
};

node *head, *tail;

void init_list()
{
	head = new node;
	tail = new node;

	if (head)
	{
		head->next = tail;
		tail->next = tail;
	}
	
}

int delete_next(node *t)
{
	node *s;
	if (t->next == tail)
		return 0;
	s = t->next;
	t->next = t->next->next;
	delete s;
	return 1;
}

node *insert_after(int k, node *t)
{
	node *s;
	s = new node;
	s->key = k;
	s->next = t->next;
	t->next = s;
	return s;
}

node *find_node(int k)
{
	node *s;
	s = head->next;
	while (s->key != k && s != tail)
		s = s->next;
	return s;
}

int delete_node(int k)
{
	node *s;
	node *p;
	p = head;
	s = p->next;
	while (s->key != k && s != tail)
	{
		p = p->next;
		s = p->next;
	}
	if (s != tail)
	{
		p->next = s->next;
		delete s;
		return 1;
	}
	else
		return 0;
}

node *insert_node(int t, int k)
{
	node *s;
	node *p;
	node *r;
	p = head;
	s = p -> next;
	while (s->key != k && s != tail)
	{
		p = p->next;
		s = p->next;
	}
	if (s != tail)
	{
		r = new node;
		r->key = t;
		p->next = r;
		r->next = s;
	}
	return p->next;
}

node *ordered_insert(int k)
{
	node *s;
	node *p;
	node *r;
	p = head;
	s = p->next;
	while (s->key <= k && s != tail)
	{
		p = p->next;
		s = p->next;
	}
	r = new node;
	r->key = k;
	p->next = r;
	r->next = s;
	return r;
}

void print_list(node *t)
{
	std::cout << std::endl;
	while (t != tail)
	{
		std::cout << "\t" << t->key;
		t = t->next;
	}
}

node *delete_all(void)
{
	node *s;
	node *t;
	t = head->next;
	while (t != tail)
	{
		s = t;
		t = t->next;
		delete s;
	}
	head->next = tail;
	return head;
}

int main()
{
	node *t;

	init_list();
	ordered_insert(10);
	ordered_insert(5);
	ordered_insert(8);
	ordered_insert(3);
	ordered_insert(1);
	ordered_insert(7);
	ordered_insert(8);

	std::cout << std::endl << "Initial Linked list is ";
	print_list(head->next);

	std::cout << std::endl << "Finding 4 is " << (find_node(4) == tail ? "un" : "") << "successful";

	t = find_node(5);
	std::cout << std::endl << "Finding 5 is " << (t == tail ? "un" : "") << "succeessful";

	std::cout << std::endl << "Inserting 9 after 5";
	insert_after(9, t);
	print_list(head->next);

	t = find_node(10);;
	std::cout << std::endl << "Deleting next last node";
	delete_next(t);
	print_list(head->next);

	t = find_node(3);
	std::cout << std::endl << "Deleting next 3";
	delete_next(t);
	print_list(head->next);

	std::cout << std::endl << "Insert node 2 before 3";
	insert_node(2, 3);
	print_list(head->next);

	std::cout << std::endl << "Deleting node 2";
	if (!delete_node(2))
		std::cout << std::endl << " deleting 2 is unsuccessful";
	print_list(head->next);

	std::cout << std::endl << "Deleting node 1";
	delete_node(1);
	print_list(head->next);

	std::cout << std::endl << "Deleting all node";
	delete_all();
	print_list(head->next);
	
}