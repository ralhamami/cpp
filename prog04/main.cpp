#include <iostream>
#include <fstream>
using namespace std;

int main()
   {while(true)    
       {string filename, sbuffer="";
        char cbuffer;
        bool space = false;
        int chars = -1, words = 0, lines = 0, temp = 0;
        cout << "Enter Filename: ";
        cin >> filename;
        ifstream Data(filename.c_str());
        if (Data.fail())
           {cout << "Error Opening File." << endl;
            return 1;
           }
        while(Data.good())  //Counting Lines and Chars
           {cbuffer = Data.get();
            chars++;
            if (cbuffer == '\n')
               lines++;
           }
        Data.clear();
        Data.seekg(0);
        while(Data >> sbuffer)  //Counting Words
           words++;
        cout << chars << " characters, "
             << words << " words, " 
             << lines << " lines." << endl; 
      }  
   }
