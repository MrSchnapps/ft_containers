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

void    test_map_construct()
{
    ft::map<int, std::string> m;

    ft::map<int, std::string>::iterator it;

    m.insert(std::pair<int, std::string>(1, "Julou"));
    m.insert(std::pair<int, std::string>(2, "julou22"));
    m.insert(std::pair<int, std::string>(6, "six"));
    m.insert(std::pair<int, std::string>(8, "mathildou"));
    m.insert(std::pair<int, std::string>(10, "olaaa"));
    m.insert(std::pair<int, std::string>(7, "bjr"));

    it = m.begin();
    while (it != m.end())
    {
        std::cout << "Key [" << it->first << "]   <>   Value : |" << it->second << "|" << std::endl;
        ++it;
    }

}


void test_map()
{
    P("           &&&&&&&&&&&&&&&&&   MAP   &&&&&&&&&&&&&&&&&");
    P("           #################   CONSTRUCTORS   #################");
	test_map_construct();
	P("");
}