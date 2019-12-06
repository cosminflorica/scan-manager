#include "DataBase.h"
#include<iostream>
#include<stdio.h>
#include"Errors.h"
#include"Exceptie.h"
C_DataBase::C_DataBase(C_DataBase * C)
{
	this->head = C->head;
}
C_DataBase::C_DataBase()
{
	head = NULL;
	createDataBase("database.txt");
}

void C_DataBase::createDataBase(char * filename)
{
	FILE *fIn = fopen(filename, "r");
	
	if (!fIn)
		throw new CExceptie(ERROR_FILE_NOT_EXIST, "Eroare deschidere fisier");
	else
	{
		fseek(fIn, 0, SEEK_END);
		int fileLength = ftell(fIn);
		rewind(fIn);
		char *buffer = new char[fileLength];
		while (fileLength>0)
		{
			fgets(buffer, fileLength, fIn);
			fileLength -= strlen(buffer)+1;

			char *p = strtok(buffer, " \n");
			while (p)
			{
				if (head == NULL)
				{
					head = new DataList;
					head->name = _strdup(buffer);
					head->next = NULL;
				}
				else
				{
					DataList *copyhead = new DataList;
					copyhead = head;
					while (copyhead->next != NULL)
						copyhead = copyhead->next;
					copyhead->next = new DataList;
					copyhead->next->name = _strdup(buffer);
					copyhead->next->next = NULL;
				}
				p = strtok(NULL, " \n");
			}
		}
	}
}

DataList * C_DataBase::getHead()
{
	return head;
}

void C_DataBase::setHead(DataList * a)
{
	this->head = a;;
}

void C_DataBase::dataBaseUpdate(char * input)
{
	FILE *fOut = fopen("database.txt", "a");
	char* copyinput = _strdup(input);
	fprintf(fOut, "\n");
	if (!input)
		throw new CExceptie(ERROR_DATA_BASE, "input nu exista");
	else
	{
		char*p = strtok(copyinput, " \n");
		while (p)
		{
			fprintf(fOut, "%s\n", p);
			p = strtok(NULL, " \n");
		}
	}
	fclose(fOut);
}

void C_DataBase::up_to_date()
{
	FILE *fIn = fopen("database.txt","r");
	if (!fIn)
		throw new CExceptie(ERROR_FILE_NOT_EXIST, "eroare fisier");
	else
	{
		fseek(fIn, 0, SEEK_END);
		int fileLength = ftell(fIn);
		rewind(fIn);
		while (!feof(fIn))
		{
			char *buffer = new char[fileLength];
			fscanf(fIn, "%s", buffer);
		}
	}
	std::cout << "DataBase up to date! ";
}

