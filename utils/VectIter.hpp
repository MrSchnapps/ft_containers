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

	/*
	** Constructot - Destructor - Copy
	*/
	VectIter()
	:	_tab(NULL)
	{}

	VectIter(pointer tab)
	:	_tab(tab)
	{}

	VectIter(const VectIter &cpy)
	:	_tab(cpy._tab)
	{}

	virtual ~VectIter() {}

	VectIter operator=(const VectIter &op)
	{
		if (this == &op)
			return (*this);
		this->_tab = op._tab;
		return (*this);
	}

	/*
	** Operators
	*/
		reference	operator*() const {return (*_tab);}

		pointer		operator->()
		{
			return (&(this->operator*()));
		}
		
		VectIter&	operator++()
		{
			++_tab;
			return (*this);
		}

		VectIter	operator++(int)
		{
			VectIter tmp(*this);
			operator++();
			return (tmp);
		}

		VectIter&	operator--()
		{
			--_tab;
			return (*this);
		}

		VectIter	operator--(int)
		{
			VectIter tmp(*this);
			operator--();
			return (tmp);
		}

		VectIter	operator+(difference_type n) const
		{
			return (_tab + n);
		}

		VectIter	operator-(difference_type n) const
		{
			return (_tab - n);
		}

		VectIter	operator+=(difference_type n) const
		{
			_tab += n;
			return (*this);
		}

		VectIter	operator-=(difference_type n) const
		{
			_tab -= n;
			return (*this);
		}

		VectIter	operator[](difference_type n) const
		{
			return (*(operator+(n)));
		}

		operator VectIter<const T> () const
		{
			return (VectIter<const T>(this->_tab));
		}

		friend bool operator==(const VectIter<T> &it1, const VectIter<T> &it2)
		{
			return (it1 == it2);
		}

		friend bool operator!=(const VectIter<T> &it1, const VectIter<T> &it2)
		{
			return (it1._elem != it2._elem);
		}

	private:
		pointer _tab;

};

} //end namespace

#endif