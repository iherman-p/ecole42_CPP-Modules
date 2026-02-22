/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 17:20:44 by iherman-          #+#    #+#             */
/*   Updated: 2026/02/22 22:57:34 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <map>
#include <string>

class BitcoinExchange
{
	public:
		class Date;

	private:
		std::map<Date, float>	c_;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		~BitcoinExchange();

		BitcoinExchange&	operator=(const BitcoinExchange& other);

		void	addIndex(const std::string& date, float value);

		std::map<Date, float>::const_iterator	getClosestDate(Date date) const;
		std::size_t								size() const;

		class	ValueTooLarge : public std::exception
		{
			virtual const char* what() const throw();
		};

		class	ValueTooSmall : public std::exception
		{
			virtual const char* what() const throw();
		};

		class Date
		{
			private:
				const static int		kMonthRange[12];

				unsigned int	year_;
				unsigned int	month_;
				unsigned int	day_;
			public:
				Date();
				Date(const std::string& date);
				Date(const Date& other);

				Date&	operator=(const Date& other);

				bool	operator==(const Date& other) const;
				bool	operator<(const Date& other) const;
				bool	operator>(const Date& other) const;

				unsigned int	getYear() const;
				unsigned int	getMonth() const;
				unsigned int	getDay() const;

				class	InvalidDate : public std::exception
				{
					virtual const char* what() const throw();
				};
		};
};

std::ostream&	operator<<(std::ostream& out, BitcoinExchange::Date date);

#endif // BITCOINEXCHANGE_HPP