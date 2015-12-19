#include <stdlib.h>
#include <string.h>
__declspec(dllexport)
int example1(int a, int b);
__declspec(dllexport)
int example2(int a);
__declspec(dllexport)
int example3(int a);
__declspec(dllexport)
int example4(int a, int b);
__declspec(dllexport)
int example5(int a);
__declspec(dllexport)
int example6(int a);
__declspec(dllexport)
int example7(int a);
// this function looks like a big ass switch
int example1(int a, int b) {
	
	switch (b)
	{
		case (0):
                a = (a+0)*0;
                a = (a+0)*0;
                a = (a+0)*0;
                a = (a+0)*0;
                a = (a+0)*0;
				break;
        case (1):
                a = (a+1)*1;
                a = (a+1)*1;
                a = (a+1)*1;
                a = (a+1)*1;
                a = (a+1)*1;
                break;
		case (2):
                a = (a+2)*2;
                a = (a+2)*2;
                a = (a+2)*2;
                a = (a+2)*2;
                a = (a+2)*2;
                break;
		case (3):
                a = (a+3)*3;
                a = (a+3)*3;
                a = (a+3)*3;
                a = (a+3)*3;
                a = (a+3)*3;
                break;
		case (4):
                a = (a+4)*4;
                a = (a+4)*4;
                a = (a+4)*4;
                a = (a+4)*4;
                a = (a+4)*4;
                break;
		case (5):
                a = (a+5)*5;
                a = (a+5)*5;
                a = (a+5)*5;
                a = (a+5)*5;
                a = (a+5)*5;
                break;
		case (6):
                a = (a+6)*6;
                a = (a+6)*6;
                a = (a+6)*6;
                a = (a+6)*6;
                a = (a+6)*6;
                break;
		case (7):
                a = (a+7)*7;
                a = (a+7)*7;
                a = (a+7)*7;
                a = (a+7)*7;
                a = (a+7)*7;
                break;
		case (8):
                a = (a+8)*8;
                a = (a+8)*8;
                a = (a+8)*8;
                a = (a+8)*8;
                a = (a+8)*8;
                break;
		case (9):
                a = (a+9)*9;
                a = (a+9)*9;
                a = (a+9)*9;
                a = (a+9)*9;
                a = (a+9)*9;
                break;
		case (10):
                a = (a+10)*10;
                a = (a+10)*10;
                a = (a+10)*10;
                a = (a+10)*10;
                a = (a+10)*10;
                break;
		case (11):
                a = (a+11)*11;
                a = (a+11)*11;
                a = (a+11)*11;
                a = (a+11)*11;
                a = (a+11)*11;
                break;
		case (12):
                a = (a+12)*12;
                a = (a+12)*12;
                a = (a+12)*12;
                a = (a+12)*12;
                a = (a+12)*12;
                break;
		case (13):
                a = (a+13)*13;
                a = (a+13)*13;
                a = (a+13)*13;
                a = (a+13)*13;
                a = (a+13)*13;
				goto something;
                break;
		case (14):
                a = (a+14)*14;
                a = (a+14)*14;
                a = (a+14)*14;
                a = (a+14)*14;
                a = (a+14)*14;
				goto something;
                break;
		case (15):
                a = (a+15)*15;
                a = (a+15)*15;
                a = (a+15)*15;
                a = (a+15)*15;
                a = (a+15)*15;
                break;
		case (16):
                a = (a+16)*16;
                a = (a+16)*16;
                a = (a+16)*16;
                a = (a+16)*16;
                a = (a+16)*16;
                break;
		case (17):
                a = (a+17)*17;
                a = (a+17)*17;
                a = (a+17)*17;
                a = (a+17)*17;
                a = (a+17)*17;
				goto something;
                break;
		case (18):
                a = (a+18)*18;
                a = (a+18)*18;
                a = (a+18)*18;
                a = (a+18)*18;
                a = (a+18)*18;
               break;
		case (19):
                a = (a+19)*19;
                a = (a+19)*19;
                a = (a+19)*19;
                a = (a+19)*19;
                a = (a+19)*19;
	}

	return a;
	something:
	if (a) {
		return example2(example2(example2(example2(a))));

	}
}
//// this is an example of a if(!something) exit
//int  example2(int a) {	
//	int b =a*3 ;
//	int d = a*5;
//	if(!a) {
//		
//		exit(b);
//	} 
//	b+=d+a;
//	if (!b) {
//		;
//		exit(b+2);
//	} 
//	d *= b -a;
//	d = a- d;
//	d = d<<2 +b ;
//	d = b-d;
//	if (!d) {
//		return example1(d, a);
//	}
//	d *= b -a;
//	d = a- d;
//	d = d<<2 +b ;
//	d = b-d;
//	if (!d) {
//		return example1(d, b);
//	}
//	d *= b -a;
//	d = a- d;
//	d = d<<2 +b ;
//	d = b-d;
//	if (!d) {
//		return example1(d, d);
//	}
//	d *= b -a;
//	d = a- d;
//	d = d<<2 +b ;
//	d = b-d;
//	if (!d) {
//		return example1(d, a);
//	}
//	return a;
//
//}

// switch case, second form
int example3(int a) {
	int b =0;
	int c =0 ;
	if (a == 2)
	{ 	
		b = a;
		a += b;
	}
	else if (a == 3) 
	{	c = a+b;
		a += c;
	}
	else if (a == 4)
	{	b = c+a;
		c += b;
	}
	else if (a == 5){
		c = example1(a,6);
		a = c + a;
	}
	else if (a == 6){
		c = example2(a);
		a = c + a;}
	else if (a == 7){
		b = example1(a, a*2);
		a = c + a;
	}


	return example2(a) + example2(b) + example1(c,b*a);
}

// huge calculation done via loop unrolling
int example4(int a, int b) {
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;a *=b;
	a +=b;
	b*=a;
	b+=a;

	b+=a;

	b+=a;

	b+=a;

	b+=a;
	b+=a;

	b+=a;
	b+=a;
	b+=a;
	b+=a;
	b+=a;
	b+=a;
	b+=a;
	b+=a;
	b+=a;
	b+=a;
	b+=a;

	b+=a;
	b+=a;
	b+=a;
	
	return a;
}

// simple loop
int example5(char* a) {
	int result;
	__asm {
		xor ecx, ecx;
		mov esi, [a]
again:
		inc ecx
		movzx eax, byte ptr [esi];
		cmp eax, 0;
		jnz again;
		dec ecx
		mov [result], ecx		
	}
	return result;
}

// loop inside a loop
int example6(int a) {	
	int result;
	int i = 0;	
	__asm {
again2:
		xor ecx, ecx;
		mov esi, [a]
again:
		inc ecx
		movzx eax, byte ptr [esi];
		cmp eax, 0;
		jnz again;
		dec ecx
		mov [result], ecx		
		
		inc [i];
		inc [i];
		cmp ecx, [i]
		jnz again2
	}
	return i;
}

// exception handler 
int example7(int a){
	int b= 0;
	b+=a;
	if (b == 0) {
		exit(b);
	}
	if (a !=6) for (b = 0; b < 100; ++b) a+=2;
	return a;


}

__declspec(dllexport) int example8(int a, int b) 
{
	try {
		a = 9 / a;
		a = 9 / a;
		a = 9 / a;
		a = 9 / a;
		a = 9 / a;
		a = 9 / a;
		a = 9 / a;

	}
	catch(...) {
		a = 23;
		return a / b;
	}
}
int main(void) {
	return 0;
}