#include <iostream>
#include <string>
using namespace std;

void nextCharacter(char* s, int index, size_t stringLength)
{
	if (s[index] == '~')
	{
		if (index == stringLength - 1)
			throw "all strings generated";
		s[index] = ' ';
		nextCharacter(s, index + 1, stringLength);
		return;
	}
	else if (s[index] == 0)
		s[index] = ' ';
	else
		s[index] = ((char)((int)s[index]) + 1);
	if (s[index] == '<' || s[index] == '>')
		s[index] = ((char)((int)s[index]) + 1);
}

int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cout << "Benutzung:" << endl << argv[0] << " <Stringl" << (char)132 << "nge> [Startstring]" << endl;
		return -1;
	}

	size_t StringLength = stoi(argv[1]);
	char* String;

	String = (char*)malloc(StringLength + 1);
	memset(String, 0, StringLength);
	String[0] = ' ';
	String[StringLength] = 0;

	if (argc == 3)
		memcpy(String, argv[2], strlen(argv[2]));

	while (true)
	{
		cout << String << endl;
		try
		{
			nextCharacter(String, 0, StringLength);
		}
		catch (const char*)
		{
			delete[] String;
			return 0;
		}
	}
}