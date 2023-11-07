#include <iostream>
using namespace std;
 #include <fstream>
int main(){
    string myText;
    string newText;
    ifstream ReadMyFile("test.txt");
    while (getline (ReadMyFile,myText))
    {
        for (int i = 0;i <myText.size();i++)
        {
        	char index ;
	        if (48 > int(myText[i]) or int(myText[i]) > 57 )
	        {
				index =  char(myText[i]-32);
			}
			else
			{
				index = char(myText[i]);
			}
			newText = newText + index;
	
		}
		newText += "\n";
    }
    cout << newText;
    ReadMyFile.close();
    ofstream MyFile("newtest.txt");
    MyFile << newText;
 	MyFile.close();
    return 0;
}
