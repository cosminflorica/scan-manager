#include "ScanManager.h"
#include "Exceptie.h"
#include<iostream>

using namespace std;

int main()
{
	try
	{
		C_ScanManager *C = C_ScanManager::getInstance("1.txt 2.txt 3.exe", 10);
		C->SimpleScan();
		C->StrictScan(50);
	  C->getWorker()->getData()->dataBaseUpdate("ana are mere");
		 C->getWorker()->getData()->up_to_date();

	}
	catch (CExceptie *e)
	{
		cout <<"Cod eroare: "<< e->getCode() << " Mesaj: " << e->getMessage();
	}
}