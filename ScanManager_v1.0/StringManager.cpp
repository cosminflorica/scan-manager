#include "StringManager.h"
#include "Exceptie.h"
#include "Errors.h"
#include <string.h>
#include<stdio.h>
#include<iostream>
using namespace std;
C_StringManager::C_StringManager()
{
	m_Head = new List;
	m_Head = NULL;
	m_FileName = _strdup("");

}

C_StringManager::C_StringManager(char * FileName)
{
	m_FileName = _strdup(FileName);
	BuildList(FileName);
}

void C_StringManager::BuildList(char *File)
{
	char *copy = new char[strlen(File) + 1];
	strcpy(copy, File);
	if (!File)
		throw new CExceptie(ERROR_NULL_STRING, "string nume fisiere null");
	else
	{
		
		char *p = strtok(copy, " \n");
		while (p)
		{
			if (this->m_Head == NULL)
			{
				m_Head = new List;
				m_Head->name = new char[strlen(p) + 1];
				strcpy(m_Head->name, p);
				m_Head->next = new List;
				m_Head->next = NULL;
				
			}
			else
			{
				List *copyHead = new List;
				copyHead = m_Head;
				while (copyHead->next!=NULL)
					copyHead = copyHead->next;
				copyHead->next = new List;
				copyHead->next->name = new char[strlen(p) + 1];
				strcpy(copyHead->next->name, p);
				copyHead->next->next = NULL;
			}
			p = strtok(NULL, " \n");
		}
	}
}

List * C_StringManager::getHead()
{
	return this->m_Head;
}
