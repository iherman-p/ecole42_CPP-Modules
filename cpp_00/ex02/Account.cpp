/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iherman- <iherman-@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:34:09 by iherman-          #+#    #+#             */
/*   Updated: 2025/08/04 18:15:43 by iherman-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <string>
#include <iostream>
#include "Account.hpp"

/*/////////////
	Private
*//////////////

int Account::_nbAccounts(0);
int Account::_totalAmount(0);
int Account::_totalNbDeposits(0);
int Account::_totalNbWithdrawals(0);

static std::string	zero_pad_timestamp(std::string str, size_t size)
{
	std::string	whitespace;
	std::string	ret;

	while ((whitespace.size() + str.size()) < size)
		whitespace = whitespace + "0";
	ret = whitespace + str;
	return ret;
}

static std::string	ft_itoa(int num)
{
	std::string ret;
	bool negative;
	char digit;

	if (num == 0) return "0";
	negative = false;
	if (num < 0)
	{
		negative = true;
		num = -num;
	}
	while (num > 0)
	{
		digit = '0' + (num % 10);
		ret = digit + ret;
		num /= 10;
	}
	if (negative)
		ret = "-" + ret;
	return ret;
}

void	Account::_displayTimestamp(void)
{
	const time_t	time_temp = std::time(NULL);
	std::tm *current_time;
	
	current_time = std::localtime(&time_temp);
	std::cout << '['
				<< zero_pad_timestamp(ft_itoa(current_time->tm_year + 1900), 4)
				<< zero_pad_timestamp(ft_itoa(current_time->tm_mon + 1), 2)
				<< zero_pad_timestamp(ft_itoa(current_time->tm_mday), 2) << '_'
				<< zero_pad_timestamp(ft_itoa(current_time->tm_hour), 2)
				<< zero_pad_timestamp(ft_itoa(current_time->tm_min), 2)
				<< zero_pad_timestamp(ft_itoa(current_time->tm_sec), 2)
				<< ']';
}

/*/////////////
	Public
*//////////////

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::Account(void) //++overloaded func
{
	_nbAccounts++;
	_totalAmount = 0;

	_accountIndex = _nbAccounts;
	_amount = 0;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account(void)
{
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";p_amount:" << (_amount - deposit)
				<< ";deposit:" << deposit
				<< ";amount:" << _amount
				<< ";nb_deposits:" << _nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	if ((_amount - withdrawal) < 0)
	{
		std::cout << " index:" << _accountIndex
					<< ";p_amount:"<< _amount
					<< ";withdrawal:refused" << std::endl;
		return false;
	}
	_totalNbWithdrawals++;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_amount -= withdrawal;
	std::cout << " index:" << _accountIndex
				<< ";p_amount:"<< (_amount + withdrawal)
				<< ";withdrawal:" << withdrawal
				<< ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals
				<< std::endl;
	return true;
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<<  ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< std::endl;
}

void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< std::endl;
}

int	Account::checkAmount(void) const
{
	return _amount;
}

//* static getters
int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}
