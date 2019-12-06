#pragma once
#include"DataBase.h"
#ifndef EXEWORKER_H
#define EXEWORKER_H

class C_ExeWorker
{
	char *filename; // numele fisierului
	char *type; //txt sau exe - pentru raportul de afisare;
	int simpleErrors; //numarul erorilor in cazul scanarii normale
	int strictErrors; //numarul erorilor in cazul scanarii stricte
	int m_WorkerId; //id-ul workerului
	char *simpleState; //infectat sau nu in cazul scanarii normale
	char *strictState; //infectat sau nu in cazul scanarii stricte
public:
	C_ExeWorker();
	C_ExeWorker(char *name, int id, C_DataBase*Data);
	void pWord(char* DataBaseWord, unsigned char ToVerifyWord, int p);
	void verify(C_DataBase*Data, int procent);
	char* getFileName();
	char* getType();
	int getSimpleErrors();
	int getStrictErrors();
	int getm_WorkerId();
	char* getSimpleState();
	char* getStrictState();
};

#endif