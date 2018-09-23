int rd()
{
	bool neg=false;
	int res=0;
	char ch;
	ch=getchar();
	while(true)
	{
		if(ch=='-')break;
		if(ch>='0'&&ch<='9')break;
		ch=getchar();
	}
	if(ch=='-')neg=true; else res=ch-'0';
	while(true){
		ch=getchar();
		if(ch<'0'||ch>'9')break;
		res=res*10+(ch-'0');
	}
	if(neg)
		return -res;
	else
		return res;
}