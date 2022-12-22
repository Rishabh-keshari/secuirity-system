#include<iostream>
#include<fstream> //for file handling
#include<sstream> //for interoperation b/w string buffer and string operation
#include<string>

using namespace std;
int main()
{
    int a, i=0;
    string text,old,password1,password2,pass,name,password0,age,user,word,word1;
    string creds[2],cp[2];
    cout<<"                     ________________Project_____________________________                    "<<endl;
    cout<<"                     Dr. Ambedkar Institute of Technology For Handicapped                    "<<endl;
    cout<<"                                  Security System                                            "<<endl;

    cout<<"                          ___________________________________                                "<<endl;
    cout<<"                         |         press 1.Register          |                               "<<endl;
    cout<<"                         |         press 2.Login             |                               "<<endl;
    cout<<"                         |         press 3.Change Password   |                               "<<endl;
    cout<<"                         |         press 4.End Program       |                               "<<endl;
    cout<<"                         |___________________________________|                               "<<endl;
    do
    {
        cout<<endl<<endl;
        cout<<"Enter your choice:";
        cin>>a;
        switch(a)
        {
            case 1:
            {
                cout<<" ____________________________________"<<endl;
                cout<<"|----------------Register------------|"<<endl;
                cout<<"|____________________________________|"<<endl;
                cout<<"Enetr your username:";
                cin>>name;
                cout<<"Enetr your password:";
                cin>>password0;
                cout<<"Enetr your Age:";
                cin>>age;

                ofstream of1;
                of1.open("file.txt");
                if(of1.is_open())
                {
                    of1<<name<<"/n";
                    of1<<password0;
                    cout<<"Registration successfull"<<endl;
                }
                break;
            }
            case 2:
            {
                i=0;
            
                cout<<" _______________________________"<<endl;
                cout<<"|------------Login--------------|"<<endl;
                cout<<"|_______________________________|"<<endl<<endl;

                ifstream of2;
                of2.open("file.txt");
                cout<<"Please enter the username:";
                cin>>user;
                cout<<"Please enter the password:";
                cin>>pass;
                if (of2.is_open())
                {
                    while(!of2.eof())
                    {
                       while(getline(of2, text))
                       {
                         istringstream iss(text);
                         iss>>word;
                         creds[i]=word;
                         i++;
                       }
            
                       if(user==creds[0] && pass==creds[1])
                       {
                          cout<<"__Login successfull";
                          cout<<endl<<endl;
            
                          cout<<" Details: "<<endl;
            
                          cout<<" Username: "<<name<<endl;
                          cout<<" password: "<<pass<<endl;
                          cout<<" Age:      "<<age<<endl;
                       }
                       else
                       {
                         cout<<endl<<endl;
                         cout<<" Incorrect Credentials"<<endl;
                         cout<<"|  1.Press 2 to Login           |"<<endl;
                         cout<<"|  2.Press 3 to change password |"<<endl;
                         break;
                       }
                    }
                }
                break;
            }
            case 3:
            {
                i=0;
                cout<<"  _____________________________"<<endl;
                cout<<" |---------Change Password-----|"<<endl;
                cout<<" |_____________________________|"<<endl<<endl;

                ifstream of0;
                of0.open("file.txt");
                cout<<"Enter the old Password: ";
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
                            if(of1.is_open())
                            {
                                cout<<"Enter your new password:";
                                cin>>password1;
                                cout<<"Enetr your password again:";
                                cin>>password2;
            
                                if(password1==password2)
                                {
                                    of1<<cp[0]<<"/n";
                                    of1<<password1;
                                    cout<<"Password changed successfully"<<endl;
                                }
                                else
                                {
                                    of1<<cp[0]<<"/n";
                                    of1<<old;
                                    cout<<"Password do not match"<<endl;
                                }
                            }
                        }
                        else
                        {
                            cout<<"Please enter a valid password"<<endl;
                            break;
                        }
                    }
                }
                break;
            }
            
            default:
            {
                cout<<"Enter a valid choice";
            }
            
        }
        cout<<"________Thank You________";
    }while(a!=4);
    return 0;
}