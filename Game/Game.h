///////////////////////////////////////////////////////////
//  Game.h
//  Implementation of the Class Game
//  Created on:      28-mar-2008 10:26:26
//  Original author: Lukas K
///////////////////////////////////////////////////////////

#if !defined(EA_02CFCDFF_7C01_4b2b_BFD8_191E979398ED__INCLUDED_)
#define EA_02CFCDFF_7C01_4b2b_BFD8_191E979398ED__INCLUDED_

#include <stack>
#include <set>

#include "Tickable.h"
#include "GameState.h"
#include "MainMenuState.h"
#include "Renderer.h"

class SoundManager;


/**
 * Receives ticks from ticker and forwards control to other game states by calling
 * their tick() function. If a game state turns invalid, it will be removed and a
 * fallback to the previous state will be done.
 * @author Lukas K
 * @version 1.0
 * @updated 21-Apr-2008 13:01:28
 */
class Game
{

public:

	/**
	 * Creates a new Game instance if not already created and returns it.
	 */
	static Game* instance();

	virtual ~Game();
	Game(const Game& g);

	void init();

	void enterState(const GameState& state);

	/**
	 * Leaves the current game state, entering the previous one if any, or exiting the
	 * game otherwise.
	 */
	void leaveState();

	/**
	 * Runs the main game loop.
	 */
	void run();

	/**
	 * Registers a tickable object to be ticked only when the current state is active.
	 * 
	 * @param tickable
	 */
	void registerStateTickable(Tickable* tickable);

	/**
	 * Unegisters a tickable object from receiving ticks.
	 * 
	 * @param tickable
	 */
	void unregisterStateTickable(Tickable* tickable);

private:

	typedef std::set<Tickable*> state_tickables_t;
	typedef std::stack<state_tickables_t*> state_tickables_stack_t;
	typedef std::stack<SoundManager*> soundmanagers_stack_t;
	
	/**
	 * Contains the singleton instance of Game (self).
	 */
	static Game* m_singleton;

	/**
	 * Tells whether the game has been initialized or not.
	 */
	bool m_initialized;

	/**
	 * Holds the current game state.
	 */
	GameState *m_currentState;

	/**
	 * Stack of currently inactive game states, ordered by the most recently left
	 * state on top and the main menu state on the bottom.
	 */
	std::stack<GameState*> m_stateStack;

	/**
	 * Stack of soundmanagers.
	 */
	soundmanagers_stack_t m_soundManagersStack;

	/**
	 * The graphics renderer for the game.
	 */
	Renderer *m_viewRenderer;

	/**
	 * Contains tickable objects that should be ticked when a specific game state is
	 * active.
	 */
	state_tickables_t * m_stateTickables;

	/**
	 * Contains the sets of tickables that belong to inactive states.
	 */
	state_tickables_stack_t m_stateTickablesStack;

	Game();

	/**
	 * Constant which says how many milliseconds one tick is.
	 */
	static const int m_millis_per_tick = 15;

};
#endif // !defined(EA_02CFCDFF_7C01_4b2b_BFD8_191E979398ED__INCLUDED_)
