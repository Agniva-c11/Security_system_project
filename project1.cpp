// #include<iostream>
// #include<fstream>   //Used for reading and writing on the file system
// #include<sstream>  //it provides templates that enable inter-operation between strings
// #include<string>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a, i = 0;
    string text, old, password1, password2, pass, name, password0, age, user, word, word1;
    string credentials[2], cp[2];


    cout<<"           Security System"<<endl;

    cout<<"___________________________________________"<<endl<<endl;
    cout<<"|              1. Register                |"<<endl;
    cout<<"|              2. Login                   |"<<endl;
    cout<<"|              3. Change Password         |"<<endl;
    cout<<"|______________4. End Program_____________|"<<endl<<endl;

    do{
        cout<<endl<<endl;
        cout<<"Enter Your Choice:-";
        cin>>a;
        switch(a)
        {
            case 1:
            {
                cout<<"____________________________________________"<<endl<<endl;
                cout<<"|-----------------Register-----------------|"<<endl;
                cout<<"|__________________________________________|"<<endl<<endl;
                cout<<"Enter Username:-";
                cin>>name;
                cout<<"Enter Password:-";
                cin>>password0;
                // cout<<"Enter Age:-";
                // cin>>age;

                ofstream of1;   //created an object to write the inputs into the file
                of1.open("file.txt");
                if(of1.is_open())
                {
                    of1<<name<<"\n";
                    of1<<password0<<"\n";
                    cout<<"Registration Successfull"<<endl;
                }

                

                break;
            }
            case 2:
            {
                i=0;

                cout<<"________________________________________"<<endl<<endl;
                cout<<"|-----------------Login-----------------"<<endl;
                cout<<"|______________________________________|"<<endl<<endl;

                ifstream of2;
                of2.open("file.txt");
                cout<<"Enter Username:-";
                cin>>user;
                cout<<"Enter Password:-";
                cin>>pass;

                if(of2.is_open())
                {
                    while(!of2.eof())   //Using this eof() function, we can detect when the end of file is reached.
                    {
                        while(getline(of2, text))   //it is used to read the file line by line
                        {
                            istringstream iss(text);    //istringstream object is used to stream the string and store it in the extraction operator
                            iss>>word;
                            credentials[i]=word;
                            i++;
                        }
                        if(user==credentials[0] && pass==credentials[1])
                        {
                            cout<<"---Logged in---";

                            cout<<endl<<endl;

                            cout<<"Details: "<<endl;

                            cout<<"Username: " + name<<endl;
                            cout<<"Password: " + pass<<endl;
                            // cout<<"Age: "+ age<<endl;
                        }
                        else
                        {
                            cout<<endl<<endl;
                            cout<<"Incorrect Credentials"<<endl;
                            cout<<"|      1.Press 2 to login           |"<<endl;
                            cout<<"|      2.Press 3 to Change Password |"<<endl;
                            break;
                        }    
                    }    
                } 
                break;   
            }
            case 3:
            {
                i=0;

                cout<<"------------------Change Password------------------"<<endl;
                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter old password:-";
                cin>>old;
                if(of0.is_open())
                {
                    while(!of0.eof())
                    {
                        while(getline(of0, text))
                        {
                            istringstream iss(text);
                            iss>>word1;
                            cp[i]=word1;
                            i++;
                        }
                        if(old==cp[1])
                        {
                            of0.close();


                            ofstream of1;
                            of1.open("file.txt");
                            if(of1.is_open())
                            {
                                cout<<"Enter New Password:-";
                                cin>>password1;
                                cout<<"Confirm Password:-";
                                cin>>password2;

                                if(password1==password2)
                                {
                                    of1<<cp[0]<<"\n";
                                    of1<<password1;
                                    cout<<"Password changes successfully"<<endl;
                                }
                                else
                                {
                                    of1<<cp[0]<<"\n";
                                    of1<<old;
                                    cout<<"Password not matched"<<endl;
                                }
                            }
                        }
                        else{
                            cout<<"PLease enter a valid password"<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                cout<<"______________________Thank You!_______________________";
                break;
            }
            default:
            cout<<"Enter a valid choice";

        }
    }
    while(a!=4);
    return 0;
    
}                