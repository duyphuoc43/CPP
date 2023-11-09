#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <fstream>

using namespace std;

int main() 
{
    ofstream file ("share_file.txt");
    file << "Sever turn on" << std::endl;
    file.close();

    pid_t pid = fork();

    if (pid == -1) 
    {
        cout<<(stderr, "Fork failed\n");
        return 1;
    } 
    else if (pid == 0) 
    {
        while (true)
        {
            string text,newtext,reptext;
            ifstream readfile ("share_file.txt");
            while (getline(readfile,text))
            {
                newtext += text;
            }
            cout<<"SEVER: "<<newtext<<endl;
            readfile.close();
            getline(cin,reptext);
            ofstream file ("share_file.txt");
            file <<reptext<<endl;
            file.close();
            cout<<"wait sever reply"<<endl;
            sleep(3);
        }
    } 
    else 
    {
        while (true)
        {
            string text,newtext,reptext;
            ifstream readfile ("share_file.txt");
            while (getline(readfile,text))
            {
                newtext += text;
            }
            cout<<"CLIENT:  "<<newtext<<endl;
            readfile.close();
            getline(cin,reptext);
            ofstream file ("share_file.txt");
            file << reptext <<endl;
            file.close();
            cout<<"wait client reply"<<endl;
            sleep(3);
        }
    }

    return 0;
}
