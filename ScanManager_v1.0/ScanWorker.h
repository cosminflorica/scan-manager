#pragma once

#include"StringManager.h"
#include"DataBase.h"
#include"TxtWorker.h"
#include"ExeWorker.h"


#ifndef SCANWORKER_H
#define SCANWORKER_H

struct workerList
{
	C_ExeWorker *exe;
	C_TxtWorker *txt;
	workerList *next;
};

class C_ScanWorker
{
	C_DataBase *Data;
	workerList *head;
	int m_MaxWorkers;
	int m_id;
public:
	C_ScanWorker();
	C_ScanWorker (C_StringManager*p_String, int MaxWorkers);
	void selectWorkers(C_StringManager *p_String);
	void SimpleScan();
	void StrictScan(int procent);
	void afisaresimple();
	void afisarestrict();
	C_DataBase* getData();

};

#endif
