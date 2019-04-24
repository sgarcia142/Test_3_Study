void decrement(){

	__asm {
		mov eax, 0x9A3C;
		dec ah;
	}

	return;
}

void twos_comp(){
	__asm{
		xor ebx, ebx;
		mov ebx, 0xFFFFFFFF;
		xor ebx, 0xFFFFFFFF;
		inc ebx;
	}
}

void decrement2(){

	__asm {
		mov eax, 0x5F0AC;
		dec ah;
	}

	return;
}

void divide_by_16_signed(){
	__asm{
		xor ebx, ebx;
		mov ebx, 0xC0;
		sar ebx, 4;
	}

}

void force_0_3_7_to_1(){
	__asm {
		xor eax, eax;
		or ah, 0x89;
	}
}


void maskoutbits(){

	__asm {
		// A2 = 10100010
		mov al, 0xA2; 
		// mask out the 1st and 7th bits should end up being 00100000 0x20
		and al, 0x7D;
	}

	return;
}

void throwbits045(){

	__asm {
		// A2 = 10100010
		mov bl, 0xA2;
		movzx eax, bl;
		// mask out the 1st and 7th bits should end up being 00100000 0x20
		and al, 0x7D;
	}

	return;
}

void alter_esp(){
	__asm{
		sub esp, 30;
		// if we comment out the add back of esp an error will be thrown
		add esp, 30;
	}
	return;
}

void string_practice(int x, char a, char y){
	__asm{
		push ecx;
		mov[ebp - 4], 0;
	}
	return;
}

void move_it(char *s, char *d, int len){
	__asm{
		mov ecx, len;
		mov esi, s;
		mov edi, d;
		cld;
		rep movsb;
		mov edx, 20;
		mov ecx, d;
		nop;
	}
	return;
}


void reverse_2_bytes(char *gK, int len){

	__asm{
		xor ecx, ecx;
		xor ebx, ebx;
		xor eax, eax;
		mov ecx, len;
		shr ecx, 1;
		mov esi, gK;
	Reverse_Loop:
		mov ax, [esi + ebx * 2];
		ror ax, 8;
		mov[esi + ebx * 2], ax;
		inc ebx;
		dec ecx;
		jne Reverse_Loop;
	}
	return;
}

void reverse_4_bytes(char *gK, int len){

	__asm{
		xor ecx, ecx;
		xor ebx, ebx;
		xor eax, eax;
		mov esi, gK;
		mov ecx, len;
		shr ecx, 2;
	Reverse_Loop:
		//mov eax, [esi + ebx * 4];
		//bswap eax;
		//mov[esi + ebx * 4], eax;
		mov ax, [esi + ebx * 4];
		ror ax, 8;
		mov dx, [esi + ebx * 4 + 2];
		ror dx, 8;
		mov[esi + ebx * 4], dx;
		mov[esi + ebx * 4 + 2], ax;
		inc ebx;
		dec ecx;
		jne Reverse_Loop;
	}
	return;

}


int find_it(char* str, char* find, int len){
	int found = -1;
	__asm{
		xor ecx, ecx;
		xor ebx, ebx;
		xor eax, eax;
		mov esi, str;
		mov edi, find;
		mov ah, [edi];
	String_Loop:
		mov al, [esi + ecx];
		cmp ah, al;
		je Found_It;
		inc ecx;
		cmp ecx, len;
		jb String_Loop;
		jmp Exit;
	Found_It:
		mov found, 1;
	Exit:
	}
	return found;
}

void copy_string(char* s, char* d, int l){
	__asm{
		cld;
		mov esi, s;
		mov edi, d;
		mov ecx, l;
		rep movsb;
	}
	return;
}

void copy_string_2(char* s, char* d, int l){
	__asm{
		cld;
		mov esi, s;
		mov edi, d;

	Loop_Through_String:
		lodsb;
		stosb;
		cmp al, 0;
		jne Loop_Through_String;
	}
	return;
}

int func(char* d){
	__asm{
		xor ecx, ecx;
		xor eax, eax;
		mov edi, d;
	String_Loop:
		cmp[edi + ecx], 0x00;
		je EXIT;
		inc ecx;
		jmp String_Loop;
	EXIT:
		mov eax, ecx;
	}
	return;
}

void multi(){
	__asm{
		xor ecx, ecx;
		mov cl, 0x08;
		shl cl, 3;
	}
	return;
}

void interpret(){
	char gk3[] = { 0x43, 0x61, 0x74, 0x20, 0x6F, 0x6E, 0x20, 0x6D, 0x61, 0x74, 0x2E, 0x00 };
	char *gptrK;
	gptrK = gk3;
	__asm{
		lea esi, gk3;
		mov eax, dword ptr [gk3+4];
		lea edi, gptrK;
		xor ecx, ecx;
		mov edx, [edi];
		add ecx, 4;
		mov bx, word ptr [gk3 + ecx * 2];
		mov ah, byte ptr [gk3 + ecx * 2];
		mov al, byte ptr [gk3 + ecx * 2 + 1];
	}
	return;
}


int main(){
	char dat[] = { 0x11, 0x33, 0x44, 0xAA, 0x00 };
	char gk[] = { 0x74, 0x20, 0x43, 0x61, 0x20, 0x6D, 0x6F, 0x6E, 0x2E, 0x00, 0x61, 0x74 };
	char gk2[] = { 0x43, 0x61, 0x74, 0x20, 0x6F, 0x6E, 0x20, 0x74, 0x68, 0x65, 0x20, 0x6D, 0x61, 0x74, 0x2E, 0x00 };
	char gk3[] = { 0x43, 0x61, 0x74, 0x20, 0x6F, 0x6E, 0x20, 0x6D, 0x61, 0x74, 0x2E, 0x00 };
	char test = 'A';
	int f;
	char s[] = "Hello World!";
	char d[13];


	//decrement();
	//maskoutbits();
	//throwbits045();
	//alter_esp();
	//string_practice(5,'A','B');
	//twos_comp();
	//force_0_3_7_to_1();
	//divide_by_16_signed();
	//decrement2();
	//move_it(s,d,12);

	//gptrK = &test;

	//reverse_4_bytes(gk3, 12);
	reverse_2_bytes(gk2, 16);
	//f = find_it(s, "W", 12);

	//copy_string(s,d,13);
	//copy_string_2(s, d, 13);
	//multi();
	//f = func(dat);
	//interpret();
	return 0;
}