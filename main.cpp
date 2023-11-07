#include <iostream>
#include <fstream>
#include <windows.h>
using namespace std;
// def sever()
// {
    
// }
int main()
{
    ofstream file ("share_file.txt");
    file << "0Sever turn on" << std::endl;
    file.close();
    while (true)
    {
        string text,newtext,reptext;
        ifstream readfile ("share_file.txt");
        while (getline(readfile,text))
        {
            newtext += text;
        }
        if (newtext[0]=='1')
        {
            newtext.erase(newtext.begin());
            cout<<"CLIENT:  "<<newtext<<endl;
            getline(cin,reptext);
            if(reptext == "q")
            {
                break;
            }
            ofstream file ("share_file.txt");
            file << '0'+reptext <<endl;
            file.close();
            cout<<"wait client reply"<<endl;
            Sleep(10000);
        }
    }

}
