/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 01:17:47 by judecuyp          #+#    #+#             */
/*   Updated: 2021/05/11 01:17:47 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __TESTER_HPP_
# define __TESTER_HPP_

# include <deque>
# include <stack>
# include <iostream>
# include <string>
# include <list>
# include <vector>
# include <stack>
# include <queue>
# include <map>

# include "../containers/list.hpp"
# include "../containers/stack.hpp"
# include "../containers/vector.hpp"
# include "../containers/queue.hpp"
# include "../containers/map.hpp"

# include "../utils/Iterators.hpp"
# include "../utils/Utils.hpp"
# include "../utils/ListIter.hpp"
# include "../utils/VectIter.hpp"
# include "../utils/MapIter.hpp"

void	test_list();
void	test_stack();
void	test_vector();
void	test_queue();
void	test_map();

template <class T>
void	print_comp(std::string title, T a, T b)
{
	if (!title.empty())
		std::cout << title << std::endl;
	std::cout << "Miens : " << a << std::endl;
	std::cout << "Vraie : " << b << std::endl;
	std::cout << std::endl;
} 
#endif