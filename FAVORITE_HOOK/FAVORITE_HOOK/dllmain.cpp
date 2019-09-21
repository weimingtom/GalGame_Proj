// dllmain.cpp : 定义 DLL 应用程序的入口点。
//For: さくら、もゆ。 -as the Night's, Reincarnation-
#include "framework.h"
#include "detours.h"
#include <fstream>
#include <iostream>
#include <map>
#include <vector>
#include <sstream>
#include "crc32.h"
#include <iomanip>
#include <mutex>
#pragma comment(lib, "detours.lib")

using namespace std;
ofstream TXT("Text.txt");
ofstream SYSTEM("System.txt");

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

typedef int (WINAPI* fnEnumFontFamiliesExA)(
	HDC           hdc,
	LPLOGFONTA    lpLogfont,
	FONTENUMPROCA lpProc,
	LPARAM        lParam,
	DWORD         dwFlags
	);
fnEnumFontFamiliesExA pEnumFontFamiliesExA;
int WINAPI newEnumFontFamiliesExA(HDC hdc, LPLOGFONTA lpLogfont, FONTENUMPROCA lpProc, LPARAM lParam, DWORD dwFlags)
{
	//lpLogfont->lfCharSet = 936;
	LOGFONTA Lfont;
	memcpy(&Lfont, lpLogfont, sizeof(LOGFONTA));
	Lfont.lfCharSet = GB2312_CHARSET;
	memcpy(lpLogfont, &Lfont, sizeof(LOGFONTA));
	return ((fnEnumFontFamiliesExA)pEnumFontFamiliesExA)(hdc, lpLogfont, lpProc, lParam, dwFlags);
}

typedef HFONT(WINAPI* fnCreateFontA)(
	int nHeight, // logical height of font height
	int nWidth, // logical average character width
	int nEscapement, // angle of escapement
	int nOrientation, // base-line orientation angle
	int fnWeight, // font weight
	DWORD fdwItalic, // italic attribute flag
	DWORD fdwUnderline, // underline attribute flag
	DWORD fdwStrikeOut, // strikeout attribute flag
	DWORD fdwCharSet, // character set identifier
	DWORD fdwOutputPrecision, // output precision
	DWORD fdwClipPrecision, // clipping precision
	DWORD fdwQuality, // output quality
	DWORD fdwPitchAndFamily, // pitch and family
	LPCSTR lpszFace // pointer to typeface name string
	);
fnCreateFontA CreateFontAOLD;
HFONT WINAPI CreateFontAEx(int nHeight, int nWidth, int nEscapement, int nOrientation, int fnWeight, DWORD fdwItalic, DWORD fdwUnderline, DWORD fdwStrikeOut, DWORD fdwCharSet, DWORD fdwOutputPrecision, DWORD fdwClipPrecision, DWORD fdwQuality, DWORD fdwPitchAndFamily, LPCSTR lpszFace)
{
	if (fdwCharSet == 0x80)
	{
		fdwCharSet = 0;
		fnWeight = FW_SEMIBOLD;
		return CreateFontAOLD(nHeight, nWidth, nEscapement, nOrientation, fnWeight, fdwItalic, fdwUnderline, fdwStrikeOut, fdwCharSet, fdwOutputPrecision, fdwClipPrecision, fdwQuality, fdwPitchAndFamily, "黑体");
	}

	return CreateFontAOLD(nHeight, nWidth, nEscapement, nOrientation, fnWeight, fdwItalic, fdwUnderline, fdwStrikeOut, fdwCharSet, fdwOutputPrecision, fdwClipPrecision, fdwQuality, fdwPitchAndFamily, lpszFace);
}

PVOID g_pOldCreateWindowExA = CreateWindowExA;
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
	const char* szWndName = "『樱花、萌放。 -as the Night's, Reincarnation-』中文测试程序";

	return ((pfuncCreateWindowExA)g_pOldCreateWindowExA)(dwExStyle, lpClassName, (LPCTSTR)szWndName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

//立绘异常处理
typedef int (WINAPI* fnlstrcmpiA)(LPCSTR lpString1, LPCSTR lpString2);
fnlstrcmpiA plstrcmpiA;
int WINAPI MylstrcmpiA(LPCSTR lpString1, LPCSTR lpString2)
{
	auto SystemStr = wtocUTF(ctowJIS((char*)lpString2));
	cout   << "【SYSTEM】	|" << wtocGBK(ctowJIS((char*)lpString2)) <<endl;
	SYSTEM <<  lpString2 <<endl;
	int ret = CompareStringA(0x411, 1, lpString1, -1, lpString2, -1);
	return ret - 2;

}
//文本
/*FVP所有文本只会出现一次，再次出现时就直接调用内存了，所以在写hook的时候还要小心一点。*/
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
	auto PushStr = wtocUTF(ctowJIS(src));
	char* dst;
	cout <<"【TEXT】	|"<< wtocGBK(ctowJIS(src)) << endl;
	TXT  << PushStr << endl;
	/*
	if (strcmp(PushStr, "そのほんの少しの隙間から、どこからか小さな春色が舞い込んで――") == 0) {
		strcpy(src, "在那狭窄的间隙中，飘来了不知何处的小小春色――");
	}
	if (strcmp(PushStr, "　世界がそっと、ため息をつく――") == 0) {
		strcpy(src, "　世界悄然地，发出一声叹息——");
	}
	*/
	ret2 = strcpy(dst, src);

	__asm {
		popfd
		popad
	}
	return ret2;
}
//窗口乱码
wchar_t szTitle[] = L"提示";
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
	return MessageBoxAOLD(hWnd, Pstr, wtocGBK(szTitle), uType);
}

__declspec(naked) void JMP_FUNC()
{
	_asm
	{
		push esi
		call replaceText
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

void Hook()
{
	DWORD BaseAddr = (DWORD)GetModuleHandle(NULL);
	cout << "BaseAddress:0x" << hex << BaseAddr << endl;
	/*JMPHookPoint：
	0043CAF9   .  49            dec ecx                                  ;  Sakura_o.<ModuleEntryPoint>
	0043CAFA   .  6A 00         push 0x0
	0043CAFC   >  85F6          test esi,esi                             ;  Sakura_o.<ModuleEntryPoint>
	0043CAFE   .  74 56         je short Sakura_o.0043CB56
	0043CB00   .  56            push esi                                 ; /String = "璐?	==> JMPHookPoint HERE
	0043CB01   .  FF15 C0D04500 call dword ptr ds:[<&KERNEL32.lstrlenA>] ; \lstrlenA

	JMPHookPointNext:
	0043CB01   .  FF15 C0D04500 call dword ptr ds:[<&KERNEL32.lstrlenA>] ; \lstrlenA
	0043CB07   .  3D 00020000   cmp eax,0x200
	0043CB0C   .  7C 40         jl short Sakura_o.0043CB4E
	0043CB0E   .  68 80000000   push 0x80
	0043CB13   .  E8 EDB00000   call Sakura_o.00447C05
	0043CB18   .  83C4 04       add esp,0x4
	0043CB1B   .  85C0          test eax,eax
	0043CB1D   .  74 1A         je short Sakura_o.0043CB39
	0043CB1F   .  8B4F 04       mov ecx,dword ptr ds:[edi+0x4]
	0043CB22   .  56            push esi                                 ;  Sakura_o.<ModuleEntryPoint>
	0043CB23   .  68 FF010000   push 0x1FF
	0043CB28   .  51            push ecx                                 ;  Sakura_o.<ModuleEntryPoint>
	0043CB29   .  68 1CDC4500   push Sakura_o.0045DC1C
	0043CB2E   .  50            push eax
	0043CB2F   .  E8 BC8DFEFF   call Sakura_o.004258F0
	0043CB34   .  83C4 14       add esp,0x14
	0043CB37   .  EB 02         jmp short Sakura_o.0043CB3B
	0043CB39   >  33C0          xor eax,eax
	0043CB3B   >  68 ECB84700   push Sakura_o.0047B8EC
	0043CB40   .  8D5424 1C     lea edx,dword ptr ss:[esp+0x1C]
	0043CB44   .  52            push edx                                 ;  Sakura_o.<ModuleEntryPoint>
	0043CB45   .  894424 20     mov dword ptr ss:[esp+0x20],eax
	0043CB49   .  E8 2EB80000   call Sakura_o.0044837C
	0043CB4E   >  56            push esi                                 ;  ==> JMPHookPointNext HERE
	0043CB4F   .  8BCD          mov ecx,ebp
	0043CB51   .  E8 BA6AFFFF   call Sakura_o.00433610
	*/
	*(DWORD*)& JMPHookPoint = BaseAddr + 0x3CB00;
	*(DWORD*)& JMPHookPointNext = BaseAddr + 0x3CB4E;
	cout   << JMPHookPoint << " | " << JMPHookPointNext << "\n------------------------------\nFVP DEBUG MODE VER 1.00\nCreate By SORATANE（空穜）\n------------------------------\n"<<endl;
	JMPHelper(JMPHookPoint, JMP_FUNC);
	CreateFontAOLD = (fnCreateFontA)GetProcAddress(GetModuleHandle(L"gdi32.dll"), "CreateFontA");
	MessageBoxAOLD = (fnMessageboxA)GetProcAddress(GetModuleHandle(L"User32.dll"), "MessageBoxA");
	plstrcmpiA = (fnlstrcmpiA)GetProcAddress(GetModuleHandle(L"Kernel32.dll"), "lstrcmpiA");
	pEnumFontFamiliesExA = (fnEnumFontFamiliesExA)GetProcAddress(GetModuleHandle(L"gdi32.dll"), "EnumFontFamiliesExA");
	DetourTransactionBegin();
	//DetourAttach((void**)& CreateFontAOLD, CreateFontAEx);
	DetourAttach(&g_pOldCreateWindowExA, NewCreateWindowExA);
	DetourAttach((void**)& plstrcmpiA, MylstrcmpiA);
	DetourAttach((void**)& MessageBoxAOLD, MessageBoxAEx);
	DetourAttach((void**)& pEnumFontFamiliesExA, newEnumFontFamiliesExA);
	if (DetourTransactionCommit() != NOERROR) { MessageBox(NULL, L"ERROR", L"Crescendo", MB_OK); }
}

static void make_console() {
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdin);
	cout << "Console\n" << endl;
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
		Hook();
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
