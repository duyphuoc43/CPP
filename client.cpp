#include <iostream>
#include <fstream>
#include <string>
#include <unistd.h>
using namespace std;

int main()
{
    while (true)
    {
        string text,newtext,reptext;
        ifstream readfile ("share_file.txt");
        while (getline(readfile,text))
        {
            newtext += text;
        }
		
        if (newtext[0]=='0')
        {
            newtext.erase(newtext.begin());
            cout<<"SEVER: "<<newtext<<endl;
           	getline(cin,reptext);
           	if(reptext == "q")
            {
                break;
            }
            reptext = '1'+reptext;
            ofstream file ("share_file.txt");
            file <<reptext<<endl;
            file.close();
            cout<<"wait sever reply"<<endl;
        	sleep(3);
        }

    }
	return 0;
}
