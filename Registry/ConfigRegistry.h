///////////////////////////////////////////////////////////
//  ConfigRegistry.h
//  Implementation of the Class ConfigRegistry
//  Created on:      28-mar-2008 10:24:39
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_857857A3_A174_4c25_9F54_160F1943ECE8__INCLUDED_)
#define EA_857857A3_A174_4c25_9F54_160F1943ECE8__INCLUDED_

#include <map>
#include <vector>

#include "Registry.h"

/**
 * Responsible to provide and handle persistence for the game configuration.
 */
class ConfigRegistry : public Registry
{

public:
	typedef std::vector<unsigned short> control_aliases_t;

	virtual ~ConfigRegistry();
	// Default copy constructor better than nothing.
	// ConfigRegistry(const ConfigRegistry& theConfigRegistry);
	const std::vector<unsigned short>& getControlAliasesForKey(int keyCode);

	const std::string& getGfxRoot();
	const std::string& getSfxRoot();
	static ConfigRegistry* instance();

private:
	/**
	 * Maps keyboard key codes to a list of static control aliases.
	 */
	std::map<int, control_aliases_t> m_controls;
	/**
	 * Path to the directory that contains all graphics.
	 */
	std::string m_gfxRoot;
	/**
	 * Maps configurable control aliases for the first local player to keyboard key
	 * codes.
	 */
	std::map<unsigned short, unsigned short> m_localPlayer1Controls;
	/**
	 * Maps configurable control aliases for the second local player to keyboard key
	 * codes.
	 */
	std::map<unsigned short, unsigned short> m_localPlayer2Controls;
	/**
	 * Path to the directory that contains all sounds.
	 */
	std::string m_sfxRoot;
	/**
	 * The singleton instance.
	 */
	static ConfigRegistry* m_singleton;

	ConfigRegistry();

};
#endif // !defined(EA_857857A3_A174_4c25_9F54_160F1943ECE8__INCLUDED_)
