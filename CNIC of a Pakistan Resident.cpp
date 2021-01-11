int Hash::HashFuntion(string data)
{
	int n = 0;
	for (int i = 0; i < data.length(); i++)
	{
		string ch(1, data[i]);
		n += atof(ch.c_str());
	}
	return (n % Max);
}


