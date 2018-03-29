#include <iostream>
#include <list>
#include <string>

struct argument_struct
{

	argument_struct* parent = NULL;

	//list of argument_struct pointers called children
	list<argument_struct*> children = new list<argument_struct*>;
	
	//
	String argumentStr = "\n";
	
	bool conclusion = false
	bool leaf = false;

	char from[25];
	//tells you how this node was derived
