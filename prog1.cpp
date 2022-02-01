
/*

Name: Hanna Zelis
Date: 24 October 2021
Class: CSC 2342
Statement: This program takes three sets, universal, A, and B, and uses their bit strings to solve certain problems, including the complement of set A, the union of sets A and B, the intersection of sets A and B, A - B, and the xor of sets A and B.

*/



#include <iostream>
#include <string>
#include <cmath>
#include <fstream>

using namespace std;



struct element
{

   string name;
   int bit;

};


element setU[32];


void allProgramFunctions();







int main()
{
   
   allProgramFunctions();

   return 0;
}







void allProgramFunctions()
{

   int p = 1 ;
   int n = 0;
   int countElements = 0;
   unsigned int U = 0;  //this variable holds the bitstring of the universal set





   //reading in the universal set
   while (cin.peek() != '\n')
   {
      cin >> setU[n].name;
      setU[n].bit = p;
      n++;
      p *= 2;
      countElements++;
   }





   //this outputs the universal set and sets the bitstring of the universal set
   cout << "U = {";
   for (int i = 0; i < countElements; i++)
   {
      if (i < countElements - 1)
         cout << setU[i].name << ", ";
      if (i == countElements - 1)
         cout << setU[i].name << "}" << endl;
   }   
   for (int i = 0; i < 32; i++)
   {
      if (setU[i].name > to_string(0))
         U = U + setU[i].bit;
   }





   //reading in and outputting setA
   cin.ignore();
   unsigned int A = 0;  //this variable holds the bitstring of the A set
   n = 0;
   cout << "A = {"; 
   while (cin.peek() != '\n')
   {
      string word;
      cin >> word;

      cout << word << ", ";

      for (int i = 0; i < 32; i++)
      {
         if (word == setU[i].name)
            A = A + setU[i].bit;
      }

      n++;
   }
   cout << '\b' << '\b' << "}";
   cout << endl;





   //reading and outputting setB
   cin.ignore();
   unsigned int B = 0;  //this variable holds the bitstring of the B set
   n = 0;
   cout << "B = {";
   while (cin.peek() != '\n')
   {
      string word;
      cin >> word;

      cout << word << ", ";

      for (int i = 0; i < 32; i++)
      {
         if (setU[i].name == word)
            B = B + setU[i].bit;
         else
            B = B;
      }
   }
   cout << '\b' << '\b' << "}";
   cout << endl;
   cout << endl;

   



   //figuring out ~A her
   cout << "~A = {";

   unsigned int x = ~A & U;
   for (int i = 0; i <= countElements - 1; i++)
   {
      if ((x & setU[i].bit) != 0)
      {
         x ^= setU[i].bit;
         cout << setU[i].name << ", ";
      }
   }
   cout << '\b' << '\b' << "}";
   cout << endl;





   ///figuring out A union B
   unsigned int AunionB = A|B;
   cout << "A union B = {";
   for (int i = 0; i <= countElements - 1; i++)
   {
      if ((AunionB & setU[i].bit) != 0)
      {
         AunionB ^= setU[i].bit;
         cout << setU[i].name << ", ";
      }

   }
   cout << '\b' << '\b' << "}";
   cout << endl;





   //figuring out A intersection B
   unsigned int AintersectionB = A&B;
   cout << "A intersect B = {";
   for (int i = 0; i <= countElements - 1; i++)
   {
      if ((AintersectionB & setU[i].bit) != 0)
      {
         AintersectionB ^= setU[i].bit;
         cout << setU[i].name << ", ";
      }

   }
   cout << '\b' << '\b' << "}";
   cout << endl;





   //figuring out A - B
   unsigned int AnotB = A^(A&B);
   cout << "A - B = {";
   for (int i = 0; i <= countElements - 1; i++)
   {
      if ((AnotB & setU[i].bit) != 0)
      {
         AnotB ^= setU[i].bit;
         cout << setU[i].name << ", ";
      }

   }
   cout << '\b' << '\b' << "}";
   cout << endl;





   ///figuring out A xor B
   unsigned int AxorB = A^B;
   cout << "A xor B = {";
   for (int i = 0; i <= countElements - 1; i++)
   {
      if ((AxorB & setU[i].bit) != 0)
      {
         AxorB ^= setU[i].bit;
         cout << setU[i].name << ", ";
      }

   }
   cout << '\b' << '\b' << "}";
   cout << endl;

}

