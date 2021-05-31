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
** Constructors etc
*/

void	test_vct_construct()
{
	ft::vector<int> vct;

	vct.insert(vct.begin(), (size_t)4, 100);
	print_vector(vct, "vct vide : vct.insert(vct.begin(), (size_t)4, 100);");

	ft::vector<int> vct2((size_t)7, 19);
	print_vector(vct2, "vct(7, 19)");

	ft::vector<int> vct3(vct2.begin(), vct2.end());
	print_vector(vct3, "vct(first, last)");



	ft::vector<int> vct4;

	//vct4.push_back(4);
	//vct4.push_back(5);
	ft::vector<int>::iterator it = vct4.begin();


	vct4.insert(it, vct.begin(), vct.end());
//	ft::vector<int> vct4(vct3);
	print_vector(vct4, "vct(autre vct)");

/*	std::vector<int> vct41;
	std::vector<int> vct21((size_t)7, 19);

	vct41.insert(vct41.begin(), vct21.begin(), vct21.end());*/
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

	P("");
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.resize(10, "test");
	v2.resize(10, "test");

	check("v1 == v2", (v1 == v2));
	v1.resize(2, "42");
	v2.resize(2, "42");
	check("v1 == v2", (v1 == v2));
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

	std::string test[] = {"Hey", "what's", "up", "?"};
	ft::vector<std::string> v1;
	ft::vector<std::string> s1;
	std::vector<std::string> v2;
	std::vector<std::string> s2;
	v1.assign(s1.begin(), s1.end());
	v2.assign(s2.begin(), s2.end());
	check("v1 == v2", v1 == v2);
	v1.assign(5, "?");
	v2.assign(5, "?");
	check("v1 == v2", v1 == v2);
	//print_vector(v1);
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
	vct.pop_back();
	vct.pop_back();
	print_vector(vct);
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
	//++it;

	vct.insert(it, vct2.begin(), vct2.end());
	print_vector(vct, "vct(begin, end)");
}

void	test_vct_erase()
{
	ft::vector<int> vct;

	print_title("Erase");
	vct.insert(vct.end(), 97);
	vct.insert(vct.end(), 206);
	vct.insert(vct.end(), 93);
	vct.insert(vct.end(), 207);
	vct.insert(vct.end(), 13);
	vct.insert(vct.end(), 14);
	vct.insert(vct.end(), 190);
	print_vector(vct);
	
	ft::vector<int>::iterator it = vct.end();
	--it;
	vct.erase(it);
	print_vector(vct);

	it = vct.begin();
	++it;
	ft::vector<int>::iterator it2 = vct.begin();
	++it2;
	++it2;
	++it2;
	++it2;
	vct.erase(it, it2);
	print_vector(vct);
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
	ft::vector<std::string> v1;
	std::vector<std::string> v2;
	v1.push_back("1");
	v2.push_back("1");
	v1.push_back("2");
	v2.push_back("2");
	v1.push_back("3");
	v2.push_back("3");
	v1.erase(v1.begin() + 2);
	v2.erase(v2.begin() + 2);
	check("v1 == v2", v1 == v2);
	v1.clear();
	v2.clear();
	check("v1 == v2", v1 == v2);
}

void	test_vct_swap()
{
	ft::vector<int> vct1((size_t)5, 7);
	ft::vector<int> vct2((size_t)9, 19);

	print_vector(vct1, "VCT1");
	print_vector(vct2, "VCT2");

	P("SWAP");
	vct1.swap(vct2);
	print_vector(vct1, "VCT1");
	print_vector(vct2, "VCT2");

	ft::vector<int>::iterator it = vct1.begin(); 
	ft::vector<int>::iterator itend = vct1.end();
	
	P("SWAP");
	vct1.swap(vct2);
	while (it != itend)
	{
		std::cout << *it << std::endl;
		++it;
	}
}

void	test_vct_op()
{
	ft::vector<int> vct1((size_t)5, 7);
	ft::vector<int> vct2((size_t)5, 7);

	print_vector(vct1, "VCT1");
	print_vector(vct2, "VCT2");
	P("vct1 == vct2 : ");
	if (vct1 == vct2)
	{
		std::cout << "Same" << std::endl;
	}
}

void	test_vector()
{
	P("           #################   CONSTRUCTORS   #################");
	test_vct_construct();
	P("");
	/*P("           #################   ITERATORS   #################");
	test_vct_iterators();
	P("");

	P("           #################   CAPACITY   #################");
	test_vct_size();
	P("");
	test_vct_max_size();
	P("");*/
	//test_vct_resize();
	//P("");
	/*test_vct_capacity();
	P("");
	test_vct_empty();
	P("");
	test_vct_reserve();
	P("");

	P("           #################   ELEMENT ACCESS   #################");
	test_vct_elem_access();
	P("");
	
	P("           #################   MODIFIERS   #################");*/
	//test_vct_assign();
	//P("");
	//test_vct_ppback();
	//P("");
	//test_vct_insert();
	//P("");
	//test_vct_erase();
	//P("");
	//test_vct_clear();
	//P("");
	test_vct_swap();
	P("");
	test_vct_op();
	P("");
}
