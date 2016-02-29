///////////////////////////////////////////////////////////
//  Debug.cpp
//  Implementation of the Class Debug
//  Created on:      10-maj-2008 18:31:41
//  Original author: Jesper
///////////////////////////////////////////////////////////

#include "Debug.h"

#include <exception>

Debug* Debug::m_instance = 0;

/**
 * Constructor.
 */
Debug::Debug():
m_file(0)
{
	m_file = fopen("D:\\gravity_debug.txt", "w+" );
}



Debug::~Debug(){

}



Debug::Debug(const Debug& dbg){
	throw std::exception("Debug::Debug() copy constructor called!!!111!");
}





/**
 * Return the instance of this singleton.
 */
Debug* Debug::instance(){
	if(m_instance) {
		return m_instance;
	} else {
		m_instance = new Debug();
		return m_instance;
	}

}


/**
 * Print a string to debug file.
 */
void Debug::printString(const char* str){
		if(m_file) {
			fprintf(m_file, "%s\r\n", str);
			fflush(m_file);
		}

}

