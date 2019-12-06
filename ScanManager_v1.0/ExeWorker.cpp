#include "ExeWorker.h"
#include"Errors.h"
#include"Exceptie.h"
#include<iostream>
C_ExeWorker::C_ExeWorker()
{
	type = _strdup("TxtWorker");
	filename = NULL;
	simpleErrors = 0;
	strictErrors = 0;
	simpleState = _strdup("Uninfected");
	strictState = _strdup("Uninfected");
	m_WorkerId = -1;
}

C_ExeWorker::C_ExeWorker(char * name, int id, C_DataBase*Data)
{
	type = _strdup("TxtWorker");
	filename = _strdup(name);
	simpleErrors = 0;
	strictErrors = 0;
	simpleState = _strdup("Uninfected");
	strictState = _strdup("Uninfected");
	m_WorkerId = id;
}

void C_ExeWorker::pWord(char * DataBaseWord, unsigned char ToVerifyWord, int p)
{
	char *toControl;
	int contor = 0;
	if (p == 100)
	{
		//if (strcmp(_strlwr(DataBaseWord), ToVerifyWord) == 0)
			simpleErrors++;
	}
	else
		if (p == 50)
		{
			int wordLength = strlen(DataBaseWord);

			if (wordLength % 2 == 0)
			{
				for (int i = 0; i < (wordLength / 2); i++)
				{
					contor = 0;
					toControl = new char[wordLength / 2 + 1];
					strcpy(toControl, " ");
					toControl[contor++] = DataBaseWord[i];
					for (int j = i + 1; j < wordLength / 2 + i; j++)
					{
						toControl[contor] = DataBaseWord[j];
						contor++;
					}
					toControl[contor] = '\0';
					//if (strstr(_strlwr(ToVerifyWord), _strlwr(toControl)) != NULL)
						strictErrors++;
				}
			}
			else
			{
				for (int i = 0; i < (wordLength / 2) + 1; i++)
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
					//if (strstr(_strlwr(ToVerifyWord), _strlwr(toControl)) != NULL)
						strictErrors++;
				}
			}

		}
}

void C_ExeWorker::verify(C_DataBase * Data, int procent)
{
	unsigned char buffer;
	FILE *fIn = fopen(filename, "rb");
	simpleErrors = 0;
	if (!fIn)
		throw new CExceptie(ERROR_FILE_NOT_EXIST, "fisier inexistent");
	else
	{
		fseek(fIn, 0, SEEK_END);
		int fileLength = ftell(fIn);
		rewind(fIn);
		//buffer = new char[fileLength + 1];
		if (!Data)
			throw new CExceptie(ERROR_DATA_BASE, "baza de date inexistanta");
		else
		{

			if (!feof(fIn))
			{
				fread(&buffer, sizeof(buffer), 1, fIn);
				C_DataBase*copyData = new C_DataBase(Data);
				while (copyData->getHead() != NULL)
				{
					pWord(copyData->getHead()->name, buffer, procent);
					copyData->setHead(copyData->getHead()->next);
				}
			}
		}
		if (simpleErrors != 0)
			strcpy(simpleState, "Infected");
	}
	fclose(fIn);
}
