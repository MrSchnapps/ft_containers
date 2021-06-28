/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 23:42:00 by judecuyp          #+#    #+#             */
/*   Updated: 2021/06/09 23:42:00 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

/*
** constructor copy etc
*/

template <class Key, class Val>
void print_map_values(ft::map<Key, Val> &m, std::string name)
{
	typename ft::map<Key, Val>::iterator it = m.begin();

	std::cout << "     ***** Variable name : " << name << std::endl;
	while (it != m.end())
	{
		std::cout << "Key [" << it->first << "]   <>   Value : |" << it->second << "|" << std::endl;
		++it;
	}
}

void insert_map_values(ft::map<int, std::string> &m)
{
	m.insert(ft::pair<int, std::string>(1, "Julou"));
	m.insert(ft::pair<int, std::string>(2, "julou22"));
	m.insert(ft::pair<int, std::string>(6, "six"));
	m.insert(ft::pair<int, std::string>(8, "mathildou"));
	m.insert(ft::pair<int, std::string>(10, "olaaa"));
	m.insert(ft::pair<int, std::string>(7, "bjr"));
}

void    test_map_construct()
{
	P("           #################   CONSTRUCTORS   #################");
	ft::map<int, std::string> m;

	ft::map<int, std::string>::iterator it;

	// m.insert(ft::pair<int, std::string>(1, "Julou"));
	// m.insert(ft::pair<int, std::string>(2, "julou22"));
	// m.insert(ft::pair<int, std::string>(6, "six"));
	// m.insert(ft::pair<int, std::string>(8, "mathildou"));
	// m.insert(ft::pair<int, std::string>(10, "olaaa"));
	// m.insert(ft::pair<int, std::string>(7, "bjr"));

	insert_map_values(m);

	it = m.begin();
	while (it != m.end())
	{
		std::cout << "Key [" << it->first << "]   <>   Value : |" << it->second << "|" << std::endl;
		++it;
	}

	std::cout << std::endl;

	ft::map<int, std::string> m2(m.begin(), m.end());
	ft::map<int, std::string>::iterator it2 = m2.begin();
	while (it2 != m2.end())
	{
		std::cout << "Key [" << it2->first << "]   <>   Value : |" << it2->second << "|" << std::endl;
		++it2;
	}

	std::cout << std::endl;

	ft::map<int, std::string> m3(m);
	ft::map<int, std::string>::iterator it3 = m3.begin();
	while (it3 != m3.end())
	{
		std::cout << "Key [" << it3->first << "]   <>   Value : |" << it3->second << "|" << std::endl;
		++it3;
	}
}

void	test_map_insert()
{
	P("           #################   INSERT   #################");
	ft::map<int, std::string> m;
	ft::map<int, std::string> m2;
	
	insert_map_values(m);
	print_map_values(m, "m");

	ft::map<int, std::string>::iterator it = m.begin();
	++it;
	++it;
	m2.insert(it, m.end());
	print_map_values(m2, "m2");

	ft::map<int, std::string>::iterator it2 = m2.begin();
	++it2;
	++it2;
	m2.insert(it2, ft::pair<int, std::string>(9, "JulouTwo"));
	print_map_values(m2, "m2");
	m2.insert(it2, ft::pair<int, std::string>(9, "JulouTwo"));
	print_map_values(m2, "m2");
}

void	test_map_capacity()
{
	P("           #################   CAPACITY   #################");
	ft::map<int, std::string> m;

	std::cout << "Empty ? " << (m.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Size : " << m.size() << std::endl;
	insert_map_values(m);
	std::cout << "Empty ? " << (m.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Size : " << m.size() << std::endl;
	m.clear();
	std::cout << "Empty ? " << (m.empty() ? "Yes" : "No") << std::endl;
	std::cout << "Size : " << m.size() << std::endl;

	std::cout << "Max size :" << m.max_size() << std::endl;
	
	// P("")
	// std::map<int, std::string> m2;

	// std::cout << "Empty ? " << (m2.empty() ? "Yes" : "No") << std::endl;
	// std::cout << "Size : " << m2.size() << std::endl;
	// m2.insert(std::pair<int, std::string>(1, "Julou"));
	// m2.insert(std::pair<int, std::string>(2, "julou22"));
	// m2.insert(std::pair<int, std::string>(6, "six"));
	// m2.insert(std::pair<int, std::string>(8, "mathildou"));
	// m2.insert(std::pair<int, std::string>(10, "olaaa"));
	// m2.insert(std::pair<int, std::string>(7, "bjr"));
	// std::cout << "Empty ? " << (m2.empty() ? "Yes" : "No") << std::endl;
	// std::cout << "Size : " << m2.size() << std::endl;
	// m2.clear();
	// std::cout << "Empty ? " << (m2.empty() ? "Yes" : "No") << std::endl;
	// std::cout << "Size : " << m2.size() << std::endl;

	// std::cout << "Max size :" << m2.max_size() << std::endl;
}

void	test_map_elements_access()
{
	P("           #################   ELEMENTS ACCESS   #################");

	ft::map<int, std::string> m;

	//insert_map_values(m);
	m[2] = "test1";
	//std::cout << "ICI2" << std::endl;
	m[4] = "test2";
	m[3] = "test3";

	std::cout << "Elem[2] = " << m[2] << std::endl;
	std::cout << "Elem[4] = " << m[4] << std::endl; 
	std::cout << "Elem[3] = " << m[3] << std::endl;
	print_map_values(m, "m");
	m[2] = "Nouveau Test";
	std::cout << "Elem[2] = " << m[2] << std::endl;

}

void	test_map_erase()
{
	P("           #################   ERASE   #################");
	ft::map<int, std::string> m;
	insert_map_values(m);

	print_map_values(m, "m");
	ft::map<int, std::string>::iterator it = m.begin();
	++it;
	++it;
	m.erase(it);
	print_map_values(m, "m");
	m.erase(10);
	print_map_values(m, "m");
	it = m.begin();
	ft::map<int, std::string>::iterator it2 = m.end();
	--it2;
	m.erase(it, it2);
	print_map_values(m, "m");
}

void test_map_swap()
{
	P("           #################   SWAP   #################");
	ft::map<int, std::string> m;
	insert_map_values(m);

	ft::map<int, std::string> m2;
	m2.insert(ft::pair<int, std::string>(42, "JUl"));
	m2.insert(ft::pair<int, std::string>(19, "Bobobo"));

	print_map_values(m, "m");
	print_map_values(m2, "m2");
	m.swap(m2);
	print_map_values(m, "m");
	print_map_values(m2, "m2");
}

void 	test_map_observers()
{
	P("           #################   OBSERVERS   #################");

	ft::map<int, std::string> m;
	insert_map_values(m);

	ft::map<int, std::string>::key_compare cmp = m.key_comp();
	ft::map<int, std::string>::iterator it = m.begin();
	ft::map<int, std::string>::iterator it2 = m.end();
	--it2;
	--it2;
	while (cmp(it->first, 7) && it != m.end())
	{
		std::cout << "Key [" << it->first << "]   <>   Value : |" << it->second << "|" << std::endl;
		++it;
	}
}

void	test_map_operations()
{
	P("           #################   OPERATIONS   #################");
	ft::map<int, std::string> m;
	insert_map_values(m);

	ft::map<int, std::string>::iterator it = m.find(2);
	std::cout << "find(2) --> Key [" << it->first << "]   <>   Value : |" << it->second << "|" << std::endl;
	it = m.find(3);
	if (it == m.end())
		std::cout << "find(3) --> Not Found." << std::endl;

	if (m.count(2))
		std::cout << "count(2) --> Found." << std::endl;
	else
		std::cout << "count(2) --> Not Found." << std::endl;
	if (m.count(3))
		std::cout << "count(3) --> Found." << std::endl;
	else
		std::cout << "count(3) --> Not Found." << std::endl;

	it = m.lower_bound(5);
	std::cout << "m.lower_bound(5) --> Key [" << it->first << "]   <>   Value : |" << it->second << "|" << std::endl;
	it = m.upper_bound(6);
	std::cout << "m.upper_bound(6) --> Key [" << it->first << "]   <>   Value : |" << it->second << "|" << std::endl;

	//P("COUCOUUUUUUUUUUUUUUUUUUUUUUUUU");
	ft::pair<ft::map<int, std::string>::iterator, ft::map<int, std::string>::iterator> ret;
	ret = m.equal_range(6);
	std::cout << "equal_range(6).first --> Key [" << ret.first->first << "]   <>   Value : |" << ret.first->second << "|" << std::endl;
	std::cout << "equal_range(6).second --> Key [" << ret.second->first << "]   <>   Value : |" << ret.second->second << "|" << std::endl;

	ret = m.equal_range(19);
	if (ret.first == m.end())
		std::cout << "equal_range(19).first --> Not Found." << std::endl;
	else
		std::cout << "equal_range(19).first --> Key [" << ret.first->first << "]   <>   Value : |" << ret.first->second << "|" << std::endl;
	if (ret.second == m.end())
		std::cout << "equal_range(19).second --> Not Found." << std::endl;
	else
		std::cout << "equal_range(19).second --> Key [" << ret.second->first << "]   <>   Value : |" << ret.second->second << "|" << std::endl;

}

void	test_map()
{
	P("           &&&&&&&&&&&&&&&&&   MAP   &&&&&&&&&&&&&&&&&");
	
	test_map_construct();
	P("");
	
	test_map_insert();
	P("");
	
	test_map_capacity();
	P("");
	
	test_map_elements_access();
	P("");

	test_map_elements_access();
	P("");

	test_map_erase();
	P("");

	test_map_swap();
	P("");

	test_map_observers();
	P("");

	test_map_operations();
	P("");
}