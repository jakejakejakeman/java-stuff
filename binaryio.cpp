#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <limits>
using namespace std;

struct Weapons
{
   string weaponname;
   int rating;
   float power;
   Weapons(string x, int y, float z)
   {
      weaponname=x;
      rating=y;
      power=z;
   }
};
struct Starship
{
   string name;
   string lass;
   short length;
   int capacity;
   float warp;
   vector <Weapons> guy;
   Starship(string a, string b, short c, int d, float e, vector <Weapons> f)
   {
      name=a;
      lass=b;
      length=c;
      capacity=d;
      warp=e;
      guy=f;
   }
};


int main()
{
   short lengths;
   int capacities, weaponcount, ratings;
   float warps, powers;
   vector <Starship> fi1;
	/*cout << "Which file(s) to open?\n";
	cout << "1. friendlyships.shp" << endl;
	cout << "2. enemyships.shp" << endl;
	cout << "3. Both files" << endl;*/
	int option;
	cin >> option;

   /* Load files here */
   if (option==1)
   {
      ifstream file("friendlyships.shp", ios_base::binary);
      if (file.is_open())
      {
         int shipcount;
         file.read ((char *)&shipcount, 4);
         for (int i=0; i<shipcount; i++)
         {
            int namecount, clasecount;
            file.read ((char *)&namecount, 4);
            char *nam= new char[namecount];
            file.read ((char *)nam,namecount*sizeof(nam[0]));
            file.read ((char *)&clasecount, 4);
            char *clas=new char[clasecount];
            file.read ((char *)clas,clasecount*sizeof(clas[0]));
            file.read ((char *)&lengths, 2);
            file.read ((char *)&capacities, 4);
            file.read ((char *)&warps, 4);
            file.read ((char *)&weaponcount, 4);
            vector <Weapons> fi2;
            if (weaponcount!=0)
            {
               for (int i=0; i<weaponcount; i++)
               {
                  int weaponnamecount;
                  file.read ((char *)&weaponnamecount, 4);
                  char *weaponnam= new char[weaponnamecount];
                  file.read ((char *)weaponnam, weaponnamecount*sizeof(weaponnam[0]));
                  file.read ((char *)&ratings, 4);
                  file.read ((char *)&powers, 4);
                  Weapons uno(weaponnam, ratings, powers);
                  fi2.push_back(uno);
               }
            }
            else
            {
               Weapons uno("none", 0, 0);
               fi2.push_back(uno);
            }
            Starship hello(nam, clas, lengths, capacities, warps, fi2);
            fi1.push_back(hello);
         }   
      }
   }
   else if (option==2)
   {
      ifstream file("enemyships.shp", ios_base::binary);
      if (file.is_open())
      {
         int shipcount;
         file.read ((char *)&shipcount, 4);
         for (int i=0; i<shipcount; i++)
         {
            int namecount, clasecount;
            file.read ((char *)&namecount, 4);
            char *nam= new char[namecount];
            file.read ((char *)nam,namecount*sizeof(nam[0]));
            file.read ((char *)&clasecount, 4);
            char *clas=new char[clasecount];
            file.read ((char *)clas,clasecount*sizeof(clas[0]));
            file.read ((char *)&lengths, 2);
            file.read ((char *)&capacities, 4);
            file.read ((char *)&warps, 4);
            file.read ((char *)&weaponcount, 4);
            vector <Weapons> fi2;
            if (weaponcount!=0)
            {
               for (int i=0; i<weaponcount; i++)
               {
                  int weaponnamecount;
                  file.read ((char *)&weaponnamecount, 4);
                  char *weaponnam= new char[weaponnamecount];
                  file.read ((char *)weaponnam, weaponnamecount*sizeof(weaponnam[0]));
                  file.read ((char *)&ratings, 4);
                  file.read ((char *)&powers, 4);
                  Weapons uno(weaponnam, ratings, powers);
                  fi2.push_back(uno);
               }
            }
            else
            {
               Weapons uno("none", 0, 0);
               fi2.push_back(uno);
            }
            Starship hello(nam, clas, lengths, capacities, warps, fi2);
            fi1.push_back(hello);
         }   
      }
   }
   else
   {
      ifstream file("friendlyships.shp", ios_base::binary);
      if (file.is_open())
      {
         int shipcount;
         file.read ((char *)&shipcount, 4);
         for (int i=0; i<shipcount; i++)
         {
            int namecount, clasecount;
            file.read ((char *)&namecount, 4);
            char *nam= new char[namecount];
            file.read ((char *)nam,namecount*sizeof(nam[0]));
            file.read ((char *)&clasecount, 4);
            char *clas=new char[clasecount];
            file.read ((char *)clas,clasecount*sizeof(clas[0]));
            file.read ((char *)&lengths, 2);
            file.read ((char *)&capacities, 4);
            file.read ((char *)&warps, 4);
            file.read ((char *)&weaponcount, 4);
            vector <Weapons> fi2;
            if (weaponcount!=0)
            {
               for (int i=0; i<weaponcount; i++)
               {
                  int weaponnamecount;
                  file.read ((char *)&weaponnamecount, 4);
                  char *weaponnam= new char[weaponnamecount];
                  file.read ((char *)weaponnam, weaponnamecount*sizeof(weaponnam[0]));
                  file.read ((char *)&ratings, 4);
                  file.read ((char *)&powers, 4);
                  Weapons uno(weaponnam, ratings, powers);
                  fi2.push_back(uno);
               }
            }
            else
            {
               Weapons uno("none", 0, 0);
               fi2.push_back(uno);
            }
            Starship hello(nam, clas, lengths, capacities, warps, fi2);
            fi1.push_back(hello);
         }   
      }
      ifstream file2("enemyships.shp", ios_base::binary);
      if (file2.is_open())
      {
         int shipcount;
         file2.read ((char *)&shipcount, 4);
         for (int i=0; i<shipcount; i++)
         {
            int namecount, clasecount;
            file2.read ((char *)&namecount, 4);
            char *nam= new char[namecount];
            file2.read ((char *)nam,namecount*sizeof(nam[0]));
            file2.read ((char *)&clasecount, 4);
            char *clas=new char[clasecount];
            file2.read ((char *)clas,clasecount*sizeof(clas[0]));
            file2.read ((char *)&lengths, 2);
            file2.read ((char *)&capacities, 4);
            file2.read ((char *)&warps, 4);
            file2.read ((char *)&weaponcount, 4);
            vector <Weapons> fi2;
            if (weaponcount!=0)
            {
               for (int i=0; i<weaponcount; i++)
               {
                  int weaponnamecount;
                  file2.read ((char *)&weaponnamecount, 4);
                  char *weaponnam= new char[weaponnamecount];
                  file2.read ((char *)weaponnam, weaponnamecount*sizeof(weaponnam[0]));
                  file2.read ((char *)&ratings, 4);
                  file2.read ((char *)&powers, 4);
                  Weapons uno(weaponnam, ratings, powers);
                  fi2.push_back(uno);
               }
            }
            else
            {
               Weapons uno("none", 0, 0);
               fi2.push_back(uno);
            }
            Starship hello(nam, clas, lengths, capacities, warps, fi2);
            fi1.push_back(hello);
         }   
      }
   }
   /*   
	cout << "1. Print all ships" << endl;
	cout << "2. Starship with the strongest weapon" << endl;
	cout << "3. Strongest starship overall" << endl;
	cout << "4. Weakest ship (ignoring unarmed)" << endl;
	cout << "5. Unarmed ships" << endl;*/
	
	cin >> option;
	if (option==1)
	{
	   for (unsigned int i=0; i<fi1.size(); i++)
	   {
	      cout<<"Name: "<<fi1[i].name<<endl;
	      cout<<"Class: "<<fi1[i].lass<<endl;
	      cout<<"Length: "<<fi1[i].length<<endl;
	      cout<<"Shield capacity: "<<fi1[i].capacity<<endl;
	      cout<<"Maximum Warp: "<<fi1[i].warp<<endl;
	      cout<<"Armaments: "<<endl;
	      if (fi1[i].guy[0].rating==0)
	         cout<<"Unarmed"<<endl;
	      else
	      {
	         int total=0;
	         for (unsigned int j=0; j<fi1[i].guy.size(); j++)
	            {
	               cout<<fi1[i].guy[j].weaponname<<", "<<fi1[i].guy[j].rating<<", "<<fi1[i].guy[j].power<<endl;
	               total+=fi1[i].guy[j].rating;
	            }
	        cout<<"Total firepower: "<<total<<endl;
	      }
	      cout<<endl;
	   }
	}
	if (option==2)
	{
	   int max=fi1[0].guy[0].rating;
	   Starship maxi=fi1[0];
	   for (unsigned int i=0; i<fi1.size(); i++)
	   {
	      for (unsigned int j=0; j<fi1[i].guy.size(); j++)
	      {
	         if (fi1[i].guy[j].rating>max)
	         {
	            max=fi1[i].guy[j].rating;
	            maxi=fi1[i];
	         }
	      }
	   }
      cout<<"Name: "<<maxi.name<<endl;
      cout<<"Class: "<<maxi.lass<<endl;
      cout<<"Length: "<<maxi.length<<endl;
      cout<<"Shield capacity: "<<maxi.capacity<<endl;
      cout<<"Maximum Warp: "<<maxi.warp<<endl;
      cout<<"Armaments: "<<endl;
      if (maxi.guy[0].rating==0)
         cout<<"Unarmed"<<endl;
      else
      {
         int total=0;
         for (unsigned int j=0; j<maxi.guy.size(); j++)
            {
               cout<<maxi.guy[j].weaponname<<", "<<maxi.guy[j].rating<<", "<<maxi.guy[j].power<<endl;
               total+=maxi.guy[j].rating;
            }
        cout<<"Total firepower: "<<total<<endl;
      }
      cout<<endl;
	} 
	if (option==3)
	{
	   int max=fi1[0].guy[0].rating;
	   Starship maxi=fi1[0];
	   for (unsigned int i=0; i<fi1.size(); i++)
	   {
	      int total=0;
	      for (unsigned int j=0; j<fi1[i].guy.size(); j++)
	         total+=fi1[i].guy[j].rating;
	      if (total>max)
	      {
	         max=total;
	         maxi=fi1[i];
	      }
	   }
      cout<<"Name: "<<maxi.name<<endl;
      cout<<"Class: "<<maxi.lass<<endl;
      cout<<"Length: "<<maxi.length<<endl;
      cout<<"Shield capacity: "<<maxi.capacity<<endl;
      cout<<"Maximum Warp: "<<maxi.warp<<endl;
      cout<<"Armaments: "<<endl;
      if (maxi.guy[0].rating==0)
         cout<<"Unarmed"<<endl;
      else
      {
         int total=0;
         for (unsigned int j=0; j<maxi.guy.size(); j++)
            {
               cout<<maxi.guy[j].weaponname<<", "<<maxi.guy[j].rating<<", "<<maxi.guy[j].power<<endl;
               total+=maxi.guy[j].rating;
            }
        cout<<"Total firepower: "<<total<<endl;
      }
      cout<<endl;
	}
	if (option==4)
	{
	   int min=50000;
	   Starship maxi=fi1[0];
	   for (unsigned int i=0; i<fi1.size(); i++)
	   {
	      if (fi1[i].guy[0].rating!=0)
	      {
            int total=0;
            for (unsigned int j=0; j<fi1[i].guy.size(); j++)
               total+=fi1[i].guy[j].rating;
            if (total<min)
            {
               min=total;
               maxi=fi1[i];
            }
	      }
	   }
      cout<<"Name: "<<maxi.name<<endl;
      cout<<"Class: "<<maxi.lass<<endl;
      cout<<"Length: "<<maxi.length<<endl;
      cout<<"Shield capacity: "<<maxi.capacity<<endl;
      cout<<"Maximum Warp: "<<maxi.warp<<endl;
      cout<<"Armaments: "<<endl;
      if (maxi.guy[0].rating==0)
         cout<<"Unarmed"<<endl;
      else
      {
         int total=0;
         for (unsigned int j=0; j<maxi.guy.size(); j++)
            {
               cout<<maxi.guy[j].weaponname<<", "<<maxi.guy[j].rating<<", "<<maxi.guy[j].power<<endl;
               total+=maxi.guy[j].rating;
            }
        cout<<"Total firepower: "<<total<<endl;
      }
      cout<<endl;
	}
   if (option==5)
	{
	   for (unsigned int i=0; i<fi1.size(); i++)
	   {
	      if (fi1[i].guy[0].rating==0)
	      {
            cout<<"Name: "<<fi1[i].name<<endl;
            cout<<"Class: "<<fi1[i].lass<<endl;
            cout<<"Length: "<<fi1[i].length<<endl;
            cout<<"Shield capacity: "<<fi1[i].capacity<<endl;
            cout<<"Maximum Warp: "<<fi1[i].warp<<endl;
            cout<<"Armaments: "<<endl;
            if (fi1[i].guy[0].rating==0)
               cout<<"Unarmed"<<endl;
	      }
	      cout<<endl;
	   }
	}


	/* Work your magic here */
	
	
   return 0;
}