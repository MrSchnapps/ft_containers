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

/*
** Printers
*/
template <class T>
void	print_vector(ft::vector<T> &vct, std::string name="")
{
	typename ft::vector<T>::iterator it = vct.begin();
	size_t 					i = 0;

	std::cout << " ------- Vector container " << name << " -------" << std::endl;
	while (it != vct.end())
	{
		std::cout << "Element " << i << ": |" << *it << "|" << std::endl;
		++it;
		++i;
	}
	P("");
}

void	print_title(std::string title)
{
	std::cout << "   *** " << title << " ***" << std::endl;
}

/*
** Iterators
*/
void	test_vct_iterators()
{
	ft::vector<int> vct;
	ft::vector<int>::iterator it;
	ft::vector<int>::reverse_iterator rit;

	vct.insert(vct.end(), 19);
	vct.insert(vct.end(), 21);
	vct.insert(vct.end(), 36);
	vct.insert(vct.end(), 42);
	vct.insert(vct.end(), 56);
	print_vector(vct);

	it = vct.begin();
	std::cout << "Begin() : " << *it << std::endl;
	std::cout << "Begin() + 3 : " << *(it + 3) << std::endl;
	P("");
	it = vct.end();
	--it;
	std::cout << "--end() : " << *it << std::endl;
	std::cout << "end() - 2 : " << *(it - 2) << std::endl;
	P("");
	rit = vct.rbegin();
	std::cout << "rbegin() : " << *rit << std::endl;
	std::cout << "rbegin() + 3 : " << *(rit + 3) << std::endl;
	P("");
	rit = vct.rend();
	--rit;
	std::cout << "--rend() : " << *rit << std::endl;
	std::cout << "rend() - 2 : " << *(rit - 2) << std::endl;
}


/*
** Capacity
*/
void	test_vct_size()
{
	ft::vector<int> vct;

	print_title("Size");
	std::cout << "      Size vct vide : " << vct.size() << std::endl;
	vct.insert(vct.end(), (size_t)5, 100);
	std::cout << "insert 5x 100, size : " << vct.size() << std::endl;
	std::cout << "        Clear, size : " << vct.size() << std::endl;
}

void	test_vct_max_size()
{
	ft::vector<int> vct;
	std::vector<int> rvct;

	print_title("Max Size");
	std::cout << "ma max size : " << vct.max_size() << std::endl;
	std::cout << "vr max size : " << rvct.max_size() << std::endl;
}

void	test_vct_resize()
{
	ft::vector<int> vct;

	print_title("Resize");
	std::cout << "Size : " << vct.size() << std::endl;
	vct.resize(5);
	std::cout << "vct.resize(5), size : " << vct.size() << std::endl;
	print_vector(vct);
	vct.resize(2);
	std::cout << "vct.resize(2), size : " << vct.size() << std::endl;
	print_vector(vct);
	vct.resize(7, 19);
	std::cout << "vct.resize(7, 19), size : " << vct.size() << std::endl;
	print_vector(vct);
}

void	test_vct_capacity()
{
	ft::vector<int> vct;

	print_title("Capacity");
	std::cout << "Capacity : " << vct.capacity() << std::endl;
	vct.reserve(10);
	std::cout << "vct.reserve(10), Capacity : " << vct.capacity() << std::endl;
	vct.insert(vct.end(), 12);
	vct.reserve(40);
	P("vct.insert(vct.end(), 12); vct.reserve(40);");
	std::cout << "Capacity : " << vct.capacity() << std::endl;
	std::cout << "size : " << vct.size() << std::endl;
}

void	test_vct_empty()
{
	ft::vector<int> vct;

	print_title("Empty");
	std::cout << "Empty ? " << vct.empty() << std::endl;
	vct.insert(vct.end(), 12);
	std::cout << "Empty ? " << vct.empty() << std::endl;
	vct.clear();
	std::cout << "Empty ? " << vct.empty() << std::endl;
}

void	test_vct_reserve()
{
	print_title("Reserve");
	P("Go to capacity tests");
}

/*
** Element access
*/

void	test_vct_elem_access()
{
		ft::vector<int> vct;

		print_title("Operator [] / at / front / back");
		vct.insert(vct.end(), 19);
		vct.insert(vct.end(), 21);
		vct.insert(vct.end(), 36);
		vct.insert(vct.end(), 42);
		vct.insert(vct.end(), 56);
		print_vector(vct);

		std::cout << "vct[0] : " << vct[0] << std::endl;
		std::cout << "vct[3] : " << vct[3] << std::endl;

		std::cout << "at(1) : " << vct.at(1) << std::endl;
		std::cout << "at(4) : " << vct.at(4) << std::endl;
		try
		{
			std::cout << "at(5) : " << vct.at(5) << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		P("");
		std::cout << "Front : " << vct.front() << std::endl;
		std::cout << "Back : " << vct.back() << std::endl;
}

/*
** Modifiers
*/
void	test_vct_assign()
{
	ft::vector<int> vct;
	ft::vector<int> vct2;

	print_title("Assign");
	vct.insert(vct.end(), 19);
	vct.insert(vct.end(), 21);
	vct.insert(vct.end(), 36);
	vct.insert(vct.end(), 42);
	vct.insert(vct.end(), 56);
	vct2.insert(vct2.end(), 97);
	vct2.insert(vct2.end(), 206);
	vct2.insert(vct2.end(), 93);
	print_vector(vct, "vct");
	print_vector(vct2, "vct2");
	vct.assign(vct2.begin(), vct2.end());
	P("vct.assign(vct2.begin(), vct2.end());");
	print_vector(vct, "vct");
	std::cout << "Size vct : " << vct.size() << std::endl;

	vct.insert(vct.end(), 19);
	vct.insert(vct.end(), 21);
	vct.insert(vct.end(), 36);
	vct.insert(vct.end(), 42);
	vct.insert(vct.end(), 56);
	P("");
	print_vector(vct, "vct");
	vct.assign((size_t)6, 137);
	P("vct.assign(6, 137);");
	print_vector(vct, "vct");
}

void	test_vct_ppback()
{
	ft::vector<int> vct;

	print_title("Push Back / Pop Back");
	P("Push : ");
	vct.push_back(12);
	vct.push_back(26);
	vct.push_back(63);
	vct.push_back(125);
	print_vector(vct);
	P("Pop 2x");
}

void	test_vct_insert()
{
	ft::vector<int> vct;
	ft::vector<int> vct2;

	print_title("Insert");
	vct.insert(vct.end(), 3);
	print_vector(vct, "vct");

	vct.insert(vct.end(), 19);
	print_vector(vct, "vct");

	vct.insert(vct.begin(), 42);
	print_vector(vct, "vct");
	
	ft::vector<int>::iterator it = vct.begin();
	++it;
	vct.insert(it, 37);
	print_vector(vct, "vct");

	vct.insert(it, (size_t)8, 100);
	print_vector(vct, "vct");

	vct2.insert(vct2.end(), 97);
	vct2.insert(vct2.end(), 206);
	vct2.insert(vct2.end(), 93);
	vct2.insert(vct2.end(), 207);
	vct2.insert(vct2.end(), 13);
	print_vector(vct2, "vct2");
	it = vct.begin();
	++it;

	vct.insert(it, vct2.begin(), vct2.end());
	print_vector(vct, "vct");
}

void	test_vct_clear()
{
	ft::vector<int> vct;

	print_title("Clear");
	vct.clear();
	P("Clear vide");
	vct.insert(vct.end(), (size_t)10, 42);
	print_vector(vct);
	P("Clear");
	vct.clear();
	print_vector(vct);
}
//void	fill_container

void	test_vector()
{

	P("           #################   ITERATORS   #################");
	test_vct_iterators();
	P("");

	P("           #################   CAPACITY   #################");
	test_vct_size();
	P("");
	test_vct_max_size();
	P("");
	test_vct_resize();
	P("");
	test_vct_capacity();
	P("");
	test_vct_empty();
	P("");
	test_vct_reserve();
	P("");

	P("           #################   ELEMENT ACCESS   #################");
	test_vct_elem_access();
	P("");
	
	P("           #################   MODIFIERS   #################");
	test_vct_assign();
	P("");
	test_vct_ppback();
	P("");
	test_vct_insert();
	P("");
	test_vct_clear();
	P("");

}
