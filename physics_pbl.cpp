#include <iostream>
#include <cmath>
#include<dos.h>
#include<windows.h>

using namespace std;
/*         ------------------------------------------
                    BASE CLASS - INCIDENCE
           ------------------------------------------
*/
float pi = 3.1415;
int c; // CHOICE
int flag = 1;

class incidence
{
public:
    float b;      // BETA
    float u1, u2; // MAGNETIC PERMEABLITY
    float n1, n2; // REEFRACTIVE INDEX
    float Q1, Q2; // ANGLE OF INCIDENCE & REFRACTION
    float r, t;   // COOFICIENTS OF R & T
    float R, T;   // REFLECTANCE & TRANSMITTANCE
    void set_n()
    {
        cout << "Enter the values of the refractive indexes n1 and n2 " << endl;
        cin >> n1 >> n2;
    }
    void set_u()
    {
        cout << "Enter the value of magnetic permeablity of both the medium" << endl;
        cin >> u1 >> u2;
    }
    void set_Q()
    {
        cout << "Enter the angle of incidence in degrees" << endl;
        cin >> Q1;
        int x = asin((n1 / n2) * (sin(Q1)));
        Q2 = (x * 180) / pi;
    }
};
/*             ----------------------------------------
                           NORMALLY INCIDENCE
               ----------------------------------------
*/
class normal : public incidence // PUBLICALLY INHERITED //
{
public:
    normal()
    {
        set_n();
        set_u();
    }
    void result()
    {
        b = (u1 * n2) / (u2 * n1);
        R = pow((1 - b) / (1 + b), 2);
        T = (n2 / n1) * pow((2 / (1 + b)), 2);
        cout << "\n\tReflectance(R) = " << R << endl;
        cout << "\n\tTransmittance(T) = " << T << endl;
    }
};
/*              -----------------------------------------
                    ELECTRIC FIELD PARALLEL TO P.O.I
                          P - POLARIZATION
                -----------------------------------------
*/
class oblique_p : public incidence // PUBLICALLY INHERITED //
{
public:
    oblique_p()
    {
        set_n();
        set_Q();
    }
    void result()
    {
        r = ((n1 * cos(Q2)) - (n2 * cos(Q1))) / ((n1 * cos(Q2)) + (n2 * cos(Q1)));
        t = (2 * n1 * cos(Q1)) / ((n1 * cos(Q2)) + (n2 * cos(Q1)));
        R = pow(r, 2);
        T = ((n2 * cos(Q2)) / (n1 * cos(Q1))) * (pow(t, 2));
        cout << "\n\tReflectance (R) = " << R << endl;
        cout << "\n\tTransmittance (T) = " << T << endl;
    }
};
/*              ---------------------------------------------
                    ELECTRIC FIELD PERPENDICULAR TO P.O.I
                            S - POLARIZATION
                ---------------------------------------------
*/
class oblique_s : public incidence // PUBLICALLY INHERITED //
{
public:
    oblique_s()
    {
        set_n();
        set_Q();
    }
    void result()
    {
        r = ((n1 * cos(Q1)) - (n2 * cos(Q2))) / ((n1 * cos(Q1)) + (n2 * cos(Q2)));
        t = (2 * n1 * cos(Q1)) / ((n1 * cos(Q1)) + (n2 * cos(Q2)));
        R = pow(r, 2);
        T = ((n2 * cos(Q2)) / (n1 * cos(Q1))) * (pow(t, 2));
        cout << "\n\tReflectance (R) = " << R << endl;
        cout << "\n\tTransmittance (T) = " << T << endl;
    }
};
/*           ------------------------------
                FINDING MAGNETIC FIELD
             ------------------------------
*/
class magnetic
{
public:
    float e;
    float v;
    float b;
    magnetic()
    {
        cout << "Enter the magnitude of electric field " << endl;
        cin >> e;
        cout << "Enter the velocity of the wave in medium" << endl;
        cin >> v;
    }
    void result()
    {
        b = e / b;
        cout << "\n\tThe magnitude of magnetic field is : " << b << endl;
    }
};
/*           ------------------------------
                FINDING ELECTRIC FIELD
             ------------------------------
*/
class electric
{
public:
    float e;
    float v;
    float b;
    electric()
    {
        cout << "Enter the magnitude of magnetic field " << endl;
        cin >> b;
        cout << "Enter the velocity of the wave in medium" << endl;
        cin >> v;
    }
    void result()
    {
        e = b * v;
        cout << "\n\tThe magnitude of electric field is : " << e << endl;
    }
};

void menu()
{

    string str = "PHYSICS PBL";
    string str2="Electro Magnetic Wave";
    cout << "\n\n\n\t\t\t---------------------------------------" << endl;
    cout << "\t\t\t\t\t";
    for(int i=0; i<11;i++)
    {
    Sleep(100);
    cout<<str[i];
    }

    cout << "\n\t\t\t\t";
    for(int i=0;i<21;i++)
    {
        Sleep(100);
        cout<<str2[i];
    }
    cout << "\n\t\t\t---------------------------------------" << endl;
    cout << "\n\tPlease enter your choice :" << endl;
    cout << "\t1: Reflactance & Trasmittance for Normal incidence." << endl;
    cout << "\t2: Reflactance & Trasmittance for Oblique incidence (p-polarization)." << endl;
    cout << "\t3: Reflactance & Trasmittance for Oblique incidence (s - polarization)." << endl;
    cout << "\t4: To find magnitude of magnetic field corresponding to electric field." << endl;
    cout << "\t5: To find magnitude of electric field corresponding to magnetic field." << endl;
    cout << "\t0: Exit." << endl;
    cin >> c;
}
int main()
{
    system("color 0e");
    do
    {
        menu();
        switch (c)
        {
        case 1:
        {
            normal n1;
            n1.result();
            break;
        }
        case 2:
        {
            oblique_p p1;
            p1.result();
            break;
        }
        case 3:
        {
            oblique_s s1;
            s1.result();
            break;
        }
        case 4:
        {
            electric e1;
            e1.result();
            break;
        }
        case 5:
        {
            magnetic m1;
            m1.result();
            break;
        }
        default: // PROGRAM TERMINATES BY USER
        {
            flag = 0;
        }
        }
        Sleep(1500);
    } while (flag);

    return 0;
}
/*          -----------------------------------------
                    MADE BY : ARYAN PATEL
                           THE END
            -----------------------------------------
*/
