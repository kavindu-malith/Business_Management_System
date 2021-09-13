#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<stdlib.h>
#include<conio.h>

using namespace std;

void managerManu(); //Function For Display Manager Menu
void CashierMenu(); //Function For Display Cashier Menu

class Employee //Parent Class
{
protected:
    string Username , Password; //Protected Variable
public:
    virtual int login(string Use , string Pass)= 0; //Virtual Function Never Use For Employee
};

class Manager : public Employee //Manager Class Inherited From Employee Class (Child Class)
{
public:
    int login(string Use , string Pass);
};

class Cashier : public Employee //Cashier class Inherited From Employee Class (Child Class)
{
public:
    int login(string Use , string Pass);
};

class Vehicle //Vehicle class Variable Declaretion and Function Declaretion
{
private:
    string Name , NIC , TP_NO , Vehicle_typename;
    int Vehicle_category , Noofvehicles;
    double Vehicle_No , Vehicle_Price , Vehicle_type;
public:
    void setcashierData(string N , string nic , string Tp , int VC , int NOV );
    void getdata(int VC);
    void Displaycashier();
    void Cashier();
    void Addvehicle(double VNo , int VC , double VT , double Vp);
    void DeleVehicle(int VC);
};
void Vehicle :: Displaycashier() //Function For Display Cashier Data From Vehicle Class
{
    string data0,data1,data2,data3,data4,data5;
    cout<<"Name\t NIC\t TP Number\t Vehicle Category\t Number Of Vehicles\t Vehicle Type"<<endl;
    ifstream datafile; //Declare input file Object
    datafile.open("Cashier Vehicle.txt"); //Open "Cashier Vehicle" txt File and Load it To Object
    if(datafile.is_open()) //Check file status (open or Not)
    {
        while(!datafile.eof()) //Read txt File Until Its not equal 1 (until string didn't Find
        {
            datafile>>data0>>data1>>data2>>data3>>data4>>data5; //Get Data From txt File
            cout<<data0<<"\t"<<data1<<"\t"<<data2<<"\t"<<data3<<"\t"<<data4<<"\t"<<data5<<endl; //Print Data For User
        }
    }
    else
    {
        system("color 94"); //Change Background Color and Text Color
        cout<<"Something Is Wrong >_<"<<endl; //Display Error Massage
        system("color 90");
    }
    datafile.close();
    cout<<"\t\tPress Any Key To Go Main Menu"<<endl; //Massage For User
    getch(); //Get Any Character From Keyboard
    CashierMenu();// Function Calling (Go back to Cashier Menu
}

void Vehicle :: Cashier()
{
    ofstream datafile1; //Declare Output File Object
    datafile1.open("Cashier Vehicle.txt");
    if(datafile1.is_open())
    {
        datafile1<<Name<<"\t"<<NIC<<"\t"<<TP_NO<<"\t"<<Vehicle_category<<"\t"<<Noofvehicles<<"\t"<<Vehicle_type; //Write Data In txt File
        cout<<"$ Successfully Reserved $"<<endl; //Massage For User
    }
    else
    {
        system("color 94");
        cout<<"Something Is Wrong >_< "<<endl;
        system("color 90");
    }
    datafile1.close(); //File Closing
    cout<<"\t\tPress Any Key To Go Main Menu"<<endl;
    getch();
    CashierMenu();
}

void Vehicle :: getdata(int VC) //Vehicle Class Function
{
    Vehicle_category = VC;
    string data0 , data1, data2;
    if(Vehicle_category==1) //Check Category
    {
        ifstream datafile2;
        datafile2.open("Car.txt");
        if(datafile2.is_open())
        {
            while(!datafile2.eof()) //Check When File Get End (eof = EndOfFile)
            {
                datafile2>>data0>>data1>>data2; //Load data from txt File
                cout<<data0<<"\t"<<data1<<"\t"<<data2<<endl;
            }
        }
        else
        {
            system("color 94");
            cout<<"Something Is Wrong >_<"<<endl;
            system("color 90");
        }
        datafile2.close();
    }
            else if(Vehicle_category==2)
            {
                ifstream datafile2;
                datafile2.open("Van.txt"); //txt File Opening
                if(datafile2.is_open())
                {
                    while(!datafile2.eof())
                    {
                        datafile2>>data0>>data1>>data2;
                        cout<<data0<<"\t"<<data1<<"\t"<<data2<<endl;
                    }
                }
                else
                {
                    system("color 94");
                    cout<<"Something Is Wrong >_<"<<endl;
                    system("color 90");
                }
                datafile2.close();
            }
            else if(Vehicle_category==3)
            {
                ifstream datafile2;
                datafile2.open("Jeep.txt");
                if(datafile2.is_open())
                {
                    while(!datafile2.eof())
                    {
                        datafile2>>data0>>data1>>data2;
                        cout<<data0<<"\t"<<data1<<"\t"<<data2<<endl;
                    }
                }
                else
                {
                    system("color 94");
                    cout<<"Something Is Wrong >_<"<<endl;
                    system("color 90");
                }
                datafile2.close();
            }
            else if(Vehicle_category==4)
            {
                ifstream datafile2;
                datafile2.open("Electronic.txt");
                if(datafile2.is_open())
                {
                    while(!datafile2.eof())
                    {
                        datafile2>>data0>>data1>>data2;
                        cout<<data0<<"\t"<<data1<<"\t"<<data2<<endl;
                    }
                }
                else
                {
                    system("color 94");
                    cout<<"Something Is Wrong >_<"<<endl;
                    system("color 90");
                }
                datafile2.close();
            }
            else
            {
                system("color 94");
                cout<<"Invalid Vehicle Category"<<endl;
                system("color 90");
            }
            cout<<"\t\tPress Any Key To Go Main Menu"<<endl;
            getch();
            CashierMenu();
}

void Vehicle :: DeleVehicle(int VC) //Function Of Vehicle Class
{
    Vehicle_category = VC;
    if(Vehicle_category==1)
    {
        ofstream datafile3;
        datafile3.open("Car.txt");
        if(datafile3.is_open())
        {
            datafile3<<"\n"; // Write Empty String on txt File (it will delete Existing Data)

            cout<<"Successfully Deleted!"<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Something Is Wrong >_<"<<endl;
            system("color 90");
        }
        datafile3.close();
    }
    else if(Vehicle_category==2)
    {
        ofstream datafile3;
        datafile3.open("Van.txt");
        if(datafile3.is_open())
        {
            datafile3<<"\n";

            cout<<"Successfully Deleted!"<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Something Is Wrong >_<"<<endl;
            system("color 90");
        }
        datafile3.close();
    }
    else if(Vehicle_category==3)
    {
        ofstream datafile3;
        datafile3.open("Jeep.txt");
        if(datafile3.is_open())
        {
            datafile3<<"\n";

            cout<<"Successfully Deleted!"<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Something Is Wrong >_<"<<endl;
            system("color 90");
        }
        datafile3.close();
    }
    else if(Vehicle_category==4)
    {
        ofstream datafile3;
        datafile3.open("Electronic.txt");
        if(datafile3.is_open())
        {
            datafile3<<"\n";

            cout<<"Successfully Deleted!"<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Something Is Wrong >_<"<<endl;
            system("color 90");
        }
        datafile3.close();
    }
    else
    {
        system("color 94");
        cout<<"wrong Vehicle Category!"<<endl;
        system("color 90");
    }
    cout<<"\t\tPress Any Key To Go Main Menu"<<endl;
    getch();
    CashierMenu();
}

class Bill //Bill class Function & Variable
{
private:
    int noofvehicle;
    double price , total;
    double BillNo;
public:
    void setnoofvehicle(int nof);
    void Billprocess(int category,int type);
};

void Bill :: setnoofvehicle(int nof) //function Of Bill Class (set Value)
{
    noofvehicle = nof;
}

void Bill :: Billprocess(int category , int type) //Function Of Bill Class (Set Values)
{
    if(category==1)
    {
        if(type==1)
        {
            price = 12000000.00;
            total = price*noofvehicle; //Process
            cout<<"Total Bill Rs:"<<total<<endl; //Show Result
        }
        else if(type==2)
        {
            price = 91000000.00;
            total = price*noofvehicle;
            cout<<"Total Bill Rs:"<<total<<endl;
        }
        else if(type==3)
        {
            price = 24000000.00;
            total = price*noofvehicle;
            cout<<"Total Bill Rs:"<<total<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Invalid Type"<<endl;
            system("color 90");
        }
    }
    else if(category==2)
    {
        if(type==1)
        {
            price = 7000000.00;
            total = price*noofvehicle;
            cout<<"Total Bill Rs:"<<total<<endl;
        }
        else if(type==2)
        {
            price = 9000000.00;
            total = price*noofvehicle;
            cout<<"Total Bill Rs:"<<total<<endl;
        }
        else if(type==3)
        {
            price = 11000000.00;
            total = price*noofvehicle;
            cout<<"Total Bill Rs:"<<total<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Invalid Type"<<endl;
            system("color 90");
        }
    }
    else if(category==3)
    {
        if(type==1)
        {
            price = 8000000.00;
            total = price*noofvehicle;
            cout<<"Total Bill Rs:"<<total<<endl;
        }
        else if(type==2)
        {
            price = 10000000.00;
            total = price*noofvehicle;
            cout<<"Total Bill Rs:"<<total<<endl;
        }
        else if(type==3)
        {
            price = 18000000.00;
            total = price*noofvehicle;
            cout<<"Total Bill Rs:"<<total<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Invalid Type"<<endl;
            system("color 90");
        }
    }
    else if(category==4)
    {
        if(type==1)
        {
            price = 12000000.00;
            total = price*noofvehicle;
            cout<<"Total Bill Rs:"<<total<<endl;
        }
        else if(type==2)
        {
            price = 24000000.00;
            total = price*noofvehicle;
            cout<<"Total Bill Rs:"<<total<<endl;
        }
        else if(type==3)
        {
            price = 26000000.00;
            total = price*noofvehicle;
            cout<<"Total Bill Rs:"<<total<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Invalid Type"<<endl;
            system("color 90");
        }
    }
    else
    {
        system("color 94");
        cout<<"Invalid Vehicle Category"<<endl;
        system("color 90");
    }
    cout<<"Press Any Key To Go Main Menu"<<endl;
    getch();
    CashierMenu();
}

int Manager :: login(string Use , string Pass) //Function Of Manager Class (Access / Check UserName And PW)
{
    Username = Use;
    Password = Pass;
    if(Username == "Dharshana" && Password == "1234") //PW and UseName Declaration (Hard coded)
    {
        system("cls"); //Clear screen (outputs before This Cmd)
        system("color 9A");
        cout<<"\n\n\n\t\t\t$$$$$$$$$$ Login Successful $$$$$$$$$$"<<endl;
        system("color 90");
        Sleep(1800); //Freez The Output (mile seconds)
        managerManu();
        return 1; //Return a Value
    }
    else
    {
        system("cls");
        system("color 94");
        cout<<"\n\n\n\t\t\t$$$$$$$$$$ Invalid UserName Or Password $$$$$$$$$$"<<endl;
        system("color 90");
        Sleep(1800);
        return 0;
    }
}

int Cashier :: login(string Use , string Pass) //Function Of Cashier Class Check Login Details
{
    Username = Use;
    Password = Pass;
    if(Username == "Harsha" && Password == "1234") //Same as Manager Login Function
    {
        system("cls");
        system("color 9A");
        cout<<"\n\n\n\t\t\t$$$$$$$$$$ Login Successful $$$$$$$$$$"<<endl;
        system("color 90");
        Sleep(1800);
        CashierMenu();
        return 1;
    }
    else
    {
        system("cls");
        system("color 94");
        cout<<"\n\n\n\t\t\t$$$$$$$$$$ Invalid User Name Or Password $$$$$$$$$$"<<endl; //Error Massage
        system("color 90");
        Sleep(1800);
        return 0;
    }
}

void Vehicle :: Addvehicle(double VNo , int VC , double VT ,double Vp) //Function Of Vehicle Class (add Vehicles)
{
    Vehicle_No = VNo;
    Vehicle_category = VC;
    Vehicle_type = VT;
    Vehicle_Price = Vp;
    if(Vehicle_category==1)
    {
        if(Vehicle_type==1) //Check vehicle Type
        {
            Vehicle_typename = "Benz"; //Inisielize Data
        }
        else if(Vehicle_type==2)
        {
            Vehicle_typename = "Lamborghini";
        }
        else if(Vehicle_type==3)
        {
            Vehicle_typename = "BMW";
        }
        else
        {
            system("color 94");
            cout<<"\n\n\t\tInvalid Type"<<endl;
            system("color 90");
        }
    }
    else if(Vehicle_category==2)
    {
        if(Vehicle_type==1)
        {
            Vehicle_typename = "Toyota";
        }
        else if(Vehicle_type==2)
        {
            Vehicle_typename = "Range Rower";
        }
        else if(Vehicle_type==3)
        {
            Vehicle_typename = "JEEP";
        }
        else
        {
            system("color 94");
            cout<<"\n\n\t\tInvalid Type"<<endl;
            system("color 90");
        }
    }
    else if(Vehicle_category==3)
    {
        if(Vehicle_type==1)
        {
            Vehicle_typename = "Toyota";
        }
        else if(Vehicle_type==2)
        {
            Vehicle_typename = "Nisan";
        }
        else if(Vehicle_type==3)
        {
            Vehicle_typename = "Benz";
        }
        else
        {
            system("color 94");
            cout<<"\n\n\t\tInvalid Type"<<endl;
            system("color 90");
        }
    }
    else if(Vehicle_category==4)
    {
        if(Vehicle_type==1)
        {
            Vehicle_typename = "Nisan";
        }
        else if(Vehicle_type==2)
        {
            Vehicle_typename = "Benz";
        }
        else if(Vehicle_type==3)
        {
            Vehicle_typename = "Tesla";
        }
        else
        {
            system("color 94");
            cout<<"\n\n\t\tInvalid Type"<<endl;
            system("color 90");
        }
    }
    else
    {
        cout<<"\n\n\n\t\t\tPress Any Key To Go Main Menu"<<endl;
        getch();
        managerManu();
    }
    if(Vehicle_category==1)
    {
        ofstream datafile0;
        datafile0.open("Car.txt");
        if(datafile0.is_open())
        {
            datafile0<<Vehicle_No<<"\t"<<Vehicle_typename<<"\t"<<Vehicle_Price;
            cout<<"$$$ Successfully Vehicle Added! $$$"<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Something Is Wrong >_<"<<endl;
            system("color 90");
        }
        datafile0.close();
    }
    else if(Vehicle_category==2)
    {
        ofstream datafile0;
        datafile0.open("Jeep.txt");
        if(datafile0.is_open())
        {
            datafile0<<Vehicle_No<<"\t"<<Vehicle_typename<<"\t"<<Vehicle_Price;
            cout<<"$$$ Successfully Vehicle Added! $$$"<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Something Is Wrong >_<"<<endl;
            system("color 90");
        }
        datafile0.close();
    }
    else if(Vehicle_category==3)
    {
        ofstream datafile0;
        datafile0.open("Van.txt");
        if(datafile0.is_open())
        {
            datafile0<<Vehicle_No<<"\t"<<Vehicle_typename<<"\t"<<Vehicle_Price;
            cout<<"$$$ Successfully Vehicle Added! $$$"<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Something Is Wrong >_<"<<endl;
            system("color 90");
        }
        datafile0.close();
    }
    else if(Vehicle_category==4)
    {
        ofstream datafile0;
        datafile0.open("Electronic.txt");
        if(datafile0.is_open())
        {
            datafile0<<Vehicle_No<<"\t"<<Vehicle_typename<<"\t"<<Vehicle_Price;
            cout<<"$$$ Successfully Vehicle Added! $$$"<<endl;
        }
        else
        {
            system("color 94");
            cout<<"Something Is Wrong >_<"<<endl;
            system("color 90");
        }
        datafile0.close();
    }
    else
    {
        system("color 94");
        cout<<"Invalid Category"<<endl;
        system("color 90");
    }
        cout<<"\n\n\n\t\t\tPress Any Key To Go Main Menu"<<endl;
        getch();
        managerManu();
}

void managerManu() //Manager Menu Display
{
    system("color 9F");
    system("cls");
    cout<<"\n\n\t\t\t\t   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ "; //Animation
    Sleep(80);
    cout<<"\n\t\t\t\t         $$$$$$$$$$$$$$$$$$$$$$$$$$$$       "<<endl;
    Sleep(80);
    cout<<"\t\t\t\t\t  $ United";
    Sleep(200);
    cout<<" Motors";
    Sleep(200);
    cout<<" PVT";
    Sleep(200);
    cout<<" LTD $";
    Sleep(200);
    cout<<"\n\t\t\t\t\t\t  Main Menu ";
    Sleep(200);
    cout<<"\n\t\t\t\t         $$$$$$$$$$$$$$$$$$$$$$$$$$$$       "<<endl;
    Sleep(80);
    cout<<"\t\t\t\t   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ "<<endl;
    Sleep(80);
    system("color 90");
    Vehicle V1; //Vehicle Class Object
    int VCategory , VNo , VType , VPrice , choice;
    cout<<"\n\t\t1. Add Vehicles"<<endl; //Menu For Manager
    cout<<"\t\t2. Delete Vehicles"<<endl;
    cout<<"\t\t3. View Vehicles"<<endl;
    cout<<"\t\t4. View Cashier Details"<<endl;
    cout<<"\t\t5. Exit"<<endl;
    cout<<"\t\t Enter Your Choice : ";
    cin>>choice; //Get User Input
    if(choice==1) //Check User Input
    {
        cout<<"\n\n\t\tEnter Vehicle Number : ";
        cin>>VNo;

        cout<<"\t\t1. Car"<<endl; //Menu
        cout<<"\t\t2. Jeep"<<endl;
        cout<<"\t\t3. Van"<<endl;
        cout<<"\t\t4. Electronic"<<endl;
        cout<<"\n\t\t Enter Vehicle Category : ";
        cin>>VCategory;
        if(VCategory==1)
        {
            cout<<"\t\t1. Benz"<<endl;
            cout<<"\t\t2. Lamborghini"<<endl;
            cout<<"\t\t3. BMW"<<endl;
            cout<<"\n\t\t Enter Vehicle Type : ";
            cin>>VType;

            cout<<"\n\t\t Enter Vehicle Price : ";
            cin>>VPrice;
            V1.Addvehicle(VNo , VCategory , VType , VPrice);
        }
        else if(VCategory==2)
        {
            cout<<"\t\t1. Toyota"<<endl;
            cout<<"\t\t2. Range Rower"<<endl;
            cout<<"\t\t3. Jeep"<<endl;
            cout<<"\n\t\t Enter Vehicle Type : ";
            cin>>VType;

            cout<<"\n\t\t Enter Vehicle Price : ";
            cin>>VPrice;
            V1.Addvehicle(VNo , VCategory , VType , VPrice);
        }
        else if(VCategory==3)
        {
            cout<<"\t\t1. Toyota"<<endl;
            cout<<"\t\t2. Nisan"<<endl;
            cout<<"\t\t3. Benz"<<endl;
            cout<<"\n\t\t Enter Vehicle Type : ";
            cin>>VType;

            cout<<"\n\t\t Enter Vehicle Price : ";
            cin>>VPrice;
            V1.Addvehicle(VNo , VCategory , VType , VPrice);
        }
        else if(VCategory==4)
        {
            cout<<"\t\t1. Nisan"<<endl;
            cout<<"\t\t2. Benz"<<endl;
            cout<<"\t\t3. Tesla"<<endl;
            cout<<"\n\t\t Enter Vehicle Type : ";
            cin>>VType;

            cout<<"\n\t\t Enter Vehicle Price : ";
            cin>>VPrice;
            V1.Addvehicle(VNo , VCategory , VType , VPrice);
        }
        else
        {
            system("color 94");
            cout<<"\n\t\tWrong Category Try Again"<<endl;
            system("color 90");
            managerManu();
        }
    }
    else if(choice==2)
    {
        system("cls");
        cout<<"\t\t1. Car"<<endl;
        cout<<"\t\t2. Jeep"<<endl;
        cout<<"\t\t3. Van"<<endl;
        cout<<"\t\t4. Electronic"<<endl;
        cout<<"\n\t\t Enter Vehicle Category : ";
        cin>>VCategory;

        V1.DeleVehicle(VCategory);
    }
    else if(choice==3)
    {
        system("cls");
        cout<<"\t\t1. Car"<<endl;
        cout<<"\t\t2. Jeep"<<endl;
        cout<<"\t\t3. Van"<<endl;
        cout<<"\t\t4. Electronic"<<endl;
        cout<<"\n\t\t Enter Vehicle Category : ";
        cin>>VCategory;

        V1.getdata(VCategory);
        managerManu();
    }
    else if(choice==4)
    {
        system("cls");
        V1.Cashier();
        managerManu();
    }
    else if(choice==5)
    {
        cout<<"Exiting Program"<<endl; //Exit Massage
        exit(0); //Kill The Program
    }
    else
    {
        system("color 94");
        cout<<"\n\t\tWrong Category Try Again"<<endl;
        system("color 90");
        Sleep(1800);
        managerManu();
    }
}

void CashierMenu()
{
    system("color 9F");
    system("cls");
    cout<<"\n\n\t\t\t\t   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ "; //Animation
    Sleep(80);
    cout<<"\n\t\t\t\t         $$$$$$$$$$$$$$$$$$$$$$$$$$$$       "<<endl;
    Sleep(80);
    cout<<"\t\t\t\t\t  $ United";
    Sleep(200);
    cout<<" Motors";
    Sleep(200);
    cout<<" PVT";
    Sleep(200);
    cout<<" LTD $";
    Sleep(200);
    cout<<"\n\t\t\t\t\t\t  Main Menu ";
    Sleep(200);
    cout<<"\n\t\t\t\t         $$$$$$$$$$$$$$$$$$$$$$$$$$$$       "<<endl;
    Sleep(80);
    cout<<"\t\t\t\t   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ "<<endl;
    Sleep(80);
    system("color 90");
    Vehicle V1;
    int Category , type , nov , choice;
    string name , tp , nic;
    double Vcategory , Vtype , Vnov;

    Bill B1; //Object of Bill class
    cout<<"\n\t\t1. Make a Bill For Purchase"<<endl;
    cout<<"\t\t2. View Bill Details"<<endl;
    cout<<"\t\t3. View Vehicle Details"<<endl;
    cout<<"\t\t4. Generate Bill"<<endl;
    cout<<"\t\t5. Exit"<<endl;
    cout<<"\t\t\n Enter Your Choice : ";
    cin>>choice;

    switch(choice) //Switch case For Check inputs
    {
    case 1:
        system("cls");
        cout<<"\n\n\t\t $$$$$$$$$$ Bill Details $$$$$$$$$$"<<endl;
        cout<<"\n\n\t Enter Customer Name : ";
        cin>>name;
        cout<<"\t Enter TelePhone Number : ";
        cin>>tp;
        cout<<"\t Enter Customer NIC Number : ";
        cin>>nic;
        cout<<"\t Enter Vehicle Category : ";
        cin>>Vcategory;
        cout<<"\t Enter Vehicle Type : ";
        cin>>Vtype;
        cout<<"\t Enter Number Of Vehicles : ";
        cin>>Vnov;

        V1.setcashierData(name,nic,tp,Vcategory,Vnov); //Function Calling
        V1.Cashier(); //Function Calling
        break;

    case 2:
        system("cls");
        V1.Displaycashier();
        CashierMenu();
        break;

    case 3:
        system("cls");
        cout<<"\n\n\t 1. Car"<<endl;
        cout<<"\t 2. Jeep "<<endl;
        cout<<"\t 3. Van "<<endl;
        cout<<"\t 4. Electronic "<<endl;
        cout<<"\n\n\t Enter Vehicle Category : ";
        cin>>Category;

        V1.getdata(Category);
        CashierMenu();
        break;

    case 4:
        system("cls");
        cout<<"\n\n\t 1. Car"<<endl;
        cout<<"\t 2. Jeep "<<endl;
        cout<<"\t 3. Van "<<endl;
        cout<<"\t 4. Electronic "<<endl;
        cout<<"\n\n\t Enter Vehicle Category : ";
        cin>>Category;
        if(Category==1)
        {
            cout<<"\n\n\t 1. Benz "<<endl;
            cout<<"\t 2. Lamborghini "<<endl;
            cout<<"\t 3. BMW "<<endl;

            cout<<"\n\n\t Enter Vehicle Type : ";
            cin>>type;
            cout<<"\n\t Enter Number Of Vehicles : ";
            cin>>nov;
            B1.setnoofvehicle(nov);
            B1.Billprocess(Category , type);
        }
        else if(Category==2)
        {
            cout<<"\n\n\t 1. Toyota "<<endl;
            cout<<"\t 2. Range Rower "<<endl;
            cout<<"\t 3. JEEP "<<endl;

            cout<<"\n\n\t Enter Vehicle Type : ";
            cin>>type;
            cout<<"\n\t Enter Number Of Vehicles : ";
            cin>>nov;
            B1.setnoofvehicle(nov);
            B1.Billprocess(Category , type);
        }
        else if(Category==3)
        {
            cout<<"\n\n\t 1. Toyota "<<endl;
            cout<<"\t 2. Nisan "<<endl;
            cout<<"\t 3. Benz "<<endl;

            cout<<"\n\n\t Enter Vehicle Type : ";
            cin>>type;
            cout<<"\n\t Enter Number Of Vehicles : ";
            cin>>nov;
            B1.setnoofvehicle(nov);
            B1.Billprocess(Category , type);
        }
        else if(Category==4)
        {
            cout<<"\n\n\t 1. Nisan "<<endl;
            cout<<"\t 2. Benz "<<endl;
            cout<<"\t 3. Tesla "<<endl;

            cout<<"\n\n\t Enter Vehicle Type : ";
            cin>>type;
            cout<<"\n\t Enter Number Of Vehicles : ";
            cin>>nov;
            B1.setnoofvehicle(nov);
            B1.Billprocess(Category , type);
        }
        else
        {
            system("color 94");
            cout<<"Invalid Type Try Again"<<endl;
            system("color 90");
            CashierMenu();
        }
        break;

    case 5:
            cout<<"Exiting Program"<<endl;
            exit(0);
            break;

    default:
        system("color 94");
        cout<<"Invalid Category Try Again"<<endl;
        system("color 90");
        Sleep(1800);
        CashierMenu();
    }
}

void Vehicle :: setcashierData(string N , string nic , string Tp , int VC , int NOV )
{
    Name = N;
    NIC = nic;
    TP_NO = Tp;
    Vehicle_category = VC;
    Noofvehicles = NOV;
}

int main()
{
    system("color 9F");
    Manager M1; //Object Creation
    Cashier Cas;
    int Utype , num;
    string Username , Password;
    cout<<"\n\n\t\t\t\t   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ "; //Animation
    Sleep(80);
    cout<<"\n\t\t\t\t         $$$$$$$$$$$$$$$$$$$$$$$$$$$$       "<<endl;
    Sleep(80);
    cout<<"\t\t\t\t\t  $ United";
    Sleep(200);
    cout<<" Motors";
    Sleep(200);
    cout<<" PVT";
    Sleep(200);
    cout<<" LTD $";
    Sleep(200);
    cout<<"\n\t\t\t\t         $$$$$$$$$$$$$$$$$$$$$$$$$$$$       "<<endl;
    Sleep(80);
    cout<<"\t\t\t\t   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ "<<endl;
    Sleep(80);
    system("color 94");
    cout<<"\n\n\n\n\n\t\t\t\t Loading......"<<endl;
    cout<<"\t\t\t\t";
    char b=219; //ASCII Code (Symble)
    for(int x=0;x<50;x++) //Loading Screen Animation
    {
        cout<<b; //Print Symble
        Sleep(30); //Waiting Time (freezing Time)
    }
    cout<<"\n\t\t\t\tLoading Completed!"<<endl;
    Sleep(1000);
    system("color 90");
    do
    {
        system("cls");
        cout<<"\n\n\t\t\t $$$$$ Welcome To United Moters PVT LTD $$$$$"<<endl;
        cout<<"\n\n\t 1. Manager "<<endl;
        cout<<"\t 2. Cashier "<<endl;
        cout<<"\n\n\t Enter Your Designation : "; //Check User Job Role
        cin>>Utype;

        switch(Utype)
        {
        case 1:
            cout<<"\n\t\t Enter UserName : ";
            cin>>Username;
            cout<<"\n\t\t Enter Password : ";
            cin>>Password;
            num=M1.login(Username , Password); //get Returned Value
            break;
        case 2:
            cout<<"\n\t\t Enter UserName : ";
            cin>>Username;
            cout<<"\n\t\t Enter Password : ";
            cin>>Password;
            num=Cas.login(Username,Password); //get Returned Value
            break;
        default:
            system("color 94");
            cout<<"\n\n\t\t\t $$$$$$$$$$ Invalid Designation Type $$$$$$$$$$"<<endl; //Error Massage
            system("color 90");
            exit(0);
        }
    }
    while(num==0); //Check Returned Value and Keep Running Loop
    return 0;
}
