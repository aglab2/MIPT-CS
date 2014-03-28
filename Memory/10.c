union data convert(union data x){
	union data res;
	int i;
	
	for (i=0; i<8; i++)
		res.arr[i] = x.arr[7-i];

	return res;
}
