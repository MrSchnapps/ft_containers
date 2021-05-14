/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: judecuyp <judecuyp@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 11:50:09 by judecuyp          #+#    #+#             */
/*   Updated: 2021/05/11 11:50:09 by judecuyp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __VECTOR_HPP__
# define __VECTOR_HPP__

# include "../utils/VectIter.hpp"
# include "../utils/Iterators.hpp"

/*
** TODO
** Check pour return end() si ya rien de retourner _start
*/

namespace ft
{

template < class T, class Alloc = std::allocator<T> > 
class vector
{
	public:
		/*
		** Member types
		*/
		typedef T											value_type;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
		typedef ft::VectIter<value_type>					iterator;
		typedef ft::VectIter<const value_type>				const_iterator;	
		typedef ft::reverse_iterator<iterator>				reverse_iterator;	
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;
		typedef ft::iterator_traits<iterator>				difference_type;
		typedef size_t										size_type;

		/*
		** Constructor - Destructor - Copy
		*/
		explicit vector (const allocator_type& alloc = allocator_type())
		:	_alloc(alloc),
			_start(NULL),
			_end(NULL),
			_max_size(NULL)
		{
			
		}

		/*explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())
		:	_alloc(alloc),
			_start(NULL),
			_end(NULL),
			_max_size(NULL)
		{

		}
							
		template <class InputIterator>
				vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
		:	_alloc(alloc),
			_alloc(alloc),
			_start(NULL),
			_end(NULL),
			_max_size(NULL)
		{

		}

		vector (const vector& x)
		:	_alloc(alloc),
			_alloc(alloc),
			_start(NULL),
			_end(NULL),
			_max_size(NULL)
		{

		}*/

		~vector()
		{
			_alloc.deallocate(_start, capacity());
			//delete [] _start;
		}

		vector& operator= (const vector& x)
		{
			if (x == *this)
				return (*this);
			//this->clear();
			//this->insert(this->end(), x.begin(), x.end());
			return (*this);
		}

		/*
		** Iterators
		*/
		iterator begin()
		{
			return (iterator(_start));
		}

		const_iterator begin() const
		{
			return (const_iterator(_start));
		}

		iterator end()
		{
			return (iterator(_end));
		}
	
		const_iterator end() const
		{
			return (const_iterator(_end));
		}

		reverse_iterator rbegin()
		{
			return (reverse_iterator(_end));
		}

		const_reverse_iterator rbegin() const
		{
			return (const_reverse_iterator(_end));
		}
	
		reverse_iterator rend()
		{
			return (reverse_iterator(_start));
		}

		const_reverse_iterator rend() const
		{
			return (const_reverse_iterator(_start));
		}

		/*
		** Capacity
		*/
		size_type size() const
		{
			return (this->_end - this->_start);
		}

		size_type max_size() const
		{
			return (allocator_type().max_size());
		}

		size_type capacity() const
		{
			return (this->_max_size - this->_start);
		}

		void reserve (size_type n)
		{
			//if (n > this->max_size())
				//faire erreur;
			if (n > this->capacity())
			{
				pointer tmp_start = this->_start;
				pointer tmp_i = this->_start;
				pointer tmp_end = this->_end;
				size_t tmp_max_size = this->capacity();

				this->_start = _alloc.allocate(n);//new value_type[n];
				this->_end = this->_start;
				while (tmp_i != tmp_end)
				{
					*_end = *tmp_i;
					tmp_i++;
					_end++;
				}
				_max_size = _start + n;
				//delete [] tmp_start;$
				_alloc.deallocate(tmp_start, tmp_max_size);
			}
		}



		/*
		** Elements access
		*/

		/*
		** Modifiers
		*/

		iterator insert (iterator position, const value_type& val)
		{
			if (n == 0)
				return ;
		}
		
   		void insert (iterator position, size_type n, const value_type& val);

		template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last);
	
	private:
		allocator_type	_alloc;
		pointer			_start;
		pointer			_end;
		pointer			_max_size;

};

} // end namespace ft

#endif