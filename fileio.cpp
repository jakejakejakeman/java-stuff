#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

struct Lego
{
   int number;
   string theme;
   string name;
   int minifig;
   int piece;
   float usprice;
   Lego(int a, string b, string c, int d, int e, float f)
   {
      number=a;
      theme=b;
      name=c;
      minifig=d;
      piece=e;
      usprice=f;
   }
};

int main()
{
   vector<Lego> fi1;
   int counter, numbers, minifigs, pieces;
   string themes, names;
   float usprices;
	cout << std::fixed << setprecision(2);
	cout << "Which file(s) to open?\n";
	cout << "1. lego1.csv" << endl;
	cout << "2. lego2.csv" << endl;
	cout << "3. lego3.csv" << endl;
	cout << "4. All 3 files" << endl;
	int option;
	cin >> option;
	   /*======= Load data from file(s) =======*/
	if (option==1)
	{
	   string someString;
	   counter=0;
	   ifstream file("lego1.csv");
	   if (file.is_open())
	   {
	      string line;
	      file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	      while (getline(file,line))
	      {
            string first = line.substr(0,line.find_first_of(','));
            string rest = line.substr(line.find_first_of(',')+1);
	         someString=first;
	         numbers=stoi(someString);
	         string second = rest.substr(0,rest.find_first_of(','));
            string rest2 = rest.substr(rest.find_first_of(',')+1);   	         
	         themes=second;
	         string third = rest2.substr(0,rest2.find_first_of(','));
	         string rest3 = rest2.substr(rest2.find_first_of(',')+1);
	         names=third;
	         string fourth = rest3.substr(0,rest3.find_first_of(','));
	         string rest4 = rest3.substr(rest3.find_first_of(',')+1);
	         someString=fourth;
	         minifigs=stoi(someString);
	         string fifth = rest4.substr(0,rest4.find_first_of(','));
	         string sixth = rest4.substr(rest4.find_first_of(',')+1);
	         someString=fifth;
	         pieces=stoi(someString);
	         someString=sixth;
	         usprices=stof(someString);
	         Lego guy(numbers, themes, names, minifigs, pieces, usprices);
	         fi1.push_back(guy);
	         counter++;
	      }
	   file.close();
	   }
	}
	else if (option==2)
	{
	   string someString;
	   counter=0;
	   ifstream file("lego2.csv");
	   if (file.is_open())
	   {
	      string line;
	      file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	      while (getline(file,line))
	      {
            string first = line.substr(0,line.find_first_of(','));
            string rest = line.substr(line.find_first_of(',')+1);
	         someString=first;
	         numbers=stoi(someString);
	         string second = rest.substr(0,rest.find_first_of(','));
            string rest2 = rest.substr(rest.find_first_of(',')+1);   	         
	         themes=second;
	         string third = rest2.substr(0,rest2.find_first_of(','));
	         string rest3 = rest2.substr(rest2.find_first_of(',')+1);
	         names=third;
	         string fourth = rest3.substr(0,rest3.find_first_of(','));
	         string rest4 = rest3.substr(rest3.find_first_of(',')+1);
	         someString=fourth;
	         minifigs=stoi(someString);
	         string fifth = rest4.substr(0,rest4.find_first_of(','));
	         string sixth = rest4.substr(rest4.find_first_of(',')+1);
	         someString=fifth;
	         pieces=stoi(someString);
	         someString=sixth;
	         usprices=stof(someString);
	         Lego guy(numbers, themes, names, minifigs, pieces, usprices);
	         fi1.push_back(guy);
	         counter++;
	      }
	   file.close();
	   }
	}
   else if (option==3)
	{
	   string someString;
	   counter=0;
	   ifstream file("lego3.csv");
	   if (file.is_open())
	   {
	      string line;
	      file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	      while (getline(file,line))
	      {
            string first = line.substr(0,line.find_first_of(','));
            string rest = line.substr(line.find_first_of(',')+1);
	         someString=first;
	         numbers=stoi(someString);
	         string second = rest.substr(0,rest.find_first_of(','));
            string rest2 = rest.substr(rest.find_first_of(',')+1);   	         
	         themes=second;
	         string third = rest2.substr(0,rest2.find_first_of(','));
	         string rest3 = rest2.substr(rest2.find_first_of(',')+1);
	         names=third;
	         string fourth = rest3.substr(0,rest3.find_first_of(','));
	         string rest4 = rest3.substr(rest3.find_first_of(',')+1);
	         someString=fourth;
	         minifigs=stoi(someString);
	         string fifth = rest4.substr(0,rest4.find_first_of(','));
	         string sixth = rest4.substr(rest4.find_first_of(',')+1);
	         someString=fifth;
	         pieces=stoi(someString);
	         someString=sixth;
	         usprices=stof(someString);
	         Lego guy(numbers, themes, names, minifigs, pieces, usprices);
	         fi1.push_back(guy);
	         counter++;
	      }
	   file.close();
	   }
	}
   else
   {
      string someString;
      counter=0;
	   ifstream file("lego1.csv");
	   if (file.is_open())
	   {
	      string line;
	      file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	      while (getline(file,line))
	      {
            string first = line.substr(0,line.find_first_of(','));
            string rest = line.substr(line.find_first_of(',')+1);
	         someString=first;
	         numbers=stoi(someString);
	         string second = rest.substr(0,rest.find_first_of(','));
            string rest2 = rest.substr(rest.find_first_of(',')+1);   	         
	         themes=second;
	         string third = rest2.substr(0,rest2.find_first_of(','));
	         string rest3 = rest2.substr(rest2.find_first_of(',')+1);
	         names=third;
	         string fourth = rest3.substr(0,rest3.find_first_of(','));
	         string rest4 = rest3.substr(rest3.find_first_of(',')+1);
	         someString=fourth;
	         minifigs=stoi(someString);
	         string fifth = rest4.substr(0,rest4.find_first_of(','));
	         string sixth = rest4.substr(rest4.find_first_of(',')+1);
	         someString=fifth;
	         pieces=stoi(someString);
	         someString=sixth;
	         usprices=stof(someString);
	         Lego guy(numbers, themes, names, minifigs, pieces, usprices);
	         fi1.push_back(guy);
	         counter++;
	      }
	   file.close();
	   }
	   counter=0;
	   ifstream file2("lego2.csv");
	   if (file2.is_open())
	   {
	      string line2;
	      file2.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	      while (getline(file2,line2))
	      {
            string first = line2.substr(0,line2.find_first_of(','));
            string rest = line2.substr(line2.find_first_of(',')+1);
	         someString=first;
	         numbers=stoi(someString);
	         string second = rest.substr(0,rest.find_first_of(','));
            string rest2 = rest.substr(rest.find_first_of(',')+1);   	         
	         themes=second;
	         string third = rest2.substr(0,rest2.find_first_of(','));
	         string rest3 = rest2.substr(rest2.find_first_of(',')+1);
	         names=third;
	         string fourth = rest3.substr(0,rest3.find_first_of(','));
	         string rest4 = rest3.substr(rest3.find_first_of(',')+1);
	         someString=fourth;
	         minifigs=stoi(someString);
	         string fifth = rest4.substr(0,rest4.find_first_of(','));
	         string sixth = rest4.substr(rest4.find_first_of(',')+1);
	         someString=fifth;
	         pieces=stoi(someString);
	         someString=sixth;
	         usprices=stof(someString);
	         Lego guy(numbers, themes, names, minifigs, pieces, usprices);
	         fi1.push_back(guy);
	         counter++;
	      }
	   file2.close();
	   }
      ifstream file3("lego3.csv");
	   if (file3.is_open())
	   {
	      string line3;
	      file3.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	      while (getline(file3,line3))
	      {
            string first = line3.substr(0,line3.find_first_of(','));
            string rest = line3.substr(line3.find_first_of(',')+1);
	         someString=first;
	         numbers=stoi(someString);
	         string second = rest.substr(0,rest.find_first_of(','));
            string rest2 = rest.substr(rest.find_first_of(',')+1);   	         
	         themes=second;
	         string third = rest2.substr(0,rest2.find_first_of(','));
	         string rest3 = rest2.substr(rest2.find_first_of(',')+1);
	         names=third;
	         string fourth = rest3.substr(0,rest3.find_first_of(','));
	         string rest4 = rest3.substr(rest3.find_first_of(',')+1);
	         someString=fourth;
	         minifigs=stoi(someString);
	         string fifth = rest4.substr(0,rest4.find_first_of(','));
	         string sixth = rest4.substr(rest4.find_first_of(',')+1);
	         someString=fifth;
	         pieces=stoi(someString);
	         someString=sixth;
	         usprices=stof(someString);
	         Lego guy(numbers, themes, names, minifigs, pieces, usprices);
	         fi1.push_back(guy);
	         counter++;
	      }
	   file3.close();
	   }
   }
   /*======= Print out how many sets were loaded =======*/
   
   /* Imagine your program had a menu like this:
   cout << "1. Most Expensive set" << endl;
	cout << "2. Largest piece count" << endl;
	cout << "3. Search for set name containing..." << endl;
	cout << "4. Search themes..." << endl;
	cout << "5. Part count information" << endl;
	cout << "6. Price information" << endl;
	cout << "7. Minifigure information" << endl;
	cout << "8. If you bought one of everything..." << endl;
	cout << "0. Exit" << endl;
   */
   cout<<"Total number of sets: "<<fi1.size()<<endl;
   cout<<endl;
	int choice;
	cin >> choice;
   cin.get();  // Clear newline character for any later input
   
   /*======= Based on the choice, execute the appropriate task and show the results =======*/
   if (choice==1)
   {
      float max=fi1[0].usprice;
      Lego maxi=fi1[0];
      for (unsigned int i=0; i<fi1.size(); i++)
      {
         if (fi1[i].usprice>max)
         {
            max=fi1[i].usprice;
            maxi=fi1[i];
         }
      }
      cout<<"The most expensive set is:"<<endl;
      cout<<"Name: "<<maxi.name<<endl;
      cout<<"Number: "<<maxi.number<<endl;
      cout<<"Theme: "<<maxi.theme<<endl;
      cout<<"Price: $"<<maxi.usprice<<endl;
      cout<<"Minifigures: "<<maxi.minifig<<endl;
      cout<<"Piece count: "<<maxi.piece<<endl;
   }
   if (choice==2)
   {
      int max=fi1[0].piece;
      Lego maxi=fi1[0];
      for (unsigned int i=0; i<fi1.size(); i++)
      {
         if (fi1[i].piece>max)
         {
            max=fi1[i].piece;
            maxi=fi1[i];
         }
      }
      cout<<"The set with the highest parts count:"<<endl;
      cout<<"Name: "<<maxi.name<<endl;
      cout<<"Number: "<<maxi.number<<endl;
      cout<<"Theme: "<<maxi.theme<<endl;
      cout<<"Price: $"<<maxi.usprice<<endl;
      cout<<"Minifigures: "<<maxi.minifig<<endl;
      cout<<"Piece count: "<<maxi.piece<<endl;
   }
   if (choice==3)
   {
      vector<Lego> fi2;
      string input;
      int count=0;

      getline (cin,input);
      for (unsigned int i=0; i<fi1.size(); i++)
         if (fi1[i].name.find(input)!=string::npos)
         {
            fi2.push_back(fi1[i]);
            count++;
         }
      if (count==0)
         cout<<"No sets found matching that search term";
      else
      {
         cout<<"Sets matching \""<<input<<"\":"<<endl;
         for (unsigned int i=0; i<fi2.size(); i++)
            cout<<fi2[i].number<<" "<<fi2[i].name<<" $"<<fi2[i].usprice<<endl;
      }
   }
   if (choice==4)
   {
      vector<Lego> fi2;
      string input;
      int count=0;
      getline (cin,input);
      for (unsigned int i=0; i<fi1.size(); i++)
         if (fi1[i].theme.find(input)!=string::npos)
         {
            fi2.push_back(fi1[i]);
            count++;
         }
      if (count==0)
         cout<<"No sets found matching that search term";
      else
      {
         cout<<"Sets matching \""<<input<<"\":";
         for (unsigned int i=0; i<fi2.size(); i++)
            cout<<fi2[i].number<<" "<<fi2[i].name<<" $"<<fi2[i].usprice<<endl;
      }
   }
   if (choice==5)
   {
      int count=0;
      for (unsigned int i=0; i<fi1.size(); i++)
         count+=fi1[i].piece;
      cout<<"Average part count for "<<fi1.size()<<"sets: "<<count/fi1.size();
   }
   if (choice==6)
   {
      float count=0;
      float max=fi1[0].usprice;
      float min=fi1[0].usprice;
      Lego maxi=fi1[0];
      Lego mini=fi1[0];
      for (unsigned int i=0; i<fi1.size(); i++)
      {
         count+=fi1[i].usprice;
         if (fi1[i].usprice>max)
         {
            max=fi1[i].usprice;
            maxi=fi1[i];
         }
         if (fi1[i].usprice<min)
         {
            min=fi1[i].usprice;
            mini=fi1[i];
         }
      }
      cout<<"Average price for "<<fi1.size()<<" sets: $"<<count/fi1.size()<<endl;
      cout<<endl;
      cout<<"Least expensive set: "<<endl;
      cout<<"Name: "<<mini.name<<endl;
      cout<<"Number: "<<mini.number<<endl;
      cout<<"Theme: "<<mini.theme<<endl;
      cout<<"Price: $"<<mini.usprice<<endl;
      cout<<"Minifigures: "<<mini.minifig<<endl;
      cout<<"Piece count: "<<mini.piece<<endl;
      cout<<endl;
      cout<<"Most expensive set: "<<endl;
      cout<<"Name: "<<maxi.name<<endl;
      cout<<"Number: "<<maxi.number<<endl;
      cout<<"Theme: "<<maxi.theme<<endl;
      cout<<"Price: $"<<maxi.usprice<<endl;
      cout<<"Minifigures: "<<maxi.minifig<<endl;
      cout<<"Piece count: "<<maxi.piece<<endl;
   }
   if (choice==7)
   {
      int count=0;
      int max=fi1[0].minifig;
      Lego maxi=fi1[0];
      for (unsigned int i=0; i<fi1.size(); i++)
      {
         count+=fi1[i].minifig;
         if (fi1[i].minifig>max)
         {
            max=fi1[i].minifig;
            maxi=fi1[i];
         }
      }
      cout<<"Average number of minifigures: "<<count/fi1.size()<<endl;
      cout<<endl;
      cout<<"Set with the most minifigures: "<<endl;
      cout<<"Name: "<<maxi.name<<endl;
      cout<<"Number: "<<maxi.number<<endl;
      cout<<"Theme: "<<maxi.theme<<endl;
      cout<<"Price: $"<<maxi.usprice<<endl;
      cout<<"Minifigures: "<<maxi.minifig<<endl;
      cout<<"Piece count: "<<maxi.piece<<endl;
   }
   if (choice==8)
   {
      float count=0;
      int count2=0;
      int count3=0;
      for (unsigned int i=0; i<fi1.size(); i++)
      {
         count+=fi1[i].usprice;
         count2+=fi1[i].piece;
         count3+=fi1[i].minifig;
      }
      cout<<"If you bought one of everything..."<<endl;
      cout<<"It would cost: $"<<count<<endl;
      cout<<"You would have "<<count2<<" pieces in your collection"<<endl;
      cout<<"You would have an army of "<<count3<<" minifigures!";
   }
      
	return 0;
}


