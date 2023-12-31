#include "Weapon.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

// Constructor
Weapon::Weapon(const std::string& weapon)
{
	this->setType(weapon);
}

// Destructor
Weapon::~Weapon()
{
	std::cout << this->getType() << " has been dropped." << std::endl;
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

void	Weapon::setType(const std::string& weapon)
{
	_type = weapon;
}

const std::string&	Weapon::getType(void) const
{
	return (_type);
}
