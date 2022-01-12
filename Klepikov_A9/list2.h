#ifndef LIST2_H
#define LIST2_H

#include "list2_node.h"

class list2
{
private:
	list2_node *head = nullptr;
	static int m;
	static int r;

public:
	list2() = default;
	list2(const list2 &x) = delete;
	list2(list2 &&x);
	~list2();

	list2 &operator=(const list2 &x) = delete;
	list2 &operator=(list2 &&x);

	int read(FILE *fp);
	void print(int tab);
	void delete_list();
	int get_length();

	static void set_m(int m) { list2::m = m; }
	static void set_r(int r) { list2::r = r; }

	int operator<(const list2 &x);
};
#endif // LIST2_H