// ! v 0.01

#include<bits/stdc++.h>
using namespace std;

class MyCash{

};

class Member{
    string name, mobile;
    int pin;
};

class History{

};

void Update_Member(){

}

void Delete_Member(){

}


void DashBoard(){

}

int Enter(){
    cout << "***MyCash***" << endl;
    cout << "1. Login" << endl;
    cout << "2. Register" << endl;
    cout << "3. Exit" << endl;
    cout << "Enter your option: ";
    int op;
    cin >> op;
    return op;
}

void Login_Form(){
    string mobile;
    int pin;
    cout << "Enter your 11 digit Mobile Number: ";
    cin >> mobile;
    cout << "Enter your pin: ";
    cin >> pin;
    cout << "Login is Successful" << endl;

    DashBoard();

}

int OTP_Generator(){
    int lb = 100000, ub = 999999;
    int otp = ((rand() % (ub - lb + 1)) + lb);
    return otp;
}

void Register(){
    string name, mobile;
    int pin;
    cout << "Enter your name: ";
    getline(cin >> ws, name);
    cout << "Enter your 11 digit mobile number: ";
    cin >> mobile;
    cout << "Set a pin number(4 or 5 digit long): ";
    cin >> pin;
    cout << "Reconfirm pin: ";
    int pin2;
    cin >> pin2;
    if(pin != pin2){
        cout << "Your pin didn't match good luck next time :(";
        return;
    }
    int generated_otp = OTP_Generator();
    cout << generated_otp << endl;
    cout << "Enter the above OTP: ";
    int Entered_otp;
    cin >> Entered_otp;
    if(Entered_otp != generated_otp){
        cout << "OTP didn't match. Good luck next time :(" << endl;
        return;
    }
    cout << "Registration is successful" << endl;
    cout << "Entering Dashboard" << endl;

    // TODO: Have to add some time here before entering the dashboard...

    DashBoard();



}

int main(){

    while(true){
        int ans = Enter();
        switch(ans){
            case 1:
                Login_Form();
                break;
            case 2:
                Register();
                break;
            case 3:
                cout << "Okay come again :)";
                exit(0);

        }
    }
    

    return 0;
}