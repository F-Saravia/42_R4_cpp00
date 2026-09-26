// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	Account::_displayTimestamp();
	std::cout <<
	"accounts:"		<< Account::getNbAccounts()		<< ";" <<
	"total:"		<< Account::getTotalAmount()	<< ";" <<
	"deposits:"		<< Account::getNbDeposits()		<< ";" <<
	"withdrawals:"	<< Account::getNbWithdrawals()	<< std::endl;
}


Account::Account( int initial_deposit )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts += 1;

	Account::_displayTimestamp();
	std::cout <<
	"index:"	<< this->_accountIndex	<< ";" <<
	"amount:"	<< this->_amount		<< ";" <<
	"created"	<< std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout <<
	"index:"	<< this->_accountIndex	<< ";" <<
	"amount:"	<< this->_amount		<< ";" <<
	"closed"	<< std::endl;

	Account::_nbAccounts -= 1;
	Account::_totalAmount -= this->_amount;
	Account::_totalNbDeposits -= this->_nbDeposits;
	Account::_totalNbWithdrawals -= this->_nbWithdrawals;
	this->_accountIndex = -1;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

void	Account::makeDeposit( int deposit )
{
	int	p_amount = this->_amount;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits += 1;
	this->_amount += deposit;
	this->_nbDeposits += 1;

	Account::_displayTimestamp();
	std::cout <<
	"index:"		<< this->_accountIndex	<< ";" <<
	"p_amount:"		<< p_amount				<< ";" <<
	"deposit:"		<< deposit				<< ";" <<
	"amount:"		<< this->_amount		<< ";" <<
	"nb_deposits:"	<< this->_nbDeposits	<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	int	p_amount = this->_amount;
	if (p_amount - withdrawal <= 0){
		std::cout <<
		"index:"		<< this->_accountIndex	<< ";" <<
		"p_amount:"		<< p_amount				<< ";" <<
		"withdrawal:"	<< "refused"			<< std::endl;
		return (false);
	}

	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals += 1;
	this->_amount -= withdrawal;
	this->_nbWithdrawals += 1;

	std::cout <<
	"index:"			<< this->_accountIndex		<< ";" <<
	"p_amount:"			<< p_amount					<< ";" <<
	"withdrawal:"		<< withdrawal				<< ";" <<
	"amount:"			<< this->_amount			<< ";" <<
	"nb_withdrawals:"	<< this->_nbWithdrawals	<< std::endl;
	return (true);
}

int		Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout <<
	"index:"		<< this->_accountIndex	<< ";" <<
	"amount:"		<< this->_amount		<< ";" <<
	"deposits:"		<< this->_nbDeposits	<< ";" <<
	"withdrawals:"	<< this->_nbWithdrawals	<< std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	now;
	std::tm		*local_time;
	char		buffer[16] = "YYYYMMDD_hhmmss";
		// {'Y', 'Y', 'Y', 'Y', 'M', 'M', 'D', 'D', '_', 'h', 'h', 'm', 'm', 's', 's', 0};

	now = std::time(NULL);
	local_time = std::localtime(&now);
	if (local_time != NULL)
		std::strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", local_time);
	std::cout << "[" << buffer << "] ";
}

Account::Account( void )
{
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_nbAccounts += 1;
	Account::_totalAmount += 0;
}





// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //

