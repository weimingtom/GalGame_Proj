// dllmain.cpp : 定义 DLL 应用程序的入口点。
//for 家神女房-イエガミニョウボウ- ～名無し猫又は神Tuber～
#include "framework.h"
#include "detours.h"
#pragma comment(lib, "detours.lib")

using namespace std;

LPWSTR ctowJIS(char* str)
{
	DWORD dwMinSize;
	dwMinSize = MultiByteToWideChar(932, 0, str, -1, NULL, 0); //计算长度
	LPWSTR out = new wchar_t[dwMinSize];
	MultiByteToWideChar(932, 0, str, -1, out, dwMinSize);//转换
	return out;
}

char* wtocGBK(LPCTSTR str)
{
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(936, NULL, str, -1, NULL, 0, NULL, FALSE); //计算长度
	char* out = new char[dwMinSize];
	WideCharToMultiByte(936, NULL, str, -1, out, dwMinSize, NULL, FALSE);//转换
	return out;
}

PVOID g_pOldCreateFontIndirectA = CreateFontIndirectA;
typedef HFONT(WINAPI* PfuncCreateFontIndirectA)(LOGFONTA* lplf);
HFONT WINAPI NewCreateFontIndirectA(LOGFONTA* lplf)
{
	lplf->lfCharSet = GB2312_CHARSET;
	strcpy(lplf->lfFaceName, "黑体");

	return ((PfuncCreateFontIndirectA)g_pOldCreateFontIndirectA)(lplf);
}

//处理最后的人名乱码
PVOID g_pOldTextOutA = TextOutA;
typedef HWND(WINAPI* pfuncTextOutA)(
	HDC    hdc,
	int    x,
	int    y,
	LPCSTR lpString,
	int    c
	);
HWND WINAPI NewTextOutA(HDC hdc, int x, int y, LPCSTR lpString, int c)
{
	char* Text = (char*)lpString;
	char* Pstr = wtocGBK(ctowJIS(Text));//避免正文内容受到影响
	/*
	???F倅
	???F倅
	?F倅
	倅
	??寝々子
	??寝々子
	寝々子
	々子
	子
	*/
	if (strcmp(Pstr, "?F倅") == 0)
	{
		return ((pfuncTextOutA)g_pOldTextOutA)(hdc, x, y, "贵树", c);
	}
	if (strcmp(Pstr, "倅") == 0)
	{
		return ((pfuncTextOutA)g_pOldTextOutA)(hdc, x, y, "树", c);
	}
	if (strcmp(Pstr, "寝々子") == 0)
	{
		return ((pfuncTextOutA)g_pOldTextOutA)(hdc, x, y, "眠子", c);

	}
	if (strcmp(Pstr, "々子") == 0)
	{
		return ((pfuncTextOutA)g_pOldTextOutA)(hdc, x, y, "子", c);

	}
	if (strcmp(Pstr, "子") == 0)
	{
		return ((pfuncTextOutA)g_pOldTextOutA)(hdc, x, y, " ", c);//lpString为空会出现迷惑字符

	}
	else
	{
		return ((pfuncTextOutA)g_pOldTextOutA)(hdc, x, y, lpString, c);

	}
}

//窗口乱码处理
wchar_t szTitle[] = L"确认";
typedef int (WINAPI* fnMessageboxA)(
	_In_opt_ HWND    hWnd,
	_In_opt_ LPCSTR lpText,
	_In_opt_ LPCSTR lpCaption,
	_In_     UINT    uType
	);
fnMessageboxA MessageBoxAOLD;
int WINAPI MessageBoxAEx(_In_opt_ HWND    hWnd,
	_In_opt_ LPCSTR lpText,
	_In_opt_ LPCSTR lpCaption,
	_In_     UINT    uType)
{
	char* Pstr = wtocGBK(ctowJIS((char*)lpText));
	if (strcmp(Pstr, "ゲームを終了します。よろしいですか？") == 0)
	{
		strcpy(Pstr, "即将结束游戏。确认吗？");

	}
	if (strcmp(Pstr, "こちらでよろしいですか？（途中で変更は出来ません）") == 0)
	{
		strcpy(Pstr, "这样可以吗？（中途无法再改变）");

	}
	return MessageBoxAOLD(hWnd, Pstr, wtocGBK(szTitle), uType);
}

void Hook()
{
	DWORD BaseAddr = (DWORD)GetModuleHandle(NULL);
	g_pOldTextOutA = (pfuncTextOutA)GetProcAddress(GetModuleHandleW(L"gdi32.dll"), "TextOutA");
	MessageBoxAOLD = (fnMessageboxA)GetProcAddress(GetModuleHandle(L"User32.dll"), "MessageBoxA");
	DetourTransactionBegin();
	DetourAttach(&g_pOldCreateFontIndirectA, NewCreateFontIndirectA);
	DetourAttach(&g_pOldTextOutA, NewTextOutA);
	DetourAttach((void**)& MessageBoxAOLD, MessageBoxAEx);
	if (DetourTransactionCommit() != NOERROR) { MessageBox(NULL, L"ERROR", L"Crescendo", MB_OK); }
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD Reason, LPVOID lpReserved)
{
	switch (Reason)
	{
	case DLL_PROCESS_ATTACH:
		Hook();

	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
extern "C" __declspec(dllexport) void dummy(void) {
	return;
}
