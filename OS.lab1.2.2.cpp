// OS.lab1.2.2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;


void Compute()
{
	int y, x;
	while (true)
	{
		for (x = 0; x<11; x++)
		{
			y = x ^ 3 + 2 * x ^ 2 + 3 * x + 10;
			cout << y << endl;
			x = x - 0, 99;
			Sleep(500);
		}
	}
}
int main(int argc, _TCHAR* argv[])
{
	HANDLE hThread;
	DWORD ID;
	DWORD Par = 0;
	int ST = 0;
	bool flg = 0;
	cout << "Press '3' for exit" << endl;
	hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Compute, (LPVOID)Par, 0, (LPDWORD)&ID);
	while (true)
	{
		switch (ST)
		{
		case 1:
		{
			SuspendThread(hThread);
			ST = 0;
			cout << "Press '2' for stop" << endl;
		}
		break;
		case 2:
		{
			cout << "Press '1' for play" << endl;
			ResumeThread(hThread);
			ST = 0;
		}
		break;
		case 3:
		{
			TerminateThread(hThread, 0);
			cout << "End" << endl;
			ST = 0;
			exit(0);
		}
			break;
	    }
		cin >> ST;

	}
	return 0;
}




















/*void Sleep(BYTE time)
{
Sleep((DWORD)time*1000);
return;
}

void main(){
int s = 0;
STARTUPINFO si = { sizeof(si) };
PROCESS_INFORMATION pi;
//
//D:\\Ксюша\\институт\\Операционные системы\\Лабораторные\\OS.lab1.1\\Debug\\OS.lab1.1.exe
//D:\\user51\\Visual Studio 2008\\Projects\\OS.lab1.1\\OS.lab1.1\\Debug\\OS.lab1.1.exe
cout << "Press '1' for play" << endl;
cout << "Press '2' for stop" << endl;
//cout << "Press '3' for exit" << endl;
while (s<=3)
{
cin >> s;
if (s == 1)        //запуск метода
{
CreateProcess(TEXT("D:\\user51\\Visual Studio 2008\\Projects\\OS.lab1.1\\OS.lab1.1\\Debug\\OS.lab1.1.exe"), NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
}
else if (s == 2)			//приостановка метода
{
DWORD dwExitCode;
BOOL fSuccess = WaitForSingleObject(pi.hProcess, INFINITE);
CloseHandle(pi.hProcess);
// VOID ExilProcess(UINT fuExitCode);
//  BOOL TerminateProcess( HANDLE hProcoss, UINT uExitCode);
WaitForSingleObject(pi.hProcess, INFINITE);
GetExitCodeProcess(pi.hProcess, &dwExitCode);
//CreateProcess(TEXT("F:\\USER51\\ИВБ-511\\Poberezhnay\\ОперацСист\\OS.lab1.1\\Debug\\OS.lab1.1.exe"), NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE , NULL, NULL, &si, &pi);
//BOOL GetExitCodeProcess( HANDLE hProcess, PDWORD pdwExitCode);
}
else if (s > 3)
{  cout << "Error" << endl; }
}
//TerminateProcess(pi.hProcess, NO_ERROR); // убрать процесс
system("pause");
}*/
