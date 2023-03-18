#include <iostream>
#include <list>
#include <stack>

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> mstack;
	std::list<int> list;

	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	list.push_back(5);
	list.push_back(17);
	list.push_back(3);
	list.push_back(5);
	list.push_back(737);
	list.push_back(0);

	list.pop_back();
	mstack.pop();
	
	MutantStack<int>::iterator mstack_it = mstack.begin();
	MutantStack<int>::iterator mstack_ite = mstack.end();
	std::list<int>::iterator list_it = list.begin();
	std::list<int>::iterator list_ite = list.end();

	++mstack_it;
	--mstack_it;

	std::cout << "MutantStack numbers:\n";
	while (mstack_it != mstack_ite)
	{
		std::cout << *mstack_it << std::endl;
		++mstack_it;
	}

	std::cout << "List numbers:\n";
	while (list_it != list_ite)
	{
		std::cout << *list_it << std::endl;
		++list_it;
	}

}
