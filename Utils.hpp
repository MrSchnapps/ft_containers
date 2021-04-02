/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 16:17:57 by judecuyp          #+#    #+#             */
/*   Updated: 2021/04/02 15:01:44 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILS_HPP__
# define __UTILS_HPP__

# include <cstddef>

namespace ft
{
template <typename T>
struct DL_List
{
	DL_List *next;
	DL_List *prev;
	T 		val;

	DL_List()
	:	next(NULL),
		prev(NULL)
	{}
};
} //end namespace ft

#endif