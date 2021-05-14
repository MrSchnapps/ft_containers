/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VectIter.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 14:09:11 by judecuyp          #+#    #+#             */
/*   Updated: 2021/05/11 14:09:11 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECT_ITER_HPP__
# define __VECT_ITER_HPP__

namespace ft
{

/*
** Random access iterator for vector container
*/
template <class T>
class VectIter : public ft::Iterator<ft::random_access_iterator_tag, T>
{
	public:
	/*
	** Member types
	*/
	typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::value_type		value_type;
	typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::difference_type	difference_type;
	typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::pointer			pointer;
	typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::reference			reference;
	typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::iterator_category	iterator_category;

	VectIter() {}
	~VectIter() {}

};

} //end namespace

#endif