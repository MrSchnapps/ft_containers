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

void test_map()
{
	P("           &&&&&&&&&&&&&&&&&   MAP   &&&&&&&&&&&&&&&&&");
	P("           #################   CONSTRUCTORS   #################");
	test_map_construct();
	P("");
	test_map_insert();
	P("");
}