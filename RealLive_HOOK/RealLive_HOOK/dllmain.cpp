// dllmain.cpp : 定义 DLL 应用程序的入口点。
//For 神曲奏界ポリフォニカ THE BLACK EPISODE 1&2 BOX EDITION
#include "framework.h"
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include "detours.h"
#include <oleauto.h>
#pragma comment(lib, "detours.lib")
using namespace std;

ofstream TXT("Text.txt");

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

char* wtocUTF(LPCTSTR str)
{
	DWORD dwMinSize;
	dwMinSize = WideCharToMultiByte(CP_UTF8, NULL, str, -1, NULL, 0, NULL, FALSE); //计算长度
	char* out = new char[dwMinSize];
	WideCharToMultiByte(CP_UTF8, NULL, str, -1, out, dwMinSize, NULL, FALSE);//转换
	return out;
}

wchar_t* ctow(const char* str)
{
	wchar_t* buffer = nullptr;
	if (str)
	{
		size_t nu = strlen(str);
		size_t n = (size_t)MultiByteToWideChar(932, 0, (const char*)str, int(nu), NULL, 0);
		buffer = 0;
		buffer = new wchar_t[n];
		memset(buffer, 0, sizeof(wchar_t) * (n));
		MultiByteToWideChar(932, 0, (const char*)str, int(nu), buffer, int(n));
	}
	return buffer;
}

wchar_t* ctow936(const char* str)
{
	wchar_t* buffer = nullptr;
	if (str)
	{
		size_t nu = strlen(str);
		size_t n = (size_t)MultiByteToWideChar(936, 0, (const char*)str, int(nu), NULL, 0);
		buffer = 0;
		buffer = new wchar_t[n];
		memset(buffer, 0, sizeof(wchar_t) * (n));
		MultiByteToWideChar(936, 0, (const char*)str, int(nu), buffer, int(n));
	}
	return buffer;
}

DWORD BaseAddr = (DWORD)GetModuleHandle(NULL);
static void make_console()
{
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
	std::cout << "DEBUG\n" << std::endl;
}
typedef bool (WINAPI* fnSetWindowTextA)(HWND hWnd, LPCSTR lpString);
typedef HFONT(WINAPI* fnCreateFontA)(_In_ int     nHeight,
	_In_ int     nWidth,
	_In_ int     nEscapement,
	_In_ int     nOrientation,
	_In_ int     fnWeight,
	_In_ DWORD   fdwItalic,
	_In_ DWORD   fdwUnderline,
	_In_ DWORD   fdwStrikeOut,
	_In_ DWORD   fdwCharSet,
	_In_ DWORD   fdwOutputPrecision,
	_In_ DWORD   fdwClipPrecision,
	_In_ DWORD   fdwQuality,
	_In_ DWORD   fdwPitchAndFamily,
	_In_ LPCTSTR lpszFace);
typedef int (WINAPI* fnEnumFontFamiliesExA)(
	HDC           hdc,
	LPLOGFONTA    lpLogfont,
	FONTENUMPROCA lpProc,
	LPARAM        lParam,
	DWORD         dwFlags
	);
typedef int (WINAPI* fnMessageboxA)(
	_In_opt_ HWND    hWnd,
	_In_opt_ LPCSTR lpText,
	_In_opt_ LPCSTR lpCaption,
	_In_     UINT    uType
	);
PVOID g_pOldCreateFileA = CreateFileA;
typedef HANDLE(WINAPI* PfuncCreateFileA)(
	LPCSTR lpFileName,
	DWORD dwDesiredAccess,
	DWORD dwShareMode,
	LPSECURITY_ATTRIBUTES lpSecurityAttributes,
	DWORD dwCreationDisposition,
	DWORD dwFlagsAndAttributes,
	HANDLE hTemplateFile
	);
fnMessageboxA MessageBoxAOLD;
fnCreateFontA pCreateFontA;
fnEnumFontFamiliesExA pEnumFontFamiliesExA;
PVOID g_pOldMultiByteToWideChar = NULL;
PVOID g_pOldCreateWindowExA = CreateWindowExA;
fnSetWindowTextA pSetWindowTextA;

typedef HWND(WINAPI* pfuncCreateWindowExA)(
	DWORD dwExStyle,
	LPCTSTR lpClassName,
	LPCTSTR lpWindowName,
	DWORD dwStyle,
	int x,
	int y,
	int nWidth,
	int nHeight,
	HWND hWndParent,
	HMENU hMenu,
	HINSTANCE hInstance,
	LPVOID lpParam);
HWND WINAPI NewCreateWindowExA(DWORD dwExStyle, LPCTSTR lpClassName, LPCTSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
	const char* szWndName = "神曲奏界 THE BLACK EPISODE 1&2 BOX EDITION";

	return ((pfuncCreateWindowExA)g_pOldCreateWindowExA)(dwExStyle, lpClassName, (LPCTSTR)szWndName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}
typedef int(WINAPI* PfuncMultiByteToWideChar)(
	_In_      UINT   CodePage,
	_In_      DWORD  dwFlags,
	_In_      LPCSTR lpMultiByteStr,
	_In_      int    cbMultiByte,
	_Out_opt_ LPWSTR lpWideCharStr,
	_In_      int    cchWideChar);


HFONT WINAPI newCreateFontA(_In_ int     nHeight,
	_In_ int     nWidth,
	_In_ int     nEscapement,
	_In_ int     nOrientation,
	_In_ int     fnWeight,
	_In_ DWORD   fdwItalic,
	_In_ DWORD   fdwUnderline,
	_In_ DWORD   fdwStrikeOut,
	_In_ DWORD   fdwCharSet,
	_In_ DWORD   fdwOutputPrecision,
	_In_ DWORD   fdwClipPrecision,
	_In_ DWORD   fdwQuality,
	_In_ DWORD   fdwPitchAndFamily,
	_In_ LPCSTR lpszFace)
{
	wchar_t* wcs = nullptr;
	fdwCharSet = GB2312_CHARSET;
	char buffer[0x100] = { 0 };
	memset(buffer, 0, 0x100);
	memcpy(buffer, lpszFace, strlen(lpszFace));
	wcs = ctow936(buffer);
	return CreateFontW(nHeight, nWidth, nEscapement, nOrientation, fnWeight, fdwItalic, fdwUnderline, fdwStrikeOut, fdwCharSet, fdwOutputPrecision, fdwClipPrecision, fdwQuality, fdwPitchAndFamily, wcs);
}

int WINAPI newEnumFontFamiliesExA(HDC hdc, LPLOGFONTA lpLogfont, FONTENUMPROCA lpProc, LPARAM lParam, DWORD dwFlags)
{
	LOGFONTA Lfont;
	memcpy(&Lfont, lpLogfont, sizeof(LOGFONTA));
	Lfont.lfCharSet = GB2312_CHARSET;
	memcpy(lpLogfont, &Lfont, sizeof(LOGFONTA));
	return ((fnEnumFontFamiliesExA)pEnumFontFamiliesExA)(hdc, lpLogfont, lpProc, lParam, dwFlags);
}

int WINAPI NewMultiByteToWideChar(UINT cp, DWORD dwFg, LPCSTR lpMBS, int cbMB, LPWSTR lpWCS, int ccWC)
{
	return ((PfuncMultiByteToWideChar)g_pOldMultiByteToWideChar)(936, dwFg, lpMBS, cbMB, lpWCS, ccWC);
}

int WINAPI MessageBoxAEx(_In_opt_ HWND    hWnd,
	_In_opt_ LPCSTR lpText,
	_In_opt_ LPCSTR lpCaption,
	_In_     UINT    uType)
{
	char* Pstr = wtocGBK(ctowJIS((char*)lpText));
	return MessageBoxAOLD(hWnd, Pstr, lpCaption, uType);
}

bool WINAPI newSetWindowTextA(HWND hw, LPCSTR lps)
{
	wchar_t newtitle[] = L"神曲奏界 THE BLACK EPISODE 1&2 BOX EDITION";
	return SetWindowTextW(hw, newtitle);
}

void EdenInitHook()
{
	pCreateFontA = (fnCreateFontA)GetProcAddress(GetModuleHandle(L"gdi32.dll"), "CreateFontA");
	pEnumFontFamiliesExA = (fnEnumFontFamiliesExA)GetProcAddress(GetModuleHandle(L"gdi32.dll"), "EnumFontFamiliesExA");
	pSetWindowTextA = (fnSetWindowTextA)GetProcAddress(GetModuleHandle(L"User32.dll"), "SetWindowTextA");
	g_pOldMultiByteToWideChar = DetourFindFunction("Kernel32.dll", "MultiByteToWideChar");
	MessageBoxAOLD = (fnMessageboxA)GetProcAddress(GetModuleHandle(L"User32.dll"), "MessageBoxA");

	DetourTransactionBegin();

	DetourAttach((void**)& pCreateFontA, newCreateFontA);
	DetourAttach((void**)& pEnumFontFamiliesExA, newEnumFontFamiliesExA);
	DetourAttach(&g_pOldMultiByteToWideChar, NewMultiByteToWideChar);
	DetourAttach((void**)& MessageBoxAOLD, MessageBoxAEx);
	DetourAttach(&g_pOldCreateWindowExA, NewCreateWindowExA);
	DetourAttach((void**)& pSetWindowTextA, newSetWindowTextA);

	if (DetourTransactionCommit() != NO_ERROR)
	{
		MessageBoxW(NULL, L"SOME ERROR!!!", L"EdenFileSystem", MB_OK | MB_ICONWARNING);
	}
}
/**********************************************************************************************************************/
#include <mutex>
static std::mutex mtx;
static PVOID JMPHookPoint;
static PVOID JMPHookPointNext;
static char* ret2;
char* __stdcall replaceText(char* src)
{

	__asm {
		pushad
		pushfd
	}
	auto PushStr = wtocGBK(ctowJIS(src));
	char* dst;
	cout << "0x" << strlen(src) << "|" << PushStr << endl;
	TXT << src << endl;
	ret2 = strcpy(dst, src);
	__asm {
		popfd
		popad
	}
	return ret2;
}
__declspec(naked) void JMP_FUNC()
{
	_asm
	{
		lea edx, dword ptr ss : [esp + 0x14]
		lea eax, dword ptr ss : [esp + 0x30]
		push edx
		lea ecx, dword ptr ss : [esp + 0x38]
		push eax
		lea edx, dword ptr ss : [esp + 0x34]
		push ecx
		lea eax, dword ptr ss : [esp + 0x34]
		push edx
		lea ecx, dword ptr ss : [esp + 0x34]
		push eax
		lea edx, dword ptr ss : [esp + 0x24]
		push ecx
		push edx
		push 0x0
		pushad
			push ebp
			call replaceText
		popad
		jmp JMPHookPointNext
	}
}
void JMPHelper(PVOID HookPoint, PVOID JMP_FUNC)
{
	DWORD oldProtect = 0;
	VirtualProtect(HookPoint, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
	DWORD offset = (DWORD)JMP_FUNC - (DWORD)HookPoint - 5;
	char JMPOp[] = { 0xE9 };
	memcpy(HookPoint, &JMPOp, 1);
	memcpy((char*)HookPoint + 1, &offset, sizeof(DWORD));
	VirtualProtect(HookPoint, 5, oldProtect, &oldProtect);
}

DWORD* (__cdecl* OldText)(int a1, DWORD* a2, DWORD* a3, DWORD* a4, unsigned int* a5, unsigned int* a6, DWORD* a7, DWORD* a8, DWORD* a9);
DWORD* __cdecl NewText(int a1, DWORD* a2, DWORD* a3, DWORD* a4, unsigned int* a5, unsigned int* a6, DWORD* a7, DWORD* a8, DWORD* a9)
{
	_asm
	{
		pushad
	}
	char* ret;
	int index;
	int rep;
	ret = (char*)a1;
	index = *(int*)ret;
	char* Pstr = ret + sizeof(int) - 4;
	cout << index << "|" << wtocGBK(ctowJIS(Pstr)) << endl;
	TXT << index << "|" << wtocGBK(ctowJIS(Pstr)) << endl;
	_asm
	{
		popad
	}
	return OldText(a1, a2, a3, a4,a5,a6,a7,a8,a9);
}

void TextHook()
{
	cout << "BaseAddress:0x" << hex << BaseAddr << endl;
	//TXT << "BaseAddress:0x" << hex << BaseAddr << endl;
	
	*(DWORD*)& JMPHookPoint = BaseAddr + 0xA3A21;
	*(DWORD*)& JMPHookPointNext = BaseAddr + 0xA3A46;
	cout << JMPHookPoint << " | " << JMPHookPointNext << "\n------------------------------\nREALLIVE DEBUG MODE VER 1.00\nCreate By SORATANE（空穜）\n------------------------------\n" << endl;
	JMPHelper(JMPHookPoint, JMP_FUNC);
	/*
	*(DWORD*)& OldText = BaseAddr + 0xA2270;
	cout << "HookAddress:0x" << hex << (BaseAddr + 0xA2270) << "\n------------------------------\nREALLIVE DEBUG MODE VER 1.00\nCreate By SORATANE（空穜）\n------------------------------\n" << endl;
	//TXT << "HookAddress:0x" << hex << (BaseAddr + 0xA2270) << endl;
	DetourTransactionBegin();
	DetourAttach((void**)& OldText, NewText);
	if (DetourTransactionCommit() != NO_ERROR)
	{
		MessageBoxW(NULL, L"SOME ERROR!!!", L"EdenFileSystem", MB_OK | MB_ICONWARNING);
	}
	*/
	
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		make_console();
		EdenInitHook();
		TextHook();
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

