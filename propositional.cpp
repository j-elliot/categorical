

struct argument_struct
{

	argument_struct* parent = NULL;

	//list of argument_struct pointers called children
	
	//list of char values used as a stack entered in reverse polish notation
	
	bool leaf = false;

	char from[10];
	//tells you how this node was derived
