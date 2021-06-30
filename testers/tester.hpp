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

# define RESET "\e[0m"
# define RED "\e[91m"
# define GREEN "\e[92m"
# define BLUE "\e[94m"
# define BOLD "\e[1m"
# define GOOD "GOOD"
# define FAIL "FAIL"

void	test_list();
void	test_stack();
void	test_vector();
void	test_queue();
void	test_map();

void 	print_header(std::string str);
void 	print_title(std::string str);

template <class T>
void	print_comp(std::string title, T a, T b)
{
	if (!title.empty())
		std::cout << title << std::endl;
	std::cout << "Miens : " << a << std::endl;
	std::cout << "Vraie : " << b << std::endl;
	std::cout << std::endl;
}

template <typename T>
inline void check(std::string name, T a, T b)
{
	std::string margin(24 - name.length(), ' ');
	if (a ==  b)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << BOLD << RED << FAIL << RESET << std::endl;
};

inline void check(std::string name, bool good)
{
	std::string margin(24 - name.length(), ' ');
	if (good)
		std::cout << name << ": " << margin << BOLD << GREEN << GOOD << RESET << std::endl;
	else
		std::cout << name << ": " << margin << BOLD << RED << FAIL << RESET << std::endl;
};

template <typename T>
bool operator==(ft::vector<T> &a, std::vector<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	for (size_t i = 0; i < a.size(); i++)
	{
		if (a[i] != b[i])
		{
			return (false);
		}
	}
	return (true);
};

template <typename T>
bool operator==(ft::list<T> &a, std::list<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::list<T>::iterator it = a.begin();
	typename std::list<T>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (*it != *it2)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

template <typename T>
bool operator==(ft::stack<T> &a, std::stack<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	if (!a.empty())
	{
		if (a.top() != b.top())
			return (false);
	}
	return (true);
};

template <typename T>
bool operator==(ft::queue<T> &a, std::queue<T> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	if (!a.empty())
	{
		if (a.front() != b.front())
			return (false);
		if (a.back() != b.back())
			return (false);
	}
	return (true);
};

template <typename T, typename S>
bool operator==(ft::map<T, S> &a, std::map<T, S> &b)
{
	if (a.size() != b.size())
		return (false);
	if (a.empty() != b.empty())
		return (false);
	typename ft::map<T, S>::iterator it = a.begin();
	typename std::map<T, S>::iterator it2 = b.begin();
	while (it != a.end())
	{
		if (it->first != it2->first || it->second != it2->second)
			return (false);
		++it;
		++it2;
	}
	return (true);
};

#endif