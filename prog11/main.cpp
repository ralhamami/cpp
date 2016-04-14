typedef double Stack_entry;
#include"Stack.h"
#include <vector>
using namespace std;

void introduction();
char get_command(void (*func)());
bool do_command(char command, Stack<int> &numbers);

int main( )
   {Stack<int> numbers;
    introduction();
    while(do_command(get_command(introduction), numbers));
   }

char get_command(void (*func)())
   {char command;
    bool waiting = true;
    cout << "Select command and press<Enter>:";
    while(waiting)
       {cin >> command;
        cin.ignore();
        command = tolower(command);
        if (command == '?' || command == '=' || command == '+' ||
            command == '-' || command == '*' || command == '/' ||
            command == 'x' || command == 's' || command == 'q' ||
            command == 'm' || command == 'p') 
           waiting = false;
        else
           {cout << "INVALID COMMAND" << endl;
            func();
            cout << "Select command and press<Enter>:";
           }
       }
    return command;
   }

void introduction()
   {cout << "This program implements a reverse Polish calulator." << endl
         << "The valid calculator commands are:" << endl
         << "[?]push to stack   [=]print top" << endl
         << "[+] [-] [*] [/]   are arithmetic operations" << endl
         << "e[X]change the top two stack entries" << endl
         << "adjoin the [S]um of the stack" << endl
         << "adjoin the [M]ean of the stack" << endl
         << "[Q]uit." << endl;
   }

bool do_command(char command, Stack<int> &numbers)
   {double p,q;
    switch (command)
       {case '?':
           cout << "Enter a real number: " << flush;  
           cin >> p;
           if (numbers.isFull())
              cout << "Warning: Stack full, lost number" << endl;
           else
               numbers.push(p);
           break;
        case '=':
           if (numbers.isEmpty())
              cout << "Stack empty" << endl;
           else
              cout << numbers.top() << endl;
           break;
        case '+':
           {if (numbers.isEmpty())
               cout << "Stack empty" << endl;
            else
               {p = numbers.top();
                numbers.pop();
                if (numbers.isEmpty())
                   {cout << "Stack has just one entry" << endl;
                    numbers.push(p);
                   }
                else
                   {q = numbers.top();
                    numbers.pop();
                    numbers.push(p+q);
                   }
               }
           }
           break;
	case '-':
	   {if (numbers.isEmpty())
                cout << "Stack empty" << endl;
            else
               {p = numbers.top();
                numbers.pop();
                if (numbers.isEmpty())
                   {cout << "Stack has just one entry" << endl;
                    numbers.push(p);
                   }
                else
                  {q = numbers.top();
                   numbers.pop();
                   numbers.push(q-p);
                  }
               }
           }
           break;
	case '*':
           {if (numbers.isEmpty())
               cout << "Stack empty" << endl;
            else 
               {p = numbers.top();
                numbers.pop();
                if (numbers.isEmpty())
                   {cout << "Stack has just one entry" << endl;
                    numbers.push(p);
                   }
                else
                   {q = numbers.top();
                    numbers.pop();
                    numbers.push(p*q);
                   }
               }
           }
           break;
        case '/':
           {if (numbers.isEmpty())
               cout << "Stack empty" << endl;
            else
               {p = numbers.top();
                numbers.pop();
                if (numbers.isEmpty())
                   {cout << "Stack has just one entry" << endl;
                    numbers.push(p);
                   }
                else
                   {q = numbers.top();
                    numbers.pop();
                    numbers.push(q/p);
                   }
               }
           }
           break;
	case 'x':
           {if (numbers.isEmpty())
               cout << "Stack empty" << endl;
            else
               {p = numbers.top();
                numbers.pop();
                if (numbers.isEmpty())
                   {cout << "Stack has just one entry" << endl;
                    numbers.push(p);
                   }
                else
                   {q = numbers.top();
                    numbers.pop();
                    numbers.push(p);
                    numbers.push(q);
                   }
               }
           }
           break;
        case 's':
           {if (numbers.isEmpty())
               cout << "Stack is empty" << endl;
            else
               {p = numbers.top();
                numbers.pop();
                if (numbers.isEmpty())
                   cout << "Stack has just one entry" << endl;
                numbers.push(p);
                p = 0;
                vector<int> temp;
                while (!numbers.isEmpty())
                   {temp.push_back(numbers.top());
                    p += numbers.top();
                    numbers.pop();
                   }
                for (int i = temp.size()-1; i >= 0; i--)
                   {numbers.push(temp[i]);
                   }
                numbers.push(p);
               }
           }
           break;
        case 'm':
           {if (numbers.isEmpty())
               cout << "Stack is empty" << endl;
            else
               {p = numbers.top();
                numbers.pop();
                if (numbers.isEmpty())
                   cout << "Stack has just one entry" << endl;
                numbers.push(p);
                p = 0;
                int count = 0;
                vector<int> temp;
                while (!numbers.isEmpty())
                   {temp.push_back(numbers.top());
                    p += numbers.top();
                    numbers.pop();
                   }
                for (int i = temp.size()-1; i >= 0; i--,count++)
                   {numbers.push(temp[i]);
                   }
                numbers.push(p/count);
               }
           }
           break;
        case 'p':
           {if (numbers.isEmpty())
               cout << "Stack is empty" << endl;
            else
               {vector<int> temp;
                while (!numbers.isEmpty())
                   {cout << numbers.top() << endl;
                    temp.push_back(numbers.top());
                    numbers.pop();
                   }
                for (int i = temp.size()-1; i >= 0; i--)
                   {numbers.push(temp[i]);
                   }
               }
           }      
           break;
        case 'q':
           cout << "Calulation finished.\n";
           return false;
       }
       return true;
   }  
