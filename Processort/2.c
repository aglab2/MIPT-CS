union hren{
	char a[2];
	short b;
};

typedef unsigned short adr;
typedef char byte;
typedef unsigned short word;

byte mem[65536];

byte b_read  (adr a){
	return mem[a];
}

void b_write (adr a, byte val){
	mem[a] = val;
}

word w_read  (adr a){
	union hren ret;
	
	ret.a[0] = mem[a];
	ret.a[1] = mem[a+1];
	return ret.b;
}

void w_write (adr a, word val){
	union hren ret;
	ret.b = val;
	
	mem[a] = ret.a[0];
	mem[a+1] = ret.a[1];
}

void load_file(){
	
}
