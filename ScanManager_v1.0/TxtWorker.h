#pragma once
#include"DataBase.h"

#ifndef TXTWORKER_H
#define TXTWORKER_h

class C_TxtWorker 
{
	char *filename; // numele fisierului
	char *type; //txt sau exe - pentru raportul de afisare;
	int simpleErrors; //numarul erorilor in cazul scanarii normale
	int strictErrors; //numarul erorilor in cazul scanarii stricte
	int m_WorkerId; //id-ul workerului
	char *simpleState; //infectat sau nu in cazul scanarii normale
	char *strictState; //infectat sau nu in cazul scanarii stricte
public:
	C_TxtWorker();
	C_TxtWorker(char *name, int id,C_DataBase*Data);
	void pWord(char* DataBaseWord, char* ToVerifyWord, int p);
	void verify(C_DataBase*Data, int p);
	char* getFileName();
	char* getType();
	int getSimpleErrors();
	int getStrictErrors();
	int getm_WorkerId();
	char* getSimpleState();
	char* getStrictState();

};

#endif