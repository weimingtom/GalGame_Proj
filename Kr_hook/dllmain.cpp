// dllmain.cpp : 定义 DLL 应用程序的入口点。
//mb2wc_Hook在krkr2上的实例，实际效果请参考《向日葵 Aqua After》的汉化。
#include "stdafx.h"
#include "detours.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include "crc32.h"
#include <iomanip>
#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#pragma comment(lib, "detours.lib")
using namespace std;

map<DWORD, wstring> REPList;

PVOID g_pOldMultiByteToWideChar = NULL;
typedef int(WINAPI *PfuncMultiByteToWideChar)(
	_In_      UINT   CodePage,
	_In_      DWORD  dwFlags,
	_In_      LPCSTR lpMultiByteStr,
	_In_      int    cbMultiByte,
	_Out_opt_ LPWSTR lpWideCharStr,
	_In_      int    cchWideChar);

char* wtocUTF(LPCTSTR str)
{
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(CP_UTF8, NULL, str, -1, NULL, 0, NULL, FALSE); //计算长度
	char *out = new char[dwMinSize];
	WideCharToMultiByte(CP_UTF8, NULL, str, -1, out, dwMinSize, NULL, FALSE);//转换
	return out;
}

char* wtocGBK(LPCTSTR str)
{
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(936, NULL, str, -1, NULL, 0, NULL, FALSE); //计算长度
	char *out = new char[dwMinSize];
	WideCharToMultiByte(936, NULL, str, -1, out, dwMinSize, NULL, FALSE);//转换
	return out;
}

LPWSTR ctowUTF(char* str)
{
	DWORD dwMinSize;
	dwMinSize = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0); //计算长度
	LPWSTR out = new wchar_t[dwMinSize];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, out, dwMinSize);//转换
	return out;
}


int WINAPI NewMultiByteToWideChar(UINT cp, DWORD dwFg, LPCSTR lpMBS, int cbMB, LPWSTR lpWCS, int ccWC)
{
	__asm
	{
		pushad
	}
	CRC32 crc;
	int ret = 0;
	ret = ((PfuncMultiByteToWideChar)g_pOldMultiByteToWideChar)(cp, dwFg, lpMBS, cbMB, lpWCS, ccWC);
	if (lpWCS != 0 && (USHORT)*lpWCS > 0x20)//检测所有的有效字符
	{
			wstring wstr = lpWCS;
			DWORD strcrc = crc.Calc((char*)lpWCS, ret);
			auto scitr = REPList.find(strcrc);
			if (scitr!= REPList.end())
			{
				wcscpy(lpWCS, scitr->second.c_str());
				ret = scitr->second.length();
				
			}

	}
	__asm
	{
		popad
	}
	return ret;
}

void LoadStringMap()
{
	ifstream fin("Crescendo.ini");
	const int LineMax = 0x99999;//其实用不到这么大，懒得计算了而已
	char str[LineMax];
	if (fin.is_open())
	{
		while (fin.getline(str,LineMax))
		{
			auto wtmp = ctowUTF(str);
			wstring wline = wtmp;
			wstring crcval = wline.substr(2, 8);
			wstring wstr = wline.substr(11);
			DWORD crc = wcstoul(crcval.c_str(), NULL, 16);
			//cout << "LOAD:" <<"0x"<<hex<<crc<< wtocGBK(wstr.c_str()) << endl;
			REPList.insert(pair<DWORD, wstring>(crc, wstr));
		}
	}
	else
	{
		MessageBox(0, L"配置文件读取失败", L"ERROR", MB_OK);
	}
}

void HookStart() 
{
	g_pOldMultiByteToWideChar = DetourFindFunction("Kernel32.dll", "MultiByteToWideChar");
	DetourTransactionBegin();
	DetourAttach(&g_pOldMultiByteToWideChar, NewMultiByteToWideChar);
	DetourTransactionCommit();
}



BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		Photo();
		LoadStringMap();
		HookStart();
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

extern "C" __declspec(dllexport) void dummy(void) {
	return;
}
