#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class account
{
protected:
   string first_name;
   string last_name;
   string city;
   string gender;
   string Pass;
   int age;
   int streetno;
   int houseno;
   int phoneno;
   char choice;
   int n;
   int amount;

public:
   int accountno;
   account()
   {

      first_name = " ";
      last_name = " ";
      phoneno = 0;
      amount = 0;
      Pass = " ";

      accountno += 1;
   }

   void setdata()
   {
      system("CLS");
      cout << "**********************************\n";
      cout << "           DATA ENTRY\n";
      cout << "**********************************\n";
      cout << "Enter first name: ";
      cin >> first_name;
      cout << "Enter last name: ";
      cin >> last_name;
      cout << "Enter your gender: ";
      cin >> gender;
      cout << "Enter age: ";
      cin >> age;
      cout << "Enter Phone no: ";
      cin >> phoneno;
      cout << "\n\nEnter your address\nStreet no:";
      cin >> streetno;
      cout << "Enter house no: ";
      cin >> houseno;
      cout << "Enter city: ";
      cin >> city;
      cout << "\n\nEnter amount you want to deposit: ";
      cin >> amount;

      system("CLS");
   }
   int getamount()
   {
      return amount;
   }
   void display()
   {
      cout << "***************************\n";
      cout << "   ACCOUNT CONFIRMATION\n";
      cout << "***************************\n\n\n";
      cout << "You Entered\n";
      cout << "Name: " << first_name << " " << last_name << endl;
      cout << "Age: " << age << endl;
      cout << "Gender: " << gender << endl;

      cout << "phone no: " << phoneno << endl;
      cout << "Address: " << streetno << "-" << houseno << " " << city << endl;
      cout << "Confirm submission (Y/N)\n";
      cin >> choice;
      system("CLS");

      cout << "***************************\n";
      cout << "your account no is: " << accountno << endl;
      cout << "***************************\n";
      cout << "Type a strong password: ";
      cin >> Pass;
      system("CLS");

      cout << "Account created successfully enter any number to continue" << endl;
      cin >> n;
      system("CLS");

      if (choice == 'Y' || choice == 'y')
      {
         ofstream s1;
         s1.open("record.txt", ios::app);
         s1 << "*********************************" << endl;
         s1 << "Account no: " << accountno << endl;
         s1 << Pass << endl;
         s1 << "Name:" << first_name << " " << last_name << endl;
         s1 << "Gender: " << gender << endl;
         s1 << "Age: " << age << endl;
         s1 << "Phone no: " << phoneno << endl;
         s1 << "Street no: " << streetno << "-" << houseno << "," << city << endl;
         s1 << "Amount: " << amount << endl;
         s1 << endl
            << "*******************************" << endl
            << endl;
         s1.close();
      }
      else if (choice == 'N' || choice == 'n')
      {
         first_name = " ";
         last_name = " ";
         phoneno = 0;
         amount = 0;
         Pass = " ";
         accountno = 1;
      }
   }
};

class widraw : public account
{
protected:
   int widraaw;
   int sum;
   int typee;
   char choice;

public:
   widraw() : widraaw(0), typee(0), sum(0)
   {
      
   }

   void type(int c)
   {
      cout << "*********************************\n";
      cout << "Choose transaction type\n1.Normal\n2.Full\nchoice(1or2): ";
      cin >> typee;
      cout << "\n*********************************\n";
      system("CLS");
      if (typee == 1)
      {
         normal(c);
      }
      else if (typee == 2)
      {
         full(c);
      }
      else
      {
         cout << "invalid operation\n";
         type(c);
      }
   }

   void normal(int d)
   {
      int def;
      def = d;
      cout << "***************************************\n";
      cout << "You can only widraw 20,000 at a time\n";
      cout << "***************************************\n";

      cout << "Enter amount to withdrwa: ";
      cin >> widraaw;
      system("CLS");
      cout << "***************************************\n";
      cout << "              CONFIRMATION\n";
      cout << "***************************************\n";
      cout << "Are you sure you want to widrwa " << widraaw << " Rs from your account\nchoice(Y/N):";
      cin >> choice;
      if (choice == 'Y' || choice == 'y')
      {

         if (widraaw > 20000)
         {

            cout << "YOU CANNOT WIDRWA BECAUSE NORMAL TRASACTION MUST BE LESS THAN 20,000 \n";
         }
         else
         {

            sum = def - widraaw;
            cout << endl
                 << endl
                 << endl;

            cout << "***************************************\n";
            cout << "Amount withdrawn: " << widraaw << endl;
            cout << "remaining balance : " << sum << endl;
            cout << "***************************************\n";
         }
      }
      if (choice == 'N' || choice == 'n')
      {

         cout << "***************************************\n";
         cout << "Widrwal canceled!\n";
         cout << " Balance : " << def << endl;
         cout << "***************************************\n";
         system("CLS");
      }
   }
   void full(int g)
   {
      int def;
      def = g;
      cout << "***************************************\n";
      cout << "You can  widraw more than 20,000 at a time\n";
      cout << "***************************************\n";
      cout << "Enter amount to withdrwa";
      cin >> widraaw;
      cout << "***************************************\n";
      cout << "              CONFIRMATION\n";
      cout << "***************************************\n";
      cout << "Are you sure you want to widrwa " << widraaw << " Rs from your account\nchoice(Y/N):";
      cin >> choice;
      if (choice == 'Y' || choice == 'y')
      {

         sum = def - widraaw;
         cout << "***************************************\n";
         cout << "Amount withdrawn: " << widraaw;
         cout << "remaining balance : " << sum;
         cout << "***************************************\n";
      }
      else if (choice == 'N' || choice == 'n')
      {
         cout << "***************************************\n";
         cout << "Widrwal canceled!\n";
         cout << " Balance : " << def << endl;
         cout << "***************************************\n";
      }
   }
};

class deposit : public account
{
protected:
   int depost1;
   char confirm1;
   int sum;

public:
   deposit() : depost1(0), confirm1(' '), sum(0) {}
   void depost(int h)
   {
      int de;
      de = h;
      cout << "Enter amount to be deposited: ";
      cin >> depost1;
      system("CLS");
      cout << "***************************************\n";
      cout << "              CONFIRMATION\n";
      cout << "***************************************\n";
      cout << "Are you sure you want to deposit " << depost1 << " Rs into your account\nchoice(Y/N):";
      cin >> confirm1;
      if (confirm1 == 'Y' || confirm1 == 'y')
      {

         sum = de + depost1;
         cout << "***************************************\n";
         cout << "Amount deposit: " << depost1 << endl;
         cout << "New Balance: " << sum << endl;
         cout << "***************************************\n";
         
      }
      else if (confirm1 == 'N' || confirm1 == 'n')
      {
         cout << "***************************************\n";
         cout << "No changes are made " << endl;
         cout << "Balance: " << de << endl;
         cout << "***************************************\n";
      }
   }
};

class transaction : virtual public account
{

protected:
   int accountc;
   string passc;
   int choice;
   widraw w1;
   deposit d1;

public:
   transaction() : accountc(0), passc(" ")
   {
   }
   void accountconfirmation(int a)
   {

      cout << "*********************************\n";
      cout << "        ACCOUNT CONFIRMATION\n";
      cout << "*********************************\n";
      cout << "Enter account no: ";
      cin >> accountc;
      cout << "Enter password: ";
      cin >> passc;
      system("CLS");
      if (accountc == accountno && passc == Pass)
      {

         cout << "*********************************\n";
         cout << "Do you want to\n1.Withdrwa \n2.Deposit\nchoice(1/2): ";
         cout << "\n*********************************\n";
         cin >> choice;
         if (choice == 1)
         {
            system("CLS");
            w1.type(a);
         }
         else if (choice == 2)
         {
            system("CLS");
            d1.depost(a);
         }
      }
      else
      {
         cout << "INVALID ACCOUNT NO OR PASSWORD" << endl;
         accountconfirmation(a);
      }
   }
};
class display_accounts : virtual public account, public transaction
{
protected:
   string read;

public:
   display_accounts()
   {

      read = " ";
   }
   void display()
   {
      ifstream r1;
      r1.open("record.txt");
      cout << "********************************\n";
      cout << "            RECORD\n";
      cout << "********************************\n";
      while (r1.good())
      {
         getline(r1, read);
         cout << read << endl;
         
      }
      r1.close();
   }
};

int main()
{

   int c, amm;
   display_accounts obj[100];
   
   cout << "-----------------------------------\n";
   cout << "              WELCOME\n";
   cout << "-----------------------------------\n";
   cout << "\nFirst you need to open your account \n";
   cout << "Enter 1 to continue: ";
   cin >> c;
   if (c == 1)
   {
      obj[1].accountno = 1;
      obj[1].setdata();

      amm = obj[1].getamount();
      obj[1].account::display();
   }
   else
   {
      cout << "INVALID OPERATION!\n";
      main();
   }
   for (int i = 1; i <= 100;)
   {
      cout << "------------------------------\n";
      cout << "  CHOOSE FROM THE FOLLOWING\n";
      cout << "------------------------------\n";
      cout << "1.create account\n2.show accounts detail\n3.withdraw or deposit\n4.Exit\nchoice: ";
      cin >> c;
      system("CLS");
      if (c == 1)
      {
         i++;
         obj[i].accountno = i;
         obj[i].setdata();
         amm = obj[i].getamount();
         obj[i].account::display();
      }
      else if (c == 2)
      {

         obj[i].display();
      }
      else if (c == 3)
      {

         obj[i].accountconfirmation(amm);
      }
      else if (c == 4)
      {
         
         cout << "---------------------------------\n";
         cout << "           THANK YOU\n";
         cout << "---------------------------------\n";
         break;
      }
      else
      {

         cout << "Invalid choice";
      }
   }

   return 0;
}