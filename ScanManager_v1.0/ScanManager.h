#pragma once
#include"ScanWorker.h"
#include"StringManager.h"

#ifndef SCANMANAGER_H
#define SCANMANAGER_H


class C_ScanManager
{
private:

	static C_ScanManager *single;

	C_ScanWorker *m_Worker;
	C_StringManager *m_String;

	C_ScanManager(char* FileName, int MaxWorkers);
	//C_ScanManager();
	C_ScanManager(C_ScanManager*A);
public:
	static C_ScanManager* getInstance(char* FileName, int MaxWorkers);
	~C_ScanManager();
	void SimpleScan();
	void StrictScan(int procent);
	C_ScanWorker* getWorker();
};

#endif