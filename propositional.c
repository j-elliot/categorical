//This is for solving propositional logic problems of any length

//Define an array of bools for the arguments a, b, ... n

#include<stdio>

//User will input the initial statements. Should I require narrow guidlines or let the statements be labelled as anything?
//Invalid characters would be v ^ > < ~ = ( ) because these need to be used for the logic
//I think I could just use the count to create an array of bools and then use the index of that array to refer back to the argv array to give me the label stored there.

//maybe reverse polish notation??

//array of ints size of cstring. Loop runs through cstring, writing depth of parentheses to coresponding int element. Also keep track of largest int, jump to the first of that, push to stack, checking for ~ before parentheses, (so long as the ~ is read after the components of the parentheses, I think it will work). Parentheses block gets cut, and keeps pushing. 

//function to search for rules that can be applied to stack
//function to apply rule and give branch to  tree in branch list 
//if no operations can be done, node is a leaf
//How would this know when every branch is at a leaf?
//function to check for conclusion
//function to print stack in normal notation
//char* stackBuilderFun(char* strPtr)
//void stackReaderFun(char* stackPtr)

//Input asks user to write argument; if not the first srgument, asks if conclusion.

//Each node could be running through it's own loop to try each possible operation... which will freeze as soon as it tries to go back and forth with De Morgan forever. Hmmm... could check all above stack members for an identical string, then if it is a repeat, it stops and becomes a leaf.

struct Argument
{
	struct Argument* parent = NULL;

int main(int argc, char* argv[])
{

	bool statementArry[argc];

	int premiseCnt;

	//How do I define a c string that is the right size?

	printf("Please indicate the number of premises\n");

	scanf("%d", &premiseCnt);

	for(int i = 0; i <= premiseCnt; i++)
	{

	}

}
