/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 14:52:19 by judecuyp          #+#    #+#             */
/*   Updated: 2021/05/28 14:58:27 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/Utils.hpp"

/*
** Printers
*/
template <class T>
void	print_queue(ft::vector<T> &vct, std::string name="")
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
