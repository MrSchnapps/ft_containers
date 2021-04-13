/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:33:18 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/13 18:06:12 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <stack>
#include <iostream>
#include <string>
#include <list>
#include <vector>
#include "ListIter.hpp"
#include "List.hpp"
#include "Iterators.hpp"
#include "Utils.hpp"

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
void	print_list(ft::List<T> &list, std::string name)
{
	ft::List<int>::iterator first = list.begin();
	ft::List<int>::iterator last = list.end();
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
void	basic_values(ft::List<T> &l1, ft::List<T> &l2)
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
void	reset(ft::List<T> &l1, ft::List<T> &l2)
{
	l1.clear();
	l2.clear();
	basic_values(l1, l2);
}


// ajouter autres fct avt le swap !!

int main()
{
	ft::List<int>			l1;
	ft::List<int>			l2;
	ft::List<int>::iterator	it1;
	ft::List<int>::iterator	it2;

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

	return (0);
}
