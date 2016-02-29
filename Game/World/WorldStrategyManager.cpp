///////////////////////////////////////////////////////////
//  WorldStrategyManager.cpp
//  Implementation of the Class WorldStrategyManager
//  Created on:      29-Mar-2008 13:45:46
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#include "WorldStrategyManager.h"


/**
 * Constructs a new world strategy manager.
 */
WorldStrategyManager::WorldStrategyManager() {
}


WorldStrategyManager::~WorldStrategyManager() {

	// Delete all contained strategies:
	strategies_t::iterator s_it = m_strategies.begin();
	for ( ; s_it != m_strategies.end(); ++s_it) {
		delete *s_it;
		*s_it = 0;
	}
	m_strategies.clear();
}


WorldStrategyManager::WorldStrategyManager(const WorldStrategyManager& sm) {

	// Copy strategies:
	strategies_t::const_iterator s_it = sm.m_strategies.begin();
	for ( ; s_it != sm.m_strategies.end(); ++s_it) {
		WorldStrategy * ws = (*s_it)->clone();
		m_strategies.push_back(ws);
	}
}


/**
 * Adds a world strategy to apply on the world on each tick. Must be called before
 * initialization.
 * 
 * @param strategy
 */
void WorldStrategyManager::addStrategy(const WorldStrategy& strategy) {
	m_strategies.push_back(strategy.clone());
}


/**
 * Applies contained strategies on the supplied world instance.
 */
void WorldStrategyManager::applyStrategies(World& world) {
	strategies_t::iterator it = m_strategies.begin();
	while (it != m_strategies.end()) {
		(*it)->applyWorldStrategy(world);
		++it;
	}
}