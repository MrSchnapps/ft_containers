/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:33:18 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/13 18:06:12 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.hpp"

int main(int argc, char **argv)
{
	std::string test;
	size_t		i = 0;

	if (argc < 2)
	{
		std::cout << "Unkown command" << std::endl;
		return (1);
	}

	test = argv[1];
	while (i < test.size())
	{
		test[i] = tolower(test[i]);
		++i;
	}

	if (test == "all")
	{
		test_list();
		test_stack();
		test_vector();
		test_queue();
	}
	else if (test == "list")
		test_list();
	else if (test == "stack")
		test_stack();
	else if (test == "vector")
		test_vector();
	else if (test == "queue")
		test_queue();
	else if (test == "map")
		test_map();
	else
	{
		std::cout << "Unkown command" << std::endl;
		return (1);
	}
	return (0);
}
