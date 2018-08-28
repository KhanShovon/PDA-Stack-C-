#include "stacktype.cpp"
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    StackType<char> s1; // s1 is an object of the StackType class


    int i, j, l; // i and J for two loops and l is to store strings length
    char s[10];

    cout << "Enter String of Binary Digits:";

    cin >> s; //Input the string

    l = strlen(s); // Length of string

    s1.Push(-1); // Pushed -1 into the stack as a bottom reference. So that we can tell if we have touched the bottom or not.



    if (l<2) // n>1, so the string length must be greater than 2
    {
        cout << "The String must contain 2 digits at least!\n";
        return 0;
    }



    else if (s[0] == '1') // The string can't start with 1, as it is against the requirements
    {
        cout << "The String must start with a 0\n";
        return 0;
    }



    else if (s[0] == '0') // So, if the string starts with 0, this program will execute the code below
    {
        for(j = 0; j<l; j++) // This loop will iterate through the whole string
        {


            if (s[j] == '1' && s[j+1] == '0') // Will look if there is any 0's after 1, as 0101 or 001110 type strings are not accepted
            {
                cout << "0's after 1 is not allowed!\n";
                return 0;
            }



            else // This segment will push and pop every element from the string to the stack. If 0 found, it will be pushed and for every 1's a 0 will be popped
            {
                for(i=0; i<l; i++)
                {
                    if(s[i]=='0' || s[i]=='1')
                    {
                        if(s[i]=='0')
                        {
                            s1.Push(s[i]);
                        }
                        else
                        {
                            if (s1.IsEmpty())//Before popping it will check if the stack is empty or not
                            {
                                cout <<"There are more 1's than 0's. So the String is Not Accepted for (0^n)(1^n)\n";
                                return 0;
                            }

                            else
                                s1.Pop();//Pop a 0
                        }
                    }
                    else
                    {
                        break;
                    }
                }
            }



        }
    }



    if(s1.Top()==-1) // Now this is checking if the loop has checked all the string elements and the stack is left with only the reference value we have set at the beginning that was "-1"
    {
        cout<<"\nString is Accepted for (0^n)(1^n).\n";
    }
    else
    {
        cout<<"\nString is Not Accepted for (0^n)(1^n).\n";
    }
    return 0;
}
