#include <iostream>
#include <windows.h>
using namespace std;

int main() 
{
    while (true) 
    {
        HANDLE hFile = CreateFile(L"C:\\Users\\phuocvnd\\Desktop\\Project2\\test.txt",
            GENERIC_READ | GENERIC_WRITE,
            0,
            NULL,
            OPEN_ALWAYS,
            FILE_ATTRIBUTE_NORMAL,
            NULL);

        if (hFile == INVALID_HANDLE_VALUE) 
        {
            cout << "Can not open this file" << endl;
            Sleep(1000);
        }
        else
        {
            OVERLAPPED overlapped;
            LockFileEx(hFile, LOCKFILE_EXCLUSIVE_LOCK, 0, MAXDWORD, MAXDWORD, &overlapped);

            SetFilePointer(hFile, 0, NULL, FILE_BEGIN);

            const int bufferSize = 1024;
            char buffer[bufferSize];
            DWORD bytesRead;

            while (ReadFile(hFile, buffer, sizeof(buffer), &bytesRead, NULL) && bytesRead > 0) 
            {
                cout.write(buffer, bytesRead);
            }
            cout << endl;

            UnlockFileEx(hFile, 0, MAXDWORD, MAXDWORD, &overlapped);

            CloseHandle(hFile);
        }
        Sleep(1000);
    }
    return 0;
}
