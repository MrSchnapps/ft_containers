/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:33:18 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/08 01:58:31 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <stack>
#include <iostream>
#include <string>
#include <list>
#include "ListIter.hpp"
#include "List.hpp"
#include "Iterators.hpp"

int main()
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
}