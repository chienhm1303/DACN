#include <windows.h>
#include <tchar.h>
#include <stdio.h>

void SampleSzz(PTSTR pszz)
{
	_tprintf(_TEXT("\tBegin multi-sz string\n"));
	while (*pszz)
	{
		_tprintf(_TEXT("\t\t%s\n"), pszz);
		pszz = pszz + _tcslen(pszz) + 1;
	}
	_tprintf(_TEXT("\tEnd multi-sz\n"));
}

int __cdecl main(int argc, char **argv)
{
	// Because the compiler adds a \0 at the end of quoted strings, 
	// there are two \0 terminators at the end. 

	_tprintf(_TEXT("Conventional multi-sz string:\n"));
	SampleSzz(_TEXT("String1\0String2\0String3\0LastString\0"));

	_tprintf(_TEXT("\nTest case with no strings:\n"));
	SampleSzz(_TEXT(""));
	getchar();
	return 0;
}

