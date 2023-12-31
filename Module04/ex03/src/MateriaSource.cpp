#include "MateriaSource.hpp"

/********************************************************************************/
/*************************** CONSTRUCTOR / DESTRUCTOR ***************************/
/********************************************************************************/

MateriaSource::MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
		this->_source[i] = NULL;
	std::cout << "Materia Source has been created." << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& copy)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (copy._source[i])
			this->_source[i] = copy._source[i]->clone();
		else
			this->_source[i] = NULL;
	}
	std::cout << "Materia Source Copy has been created." << std::endl;
}

MateriaSource::~MateriaSource()
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_source[i])
			delete this->_source[i];
	}
	std::cout << "Materia Source has been destroyed." << std::endl;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &src)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_source[i])
			delete this->_source[i];
		if (src._source[i])
			this->_source[i] = src._source[i]->clone();
	}
	return (*this);
}

/********************************************************************************/
/***************************** MEMBER FUNCTIONS *********************************/
/********************************************************************************/

// Functions
void	MateriaSource::learnMateria(AMateria* materia)
{
	for(size_t i = 0; i < 4; i++)
	{
		if (this->_source[i] == NULL)
		{
			this->_source[i] = materia;
			std::cout << "Materia Source has learned " << materia->getType() << "." << std::endl;
			return ;
		}
	}
	std::cout << "\033[0;31m" << "Max nb of Materia Source reached. Could not learn " <<  materia->getType() << "." << "\033[0m" << std::endl;
	delete materia;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_source[i] && this->_source[i]->getType() == type)
		{
			std::cout << "Materia Source is creating " << type << " materia..." << std::endl;
			return (this->_source[i]->clone());
		}
	}
	std::cout << "\033[0;31m" << "Materia Source could not create " <<  type << "." << "\033[0m" << std::endl;
	return (NULL);
}
