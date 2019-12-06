#include"ScanManager.h"
#include"Errors.h"
#include"Exceptie.h"
#include"TxtWorker.h"
#include"ExeWorker.h"
using namespace std;
#include<iostream>

C_ScanManager::C_ScanManager(char * FileName, int MaxWorkers)
{
	
	m_String = new C_StringManager(FileName);
	m_Worker = new C_ScanWorker(m_String,MaxWorkers);
}

C_ScanManager::C_ScanManager(C_ScanManager * A)
{
	this->m_Worker = A->m_Worker;
	this->m_String = A->m_String;
}

C_ScanManager *C_ScanManager::single = NULL;

C_ScanManager *C_ScanManager::getInstance(char* FileName, int MaxWorkers)
{
	if (!single)
	{
		single = new C_ScanManager(FileName,MaxWorkers);
		return single;
	}
	throw new CExceptie(ERROR_SINGLETON, "S-a creat deja un ScanManager\n");
	return NULL;
}

void C_ScanManager::SimpleScan()
{
	m_Worker->SimpleScan();
}

void C_ScanManager::StrictScan(int procent)
{
	m_Worker->StrictScan(procent);
}

C_ScanWorker * C_ScanManager::getWorker()
{
	return m_Worker;
}
