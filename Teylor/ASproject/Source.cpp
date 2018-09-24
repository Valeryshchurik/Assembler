#include <iostream>
#include <tchar.h>
#include <cmath>
#include <iomanip>
using namespace std;

double costranscend(double x)
{
	_asm
	{
		finit
		fld x
		fcos
	}
}

double cosx(double x, unsigned k)
{
	const double TEN = 10.0;
	_asm
	{
		finit
		mov ecx, k
		fld1

		prec :
		fdiv TEN
			Loop prec

			fld1
			fldz
			fld1

			while_begin :
		fld st(0)
			fabs
			fcomp st(4)
			fstsw AX
			sahf
			jc while_end


			fmul x
			fmul x
			fchs
			fld1
			faddp st(2), st
			fdiv st, st(1)
			fld1
			faddp st(2), st
			fdiv st, st(1)
			fadd st(2), st
			jmp while_begin

			while_end :
			fincstp
			fincstp
	}

}

int _tmain(int argc, _TCHAR *argv[])
{
	if (argc != 3)
	{
		cout << "Invalid number of arguments\n";
		return 1;
	}
	double x = strtod(argv[1], NULL);
	unsigned k = strtoul(argv[2], NULL, 10);
	if (k > 53)
	{
		cout << "too big accuracy. It will be done for 53 numbers after point"<< endl;
		k = 53;
	}
	if (k < 1)
	{
		cout << "Incorrect accuracy. It will be done for 1 number after point" << endl;
		k = 1;
	}
	cout << "cos(" << x << ") = " << endl;
	cout << "Assembler_Taylor: " << fixed << setprecision(k) << cosx(x, k) << endl;
	cout << "Asm transcedent operations: " << costranscend(x) << endl;
	cout << "Standard C++ function: " << cos(x) << endl;
}