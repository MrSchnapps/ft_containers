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

	if (argc < 2)
	{
		test_list();
		test_stack();
		test_vector();
		return (0);
	}
	test = argv[1];
	if (test == "list")
		test_list();
	else if (test == "stack")
		test_stack();
	else if (test == "vector")
		test_vector();
	else if (test == "queue")
		test_queue();
	return (0);
}
