//this shit is logical

#include<stdio.h>
#include<stdbool.h>
#include<string.h>

void printer(int moodFigPar[])
{

	for(int i = 0; i < 3; i++)
	{

		if (moodFigPar[i] == 0)
			printf("a");
		else if (moodFigPar[i] == 1)
			printf("e");
		else if (moodFigPar[i] == 2)
			printf("i");
		else if (moodFigPar[i] == 3)
			printf("o");
		else
		{	
			printf("\nError encountered in mood encoding.\nExiting now.");
			return;

		}

	}

	printf(" - %d\n", moodFigPar[3]);

}

int intGet(char c)
{

	int i;

	if (c == 'a' || c == 'A')
		i = 0;
	else if (c == 'e' || c == 'E')
		i = 1;
	else if (c == 'i' || c == 'I')
		i = 2;
	else if (c == 'o' || c == 'O')
		i = 3;
	else
		i = -1;

	return i;

}

void loader(int moodFig[])
{

	char holdChar;

	printf("Input major premise categorical proposition type: ");
	scanf(" %c", &holdChar);
	printf("\n");
	moodFig[0] = intGet(holdChar);

	printf("Input minor premise categorical proposition type: ");
	scanf(" %c", &holdChar);
	printf("\n");
	moodFig[1] = intGet(holdChar);

	printf("Input conclusion premise categorical proposition type: ");
	scanf(" %c", &holdChar);
	printf("\n");
	moodFig[2] = intGet(holdChar);

	printf("Input figure: ");
	scanf(" %d", &moodFig[3]);
	printf("\n");

}

bool validCheck(int catArg[], char* type)
{

	bool position[6] = {0, 0, 0, 0, 0, 0};

	bool fallacyFlag = 1;

	*type = '\0';

	//These use the position array to determine if argument
	//types are distributive or not to test for undistributed middle
	//and illicit major and minor
	for(int i = 0; i < 3; i++)
	{

		//Is the current statement type a?
		//if so, the subject is distributed.
		if (catArg[i] == 0)
			position[2 * i] = 1;
		//Is the current statement type e?
		//if so, the subject and predicate are distributed.
		else if(catArg[i] == 1)
		{
			position[2 * i] = 1;
			position[2 * i + 1] = 1;	
		}
		//Is the current statement type o?
		//if so, the predicate is distributed.
		else if(catArg[i] == 3)
			position[2 * i + 1] = 1;

	}

	//Where would the middle be? Look at the figure
	//if both the middle positions associated with that figure are
	//undistributed: undistributed middle
	if(((catArg[3] == 1) && !(position[0] || position[3])) || 
			((catArg[3] == 2) && !(position[1] || position[3])) ||
			((catArg[3] == 3) && !(position[0] || position[2])) ||
			((catArg[3] == 4) && !(position[1] || position[2])))
	{	
		fallacyFlag = false;
		strcat(type, "Undistributed Middle\n");
	}

	//Is the conclusion type a or e, both of which imply a distributed S term?
	//if so, does the figure imply that the S term is in the subject or the predicate of the minor premise?
	//check for distribution where the S term would be in the minor premise.
	if(((catArg[2] == 0) || (catArg[2] == 1)) && (((catArg[3] <= 2) && !position[2]) || ((catArg[3] >= 3) && !position[3])))
	{
		fallacyFlag = false;
		strcat(type, "Illicit Minor\n");
	}

	//Is the conclusion type e or o, both of which imply a distributed P term?
	//if so, does the figure imply that the P term is in the subject or the predicate of the major premise?
	//check for distribution where the P term would be in the minor premise.
	if(((catArg[2] == 1) || (catArg[2] == 4)) && ((((catArg[3] % 2) == 1) && !position[1]) || (((catArg[3] % 2) == 0) && !position[0])))

	{
		fallacyFlag = false;
		strcat(type, "Illicit Major\n");
	}

	if(((catArg[0] == 1) || (catArg[0] == 3)) && ((catArg[1] == 1) || (catArg[1] == 3)))
	{
		fallacyFlag = false;
		strcat(type, "Exclusive Premises\n");
	}

	if((((catArg[0] == 1) || (catArg[0] == 3)) || ((catArg[1] == 1) || (catArg[1] == 3))) && !((catArg[2] == 1) || (catArg[2] == 3)))
	{
		fallacyFlag = false;
		strcat(type, "Affirmative Conclusion from Negative Premise\n");
	}

	if((((catArg[0] == 0) || (catArg[0] == 1)) && ((catArg[1] == 0) || (catArg[1] == 1))) && !((catArg[2] == 0) || (catArg[2] == 1)))
	{
		fallacyFlag = false;
		strcat(type, "Existential Import\n");
	}

	return fallacyFlag;

}


int main()
{

	int moodFig[4];

	char type[144];

	//loader(moodFig);

	for(int i = 0; i < 4; i++)
	{
		moodFig[0] = i;

		for(int j = 0; j < 4; j++)
		{
			moodFig[1] = j;

			for(int k = 0; k < 4; k++)
			{
				moodFig[2] = k;

				for(int l = 1; l <= 4; l++)
				{
					moodFig[3] = l;

					printer(moodFig);

					if(!validCheck(moodFig, type))
						printf("\tInvalid!\n%s", type);
					else
						printf("\tValid!\n");
				}
			}
		}
	}
}
