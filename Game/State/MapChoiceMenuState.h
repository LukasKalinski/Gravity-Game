///////////////////////////////////////////////////////////
//  MapChoiceMenuState.h
//  Implementation of the Class MapChoiceMenuState
//  Created on:      28-mar-2008 10:29:27
//  Original author: Lukas Kalinski
///////////////////////////////////////////////////////////

#if !defined(EA_CCC99014_D7D9_48ca_8F9D_AE89F11B9BB7__INCLUDED_)
#define EA_CCC99014_D7D9_48ca_8F9D_AE89F11B9BB7__INCLUDED_

#include "World.h"
#include "EnterStateAction.h"
#include "MenuState.h"
#include "PlayState.h"
#include "MainMenuState.h"

/**
 * The map choice menu, containing one button for each available map.
 */
class MapChoiceMenuState : public MenuState
{

public:

	class EnterPlayingStateAction : public EnterStateAction
	{

	public:

		EnterPlayingStateAction(
			const PlayState& playState,
			MapChoiceMenuState* mapChoiceState,
			const std::string& mapName);
		virtual ~EnterPlayingStateAction();
		EnterPlayingStateAction(const EnterPlayingStateAction& action);

		virtual void trigger();

		virtual EnterPlayingStateAction * clone() const;

	private:

		/**
		 * Pointer to the map choice menu state to trigger world generation for.
		 */
		MapChoiceMenuState * m_mapChoiceMenuState;

		/**
		 * Name of the world map to generate.
		 */
		std::string m_mapName;
	};


	MapChoiceMenuState(const PlayState& playingState);
	virtual ~MapChoiceMenuState();
	MapChoiceMenuState(const MapChoiceMenuState& state);


	/**
	 * Routes the enter handling depending on type obtained through RTTI.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const GameState* fromState);

	const World& getWorld() const;

	/**
	 * Notifies this state about a fallback to it from a child state, providing the
	 * child state instance. The child game state will be checked, and, when required,
	 * proper action will be taken (for example, if the child game state was a pause
	 * menu, it may have ordered a "quit", and we should realize it).
	 * 
	 * @param childState
	 */
	virtual void handleFallback(const GameState* childState);

	/**
	 * Clones a map choice menu state, returning a pointer to the clone.
	 */
	virtual MapChoiceMenuState* clone() const;

private:

	/**
	 * The world to start game on.
	 */
	World *m_world;

	/**
	 * The play state to enter when a map is chosen.
	 */
	PlayState *m_playState;

	/**
	 * Enters the map choice menu state, specifying the instance of the main menu
	 * state that it is being entered from.
	 * 
	 * @param fromState    Takes a pointer because we need to be able to accept 0 as
	 * value.
	 */
	virtual void enterFrom(const MainMenuState* fromState = 0);

	void generateWorld(const std::string& mapName);
	void init();

	/**
	 * Notifies the state about being "fallbacked" into, from a playing state. Takes
	 * no action. (Could possibly forward fallback to the main menu state.)
	 * 
	 * @param childState
	 */
	virtual void handleFallback(const PlayState* childState);

};
#endif // !defined(EA_CCC99014_D7D9_48ca_8F9D_AE89F11B9BB7__INCLUDED_)
