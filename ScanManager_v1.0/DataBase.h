#pragma once

#ifndef DATABASE_H
#define DATABASE_H

struct DataList
{
	char *name;
	DataList *next;
};


class C_DataBase
{
	DataList *head;
public:
	C_DataBase(C_DataBase*C);
	C_DataBase();
	void createDataBase(char *filename);
	void updateDataBase(char *string);
	DataList* getHead();
	void setHead(DataList* a);
	void dataBaseUpdate(char* input);
	void up_to_date();
};

#endif