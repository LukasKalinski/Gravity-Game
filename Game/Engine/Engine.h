///////////////////////////////////////////////////////////
//  Engine.h
//  Implementation of the Class Engine
//  Created on:      28-mar-2008 10:25:33
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_48C9C21F_3BA1_469c_8F7C_960822C812E1__INCLUDED_)
#define EA_48C9C21F_3BA1_469c_8F7C_960822C812E1__INCLUDED_

#include "World.h"
#include "Tickable.h"
#include "Player.h"

/**
 * Responsible for maintaining the players and the game world they play within.
 */
class Engine : public Tickable
{

public:

	typedef std::vector<Player*> players_t;

	/**
	 * @author Lukas Kalinski
	 * @version 1.0
	 * @updated 18-Apr-2008 15:58:14
	 */
	enum player_num_t
	{
		PLAYER_ONE = 0,
		PLAYER_TWO = 1
	};

	Engine();
	virtual ~Engine();
	Engine(const Engine& engine);

	/**
	 * Initializes the world and the added players, meaning that both the world and
	 * all players must be present.
	 */
	void init();

	void init(const World& world, GameEventManager * eventManager);

	/**
	 * Adds a player to the engine and returns the pointer to the player
	 * instance stored by engine.
	 */ 
	Player * addPlayer(const Player& player);

	/**
	 * Returns the specified player.
	 * 
	 * @param num
	 */
	Player& getPlayer(player_num_t num);
	const Player& getPlayer(player_num_t num) const;

	players_t& getPlayers();
	const players_t& getPlayers() const;

	World& getWorld();
	const World& getWorld() const;
	
	virtual void tick();

	/**
	 * Loads the world that the engine should manage, and in which the game will be
	 * played. This function also validates that the world is in a consistent state.
	 * 
	 * @param world
	 */
	void loadWorld(const World& world);

	/**
	 * Sets the event manager that is used in the current game state.
	 * 
	 * @param eventManager
	 */
	void setEventManager(GameEventManager* eventManager);

private:

	/**
	 * Tells whether the engine is initialized or not.
	 */
	bool m_initialized;

	/**
	 * The event manager that is used within the current game state. Must be set when
	 * engine is initialized.
	 */
	GameEventManager *m_eventManager;

	/**
	 * The world that the engine is managing, and where the game will be played. Must
	 * be set when the engine is initialized.
	 */
	World *m_world;

	/**
	 * The game player(s).
	 */
	players_t m_players;

	void validateWorld(const World& world) const;

};
#endif // !defined(EA_48C9C21F_3BA1_469c_8F7C_960822C812E1__INCLUDED_)
