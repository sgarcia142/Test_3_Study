void decrement(){

	__asm {
		mov eax, 0x9A3C;
		dec ah;
	}

	return;
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

void reverse_it(char *gk, int len, char *ptr){
	__asm{
		mov ecx, len;
		shr ecx, 2;
		mov esi, gk;
		xor ebx, ebx;
		xor eax, eax;

	next:
		mov ax, [esi + ebx * 4];
		ror ax, 8;
		mov dx, [esi + ebx * 4 + 2];
		ror dx, 8;
		mov [esi + ebx * 4], ax;
		mov [esi + ebx * 4+2], dx;
		inc ebx;
		dec ecx;
		jne next;

	}
	return;
}

void reverse_it2(char* gk, int len){
	__asm{
		xor ecx, ecx;
		xor eax, eax;
		xor ebx, ebx;
		xor edx, edx;
		mov ecx, len;
		shr ecx, 2;
		mov esi, gk;

	Reverse_Loop:
		mov ax, [esi + ebx * 4];
		ror ax, 8;
		mov dx, [esi + ebx * 4 + 2];
		ror dx, 8;
		mov[esi + ebx * 4], ax;
		mov[esi + ebx * 4 + 2], dx;
		inc ebx;
		cmp ebx, ecx;
		jb Reverse_Loop;
	}
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
}

int main(){
	//decrement();
	//maskoutbits();
	//throwbits045();
	//alter_esp();
	//string_practice(5,'A','B');
	int f; 
	char s[] = "Hello World!";
	char d[13];
	//move_it(s,d,12);
	char gk[] = { 0x74, 0x20, 0x43, 0x61, 0x20, 0x6D, 0x6F, 0x6E, 0x2E, 0x00, 0x61, 0x74};
	char test = 'A';
	char *gptrK;
	gptrK = &test;
	//reverse_it(gk, 12, gptrK);
	//reverse_it2(gk, 12);
	//f = find_it(s, "W", 12);

	//copy_string(s,d,13);
	copy_string_2(s, d, 13);
	return 0;
}