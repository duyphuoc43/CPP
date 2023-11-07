#include <iostream>
#include <fstream>
using namespace std;
// def sever()
// {
    
// }
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
            cout<<newtext<<endl;
            cin >> reptext;
            if(reptext =="q")
            {
                break;
            }
            ofstream file ("share_file.txt");
            file << "1"+reptext <<endl;
            file.close();
        }
    }

}