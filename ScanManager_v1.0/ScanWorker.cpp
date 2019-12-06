#include "ScanWorker.h"
#include<string.h>
#include<iostream>
#include"Exceptie.h"	

#include"Errors.h"

using namespace std;

C_ScanWorker::C_ScanWorker()
{
	Data = new C_DataBase;
	Data = NULL;
	head = new workerList;
	head = NULL;
	m_MaxWorkers = 0;
	m_id = -1;
}

C_ScanWorker::C_ScanWorker(C_StringManager*p_String, int MaxWorkers)
{
	head = new workerList;
	head = NULL;
	Data = new C_DataBase;
	m_MaxWorkers = MaxWorkers;
	m_id = -1; 
	selectWorkers(p_String);
}

void C_ScanWorker::selectWorkers(C_StringManager * p_String)
{

	List* copy = new List;
	copy = p_String->getHead();
	while (copy != NULL)
	{
		workerList* copyHead = new workerList;
		copyHead = head;
		if (strstr(copy->name, "txt") != NULL)
		{
			if (copyHead == NULL)
			{
				copyHead = new workerList;
				copyHead->txt = new C_TxtWorker(copy->name,++m_id,Data);
				copyHead->exe = NULL;
				copyHead->next = NULL;
				head = copyHead;
			}
			else
			{
				while (copyHead->next != NULL)
					copyHead = copyHead->next;
				copyHead->next = new workerList;
				copyHead->next->txt = new C_TxtWorker(copy->name,++m_id,Data);
				copyHead->next->exe = NULL;
				copyHead->next->next = NULL;
			}
		}
		else
		{
			if (strstr(copy->name, "exe") != NULL)
			{
				if (copyHead == NULL)
				{
					copyHead = new workerList;
					copyHead->exe = new C_ExeWorker(copy->name,++m_id,Data);
					copyHead->txt = NULL;
					copyHead->next = NULL;
					head = copyHead;
				}
				else
				{
					while (copyHead->next != NULL)
						copyHead = copyHead->next;
					copyHead->next = new workerList;
					copyHead->next->exe = new C_ExeWorker(copy->name,++m_id,Data);
					copyHead->next->txt = NULL;
					copyHead->next->next = NULL;
				}

			}
		}
		copy = copy->next;
	}

}

void C_ScanWorker::SimpleScan()
{
	workerList*copyHead = head;
	if (!copyHead)
		throw new CExceptie(ERROR_LIST_HEAD, "head lista inexistent");
	else
	{
		while (copyHead != NULL)
		{
			if (copyHead->txt != NULL)
				copyHead->txt->verify(Data, 100);
			else
				if (copyHead->exe != NULL)
					copyHead->exe->verify(Data, 100);
			copyHead = copyHead->next;
		}
	}
	afisaresimple();
}

void C_ScanWorker::StrictScan(int procent)
{
	workerList*copyHead = head;
	if (!copyHead)
		throw new CExceptie(ERROR_LIST_HEAD, "head lista inexistent");
	else
	{
		while (copyHead != NULL)
		{
			if (copyHead->txt != NULL)
				copyHead->txt->verify(Data, procent);
			else
				if (copyHead->exe != NULL)
					copyHead->exe->verify(Data, procent);
			copyHead = copyHead->next;
		}
	}
	afisarestrict();
}

void C_ScanWorker::afisaresimple()
{
	FILE *fOut = fopen("SimpleScanReport.txt", "w");
	fwrite("", 0, 0, fOut);
	fclose(fOut);
	FILE *fOu = fopen("SimpleScanReport.txt", "a");
	workerList*copyHead = head;
	if (!copyHead)
		throw new CExceptie(ERROR_LIST_HEAD, "head lista inexistent");
	else
	{
		while (copyHead != NULL)
		{
			if (copyHead->txt != NULL)
				fprintf(fOu, "%s %d %s %s %s %d\n", copyHead->txt->getFileName(), copyHead->txt->getm_WorkerId(), copyHead->txt->getType(), copyHead->txt->getSimpleState(), "numar de erori:",copyHead->txt->getSimpleErrors());
				copyHead = copyHead->next;
		}
	}
	fclose(fOu);
}

void C_ScanWorker::afisarestrict()
{
	FILE *fOut = fopen("StrictScanReport.txt", "w");
	fwrite("", 0, 0, fOut);
	fclose(fOut);
	FILE *fOu = fopen("StrictScanReport.txt", "a");
	workerList*copyHead = head;
	if (!copyHead)
		throw new CExceptie(ERROR_LIST_HEAD, "head lista inexistent");
	else
	{
		while (copyHead != NULL)
		{
			if (copyHead->txt != NULL)
				fprintf(fOu, "%s %d %s %s %s %d\n", copyHead->txt->getFileName(), copyHead->txt->getm_WorkerId(), copyHead->txt->getType(), copyHead->txt->getStrictState(), "numar de erori:", copyHead->txt->getStrictErrors());
			copyHead = copyHead->next;
		}
	}
	fclose(fOu);
}

C_DataBase * C_ScanWorker::getData()
{
	return Data;
}


