///////////////////////////////////////////////////////////
//  WorldMapRegistry.cpp
//  Implementation of the Class WorldMapRegistry
//  Created on:      28-mar-2008 10:36:13
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "WorldMapRegistry.h"
#include "World.h"
#include "WrapBoundaryStrategy.h"
#include "Coord2d.h"
#include "Planet.h"
#include "SpawnPoint.h"
#include "FuelItem.h"

#include <iostream>
#include <fstream>
#include <sstream>


WorldMapRegistry* WorldMapRegistry::m_singleton = 0;

WorldMapRegistry::~WorldMapRegistry() {

}


WorldMapRegistry::WorldMapRegistry(const WorldMapRegistry& registry) {
	throw std::exception("WorldMapRegistry.cpp: Copy constructor called.");
}


/**
 * Constructs a world map registry instance.
 */
WorldMapRegistry::WorldMapRegistry() {

}


/**
 * Generates a game world instance from a given map name.
 */
World WorldMapRegistry::generateFromMap(const std::string& mapName) const {



	// Open map file:
	std::ifstream ff(mapName.c_str(), std::ios_base::in);

	// Read a map from a file:
	if (ff.is_open()) {
		std::string line;
		std::string token;

		// First line is special and contains the world coordinates:
		float world_x_coord, world_y_coord;
		ff >> world_x_coord >> world_y_coord;
		World world(Coord2d(0.0f, 0.0f), Coord2d(world_x_coord, world_y_coord));
		WorldObjectsManager & wom = world.getWorldObjectsManager();

		

		// For each line...
		while (!ff.eof()) {
			getline(ff, line);
			std::stringstream ss(line); // Insert the string into a stream

			std::vector<std::string> line_tokens;

			// For each token in line...
			for(int i=0; !ss.eof(); ++i) {
					ss >> token;
					line_tokens.push_back(token);
			}
			if(std::string("PLANET") == line_tokens[0]) {
				float mass, radius, x_coord, y_coord;
				Planet::planet_t planet_type;
				//         mass, radius, type                   x       y
				// Planet(550.0, 140.0, Planet::EARTH), Coord2d(2500.0, 2500.0)
				sscanf_s(line_tokens[1].c_str(), "%f", &mass);
				sscanf_s(line_tokens[2].c_str(), "%f", &radius);
				sscanf_s(line_tokens[3].c_str(), "%d", &planet_type);
				sscanf_s(line_tokens[4].c_str(), "%f", &x_coord);
				sscanf_s(line_tokens[5].c_str(), "%f", &y_coord);
				wom.insert(Planet(mass, radius, planet_type), Coord2d(x_coord, y_coord));
			} else if(std::string("SPAWNPOINT") == line_tokens[0]) {
				float x_coord, y_coord;
				sscanf_s(line_tokens[1].c_str(), "%f", &x_coord);
				sscanf_s(line_tokens[2].c_str(), "%f", &y_coord);
				//wom.insert(SpawnPoint(), Coord2d(3500.0, 3500.0));
				wom.insert(SpawnPoint(), Coord2d(x_coord, y_coord));
			} else if(std::string("FUEL") == line_tokens[0]) {
				float x_coord, y_coord;
				unsigned int fuel_amount;
				sscanf_s(line_tokens[1].c_str(), "%f", &x_coord);
				sscanf_s(line_tokens[2].c_str(), "%f", &y_coord);
				sscanf_s(line_tokens[3].c_str(), "%d", &fuel_amount);
				wom.insert(FuelItem(fuel_amount), Coord2d(x_coord, y_coord));
			}
		}

		ff.close();
		return world;
	} else {
		throw std::exception("WorldMapRegistry::readFromMapFile(): Error opening map file.");
	}
}


/**
 * Returns an iterator of strings containing the names of all available maps.
 */
std::vector<std::string>::iterator WorldMapRegistry::getMaps() {
	std::vector<std::string> v;
	v.push_back("Map 1");
	return v.begin();
}


/**
 * Returns the singleton instance of the world map registry.
 */
WorldMapRegistry* WorldMapRegistry::instance() {

	if (!m_singleton) {
	  m_singleton = new WorldMapRegistry();
	}
	return m_singleton;
}