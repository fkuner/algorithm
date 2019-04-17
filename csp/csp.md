```
//字符串分割函数，将字符串s用"/"分割，并存放于向量v中 
void split(vector<string> &v,char *s)
{
	char *sp=strtok(s,"/");
	while(sp)
	{
		v.push_back(sp);
		sp=strtok(NULL,"/");
	}
}
```


