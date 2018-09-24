#include <iostream>;
using namespace std;
int main()
{
	int n, val1, val2, val=0, result;
	cout << "Input, how many first Fibonacci numbers you want to sum up (all negative n will return 0)" << endl;
	cin >> n;
	__asm
	{
		mov  result, 0;
		mov  eax, 1;
		mov  ebx, 0;
		mov  edx, 1;
		mov  ecx, n;
		cmp  ecx, 2;
		jl   end_;
		je   end_2;
		sub  ecx, 2;
	beg:
		add  eax, ebx;
		add  eax, edx;
		add  ebx, edx;
		mov  val, ebx;
		mov  ebx, edx;
		mov  edx, val;
		loop beg
	end_2:
		mov  result, eax;
		mov  val1, ebx;
		mov  val2, edx;
	end_:
	}
	cout<<"result="<<result<<endl;
	system("pause");
}