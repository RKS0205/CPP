#include "Account.hpp"

#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	_displayTimestamp();
	this->_accountIndex = getNbAccounts();
	std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
	this->_amount += initial_deposit;
	_nbAccounts++;
	_totalAmount += initial_deposit;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount() << ";closed" << std::endl;
	_nbAccounts--;
	_totalAmount -= checkAmount();
}

void	Account::_displayTimestamp(void) {
	time_t time_data;
	tm * current_time;
	char time_string[19];

	time(&time_data);
	current_time = localtime(&time_data);
	strftime(time_string, 19, "[%Y%m%d_%I%M%S] ", current_time);
	std::cout << time_string;
}

int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount(void) const {
	return (this->_amount);
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
	<< ";deposits:" << getNbDeposits() << ";withdrawals:" << getNbWithdrawals()
	<< std::endl;
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << checkAmount()
	<< ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals
	<< std::endl;
}

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	this->_nbDeposits++;
	this->_amount += deposit;
	_totalNbDeposits++;
	_totalAmount += deposit;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount() - deposit <<
	";deposit:" << deposit << ";amount:" << checkAmount() << ";nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	_displayTimestamp();
	if (checkAmount() - withdrawal < 0) {
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount()
		<< ";withdrawal:refused" << std::endl;
		return (false);
	}
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << checkAmount() + withdrawal
	<< ";withdrawal:" << withdrawal << ";amount:" << checkAmount() << ";nb_withdrawals:" << this->_nbWithdrawals
	<< std::endl;
	return (true);
}
