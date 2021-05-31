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

# include <stdexcept>
# include "../utils/VectIter.hpp"
# include "../utils/Iterators.hpp"

/*
** TODO
** return error en cas de n qui depasse size etc
** throw des out of range au at etc
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
			clear();
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
		iterator				begin()
		{
			return (iterator(_start));
		}

		const_iterator			begin() const
		{
			return (const_iterator(_start));
		}

		iterator				end()
		{
			return (iterator(_end));
		}
	
		const_iterator			end() const
		{
			return (const_iterator(_end));
		}

		reverse_iterator		rbegin()
		{
			return (reverse_iterator(_end));
		}

		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(_end));
		}
	
		reverse_iterator		rend()
		{
			return (reverse_iterator(_start));
		}

		const_reverse_iterator	rend() const
		{
			return (const_reverse_iterator(_start));
		}

		/*
		** Capacity
		*/
		size_type	size() const
		{
			return (this->_end - this->_start);
		}

		size_type	max_size() const
		{
			return (allocator_type().max_size());
		}

		void		resize (size_type n, value_type val = value_type())
		{
			//if (n > max_size() || size() + n > max_size())
				//return (error jsp quoi);
			if (n < size())
			{
				while (size() > n)
				{
					--_end;
					_alloc.destroy(_end);
				}
			}
			else if (n > size())
			{
				insert(end(), n - size(), val);
			}
		}

		size_type	capacity() const
		{
			return (this->_max_size - this->_start);
		}

		bool		empty() const
		{
			if (size() == 0)
				return (true);
			return (false);
		}

		void		reserve (size_type n)
		{
			//if (n > this->max_size())
				//faire erreur;
			if (n > this->capacity())
			{
				pointer tmp_start = this->_start;
				pointer tmp_i = this->_start;
				pointer tmp_end = this->_end;
				size_t tmp_max_size = this->capacity();

				this->_start = _alloc.allocate(n); //new value_type[n];
				this->_end = this->_start;
				while (tmp_i != tmp_end)
				{
					_alloc.construct(_end, *tmp_i);
					tmp_i++;
					_end++;
				}
				_max_size = _start + n;
				_alloc.deallocate(tmp_start, tmp_max_size);
			}
		}

		/*
		** Elements access
		*/
		reference		operator[] (size_type n)
		{
			return (*(_start + n));
		}

		const_reference	operator[] (size_type n) const
		{
			return (*(_start + n));
		}

		reference		at (size_type n)
		{
			if (n >= size())
				throw std::out_of_range("Out of range");
			return (*(_start + n));
		}
		const_reference	at (size_type n) const
		{
			if (n >= size())
				throw std::out_of_range("Out of range");
			return (*(_start + n));
		}

		reference		front()
		{
			return (*_start);
		}

		const_reference	front() const
		{
			return (*_start);
		}

		reference back()
		{
			return (*(_end - 1));
		}

		const_reference back() const
		{
			return (*(_end - 1));
		}

		/*
		** Modifiers
		*/
		template <class InputIterator>
  		void		assign (InputIterator first, InputIterator last)
		{
			clear();
			insert(end(), first, last);
		}

		void		assign (size_type n, const value_type& val)
		{
			clear();
			insert(end(), n, val);
		}

		void push_back (const value_type& val)
		{
			insert(end(), val);
		}

		void pop_back()
		{
			erase(--(end()));
		}

		iterator	insert (iterator position, const value_type& val)
		{
			if (_end == _max_size)
			{
				int last_pos = &(*position) - _start;
				reserve(capacity() == 0 ? 1 : capacity() * 2);
				position = iterator(_start + last_pos);
			}
			iterator itend = end();
			++_end;
			if (itend != position)
			{
				while (itend != position)
				{
					--itend;
					_alloc.construct(&(*(itend + 1)), *itend);
				}
			}
			_alloc.construct(&(*itend), val);
			return (itend);
		}
		
   		void		insert (iterator position, size_type n, const value_type& val)
		{
			/*if (_end + n >= _max_size)
			{
				int last_pos = &(*position) - _start;
				reserve(capacity() == 0 ? 1 : capacity() * 2);
				position = iterator(_start + last_pos);
			}*/
			while (n > 0)
			{
				--n;
				position = insert(position, val);
			}
		}

		template <class InputIterator>
			void	insert (iterator position, InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				insert(position, *first);
				++position;
				++first;
			}
		}

		iterator	erase (iterator position)
		{
			pointer	tmp = &(*position);
			
			_alloc.destroy(&(*position));
			while (tmp + 1 != _end)
			{
				_alloc.construct(&(*tmp), *(&(*tmp) + 1));
				_alloc.destroy(&(*tmp) + 1);
				++tmp;
			}
			//_alloc.destroy(_end);
			--_end;
			return (position);
		}

		iterator	erase (iterator first, iterator last)
		{
			iterator tmp = first;
	
			while (first != last)
			{
				tmp = erase(tmp);
				++first;
			}
			return (tmp);
		}

		void swap (vector& x)
		{
			P("Not implemented ahah");
		}

		void		clear()
		{
			size_t i = size();
			while (i > 0)
			{
				--i;
				--_end;
				_alloc.destroy(_end);
			}
		}

	private:
		allocator_type	_alloc;
		pointer			_start;
		pointer			_end;
		pointer			_max_size;

};

} // end namespace ft

#endif