#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <cstdlib>

class Zombie
{

public:

	Zombie();
	~Zombie();

	void	announce(void);
	void	set_name(std::string name);

private:

	std::string		_name;
};

Zombie	*zombieHorde( int N, std::string name );

#endif