/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:52:10 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/01 17:56:37 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <list>

template <typename T>
struct testi
{
	T val;

	testi()
	:	val(19)
	{}

	testi(T &data)
	: val(data)
	{}
};

int main()
{
	int d = 5;
	testi<int> *l = new (testi<int>);
	std::cout << l->val << std::endl;
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