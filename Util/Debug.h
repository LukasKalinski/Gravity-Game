///////////////////////////////////////////////////////////
//  Debug.h
//  Implementation of the Class Debug
//  Created on:      10-maj-2008 18:31:41
//  Original author: Jesper
///////////////////////////////////////////////////////////

#if !defined(EA_9FAE75A1_E002_4fab_ADF3_0CD433B8074A__INCLUDED_)
#define EA_9FAE75A1_E002_4fab_ADF3_0CD433B8074A__INCLUDED_

#include <SDL.h>

/**
 * Debug output class.
 */
class Debug
{

public:	
	Debug();
	Debug(const char* fname);
	virtual ~Debug();
	Debug(const Debug& theDebug);

	static Debug* instance();
	void printString(const char* str);

private:
	static Debug* m_instance;
	FILE* m_file;

};
#endif // !defined(EA_9FAE75A1_E002_4fab_ADF3_0CD433B8074A__INCLUDED_)
