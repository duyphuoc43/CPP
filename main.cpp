#include <iostream>
#include <windows.h>
using namespace std;

int main() 
{
    while (true) 
    {
        HANDLE hFile = CreateFile(
            L"C:\\Users\\phuocvnd\\Desktop\\Project2\\test.txt",
            GENERIC_READ | GENERIC_WRITE,
            0,
            NULL,
            OPEN_ALWAYS,
            FILE_ATTRIBUTE_NORMAL,
            NULL);
        if (hFile == INVALID_HANDLE_VALUE) 
        {
            cout << "Can not open this file" << endl;
        }
        else
        {
            OVERLAPPED overlapped;
            LockFileEx(hFile, LOCKFILE_EXCLUSIVE_LOCK, 0, MAXDWORD, MAXDWORD, &overlapped);
            cout << "Sever is wirting" << endl;
            string text = "Server has written to this file";
            const char* dataToWrite = text.c_str();
            DWORD bytesWritten;
            WriteFile(hFile, dataToWrite, strlen(dataToWrite), &bytesWritten, NULL);

            Sleep(5000);

            UnlockFileEx(hFile, 0, MAXDWORD, MAXDWORD, &overlapped);
            CloseHandle(hFile);
            cout << "Sever was wirted" << endl;
        }
        Sleep(3000);
    }
    return 0;
}
