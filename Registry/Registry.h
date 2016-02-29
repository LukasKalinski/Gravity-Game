///////////////////////////////////////////////////////////
//  Registry.h
//  Implementation of the Class Registry
//  Created on:      28-mar-2008 10:32:47
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_4D611E15_3170_4ff7_859C_55FD01EC9FF2__INCLUDED_)
#define EA_4D611E15_3170_4ff7_859C_55FD01EC9FF2__INCLUDED_

#include <string>


/**
 * Abstract registry class, holding file management functions.
 */
class Registry
{

public:
	Registry();
	virtual ~Registry();
	Registry(const Registry& theRegistry);

protected:
	std::string* readFromFile(const std::string& fileName);
	void saveToFile(const std::string& text, const std::string& fileName);

};
#endif // !defined(EA_4D611E15_3170_4ff7_859C_55FD01EC9FF2__INCLUDED_)
