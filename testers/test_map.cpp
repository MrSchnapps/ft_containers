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
}


void test_map()
{
    P("           &&&&&&&&&&&&&&&&&   MAP   &&&&&&&&&&&&&&&&&");
    P("           #################   CONSTRUCTORS   #################");
	test_map_construct();
	P("");
}