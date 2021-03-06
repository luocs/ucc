#ifndef TEMPLATE
#error "You must define TEMPLATE macro before include this file"
#endif

TEMPLATE(X86_MOV,       "mov %0, %1")
TEMPLATE(X86_MOVB,      "lea edi, %0;lea esi, %1;mov ecx, %2;rep movsb")
TEMPLATE(X86_OR,        "or %0, %2")
TEMPLATE(X86_XOR,		"xor %0, %2")
TEMPLATE(X86_AND,		"and %0, %2")
TEMPLATE(X86_SHL,		"shl %0, %2")
TEMPLATE(X86_SAR,		"sar %0, %2")
TEMPLATE(X86_SHR,		"shr %0, %2")
TEMPLATE(X86_ADD,		"add %0, %2")
TEMPLATE(X86_SUB,		"sub %0, %2")
TEMPLATE(X86_IMUL,		"imul %0, %2")
TEMPLATE(X86_MUL,		"mul %2")
TEMPLATE(X86_IDIV,		"cdq;idiv %2")
TEMPLATE(X86_DIV,		"mov edx, 0;div %2")
TEMPLATE(X86_IMOD,		"cdq;idiv %2")
TEMPLATE(X86_MOD,		"mov edx, 0;div %2")
TEMPLATE(X86_NEG,		"neg %0")
TEMPLATE(X86_NOT,		"not %0")
TEMPLATE(X86_ADDR,		"lea %0, %1")
TEMPLATE(X86_INC,		"inc %0")
TEMPLATE(X86_DEC,		"dec %0")

TEMPLATE(X86_JMP,		"jmp %0")
TEMPLATE(X86_IJMP,		"jmp DWORD PTR %0[%1]")
TEMPLATE(X86_JZ,		"cmp %1, 0;je %0") 
TEMPLATE(X86_JNZ,		"cmp %1, 0;jne %0")
TEMPLATE(X86_JE,		"cmp %1, %2;je %0")
TEMPLATE(X86_JNE,		"cmp %1, %2;jne %0")
TEMPLATE(X86_JG,		"cmp %1, %2;jg %0")
TEMPLATE(X86_JA,		"cmp %1, %2;ja %0")
TEMPLATE(X86_JL,		"cmp %1, %2;jl %0")
TEMPLATE(X86_JB,		"cmp %1, %2;jb %0")
TEMPLATE(X86_JGE,		"cmp %1, %2;jge %0")
TEMPLATE(X86_JAE,		"cmp %1, %2;jae %0")
TEMPLATE(X86_JLE,		"cmp %1, %2;jle %0")
TEMPLATE(X86_JBE,		"cmp %1, %2;jbe %0")

TEMPLATE(X86_PROLOGUE,	"push ebp;push ebx;push esi;push edi;mov ebp, esp")
TEMPLATE(X86_PUSH,		"push %0")
TEMPLATE(X86_PUSHR4,	"push ecx;fld %0;fstp DWORD PTR [esp]")
TEMPLATE(X86_PUSHR8,	"sub esp, 8;fld %0;fstp QWORD PTR [esp]")
TEMPLATE(X86_PUSHB,		"lea esi, %0;sub esp, %1;mov edi, esp;mov ecx, %1;rep movsb")
TEMPLATE(X86_EXPANDF,	"sub esp, %0")
TEMPLATE(X86_CALL,		"call %1")
TEMPLATE(X86_REDUCEF,	"add esp, %0")
TEMPLATE(X86_EPILOGUE,	"mov esp, ebp;pop edi;pop esi;pop ebx;pop ebp;ret")

TEMPLATE(X86_FADD,		"fadd %2")
TEMPLATE(X86_FSUB,		"fsub %2")
TEMPLATE(X86_FMUL,		"fmul %2")
TEMPLATE(X86_FDIV,		"fdiv %2")
TEMPLATE(X86_FNEG,		"fchs")
TEMPLATE(X86_FINC,		"fld1;fadd %0;fstp %0")
TEMPLATE(X86_FDEC,		"fld1;fsub %0;fabs;fstp %0")

TEMPLATE(X86_FLD,		"fld %0")
TEMPLATE(X86_FSTP,		"fstp %0")
TEMPLATE(X86_FJZ,		"fldz;fcomp %1;fnstsw ax;and ah, 40h;je %0")
TEMPLATE(X86_FJNZ,		"fldz;fcomp %1;fnstsw ax;and ah, 40h;jne %0")
TEMPLATE(X86_FJE,		"fcom %2;fnstsw ax;and ah, 40h;jnz %0")
TEMPLATE(X86_FJNE,		"fcom %2;fnstsw ax;and ah, 40h;jz %0")
TEMPLATE(X86_FJG,		"fcom %2;fnstsw ax;and ah, 41h;jz %0")
TEMPLATE(X86_FJL,		"fcom %2;fnstsw ax;and ah, 1h;jnz %0")
TEMPLATE(X86_FJGE,		"fcom %2;fnstsw ax;and ah, 1h;jz %0")
TEMPLATE(X86_FJLE,		"fcom %2;fnstsw ax;and ah, 41h;jnz %0")

TEMPLATE(X86_MOVSX,		"movsx %0, %1")
TEMPLATE(X86_MOVZX,		"movzx %0, %1")
TEMPLATE(X86_CVTIF,		"push %1;fild DWORD PTR [esp];fstp %0")
TEMPLATE(X86_CVTUF,		"push 0;push %1;fild QWORD PTR [esp];fstp %0")
TEMPLATE(X86_CVTFI,		"fld %1;call __ftol;")
TEMPLATE(X86_CVTFU,		"fld %1;sub esp, 16;fnstsw [esp];movzx eax, WORD PTR [esp];"
						"or eax, 0c00H;mov 4[esp], eax;fldcw 4[esp];fistp QWORD PTR 8[esp];"
						"fldcw [esp];mov eax, 8[esp];add esp, 16")
TEMPLATE(X86_CVTF,		"fld %1;fistp %0")

TEMPLATE(X86_HLT,		"hlt")
