/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:46 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/19 17:29:29 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <limits>

const float		BitcoinExchange::kValueLimitUpper = 1000;
const float		BitcoinExchange::kValueLimitLower = 0;

const int		BitcoinExchange::Date::kMonthRange[12] = {
	31,
	28,
	31,
	30,
	31,
	30,
	31,
	31,
	30,
	31,
	30,
	31
};

BitcoinExchange::BitcoinExchange()
	: c_()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
	: c_(other.c_)
{}

BitcoinExchange::~BitcoinExchange()
{}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& other)
{
	if (this != &other)
	{
		c_ = other.c_;
	}
	return *this;
}

void	BitcoinExchange::addIndex(const std::string& date, float value)
{
	Date	tmp_date(date);

	if (value < kValueLimitLower)
		throw ValueTooSmall();
	else if (value > kValueLimitUpper)
		throw ValueTooLarge();

	c_.insert(std::pair<Date,float>(tmp_date, value));
}

std::map<BitcoinExchange::Date, float>::const_iterator	BitcoinExchange::getClosestDate(Date date) const
{
	for (std::map<Date,float>::const_iterator it = c_.begin(); it != c_.end(); ++it)
	{
		std::cout << it->first << ':' << it->second << ' ';
	}
	std::cout << std::endl;
}

std::size_t	BitcoinExchange::size() const
{
	return c_.size();
}

const char* BitcoinExchange::ValueTooLarge::what() const throw()
{
	return "Value too large";
}

const char* BitcoinExchange::ValueTooSmall::what() const throw()
{
	return "Value too small";
}

const char* BitcoinExchange::InvalidSyntax::what() const throw()
{
	return "Invalid syntax";
}

BitcoinExchange::Date::Date()
	: year_(2008), month_(8), day_(31) // FIX !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
{

}

BitcoinExchange::Date::Date(const std::string& date)
{
	
}

BitcoinExchange::Date::Date(const Date& other)
	: year_(other.year_), month_(other.month_), day_(other.day_)
{
}

BitcoinExchange::Date&	BitcoinExchange::Date::operator=(const Date& other)
{
	if (this != &other)
	{
		year_ = other.year_;
		month_ = other.month_;
		day_ = other.day_;
	}
	return *this;
}

bool	BitcoinExchange::Date::operator==(const Date& other) const
{
	if (year_ != other.year_)
		return false;
	else if (month_ != other.month_)
		return false;
	else if (day_ != other.day_)
		return false;
	return true;
}

bool	BitcoinExchange::Date::operator<(const Date& other) const
{
	if (year_ >= other.year_)
		return false;
	else if (month_ >= other.month_)
		return false;
	else if (day_ >= other.day_)
		return false;
	return true;
}

bool	BitcoinExchange::Date::operator>(const Date& other) const
{
	if (year_ <= other.year_)
		return false;
	else if (month_ <= other.month_)
		return false;
	else if (day_ <= other.day_)
		return false;
	return true;
}

unsigned int	BitcoinExchange::Date::getYear() const
{
	return year_;
}

unsigned int	BitcoinExchange::Date::getMonth() const
{
	return month_;
}

unsigned int	BitcoinExchange::Date::getDay() const
{
	return day_;	
}

const char* BitcoinExchange::Date::InvalidDate::what() const throw()
{
	return "date is invalid";
}

std::ostream&	operator<<(std::ostream& out, BitcoinExchange::Date date)
{
	out << date.getYear() << '-'
		<< date.getMonth() << '-'
		<< date.getDay();
}
