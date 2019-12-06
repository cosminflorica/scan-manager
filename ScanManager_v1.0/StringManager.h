#pragma once
#ifndef STRINGMANAGER_H
#define STRINGMANAGER_H

struct List
{	
	char *name;
	List*next;
};

class C_StringManager
{
	List *m_Head;
	char* m_FileName;

public:
	C_StringManager();
	C_StringManager(char *FileName);
	void BuildList(char *File);
	List *getHead();
};

#endif