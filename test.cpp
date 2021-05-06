/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:52:10 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/02 22:49:23 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <list>



int main()
{

	std::list<int> test;

	test.push_back(5);
	test.push_back(7);
	test.push_back(48);
	test.push_back(19);
	test.push_back(24);

	std::list<int>::reverse_iterator rit = test.rbegin();
	
	std::cout << "Rbegin --> " << *rit << std::endl;

	rit++;
	std::cout << "Rbegin --> " << *rit << std::endl;
	/*int d = 5;
	testi<int> *l = new (testi<int>);
	std::cout << l->val << std::endl;*/
	//delete l;
	
	/*std::list<char> li;
	li.push_back('e');
	li.push_back('d');
	li.push_front('a');
	li.push_front('b');
	
	std::list<char>::iterator it;
	
	it = li.begin();
	std::cout << *it << std::endl;

	it--;
	std::cout << *it << std::endl;
	it--;
	std::cout << *it << std::endl;
	it--;
	std::cout << *it << std::endl;
	it--;
	std::cout << *it << std::endl;
	it--;
	std::cout << *it << std::endl;
	it--;
	std::cout << *it << std::endl;

	std::list<char>::iterator itend;
	itend = li.end();
	std::cout << *it << std::endl;*/
	return (0);
}