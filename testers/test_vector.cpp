/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:14:36 by judecuyp          #+#    #+#             */
/*   Updated: 2021/05/11 14:14:36 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

template <class T>
void	print_vector(ft::vector<T> &vct)
{
	typename ft::vector<T>::iterator it = vct.begin();
	size_t 					i = 0;

	std::cout << " ---------- Vector container ----------" << std::endl;
	while (it != vct.end())
	{
		std::cout << "Element " << i << ": |" << *it << "|" << std::endl;
		++it;
		++i;
	}
}

//void	fill_container

void	test_vector()
{
	ft::vector<int> vct;
	ft::vector<int> vct2;

	vct.reserve(10);

	P("   --- Insert ---");
	vct.insert(vct.end(), 3);
	print_vector(vct);

	vct.insert(vct.end(), 19);
	print_vector(vct);

	vct.insert(vct.begin(), 42);
	print_vector(vct);
	
	ft::vector<int>::iterator it = vct.begin();
	++it;
	vct.insert(it, 37);
	print_vector(vct);

	vct.insert(it, (size_t)8, 100);
	print_vector(vct);

	vct2.insert(vct2.end(), 97);
	vct2.insert(vct2.end(), 206);
	vct2.insert(vct2.end(), 93);
	vct2.insert(vct2.end(), 207);
	vct2.insert(vct2.end(), 13);
	print_vector(vct2);
	it = vct.begin();
	++it;

	vct.insert(it, vct2.begin(), vct2.end());
	print_vector(vct);

}
