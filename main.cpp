/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:33:18 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/01 21:16:15 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <deque>
#include <stack>
#include <iostream>
#include <string>
#include <list>
#include "List.hpp"

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
	return (0);
}