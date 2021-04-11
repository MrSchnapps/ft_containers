/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:33:18 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/11 03:04:40 by judecuyp         ###   ########.fr       */
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

template <class T>
void	print_list(ft::List<T> &list)
{
	ft::List<int>::iterator first = list.begin();
	ft::List<int>::iterator last = list.end();
	size_t 					i = 0;

	//std::cout << "Print values :" << std::endl;
	while (first != last)
	{
		std::cout << "Val : " << i << " --> " << *first << std::endl;
		++i;
		++first;
	}
	std::cout << std::endl;
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
/*int main()
{
	std::cout << "--------------------------- Mien -----------------------------------" << std::endl;
	ft::List<int> li;
	ft::List<int>::iterator it;
	ft::List<int>::iterator itend;
	
	li.push_back(5);
	li.push_back(9);

	
	it = li.begin();
	std::cout << "Begin1 --> " << *it << std::endl;

	li.push_front(7);
	it = li.begin();
	std::cout << "Begin2 --> " << *it << std::endl;

	std::cout << "Size_max : " << li.max_size() << std::endl;
	std::cout << "Front : " << li.front() << std::endl;
	std::cout << "Back : " << li.back() << std::endl;

	itend = li.end();
	while (it != itend)
	{
		std::cout << *it << std::endl;
		++it;
	}
	it = li.begin();
	while (it != itend)
	{
		std::cout << *it << std::endl;
		it++;
	}

	std::cout << "Reverse iterator --------" << std::endl;
	ft::List<int>::reverse_iterator rit;
	ft::List<int>::reverse_iterator reit;
	rit = li.rbegin();
	reit = li.rend();
	while (rit != reit)
	{
		std::cout << *rit << std::endl;
		rit++;
	}

	std::cout << "Print function --------" << std::endl;
	li.print_elem();
	li.erase(li.begin());
	li.print_elem();
	li.pop_front();
	li.print_elem();

	std::cout << "--------------------------- VRAI -----------------------------------" << std::endl;

	std::list<int> li2;
	std::list<int>::iterator it2;
	std::list<int>::iterator itend2;
	li2.push_back(5);
	li2.push_back(9);

	it2 = li2.begin();
	std::cout << "Begin1 --> " << *it2 << std::endl;

	li2.push_front(7);
	it2 = li2.begin();
	std::cout << "Begin2 --> " << *it2 << std::endl;

	std::cout << "Size_max : " << li2.max_size() << std::endl;
	std::cout << "Front : " << li2.front() << std::endl;
	std::cout << "Back : " << li2.back() << std::endl;

	itend2 = li2.end();
	while (it2 != itend2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	it2 = li2.begin();
	while (it2 != itend2)
	{
		std::cout << *it2 << std::endl;
		it2++;
	}

	std::cout << "Reverse iterator --------" << std::endl;
	std::list<int>::reverse_iterator rlit;
	std::list<int>::reverse_iterator rleit;
	rlit = li2.rbegin();
	rleit = li2.rend();
	while (rlit != rleit)
	{
		std::cout << *rlit << std::endl;
		rlit++;
	}
	return (0);
}*/

/*int main ()
{
  ft::List<int> mylist;
  ft::List<int>::iterator it;

  // set some initial values:
  for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

  it = mylist.begin();
  ++it;       // it points now to number 2           ^

  mylist.insert(it,10);                        // 1 10 2 3 4 5

  // "it" still points to number 2                      ^
  mylist.insert(it,size_t(2),20);                      // 1 10 20 20 2 3 4 5

  --it;       // it points now to the second 20            ^

  ft::List<int> myvector; //(2,30);
  myvector.push_back(30);
  myvector.push_back(40);
  mylist.insert (it, myvector.begin(), myvector.end());
                                                // 1 10 20 30 30 20 2 3 4 5
                                                //               ^
  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}*/


int main()
{
	ft::List<int> l1;
	ft::List<int> l2;

	basic_values(l1, l2);
	std::cout << "=======   SWAP   =======" << std::endl;

	std::cout << "Before : " << std::endl;
	std::cout << "-- L1 --" << std::endl;
	print_list(l1);
	std::cout << "-- L2 --" << std::endl;
	print_list(l2);

	l1.swap(l2);
	std::cout << "After : " << std::endl;
	std::cout << "-- L1 --" << std::endl;
	print_list(l1);
	std::cout << "-- L2 --" << std::endl;
	print_list(l2);

	reset(l1, l2);
	
	std::cout << "=======   RESIZE   =======" << std::endl;
	print_list(l1);
	
	l1.resize(3);

	std::cout << "l1.resize(3);" << std::endl;
	print_list(l1);
	l1.resize(8, 19);
	std::cout << "l1.resize(8, 19);" << std::endl;
	print_list(l1);

	reset(l1, l2);
}
