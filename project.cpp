//Project is designed using OBJECT ORIENTED PROGRAMMING LANGUAGE C++
#include<iostream>
#include <conio.h>//Used because it contains getch() function which is used in password code.
#include <windows.h>//Used because it contains beep function to create sounds of different frequencies.
#include<math.h>//Used because it contains mathematical functions
float pi = 3.14159265359;
using namespace std;
//This is the class of Fiberoptics which contains various member functions which will perform various parameters operatons as per user choice.
class Fiberoptics{
    float n1,n2;
    public:
    void get(){
        system("color 0A");
        a:
        cout<<"\nEnter value of refrective index of core:";
        cin>>n1;
        if(n1<=0||!cin){
            fflush(stdin);
            cin.clear();
            Beep(300,500);
            cout<<"\nWrong input!";
            goto a;}
        lnew:
        cout<<"\nEnter value of refractive index of cladding:";
        cin>>n2;
        if(n2<=0||!cin){
            fflush(stdin);
            cin.clear();
            Beep(300,500);
            cout<<"\nWrong input!";
            goto lnew;}
        if(n1<n2){
            cout<<"\nWrong inputs- TIR not possible for this case as n1<n2.";
            goto a;
        }
    }

     //To calculate numerical aperture , i.e.; light gathering capacity of fiber.
    void NA(){
        system("color 2F");
        cout<<"\nLet the outside ambient medium be air";
        float na=sqrt(n1*n1-n2*n2);
        cout<<"\nThe numerical aperture of the given fiber is :"<<na;
    }
    //To calculate relative refractive index and percentage relative refractive index of fiber. 
    void RRI(){
            system("color FD");
            float rr=(n1-n2)/n1;
            cout<<"\nThe relative refractive index of the given medium is:"<<rr;
            cout<<"\nThe percentage relative refractive index of the given fiber is:"<<rr*100<<"%";
    }
//To calculate the angle of acceptance of an optical fiber cable
    void AA(){
        system("color 4F");
        if((n1*n1-n2*n2)>1){
            cout<<"\nThis configuration is not possible";
            fflush(stdin);
            getchar();
            get();
        }
        cout<<"\nLet the outside ambient medium be air";
        float a=asin(sqrt(n1*n1-n2*n2));
        cout<<"\nThe acceptance of given fiber is "<<a*180/pi<<" degrees";
    }
    //To calculate the V number and possible number of modes of optical fiber.
    void VM(){
        system("color 02");
        cout<<"\nLet the outside ambient medium be air and the given fiber is step index fiber";
        float d,w;
        label:
        cout<<"\nEnter diameter of fiber and wavelength of incident light in same units:";
        cin>>d>>w;
        if(d<=0||w<=0||!cin){
            fflush(stdin);
            cin.clear();
            Beep(300,500);
            cout<<"\nWrong input!";
            goto label;}
        float v=(pi*d*sqrt(n1*n1-n2*n2))/w;
        cout<<"\nThe V number of the given fiber is:"<<v;
        if(v>2.405)
            cout<<"\nAs V number is greater than 2.405 so, the given fiber is multimode fiber";
        else
            cout<<"\nAs V number is <= 2.405 so, the given fiber is stepindex fiber";
        cout<<"\nNumber of modes possible by the given fiber is:"<<floor(v*v/2);
    }
    //To calculate the attenuation losses (attenuation coeficient in dB/Km)
    void ACa(){
    system("color D");
    float po,pi,l;
    float a;
    cout<<"\nFor Attenuation Coefficient"<<endl;
    q:
    cout<<"\nEnter the output power(in W):";
    cin>>po;
    if(po<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto q;
    }
    g:
    cout<<"\nEnter the input power(in W):";
    cin>>pi;
    if(pi<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto g;
    }
    if(pi<po){
        Beep(300,500);
        cout<<"\nWrong input!";
        goto q;
    }
    dis:
    cout<<"\nEnter the distance(in km) between which the energy loss is observed:";
    cin>>l;
    if(l<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto dis;
    }
    float k=po/pi;
    a=-(10/l)*(log10(k));
    cout<<"\nThe attenuation coefficient of fiber (in dB/km) is: "<<a<<"dB/km";
}
//To calculate the output power of an optical fiber after reduction of losses in inputted power in optical fiber
void ACpo(){
    system("Color E4");
    float po,pi,l;
    float a;
    cout<<"\nFor Output Power:-"<<endl;
    lab:
    cout<<"\nEnter the value of attenuation coefficient (dB/km):";
    cin>>a;
    if(a<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto lab;
    }
    label:
    cout<<"\nEnter the input power(in W):";
    cin>>pi;
    if(pi<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto label;
    }
    Dis:
    cout<<"\nEnter the distance(in km) between which the energy loss is observed:";
    cin>>l;
    if(l<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto Dis;
    }
    float k=-(a*l)/10;
    float x=pow(10,k);
    po=pi*x;
    cout<<"\nThe output power here is: "<<po<<" W";
}
//To calculate the inputted  power of an optical fiber if attenuation losses and output power is known to us.
void ACpi(){
    system("Color 6");
    float po,pi,l;
    float a;
    cout<<"\nFor Input Power:-"<<endl;
    labelnew:
    cout<<"\nEnter the value of attenuation (dB/km):";
    cin>>a;
    if(a<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto labelnew;
    }
    labpo:
    cout<<"\nEnter the output power(in W):";
    cin>>po;
    if(po<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto labpo;
    }
     j:
    cout<<"\nEnter the distance(in km) between which the energy loss is observed:";
    cin>>l;
    if(l<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto j;
    }
    float k=-(a*l)/10;
    float x=pow(10,k);
    pi=po/x;
    cout<<"\nThe input power here is: "<<pi<<" W";
}
//To calculate the length of optical fiber if output , input power and attenuation losses are known to us.
void ACl(){
    system("Color 5");
    float po,pi,l;
    float a;
    cout<<"\nFor Length of Fiber"<<endl;
    newl:
    cout<<"\nEnter the output power(in W):";
    cin>>po;
    if(po<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto newl;
    }
    nl:
    cout<<"\nEnter the input power(in W):";
    cin>>pi;
    if(pi<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto nl;
    }
    all:
    cout<<"\nEnter the attenuation coefficient(in dB/km):";
    cin>>a;
    if(a<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto all;
    }
    float k=po/pi;
    l=-(10/a)*(log10(k));
    cout<<"\nThe length of fiber is: "<<l<<"km";
}
//To calculate the numerical aperture of graded index fiber.
void GRIN(){
    system("Color 9");
    float a,r;
    l1:
    cout<<"\nEnter the value of core radius:";
    cin>>a;
    if(a<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto l1;
    }
    l2:
    cout<<"\nEnter the value of position across core:";
    cin>>r;
    if(r>2*a||r<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto l2;
    }
    float rr=(n1-n2)/n1;
    //cout<<"\nIn the graded index fiber , the nuerical aperture is a function of position across the core(r)";
    if(r<a){
        float var=r/a;
        if((2*rr*pow(var,2)>1)){
        Beep(300,500);
        cout<<"\nWrong inputs!";
        goto l1;
        }
        float g1=n1*sqrt(1-2*rr*pow(var,2));
        cout<<"\nThe numerical aperture of the graded index fibre will be: "<<g1<<endl;
    }
    else{
        if((2*rr)>1){
        Beep(300,500);
        cout<<"\nWrong inputs!";
        goto l1;
        }
    float g=n1*sqrt(1-2*rr);
    cout<<"\nThe numerical aperture of the graded index fibre will be: "<<g<<endl;}
}
//To calculate the critical radius of a given optical fiber cable on particular operating wavelength.
void CR(){
    system("Color B");
    int mode;
    float critical_radius,g,l,lc,d;
    l3:
    cout<<"Enter the value for diameter index of core in centi-meters:"<<endl;
    cin>>d;//d:diameter of core
    if(d<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto l3;
    }
    l4:
    cout<<"\nEnter the value for operating wavelength:"<<endl;
    cin>>l;
    if(l<0||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto l4;
    }
    cho:
    cout<<"\nEnter 0 for single-mode optical fibre and 1 for multi-mode optical fiber"<<endl;
    cin>>mode;
    if((mode!=0&&mode!=1)||!cin){
        cin.clear();
        fflush(stdin);
        Beep(300,500);
        cout<<"\nWrong input!";
        goto cho;
    }
    if(mode==1){
    g=pow(n1,2)-pow(n2,2);
    critical_radius=(3*pow(n1,2)*l)/(4*3.14*pow(g,1.5));//----------->l:operating wavelength
    cout<<"\ncritical radius of your multimode fiber is:"<<critical_radius<<" "<<"centi-meters"<<endl;
}
else{
    g=pow(n1,2)-pow(n2,2);
    lc=3.14*d*pow(g,0.5)/2.405;//lc:cut-off wavelength
    critical_radius=((20*l)/g)*pow((((2.748)*lc-0.996*g)/lc),-3);
    cout<<"critical radius of your singlemode fiber is:"<<critical_radius<<" "<<"centi-meters"<<endl;
}
}
//To explain various applications of optical fiber.
void application(){
    system("Color 5");
    cout<<"\nApplications of optical fibers are as follows:"<<endl;
    cout<<"1."<< " "<<"Optical Fibres uses in Medical industry:"<<endl;
    cout<<"Because of the extremely thin and flexible nature,it used in various instruments to view internal body parts by inserting into hollow spaces in the body."; 
    cout<<"It is used as lasers during surgeries, endoscopy, microscopy and biomedical research."<<endl;
    cout<<"2."<< " "<<"Optical Fibres used in Communication:"<<endl;
    cout<<"In the communication system, telecommunication has major uses of optical fibre cables for transmitting and receiving purposes.";
    cout<<"It is used in various networking fields and even increases the speed and accuracy of the transmission data.";
    cout<<"Compared to copper wires, fibre optics cables are lighter, more flexible and carry more data."<<endl;
    cout<<"3."<< " "<<"Optical Fibres used in Defense Purpose:"<<endl;
    cout<<"Fibre optics are used for data transmission in high-level data security fields of military and aerospace applications." ;
    cout<<" These are used in wirings in aircraft, hydrophones for SONARs and Seismics applications."<<endl;
    cout<<"4."<< " "<<"Uses of Optical Fibre for Lightening and Decorations:"<<endl;
    cout<<"they give an attractive, economical and easy way to illuminate the area and ";
    cout<<"that is why it is widely used in decorations and Christmas trees."<<endl;
    cout<<"5."<< " "<<"Optical Fibres used in Mechanical Inspections:"<<endl;
    cout<<"On-site inspection engineers use optical fibres to detect damages and faults which are at hard to reach places.";
    cout<<"Even plumbers use optical fibres for inspection of pipes."<<endl;
}
};
//This is the driver code , which controls the complete flow of program .
int main(){
    system("color 4");  
char mypassword[]="n123";
 START:
    system("cls");
    cout<<"\nEnter Password  : ";
    char pass[32];//to store password.
    int i = 0;
    char a;
    for(i=0;;)
    {
        a=getch();
        if((a>='a'&&a<='z')||(a>='A'&&a<='Z')||(a>='0'&&a<='9'))
            //check if a is numeric or alphabet
        {
            pass[i]=a;
            ++i;
            cout<<"*";
        }
        if(a=='\b'&&i>=1)//if user typed backspace
            //i should be greater than 1.
        {
            cout<<"\b \b";//rub the character behind the cursor.
            --i;
        }
        if(a=='\r')//if enter is pressed
        {
            pass[i]='\0';
            break;
        }
    }
    fflush(stdin);
     if(strlen(pass)==strlen(mypassword))
     {
        int len=strlen(pass);
        int i=0;
        while(len){
            if(pass[i]==mypassword[i])
            {
                i++;
            }
            else{
                Beep(300,500);
                cout<<"\nWRONG PASSWORD!";
                cout<<"\nPress enter to try again";
                getchar();
                goto START;
            }
            len--;
        }
    }
    else{
        Beep(300,500);
        cout<<"\nWRONG PASSWORD!";
        cout<<"\nPress enter to try again";
        getchar();
        goto START;
    }

Fiberoptics F;
int x;
int choice;
while(true)
{
system("cls");
system("color 9F");
cout<<"\n\n\n\n\n1:For Fiberoptics calculation\n2:Exit\nEnter choice:";
cin>>x;
if(!cin){
            fflush(stdin);
            cin.clear();
            Beep(300,500);
            cout<<"\nWrong input! Press enter to choose again";
            getchar();
            continue;
            }
cout<<"\n__________________________________________________________________________________________________________________\n";
switch(x){
    case 1:
        system("color 3F");
        label2:
        cout<<"\n\n1:For Numerical Aperture \n2: For Relative refractive index:\n3:For acceptance angle \n4:For V number and Number of modes \n5:For Attenuation Coefficient \n6:For Output Power\n7:For Input Power\n8:For Length of Fiber\n9:For Numerical Aperture of graded index fiber\n10:For Critical radius\n11:To know verious applications of optical fiber\nEnter choice:";
        cin>>choice;
        if(!cin){
            fflush(stdin);
            cin.clear();
            Beep(300,500);
            cout<<"\nWrong input!";
            goto label2;
            }
        switch(choice){
            case 1:
                F.get();
                F.NA();
                break;
            case 2:
                F.get();
                F.RRI();
               break;
            case 3:
                F.get();
                F.AA();
                break;
            case 4:
                F.get();
                F.VM();
                break;
            case 5:
                F.ACa();
                break;
            case 6:
                F.ACpo();
                break;
            case 7:
                F.ACpi();
                break;
            case 8:
                F.ACl();
                break;
            case 9:
                F.get();
                F.GRIN();
                break;
            case 10:
                F.get();
                F.CR();
                break;
            case 11:
                F.application();
                break;
            default:
                Beep(300,500);
                cout<<"\nwrong input";
                goto label2;
                break; 
        }
        break;
    case 2:
        break;
    default:
        Beep(300,500);
        cout<<"\nwrong input!\nPress enter to try again";
        break;
}
if(x==2){
    system("cls");
    system("color F");
    cout<<"*************************Program exit successfully**************************";
    cout<<"\n__________________________________________________________________________________________________________________\n";
    break;}
    fflush(stdin);
    getchar();
}
return 0;
}
//Respected sir , we have designed this project with great dedication.
//Hoping your positive response.