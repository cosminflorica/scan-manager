#include "TxtWorker.h"
#include"Exceptie.h"
#include"Errors.h"
#include<iostream>
#include<stdio.h>

using namespace std;


C_TxtWorker::C_TxtWorker()
{
	type = _strdup("TxtWorker");
	filename = NULL;
	simpleErrors = 0;
	strictErrors = 0;
	simpleState = _strdup("Uninfected");
	strictState = _strdup("Uninfected");
	m_WorkerId = -1;
}

C_TxtWorker::C_TxtWorker(char * name,int id, C_DataBase* Data)
{
	type = _strdup("TxtWorker");
	filename = _strdup(name);
	simpleErrors = 0;
	strictErrors = 0;
	simpleState = _strdup("Uninfected");
	strictState = _strdup("Uninfected");
	m_WorkerId = id;
}

void C_TxtWorker::pWord(char * DataBaseWord, char * ToVerifyWord, int p)
{
	char *toControl;
	int contor = 0;
	if (p == 100)
	{
		if (strcmp(_strlwr(DataBaseWord), _strlwr(ToVerifyWord)) == 0)
			simpleErrors++;
	}
	else
		if (p == 50)
		{
			int wordLength = strlen(DataBaseWord);
			
			if (wordLength % 2 == 0)
			{
				for (int i = 0; i < (wordLength / 2) ; i++)
				{
					contor = 0;
					toControl = new char[wordLength / 2 + 1];
					strcpy(toControl, " ");
					toControl[contor++] = DataBaseWord[i];
					for (int j = i + 1; j < wordLength / 2 + i ; j++)
					{
						toControl[contor] = DataBaseWord[j];
						contor++;
					}
					toControl[contor] = '\0';
					if (strstr(_strlwr(ToVerifyWord), _strlwr(toControl)) != NULL)
						strictErrors++;
				}
			}
			else
			{
				for (int i = 0; i < ( wordLength / 2 ) + 1; i++)
				{
					toControl = new char[wordLength / 2 + 1];
					strcpy(toControl, " ");
					toControl[contor++] = DataBaseWord[i];
					for (int j = i + 1; j < wordLength / 2 + i + 1; j++)
					{
						toControl[contor] = DataBaseWord[j];
						contor++;
					}
					toControl[contor] = '\0';
					if (strstr(_strlwr(ToVerifyWord), _strlwr(toControl)) != NULL)
						strictErrors++;
				}
			}
			
		}
}

void C_TxtWorker::verify(C_DataBase * Data, int procent)
{
	char *buffer;
	FILE *fIn = fopen(filename, "r");
	simpleErrors = 0;
	if (!fIn)
		throw new CExceptie(ERROR_FILE_NOT_EXIST, "fisier inexistent");
	else
	{
		fseek(fIn, 0, SEEK_END);
		int fileLength = ftell(fIn);
		rewind(fIn);
		buffer = new char[fileLength + 1];				
		if (!Data)
			throw new CExceptie(ERROR_DATA_BASE, "baza de date inexistanta");
		else
		{

			if (!feof(fIn))
			{
				fgets(buffer, fileLength, fIn);
				char *p = strtok(buffer, " \n");
				while (p)
				{
					C_DataBase*copyData = new C_DataBase(Data);
					while (copyData->getHead() != NULL)
					{
						pWord(copyData->getHead()->name, p, procent);
						copyData->setHead(copyData->getHead()->next);
					}
					p = strtok(NULL, " \n");
				}
			}
		}
		if (simpleErrors != 0)
			strcpy(simpleState, "Infected");
	}
}

char * C_TxtWorker::getFileName()
{
	return filename;
}

char * C_TxtWorker::getType()
{
	return type;
}

int C_TxtWorker::getSimpleErrors()
{
	return simpleErrors;
}

int C_TxtWorker::getStrictErrors()
{
	return strictErrors;
}

int C_TxtWorker::getm_WorkerId()
{
	return m_WorkerId;
}

char * C_TxtWorker::getSimpleState()
{
	return simpleState;
}

char * C_TxtWorker::getStrictState()
{
	return strictState;
}
