///////////////////////////////////////////////////////////
//  WorldMapRegistry.h
//  Implementation of the Class WorldMapRegistry
//  Created on:      28-mar-2008 10:36:09
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_38F90C2C_D153_47b5_B7B0_DC17DF0D8690__INCLUDED_)
#define EA_38F90C2C_D153_47b5_B7B0_DC17DF0D8690__INCLUDED_

#include "World.h"
#include "WorldStrategyManager.h"
#include "Registry.h"

/**
 * Responsible for generating game worlds while being provided a map name.
 */
class WorldMapRegistry : public Registry
{

public:
	virtual ~WorldMapRegistry();
	WorldMapRegistry(const WorldMapRegistry& theWorldMapRegistry);

	World generateFromMap(const std::string& mapName) const;
	std::vector<std::string>::iterator getMaps();
	static WorldMapRegistry* instance();

private:
	/**
	 * Contains the names of all available maps.
	 */
	std::vector<std::string> m_maps;
	/**
	 * The singleton instance.
	 */
	static WorldMapRegistry* m_singleton;

	WorldMapRegistry();

};
#endif // !defined(EA_38F90C2C_D153_47b5_B7B0_DC17DF0D8690__INCLUDED_)
