/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mapiter.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:51:55 by judecuyp          #+#    #+#             */
/*   Updated: 2021/06/07 20:51:55 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MAPITER_HPP__
# define __MAPITER_HPP__

# include "Utils.hpp"
# include "Iterators.hpp"

namespace ft
{

template <class T>
class MapIter : public ft::Iterator<ft::bidirectionnal_iterator_tag, T>
{
	public:
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::value_type			value_type;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::difference_type		difference_type;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::reference			reference;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::pointer				pointer;
		typedef typename ft::Iterator<ft::bidirectionnal_iterator_tag, T>::iterator_category	iterator_category;

	BST_List<T, V> *_elem;

	MapIter () {}

	~MapIter() {}
};

} // End namespace ft
#endif