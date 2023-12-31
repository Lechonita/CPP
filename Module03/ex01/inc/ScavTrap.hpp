#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <cstdlib>

class ScavTrap: public ClapTrap
{

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& copy);
	~ScavTrap();
	
	ScavTrap& operator=(const ScavTrap& src);

	void	attack(const std::string& target);
	void	guardGate(void);

private:

	bool 	_guarding_gate;

};

#endif