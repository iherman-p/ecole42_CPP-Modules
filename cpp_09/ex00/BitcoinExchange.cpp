/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:46 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/22 22:54:57 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <limits>
#include <cerrno>

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

	if (value < 0)
		throw ValueTooSmall();
	//else if (value > kValueLimitUpper)
		//throw ValueTooLarge();

	c_.insert(std::pair<Date,float>(tmp_date, value));
}

std::map<BitcoinExchange::Date, float>::const_iterator	BitcoinExchange::getClosestDate(Date date) const
{
	std::map<Date,float>::const_iterator it = c_.upper_bound(date);

	if (it == c_.begin())
		return it;

	--it;
	return it;
}

std::size_t	BitcoinExchange::size()  const
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

BitcoinExchange::Date::Date()
	: year_(2008), month_(8), day_(kMonthRange[7])
{
}

static unsigned int parseString(const char* start, char** end, unsigned long limit_upper, char accept = '-')
{
	unsigned long	value;

	errno = 0;
	value = std::strtoul(start, end, 10);
	if (errno == ERANGE || value > limit_upper || value < 1 || **end != accept)
		throw BitcoinExchange::Date::InvalidDate();

	(*end)++;
	return static_cast<unsigned int>(value);
}

BitcoinExchange::Date::Date(const std::string& date)
{
	char*	end;

	year_ = parseString(date.c_str(), &end, std::numeric_limits<unsigned int>::max());

	char*	start = end;
	month_ = parseString(start, &end, 12);

	start = end;
	day_ = parseString(start, &end, kMonthRange[month_ - 1], '\0');
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
	return out;
}
