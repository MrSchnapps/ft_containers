/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 01:42:04 by judecuyp          #+#    #+#             */
/*   Updated: 2021/05/11 01:42:04 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"
#include <list>

bool binary13(int &val, int &val2)
{
	if (val % 13 == 0 && val2 % 13 == 0)
		return (true);
	return (false);
}

bool test_pair(int &val)
{
	if (val % 2)
		return (false);
	return (true);
}

template <class T>
void	print_list(ft::list<T> &list, std::string name)
{
	ft::list<int>::iterator first = list.begin();
	ft::list<int>::iterator last = list.end();
	size_t 					i = 0;

	std::cout << name << "|" << std::endl;
	while (first != last)
	{
		std::cout << "Val : " << i << " --> " << *first << std::endl;
		++i;
		++first;
	}
	std::cout << "|" << std::endl << std::endl;
}

template <class T>
void	print_vraie_list(std::list<T> &list, std::string name)
{
	std::list<int>::iterator first = list.begin();
	std::list<int>::iterator last = list.end();
	size_t 					i = 0;

	std::cout << name << "|" << std::endl;
	while (first != last)
	{
		std::cout << "Val : " << i << " --> " << *first << std::endl;
		++i;
		++first;
	}
	std::cout << "|" << std::endl << std::endl;
}

template <class T>
void	basic_values(ft::list<T> &l1, ft::list<T> &l2)
{
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);

	l2.push_back(103);
	l2.push_back(-5);
	l2.push_back(42);
	l2.push_back(19);
}

template <class T>
void	basic_values(ft::list<T> &l1, std::list<T> &l2)
{
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);

	l2.push_back(1);
	l2.push_back(2);
	l2.push_back(3);
	l2.push_back(4);
	l2.push_back(5);
}

template <class T>
void	basic_values(ft::list<T> &l1)
{
	l1.push_back(1);
	l1.push_back(2);
	l1.push_back(3);
	l1.push_back(4);
	l1.push_back(5);
}

template <class T>
void	reset(ft::list<T> &l1, ft::list<T> &l2)
{
	l1.clear();
	l2.clear();
	basic_values(l1, l2);
}

void	main_test_list()
{
	std::cout << "###############  LIST ###############" << std::endl;
	ft::list<int>			l1;
	ft::list<int>			l2;
	ft::list<int>::iterator	it1;
	ft::list<int>::iterator	it2;

	std::cout << "Empty ? " << l1.empty();

	basic_values(l1, l2);
	std::cout << "=======   SWAP   =======" << std::endl;

	std::cout << "Before : " << std::endl;
	std::cout << "-- L1 --" << std::endl;
	print_list(l1, "l1");
	std::cout << "-- L2 --" << std::endl;
	print_list(l2, "l2");

	l1.swap(l2);
	std::cout << "After : " << std::endl;
	std::cout << "-- L1 --" << std::endl;
	print_list(l1, "l1");
	std::cout << "-- L2 --" << std::endl;
	print_list(l2, "l2");

	reset(l1, l2);
	
	std::cout << "=======   RESIZE   =======" << std::endl;
	print_list(l1, "l1");
	
	l1.resize(3);

	std::cout << "l1.resize(3);" << std::endl;
	print_list(l1, "l1");
	l1.resize(8, 19);
	std::cout << "l1.resize(8, 19);" << std::endl;
	print_list(l1, "l1");

	reset(l1, l2);

	std::cout << "=======   SPLICE   =======" << std::endl;
	it1 = l1.begin();
	print_list(l1, "l1");
	print_list(l2, "l2");
	++it1;
	++it1;

	std::cout << "Splice 1" << std::endl;
	l1.splice(it1, l2);
	print_list(l1, "l1");
	print_list(l2, "l2");

	std::cout << "Splice 2" << std::endl;
	l2.splice(l2.begin(), l1, it1);
	print_list(l1, "l1");
	print_list(l2, "l2");

	it1 = l1.begin();
	++it1;
	it2 = l1.begin();
	for (int i = 0; i < 6; i++)
		++it2;

	std::cout << "Splice 3" << std::endl;
	l2.splice(l2.begin(), l1, it1, it2);
	print_list(l1, "l1");
	print_list(l2, "l2");

	reset(l1, l2);
	
	std::cout << "=======   REMOVE   =======" << std::endl;
	l1.push_back(4);
	l1.push_back(9);
	l1.push_back(4);

	std::cout << "Before remove :" << std::endl;
	print_list(l1, "l1");
	l1.remove(4);
	P("l1.remove(4);");
	print_list(l1, "l1");

	reset(l1, l2);
	
	P("=======   REMOVE IF   =======");
	P("Before remove_if :");
	print_list(l1, "l1");
	
	l1.remove_if(test_pair);
	P("l1.remove_if(test_pair);");
	print_list(l1, "l1");

	reset(l1, l2);
	
	P("=======   UNIQUE   =======");
	l1.push_front(1);
	l1.push_back(5);
	l1.push_back(5);
	l1.push_front(2);
	P("Before unique :");
	print_list(l1, "l1");

	l1.unique();
	P("l1.unique();");
	print_list(l1, "l1");


	reset(l1, l2);
	l1.push_front(13);
	l1.push_front(26);
	l1.push_front(39);
	l1.push_front(26);
	l1.push_back(26);
	l1.push_back(39);
	P("Before unique binary :");
	print_list(l1, "l1");

	l1.unique(binary13);
	P("l1.unique(binary13());");
	print_list(l1, "l1");

	reset(l1, l2);

	P("=======   MERGE   =======");
	P("Before merge :");
	l2.sort();
	print_list(l1, "l1");
	print_list(l2, "l2");

	l1.merge(l2);
	P("l1.merge(l2);");
	print_list(l1, "l1");
	print_list(l2, "l2");

	reset(l1, l2);

	P("Before merge binary :");
	l2.sort();
	print_list(l1, "l1");
	print_list(l2, "l2");

	l1.merge(l2, std::less<int>());
	P("l1.merge(l2);");
	print_list(l1, "l1");
	print_list(l2, "l2");

	reset(l1, l2);

	P("=======   SORT   =======");
	l1.push_front(19);
	l1.push_back(42);
	l1.push_back(-15);
	l1.push_front(27);
	l1.push_front(27);
	P("Before sort :");
	print_list(l1, "l1");

	l1.sort();
	P("l1.sort();");
	print_list(l1, "l1");

	reset(l1, l2);

	l1.push_front(19);
	l1.push_back(42);
	l1.push_back(-15);
	l1.push_front(27);
	P("Before sort compare :");
	print_list(l1, "l1");

	l1.sort(std::less<int>());
	P("l1.sort(std::less<int>());");
	print_list(l1, "l1");

	reset(l1, l2);

	P("=======   REVERSE   =======");
	P("Before reverse :");
	l1.push_back(19);
	print_list(l1, "l1");

	l1.reverse();
	P("l1.reverse();");
	print_list(l1, "l1");
 
	P("#####  Non member operators overload == != > >= < <=  #####");
	basic_values(l1, l2);
	std::cout << "L1 == L2 ?? : ";
	if (l1 == l2)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	
	std::cout << "L1 == L1 ?? : ";
	if (l1 == l1)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	
	std::cout << "L1 != L2 ?? : ";
	if (l1 != l2)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	
	std::cout << "L1 != L1 ?? : ";
	if (l1 != l1)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	std::cout << "L1 < L2 ?? : ";
	if (l1 < l2)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;
	
	std::cout << "L1 < L1 ?? : ";
	if (l1 < l1)
		std::cout << "true" << std::endl;
	else
		std::cout << "false" << std::endl;

	P("  -- Swap l1 & l1");
	P("before swap :")
	print_list(l1, "l1");
	print_list(l2, "l2");
	P("after swap :")
	ft::swap(l1, l2);
	print_list(l1, "l1");
	print_list(l2, "l2");

	P("constructor tester");
	P(" - ft::list<int>	l3((size_t)5, 300)");
	ft::list<int>	l3((size_t)5, 300);
	print_list(l3, "l3");

	P(" - ft::list<int>	l4(l1.begin(),l1.end());");
	ft::list<int>	l4(l1.begin(),l1.end());
	print_list(l4, "l4");

	P(" - ft::list<int>	l5(l2);");
	ft::list<int>	l5(l2);
	print_list(l5, "l5");
}


static bool compare(int a, int b)
{
	return (a % 2 == b % 2);
    //return (a >= b);
}

void 	test_list_unique()
{
	std::cout << "###############  UNIQUE ###############" << std::endl;
	int test[] = {0, 0, 0, 1, 2, 0, 5, 5, 4, 5, 1, -1, 0, 1};
	ft::list<int> l1(test, test + 14);
	std::list<int> l2(test, test + 14);
	l1.unique();
	l2.unique();

	P(" ==  TEST 1 == ");
	print_list(l1, "l1");
	print_vraie_list(l2, "l2");
	//check("l1 == l2", l1 == l2);

	P("\n ==  TEST 2 == ");

	l1.assign(test, test + 14);
	l2.assign(test, test + 14);
	
	print_list(l1, "l1");
	print_vraie_list(l2, "l2");

	l1.unique(compare);
	l2.unique(compare);

	print_list(l1, "l1");
	print_vraie_list(l2, "l2");

	//check("l1 == l2", l1 == l2);
}

void	test_list_constructor()
{
	print_title("Constructors");
	
	ft::list<int>	my1;
	std::list<int>	real1;
	check("Empty constructor", (my1 == real1));

	ft::list<int>	my2((size_t)9, 19);
	std::list<int>	real2((size_t)9, 19);
	check("Fill constructor", (my2 == real2));

	my2.clear();
	my2.push_back(1);
	my2.push_back(2);
	my2.push_back(3);
	my2.push_back(4);
	real2.clear();
	real2.push_back(1);
	real2.push_back(2);
	real2.push_back(3);
	real2.push_back(4);
	ft::list<int>	my3(my2.begin(), my2.end());
	std::list<int>	real3(real2.begin(), real2.end());
	check("Range constructor", (my3 == real3));

	ft::list<int>	my4(my3);
	std::list<int>	real4(real3);
	check("Copy constructor", (my4 == real4));

	ft::list<int>	my5 = my4;
	std::list<int>	real5 = real4;
	check("Operator =", (my5 == real5));

	my4 = my3;
	real4 = real3;
	check("Operator =", (my4 == real4));
}

void	test_list_iterators()
{
	print_title("Iterators / Capacity / Element Access"); 
	ft::list<int>	my1;
	std::list<int>	real1;
	check("Empty()", my1.empty(), real1.empty());
	check("Size()", my1.size(), real1.size());
	basic_values(my1, real1);
	check("Empty()", my1.empty(), real1.empty());
	check("Size()", my1.size(), real1.size());

	bool test = true;
	ft::list<int>::iterator myIt = my1.begin();
	std::list<int>::iterator realIt = real1.begin();
	while (myIt != my1.end())
	{
		if (*myIt != *realIt)
			test = false;
		++myIt;
		++realIt;
	}
	check("Begin() / End()", test);
	
	test = true;
	ft::list<int>::reverse_iterator myItR = my1.rbegin();
	std::list<int>::reverse_iterator realItR = real1.rbegin();
	while (myItR != my1.rend())
	{
		if (*myItR != *realItR)
			test = false;
		++myItR;
		++realItR;
	}
	check("RBegin() / REnd()", test);

	check("Front()", my1.front(), real1.front());
	check("Back()", my1.back(), real1.back());

}

void	test_list_const_iterators()
{
	print_title("Const Iterators"); 
	const ft::list<int>	my1((size_t)2, 19);
	const std::list<int>	real1((size_t)2, 19);

	bool test = true;
	ft::list<int>::const_iterator myIt = my1.begin();
	//*myIt = 2;
	std::list<int>::const_iterator realIt = real1.begin();
	//*realIt = 2;
	while (myIt != my1.end())
	{
		if (*myIt != *realIt)
			test = false;
		++myIt;
		++realIt;
	}
	check("Begin() / End()", test);
	
	test = true;
	ft::list<int>::const_reverse_iterator myItR = my1.rbegin();
	std::list<int>::const_reverse_iterator realItR = real1.rbegin();
	while (myItR != my1.rend())
	{
		if (*myItR != *realItR)
			test = false;
		++myItR;
		++realItR;
	}
	check("RBegin() / REnd()", test);
}

void	test_list_assign()
{
	print_title("Assign");
	ft::list<int>	my1;
	std::list<int>	real1;
	basic_values(my1, real1);

	ft::list<int>	my2;
	std::list<int>	real2;
	my2.assign(my1.begin(), my1.end());
	real2.assign(real1.begin(), real1.end());
	check("assign iterators", (my2 == real2));

	ft::list<int>::iterator myIt = my1.begin();
	std::list<int>::iterator realIt = real1.begin();
	++myIt;
	++realIt;
	++myIt;
	++realIt;
	my2.assign(myIt, my1.end());
	real2.assign(realIt, real1.end());
	check("assign iterators", (my2 == real2));

	ft::list<int>	my3;
	std::list<int>	real3;
	my3.assign((size_t)10, 19);
	real3.assign((size_t)10, 19);
	check("assign values", (my3 == real3));
	my3.assign((size_t)5, 42);
	real3.assign((size_t)5, 42);
	check("assign values", (my3 == real3));
}

void	test_list_push()
{
	print_title("Push");
	ft::list<int>	my1;
	std::list<int>	real1;

	my1.push_front(1);
	real1.push_front(1);
	check("push_front(1)", (my1 == real1));
	my1.push_front(2);
	real1.push_front(2);
	check("push_front(2)", (my1 == real1));

	my1.pop_front();
	real1.pop_front();
	check("pop_front()", (my1 == real1));
	my1.pop_front();
	real1.pop_front();
	check("pop_front()", (my1 == real1));

	my1.push_back(3);
	real1.push_back(3);
	check("push_back(3)", (my1 == real1));
	my1.push_back(4);
	real1.push_back(4);
	check("push_back(4)", (my1 == real1));

	my1.pop_back();
	real1.pop_back();
	check("pop_back()", (my1 == real1));
	my1.pop_back();
	real1.pop_back();
	check("pop_back()", (my1 == real1));
}

void	test_list_insert()
{
	print_title("Insert");
	//test1
	ft::list<int>	my1;
	std::list<int>	real1;

	ft::list<int>::iterator myIt = my1.begin();
	std::list<int>::iterator realIt = real1.begin();

	my1.insert(myIt, 19);
	real1.insert(realIt, 19);
	my1.insert(myIt, 42);
	real1.insert(realIt, 42);
	check("insert value begin", (my1 == real1));

	my1.insert(my1.end(), 91);
	real1.insert(real1.end(), 91);
	my1.insert(my1.end(), 24);
	real1.insert(real1.end(), 24);
	check("insert value end", (my1 == real1));

	myIt = my1.begin();
	realIt = real1.begin();
	++myIt;
	++realIt;
	my1.insert(myIt, 192);
	real1.insert(realIt, 192);
	check("insert value inside", (my1 == real1));

	//test2
	ft::list<int>	my2;
	std::list<int>	real2;

	ft::list<int>::iterator myIt2 = my2.begin();
	std::list<int>::iterator realIt2 = real2.begin();

	my2.insert(myIt2, (size_t)3, 19);
	real2.insert(realIt2, (size_t)3, 19);
	my2.insert(myIt2, (size_t)3, 42);
	real2.insert(realIt2, (size_t)3, 42);
	check("insert size value begin", (my2 == real2));

	my2.insert(my2.end(), (size_t)3, 91);
	real2.insert(real2.end(), (size_t)3, 91);
	my2.insert(my2.end(), (size_t)3, 24);
	real2.insert(real2.end(), (size_t)3, 24);
	check("insert size value end", (my2 == real2));

	++myIt2;
	++realIt2;
	my2.insert(myIt2, 192);
	real2.insert(realIt2, 192);
	check("insert size value inside", (my2 == real2));

	//test3
	ft::list<int>	my3;
	std::list<int>	real3;

	ft::list<int>::iterator myIt3 = my3.begin();
	std::list<int>::iterator realIt3 = real3.begin();

	my3.insert(myIt3, my2.begin(), my2.end());
	real3.insert(realIt3, real2.begin(), real2.end());
	check("insert iterators", (my3 == real3));

	myIt3 = my3.begin();
	realIt3 = real3.begin();
	++myIt3;
	++realIt3;
	my3.insert(myIt3, my2.begin(), my2.end());
	real3.insert(realIt3, real2.begin(), real2.end());
	check("insert iterators", (my3 == real3));
}

void	test_list_erase()
{
	print_title("Erase");
	ft::list<int>	my1;
	std::list<int>	real1;
	basic_values(my1, real1);

	my1.erase(my1.begin());
	real1.erase(real1.begin());
	check("erase begin()", (my1 == real1));

	ft::list<int>::iterator myIt = my1.begin();
	std::list<int>::iterator realIt = real1.begin();
	++myIt;
	++realIt;
	my1.erase(myIt);
	real1.erase(realIt);
	check("erase iterator", (my1 == real1));

	my1.erase(my1.begin(), my1.end());
	real1.erase(real1.begin(), real1.end());
	check("erase range", (my1 == real1));
}

void	test_list_swap()
{
	print_title("Swap / Swap extern");
	ft::list<int>	my1;
	std::list<int>	real1;
	ft::list<int>	my2;
	std::list<int>	real2;

	my1.swap(my2);
	real1.swap(real2);
	check("swap", (my1 == real1), (my2 == real2));

	ft::swap(my1, my2);
	std::swap(real1, real2);

	check("swap extern", (my1 == real1), (my2 == real2));

	basic_values(my1, real1);
	my2.push_back(19);
	my2.push_back(42);
	my2.push_back(101);
	my2.push_back(24);
	my2.push_back(91);
	real2.push_back(19);
	real2.push_back(42);
	real2.push_back(101);
	real2.push_back(24);
	real2.push_back(91);

	my1.swap(my2);
	real1.swap(real2);
	check("swap", (my1 == real1), (my2 == real2));

	ft::swap(my1, my2);
	std::swap(real1, real2);
	check("swap extern", (my1 == real1), (my2 == real2));
}

void	test_list_resize()
{
	print_title("Resize");
	ft::list<int>	my1;
	std::list<int>	real1;

	my1.resize(0);
	real1.resize(0);
	check("resize(0)", (my1 == real1));

	my1.resize(9);
	real1.resize(9);
	check("resize(9)", (my1 == real1));

	my1.resize(9, 19);
	real1.resize(9, 19);
	check("resize(9, 19)", (my1 == real1));

	ft::list<int>	my2;
	std::list<int>	real2;
	basic_values(my2, real2);

	my2.resize(4, 10);
	real2.resize(4, 10);
	check("resize(4, 10)", (my2 == real2));

	my2.resize(9, 19);
	real2.resize(9, 19);
	check("resize(9, 19)", (my2 == real2));
}

void	test_list_clear()
{
	print_title("clear");
	ft::list<int>	my1;
	std::list<int>	real1;

	my1.clear();
	real1.clear();
	check("clear void", (my1 == real1));

	basic_values(my1, real1);
	my1.clear();
	real1.clear();
	check("clear", (my1 == real1));
}

void	test_list_splice()
{
	print_title("Splice");
	ft::list<int>	my1;
	std::list<int>	real1;
	ft::list<int>	my2;
	std::list<int>	real2;

	my2.splice(my2.begin(), my1);
	real2.splice(real1.begin(), real1);
	check("Splice empty 2", (my2 == real2));
	check("Splice empty 1", (my1 == real1));

	basic_values(my1, real1);
	my2.splice(my2.begin(), my1);
	real2.splice(real2.begin(), real1);
	check("Splice first empty 2", (my2 == real2));
	check("Splice first empty 1", (my1 == real1));
	
	ft::list<int>	my3;
	std::list<int>	real3;
	basic_values(my3, real3);
	ft::list<int>::iterator myIt = my3.begin();
	std::list<int>::iterator realIt = real3.begin();
	++myIt;
	++realIt;
	++myIt;
	++realIt;
	my3.splice(myIt, my1);
	real3.splice(realIt, real1);
	check("Splice fill 3", (my3 == real3));
	check("Splice fill 1", (my1 == real1));

	my1.clear();
	real1.clear();
	myIt = ++(my3.begin());
	realIt = ++(real3.begin());
	my1.splice(my1.begin(), my3, myIt);

	real1.splice(real1.begin(), real3, realIt);
	check("Splice one iter 1", (my1 == real1));
	check("Splice one iter 3", (my3 == real3));

	myIt = ++(my3.begin());
	realIt = ++(real3.begin());
	++myIt;
	++realIt;
	my1.splice(my1.begin(), my3, myIt);
 	real1.splice(real1.begin(), real3, realIt);
 	check("Splice one iter 1", (my1 == real1));
	check("Splice one iter 3", (my3 == real3));

	myIt = my2.begin();
	realIt = real2.begin();
	my1.splice(++(my1.begin()), my2, myIt);
 	real1.splice(++(real1.begin()), real2, realIt);
	check("Splice range iter 1", (my1 == real1));
	check("Splice range iter 2", (my2 == real2));

}

void 	test_list_remove()
{
	print_title("Splice");
	ft::list<int>	my1;
	std::list<int>	real1;

	basic_values(my1, real1);
	my1.push_back(19);
	real1.push_back(19);
	my1.push_back(19);
	real1.push_back(19);
	my1.push_back(42);
	real1.push_back(42);

	my1.remove(12);
	real1.remove(12);
	check("Remove", (my1 == real1));
	my1.remove(19);
	real1.remove(19);
	check("Remove", (my1 == real1));
	my1.remove(1);
	real1.remove(1);
	check("Remove", (my1 == real1));

}

void	test_list_modifiers()
{
	//print_title("Modifiers");
	test_list_assign();
	P("");
	test_list_push();
	P("");
	test_list_insert();
	P("");
	test_list_erase();
	P("");
	test_list_swap();
	P("");
	test_list_resize();
	P("");
	test_list_clear();
}



void test_list_operations()
{
	test_list_splice();
	P("");
	test_list_remove(); //need
	P("");
	// test_list_remove_if(); //need
	// P("");
	// test_list_unique(); //need
	// P("");
	// test_list_merge(); //need
	// P("");
	// test_list_sort(); //need
	// P("");
	// test_list_reverse(); //need

}

void test_list()
{
	print_header("LIST");
	test_list_constructor();
	P("");
	test_list_iterators();
	P("");
	test_list_const_iterators();
	P("");
	test_list_modifiers();
	P("");
	test_list_operations();
	P("");

}
