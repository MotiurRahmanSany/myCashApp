// ! v 0.01

#include<bits/stdc++.h>
using namespace std;

class Member{
public:
    string name, mobile;
    int pin;
    double balance;
    int Id;
    void setData(string name, string mobile, int pin){
        this->mobile = mobile;
        this->name = name;
        this->pin = pin;
    }
    string getMobile(){
        return mobile;
    }

};

vector<Member> user;

void History(){

}

void Check_Balance(){

}

void Pay_Bill(){

}

void Mobile_Recharge(){

}

void Add_Money(){

}

void Send_Money(){

}

void Recharge(){

}

void Update_User(){
    cout << "Enter id of the member: ";
    int id;
    cin >> id;
    int flag = false;
    auto it = find(user.begin(), user.end(), id);
    if(it == user.end())
        cout << "Member doesn't exist";
    else{
        cout << "What do you want to update: 1. name 2. mobile or 3. pin";
        cout << "Enter your option: ";
        int op;
        cin >> op;
        switch(op){
            case 1:
            {
                string name;
                getline(cin >> ws, name);
                
            }
        }
    }


}

void Remove_User(){
     cout << "Enter id of the member: ";
    int id;
    cin >> id;
    int flag = false;
    auto it = find(user.begin(), user.end(), id);
    if(it != user.end())
        user.erase(it);
    else cout << "Member doesn't exist";
}

void Exit(){
    cout << "Ok come back again :)" << endl;
    cout << "Exiting the program " << endl;

    return;
}

void DashBoard(){
    cout << "****MyCash Menu****" << endl;
    cout << "Your mobile number is: ";
    cout << endl; // TODO: mobile should be visible here of user
    cout << "1. Check Balance" << endl;
    cout << "2. Add Money" << endl;
    cout << "3. Send Money" << endl;
    cout << "4. Mobile Recharge" << endl;
    cout << "5. Pay Bill" << endl;
    cout << "6. Update Me" << endl;
    cout << "7. Remove Me" << endl;
    cout << "8. History" << endl;
    cout << "9. Logout" << endl;
    int op;
    while(cin >> op){

        switch(op){
            case 1:
                Check_Balance();
                break;
            case 2: 
                Add_Money();
                break;
            case 3:
                Send_Money();
                break;
            case 4:
                Recharge();
                break;
            case 5:
                Pay_Bill();
                break;
            case 6:
                Update_User();
                break;
            case 7:
                Remove_User();
            case 8:
                History();
            case 9:
                Exit();
            default:
                cout << "Invalid input" << endl;

        }
    }
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

int idGenerator(){
    int lb = 1000, ub = 9999;
    int id = ((rand() % (ub - lb + 1)) + lb);
    return id;
}

void Register(){
    string name, mobile;
    int pin;
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
    Member member;
    member.name = name;
    member.mobile = mobile;
    member.pin = pin;
    int id = idGenerator();
    member.Id = id;
    user.push_back(member);
    cout << "Registration is successful" << endl;
    cout << "Your id is: " << id << " Never share this with others" << endl;
    cout << "Entering Dashboard" << endl;

    // TODO: Have to add some time here before entering the dashboard appears...

    DashBoard();



}

void Display(){

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
    // TODO: Have to add some time here before entering the dashboard appears...

                cout << "Okay come back again :)" << endl;
                cout << "Exiting the app..." << endl;
                exit(0);

        }
    }
    

    return 0;
}