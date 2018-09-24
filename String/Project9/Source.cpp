#include <iostream>
#include <stdio.h>
#include <tchar.h>
using namespace std;
int main()
{
	/*static const char s[100] = ("εσοκκσ67445εο");*/
	static const _TCHAR s[100] = _T("tralala 8-800-tralala4234555-35-35tidim345436");
	int result, index=0;
		_asm {
			mov edx, 0
			mov ecx, 0
			mov esi, 0
		beginn:
			cmp s[esi], 0
			je te
		# ifdef _UNICODE
			mov ax, s[esi]
			CMP ax, '0'
			JB te
			CMP ax, '9'
			JA te
		# else
			mov al, s[esi]
			CMP al, '0'
			JB te
			CMP al, '9'
			JA te
		#endif
			add edx, 1
		naz:
			cmp s[esi], 0
			je endn
		#ifdef _UNICODE
			add esi, 2
		#else
			add esi, 1
		#endif
			jmp beginn
		yes:
			mov ebx, esi
			mov ecx, edx
			mov edx, 0
			jmp naz
		te :
			CMP edx, ecx
			JA yes
			mov edx, 0
			jmp naz
		endn:
			mov result, ecx
	}
	cout << "result=" << result<< endl;
	system("pause");
}