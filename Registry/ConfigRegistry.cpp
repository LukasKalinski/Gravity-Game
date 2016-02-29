///////////////////////////////////////////////////////////
//  ConfigRegistry.cpp
//  Implementation of the Class ConfigRegistry
//  Created on:      28-mar-2008 10:24:44
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <sstream>
#include "ConfigRegistry.h"


ConfigRegistry* ConfigRegistry::m_singleton = 0;

ConfigRegistry::~ConfigRegistry() {

}

// Default copy constructor is better than nothing.
// ConfigRegistry::ConfigRegistry(const ConfigRegistry& theConfigRegistry) {
// }

/**
 * Constructs a config registry instance.
 */
ConfigRegistry::ConfigRegistry() {

	// Open key config file:
	std::ifstream ff("keys.cfg", std::ios_base::in);

	// Read and save control config from file:
	if (ff.is_open()) {
		std::string line;
		std::string token;

		// For each line...
		while (!ff.eof()) {
			getline(ff, line);
			std::stringstream ss(line); // Insert the string into a stream
			
			int keyCode;

			std::vector<unsigned short> controlAliases;

			// For each token in line...
			for(int i=0; !ss.eof(); ++i) {
				if(i==0) {
					ss >> token;
					keyCode = atoi(token.c_str());
				} else {
					ss >> token;
					controlAliases.push_back(atoi(token.c_str()));
				}
			}

			m_controls[keyCode] = controlAliases;
		}

		ff.close();
	} else {
		throw std::exception("ConfigRegistry::ConfigRegistry(): Error opening keys.cfg.");
	}
}


/**
 * Returns the corresponding control alias key for the provided key code.
 */
const ConfigRegistry::control_aliases_t& ConfigRegistry::getControlAliasesForKey(int keyCode) {
	return m_controls[keyCode];

	//std::map<int, unsigned short>::const_iterator it;

	//it = m_controls.find(keyCode);

	//return (it != m_controls.end()) ? it->second : 0;
}


/**
 * Returns the path to the directory where all graphics reside.
 */
const std::string& ConfigRegistry::getGfxRoot() {
	return  m_gfxRoot;
}




/**
 * Returns the path to the directory where all sounds reside.
 */
const std::string& ConfigRegistry::getSfxRoot() {
	return  m_sfxRoot;
}


/**
 * Returns the singleton instance of the config registry.
 */
ConfigRegistry* ConfigRegistry::instance() {
	if (!m_singleton) {
	  m_singleton = new ConfigRegistry();
	}
	return m_singleton;
}
