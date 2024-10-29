#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(const char* str, int i = 0)
{
    if (str[i] == '\0')
        return 0;
    int count = (str[i] == '+' || str[i] == '-' || str[i] == '=') ? 1 : 0;
    return count + Count(str, i + 1);
}

char* Change(char* dest, const char* str, int i = 0, int j = 0)
{
    if (str[i] == '\0')
    {
        dest[j] = '\0';
        return dest;
    }
    if (str[i] == '+' || str[i] == '-' || str[i] == '=')
    {
        dest[j] = '*';
        dest[j + 1] = '*';
        return Change(dest, str, i + 1, j + 2);
    }
    else
    {
        dest[j] = str[i];
        return Change(dest, str, i + 1, j + 1);
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int occurrences = Count(str);
    cout << "Total occurrences of '+', '-', '=': " << occurrences << endl;

    char* dest = new char[2 * strlen(str) + 1];
    Change(dest, str);

    cout << "Modified string: " << dest << endl;

    delete[] dest;
    return 0;
}
