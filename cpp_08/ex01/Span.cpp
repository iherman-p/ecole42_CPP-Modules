/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:45:07 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/12 16:08:04 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span()
	: elements_(),
		maxElements_(0)
{
}

Span::Span(const Span& other)
	: elements_(other.elements_),
		maxElements_(other.maxElements_)
{
	
}

Span::Span(std::size_t n)
	: elements_(),
		maxElements_(n)
{
	elements_.reserve(n);
}

Span::~Span()
{
}

Span&	Span::operator=(const Span& other)
{
	if (this != &other)
	{
		maxElements_ = other.maxElements_;
		elements_ = other.elements_;
	}
	return *this;
}

void	Span::addNumber(int n)
{
	if (elements_.size() == maxElements_)
		throw MaxElementsReached();
	elements_.push_back(n);
}

unsigned int	Span::shortestSpan()
{
	if (elements_.size() <= 1)
	{
		throw InsufficientElements();
	}

	unsigned int		min_span;
	std::vector<int>	sorted(elements_);

	std::sort(sorted.begin(), sorted.end());
	min_span = sorted[1] - sorted[0];
	for (std::size_t i = 2; i < sorted.size(); ++i)
	{
		min_span = std::min(min_span, static_cast<unsigned int>(sorted[i] - sorted[i - 1]));
	}
	return min_span;
}

unsigned int	Span::longestSpan()
{
	int	largest;
	int	smallest;

	if (elements_.size() <= 1)
	{
		throw InsufficientElements();
	}

	largest = elements_[0];
	smallest = elements_[0];
	for (std::size_t i = 1; i < elements_.size(); ++i)
	{
		largest = std::max(largest, elements_[i]);
		smallest = std::min(smallest, elements_[i]);
	}
	return largest - smallest;
}

std::size_t	Span::size()
{
	return elements_.size();
}

std::size_t	Span::maxSize()
{
	return elements_.size();
}

Span::iterator Span::begin()
{
	return elements_.begin();
}

Span::iterator Span::end()
{
	return elements_.end();
}

Span::const_iterator Span::cbegin() const
{
	return elements_.begin();
}

Span::const_iterator Span::cend() const
{
	return elements_.end();
}

Span::reverse_iterator Span::rbegin()
{
	return elements_.rbegin();
}

Span::reverse_iterator Span::rend()
{
	return elements_.rend();
}

Span::const_reverse_iterator Span::crbegin() const
{
	return elements_.rbegin();
}

Span::const_reverse_iterator Span::crend() const
{
	return elements_.rend();
}


const char* Span::MaxElementsReached::what() const throw()
{
	return "Too many elements";
}

const char* Span::InsufficientElements::what() const throw()
{
	return "Insufficient elements";
}
