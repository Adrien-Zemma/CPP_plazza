/*
** EPITECH PROJECT, 2018
** plazza
** File description:
** Plazza
*/

/*!
 * @brief 
 * 	header of the Plazza Class
 * 
 * @file plazza.hpp
 * 
 */

#ifndef PLAZZA_HPP_
	#define PLAZZA_HPP_

#include <iostream>
#include <vector>
#include <map>
#include "process.hpp"
#include "transport.hpp"

class Plazza {
	public:
		Plazza();
		Plazza(char *str); 
		~Plazza();
		int start();
	protected:
		enum Information
		{
			PHONE_NUMBER = 0,
			EMAIL_ADDRESS = 1,
			IP_ADDRESS = 2
		};
		std::map<Information, std::string>	informations;
		size_t	_threadMax;
	private:
		void	manager();
		Transport	input;
		Transport	output;
		std::vector< Process*>	processes;

};

#endif /* !PLAZZA_HPP_ */