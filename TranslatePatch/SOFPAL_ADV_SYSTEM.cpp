﻿char* RepString(int pos, int bufsize)
{
	_asm
	{
		pushad
	}
	char* ret;
	int index;
	ret = GetTextByIndexOld(pos, bufsize);
	index = *(int*)ret;
	char* Pstr = ret + sizeof(int);
	if (debug)
		cout << "Index:" << index << " Str:" << wtocGBK(ctowJIS(Pstr)) << endl;
	wchar_t* tmpStr = ctowJIS(Pstr);
	ScriptInsert(tmpStr, Pstr);
	if (!TitleChanged)
	{
		HWND Target = FindWindowW(NULL, L"ナツイロココロログ～Happy Summer～");
		SetWindowText(Target, szTitle);
		TitleChanged = true;
	}
	_asm
	{
		popad
	}
	return ret;
}

HFONT WINAPI CreateFontAEx(int nHeight, int nWidth, int nEscapement, int nOrientation, int fnWeight, DWORD fdwItalic, DWORD fdwUnderline, DWORD fdwStrikeOut, DWORD fdwCharSet, DWORD fdwOutputPrecision, DWORD fdwClipPrecision, DWORD fdwQuality, DWORD fdwPitchAndFamily, LPCSTR lpszFace)
{
	if (fdwCharSet == 0x80)
	{
		fdwCharSet = 0;
		fnWeight = FW_SEMIBOLD;
		if (strcmp(lpszFace, "俵俽 僑僔僢僋") == 0)
		{
			return CreateFontAOLD(nHeight, nWidth, nEscapement, nOrientation, fnWeight, fdwItalic, fdwUnderline, fdwStrikeOut, fdwCharSet, fdwOutputPrecision, fdwClipPrecision, fdwQuality, fdwPitchAndFamily, "黑体");
		}
		else if (strcmp(lpszFace, "俵俽 柧挬") == 0)
		{
			return CreateFontAOLD(nHeight, nWidth, nEscapement, nOrientation, fnWeight, fdwItalic, fdwUnderline, fdwStrikeOut, fdwCharSet, fdwOutputPrecision, fdwClipPrecision, fdwQuality, fdwPitchAndFamily, "宋体");
		}
	}

	return CreateFontAOLD(nHeight, nWidth, nEscapement, nOrientation, fnWeight, fdwItalic, fdwUnderline, fdwStrikeOut, fdwCharSet, fdwOutputPrecision, fdwClipPrecision, fdwQuality, fdwPitchAndFamily, lpszFace);
}

int WINAPI NewCreateFontIndirectA(LOGFONTA* lplf)
{
	strcpy(lplf->lfFaceName, "黑体");
	lplf->lfCharSet = GB2312_CHARSET;

	return ((PfuncCreateFontIndirectA)g_pOldCreateFontIndirectA)(lplf);
}

int WINAPI MessageBoxAEx(_In_opt_ HWND    hWnd,
	_In_opt_ LPCSTR lpText,
	_In_opt_ LPCSTR lpCaption,
	_In_     UINT    uType)
{
	char* Pstr = wtocGBK(ctowJIS((char*)lpText));
	if (strcmp(Pstr, "本当に終了しますか？") == 0)
	{
		strcpy(Pstr, "确认要结束游戏吗？");
	}
	return MessageBoxAOLD(hWnd, Pstr, "夏色心跳日志～Happy Summer～", uType);
}

HMODULE WINAPI MyLLEA(
	LPCSTR lpLibFileName,
	HANDLE HfILE,
	DWORD dwFlags
)
{
	HMODULE Head = LoadLibraryExA_Old(lpLibFileName,HfILE,dwFlags);
	DWORD Addr = (DWORD)Head;
	string LibName(lpLibFileName);
	string strName = LibName.substr(LibName.find_last_of("\\") + 1);
	if (strName == "PAL.dll")
	{
		//cout << strName << endl;
		//cout << "0x" << hex << Addr << endl;
		PalAddr = Addr;
	}
	return Head;
}

int WINAPI NewSetWindowTextA(HWND hwnd, LPCTSTR lpString)
{
	/*
	00000000h: 8F 89 8B 4E 93 AE 8E 9E 82 CC 83 45 83 43 83 93 ; 弶婲摦帪偺僂僀儞
	00000010h: 83 68 83 45 83 82 81 5B 83 68 82 F0 90 DD 92 E8 ; 僪僂儌乕僪傪愝掕
	00000020h: 82 B5 82 DC 82 B7 81 42 0D 0A 83 74 83 8B 83 58 ; 偟傑偡丅..僼儖僗
	00000030h: 83 4E 83 8A 81 5B 83 93 82 C5 83 51 81 5B 83 80 ; 僋儕乕儞偱僎乕儉
	00000040h: 82 F0 8A 4A 8E 6E 82 B7 82 E9 81 42 20 20       ; 傪奐巒偡傞丅  
	*/
	cout << (char*)(LPCTSTR)lpString << endl;
	if (strcmp((char*)(LPCTSTR)lpString, "弶婲摦帪偺僂僀儞僪僂儌乕僪傪愝掕偟傑偡丅")==0)
	{
		return ((PfuncSetWindowTextA)g_pOldSetWindowTextA)(hwnd, (LPCTSTR)(char*)"第一次启动游戏请选择显示模式。");
	}
	else if (strcmp((char*)(LPCTSTR)lpString, "僼儖僗僋儕乕儞偱僎乕儉傪奐巒偡傞丅") == 0)
	{
		return ((PfuncSetWindowTextA)g_pOldSetWindowTextA)(hwnd, (LPCTSTR)(char*)"以全屏模式启动");
	}
	else
	{
		return ((PfuncSetWindowTextA)g_pOldSetWindowTextA)(hwnd, lpString);
	}
}

void GetPalAddr()
{
	LoadLibraryExA_Old = (PfuncLoadLibraryExA)GetProcAddress(GetModuleHandle(L"kernel32.dll"), "LoadLibraryExA");
	DetourTransactionBegin();
	DetourAttach((void**)& LoadLibraryExA_Old, MyLLEA);
	DetourTransactionCommit();
}

HWND WINAPI NewCreateWindowExA(DWORD dwExStyle, LPCTSTR lpClassName, LPCTSTR lpWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU hMenu, HINSTANCE hInstance, LPVOID lpParam)
{
	const char* szWndName = "夏色心跳日志～Happy Summer～";

	return ((pfuncCreateWindowExA)g_pOldCreateWindowExA)(dwExStyle, lpClassName, (LPCTSTR)szWndName, dwStyle, x, y, nWidth, nHeight, hWndParent, hMenu, hInstance, lpParam);
}

void Init()
{
	*(DWORD*)& GetTextByIndexOld = BaseAddr + 0x3E8B0;
	cout << "HookAddress:0x" << hex << (GetTextByIndexOld) << endl;
	cout << "MainAddress:0x" << hex << (BaseAddr) << endl;
	CreateFontAOLD = (fnCreateFontA)GetProcAddress(GetModuleHandle(L"gdi32.dll"), "CreateFontA");
	MessageBoxAOLD = (fnMessageboxA)GetProcAddress(GetModuleHandle(L"User32.dll"), "MessageBoxA");
	g_pOldSetWindowTextA = DetourFindFunction("USER32.dll", "SetWindowTextA");
	g_pOldCreateFontIndirectA = DetourFindFunction("GDI32.dll", "CreateFontIndirectA");
	DetourTransactionBegin();
	DetourAttach((void**)& GetTextByIndexOld, RepString);
	DetourAttach((void**)& CreateFontAOLD, CreateFontAEx);
	DetourAttach((void**)& MessageBoxAOLD, MessageBoxAEx);
	DetourAttach(&g_pOldSetWindowTextA, NewSetWindowTextA);
	DetourAttach(&g_pOldCreateWindowExA, NewCreateWindowExA);
	DetourTransactionCommit();
}

void PalFileSet(char* FileName)
{
	__asm
	{
		pushad
		pushfd
	}
	if(strlen(FileName)!=0)
		cout << "Get File Name:" << FileName <<endl;
	__asm
	{
		popfd
		popad
	}
}

PVOID pGetName = NULL;
PVOID dGetName = NULL;
__declspec(naked)void GetName()
{
	__asm
	{
		push edx
		call PalFileSet
		mov dword ptr ss : [ebp - 0x8] , eax
		mov eax, dword ptr ss : [ebp + 0x8]
		jmp dGetName
	}
}
int sig = 0;
void PalConf()
{
	pGetName = (PVOID)(PalAddr + 0x82E0);
	dGetName = (PVOID)(PalAddr + 0x82E6);
	if (debug)
	{
		cout << "PalAddress: 0x" << hex << (PalAddr) << endl;
		cout << "HookAddress2:0x" << hex << (pGetName) << endl;
	}
	EveHook(pGetName, GetName);
	/*
	          04 05 06 07 08 09 0A 0B 0C 0D 0E 0F 00 01 02 03
	10106554  82 6C 82 72 20 83 53 83 56 83 62 83 4E 00 00 00  俵俽 僑僔僢僋...
	10106564  82 6C 82 72 20 96 BE 92 A9 00 00 00 82 6C 82 72  俵俽 柧挬...俵俽
	10106574  20 82 6F 83 53 83 56 83 62 83 4E 00 82 6C 82 72   俹僑僔僢僋.俵俽
	10106584  20 82 6F 96 BE 92 A9 00 83 49 83 8A 83 57 83 69   俹柧挬.僆儕僕僫
	10106594  83 8B 83 74 83 48 83 93 83 67                    儖僼僅儞僩..br.
	从1010658C到1010659D
	*/
	BYTE Patch2[] = { 0x00 };
	BYTE Patch3[] = { 0x00 };
	BYTE Patch4[] = { 0x00 };
	BYTE Patch5[] = { 0x00 };
	BYTE Patch6[] = { 0x00 };

	int CheckPoint1 = PalAddr + 0x10659D;
	int CheckPoint2 = PalAddr + 0x10658C;
	int CheckPoint3 = PalAddr + 0x10658D;
	int CheckPoint4 = PalAddr + 0x10658E;
	int CheckPoint5 = PalAddr + 0x10658F;
	int CheckPoint6 = PalAddr + 0x106590;
	int CheckPoint7 = PalAddr + 0x106591;
	int CheckPoint8 = PalAddr + 0x106592;
	int CheckPoint9 = PalAddr + 0x106593;
	int CheckPoint10 = PalAddr + 0x106594;
	int CheckPoint11 = PalAddr + 0x106595;
	int CheckPoint12 = PalAddr + 0x106596;
	int CheckPoint13 = PalAddr + 0x106597;
	int CheckPoint14 = PalAddr + 0x106598;
	int CheckPoint15 = PalAddr + 0x106599;
	int CheckPoint16 = PalAddr + 0x10659A;
	int CheckPoint17 = PalAddr + 0x10659B;
	int CheckPoint18 = PalAddr + 0x10659C;
	if (debug)
	{
		cout << "Pal.dll Check info" << endl;
		cout << hex << CheckPoint1 << " | " << hex << CheckPoint2 << " | " << hex << CheckPoint3 << " | " << hex << CheckPoint4 << endl;
		cout << hex << CheckPoint5 << " | " << hex << CheckPoint6 << " | " << hex << CheckPoint7 << " | " << hex << CheckPoint8 << endl;
		cout << hex << CheckPoint9 << " | " << hex << CheckPoint10 << " | " << hex << CheckPoint11 << " | " << hex << CheckPoint12 << endl;
		cout << hex << CheckPoint13 << " | " << hex << CheckPoint14 << " | " << hex << CheckPoint15 << " | " << hex << CheckPoint16 << endl;
		cout << hex << CheckPoint17 << " | " << hex << CheckPoint18 << endl;
	}
	memcopy((void*)CheckPoint1, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint2, Patch3, sizeof(Patch3));
	memcopy((void*)CheckPoint3, Patch4, sizeof(Patch4));
	memcopy((void*)CheckPoint4, Patch5, sizeof(Patch5));
	memcopy((void*)CheckPoint5, Patch6, sizeof(Patch6));
	memcopy((void*)CheckPoint6, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint7, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint8, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint9, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint10, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint11, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint12, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint13, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint14, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint15, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint16, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint17, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint18, Patch2, sizeof(Patch2));
	sig = 1;//hook一次
}

void EdenCharCheck()
{
	BYTE Patch2[] = { 0xFE };
	BYTE Patch3[] = { 0x86 };//修改一个CFIA的CharSet
	/*存档路径更改*/
	BYTE Patch4[] = { 0x5F };
	BYTE Patch5[] = { 0x63 };
	BYTE Patch6[] = { 0x6E };

	int CheckPoint1 = BaseAddr + 0x31f37;
	int CheckPoint2 = BaseAddr + 0x31f3f;
	int CheckPoint3 = BaseAddr + 0x31f4a;
	int CheckPoint4 = BaseAddr + 0x325df;
	int CheckPoint5 = BaseAddr + 0x325e7;
	int CheckPoint6 = BaseAddr + 0x325f6;
	int CheckPoint7 = BaseAddr + 0x32cb5;
	int CheckPoint8 = BaseAddr + 0x32cbd;
	int CheckPoint9 = BaseAddr + 0x32cc9;
	int CheckPoint10 = BaseAddr + 0x31fdf;
	int CheckPoint11 = BaseAddr + 0x31fe9;
	int CheckPoint12 = BaseAddr + 0x31ff5;
	int CheckPoint13 = BaseAddr + 0x330c3;
	int CheckPoint14 = BaseAddr + 0x330cd;
	int CheckPoint15 = BaseAddr + 0x3edd9;
	int CheckPoint16 = BaseAddr + 0x1df011;
	int CheckPoint17 = BaseAddr + 0x1df012;
	int CheckPoint18 = BaseAddr + 0x1df013;

	if (debug)
	{
		cout << "SofPal Check info" << endl;
		cout << hex << CheckPoint1 << " | " << hex << CheckPoint2 << " | " << hex << CheckPoint3 << " | " << hex << CheckPoint4 << endl;
		cout << hex << CheckPoint5 << " | " << hex << CheckPoint6 << " | " << hex << CheckPoint7 << " | " << hex << CheckPoint8 << endl;
		cout << hex << CheckPoint9 << " | " << hex << CheckPoint10 << " | " << hex << CheckPoint11 << " | " << hex << CheckPoint12 << endl;
		cout << hex << CheckPoint13 << " | " << hex << CheckPoint14 << " | " << hex << CheckPoint15 << " | " << hex << CheckPoint16 << endl;
		cout << hex << CheckPoint17 << " | " << hex << CheckPoint18 << endl;
	}

	memcopy((void*)CheckPoint1, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint2, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint3, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint4, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint5, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint6, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint7, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint8, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint9, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint10, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint11, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint12, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint13, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint14, Patch2, sizeof(Patch2));
	memcopy((void*)CheckPoint15, Patch3, sizeof(Patch3));
	memcopy((void*)CheckPoint16, Patch4, sizeof(Patch4));
	memcopy((void*)CheckPoint17, Patch5, sizeof(Patch5));
	memcopy((void*)CheckPoint18, Patch6, sizeof(Patch6));
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		if (debug)
		{
			make_console();
		}
		EdenCharCheck();
		GetPalAddr();//一定要先hook
		Init();
    case DLL_THREAD_ATTACH:
		if (PalAddr != NULL)
		{
			if (sig==0)
				PalConf();
		}
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

