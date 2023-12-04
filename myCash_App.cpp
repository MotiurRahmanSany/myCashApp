#include<bits/stdc++.h>
#include<conio.h>

using namespace std;

class Member{
    int pin;
    double balance;
    string name, mobile;
public:
    Member(string name, string mobile, int pin = 0){
        balance = 0.0;
        this->pin = pin;
        this->name = name;
        this->mobile = mobile;
    }
    string getName(){
        return name;
    }
    void setName(string name){
        this->name = name;
    }
    int getPin(){
        return pin;
    }
    void settingPin(int p){
        pin = p;
    }
    Member(){}
    friend double getBalance(Member const &obj); 
    friend void setBalance(Member const &obj,  double x);
};
// friend function of Member class

double getBalance(Member const &obj){
    return obj.balance;
}

void setBalance(Member const &obj, double x){
    // 
}

vector<Member> members;

class myCash{
public:
    Member newMember;
    void goToMain(){
        cout << "Press any key to go to main menu....." << endl;
        int ch;
        if(cin >> ch){
            mainMenu();
        }
    }
    int setPin(){
        string s;
        while (true)
        {
            char ch;
            ch = _getch();
            if (ch == 13)
                break;
            else if (ch == 8)
            {
                cout << "\b \b";
                s.pop_back();
            }
            else
            {
                cout << '*';
                s.push_back(ch);
            }
        }
        int pin = stoi(s);
        cout << '\n';
        return pin;
    }

    int getOtp(){
        int lb = 100000, ub = 999999;
        int otp = ((rand() % (ub - lb + 1)) + lb);
        return otp;
    }

    void Register(){
        string mobile, name;
        int pin;
        cout << "Enter Mobile No: ";
        cin >> mobile;
        cout << "Enter Name: ";
        getline(cin >> ws, name);
        cout << "Enter pin: ";
        pin = setPin();
        cout << "Reconfirm pin: ";
        int repin = setPin();
        if(pin != repin){
            cout << "Pin doesn't matched";
            return;
        }
        cout << "Your pin is: " << pin << " Don't share or forget this" << endl;
        int Rotp = getOtp();
        cout << "myCash OTP: " << Rotp << endl;
        cout << "Enter OTP: ";
        int otp;
        cin >> otp;
        if(otp != Rotp){
            cout << "Otp have to be same" << endl;
            return;
        }
        cout << "Registration is Successful" << endl;
        Member newMember(name, mobile, pin);
        members.push_back(newMember);
        cout << "Press any key to go to main menu..... " << endl;
        char ch;
        if(cin >> ch){
            mainMenu();
        }
        //! maybe incomplete
    }

     void Login(){
       string mobile;
       int pin;
       cout << "Enter Mobile No: ";
       cin >> mobile;
       cout << "Enter pin: ";
       pin = setPin();
        // ! incomplete
    }

    void mainMenu(){
        cout << "********** MyCash Menu ********" << endl;
        cout << "1. Update Me" << endl;
        cout << "2. Remove Me" << endl;
        cout << "3. Send Money" << endl;
        cout << "4. Cash-in" << endl;
        cout << "5. Cash-out" << endl;
        cout << "6. Pay Bill" << endl;
        cout << "7. Check Balance" << endl;
        cout << "8. History" << endl;
        cout << "9. Logout" << endl;
        cout << "Enter Your Option (1-9): "<< endl;
        int option;
        cin >> option;
        switch(option){
            case 1:
                updateMember();
                break;
            case 2:
                removeMember();
                break;
            case 3:
                sendMoney();
                break;
            case 4:
                cashIn();
                break;
            case 5:
                cashOut();
                break;
            case 6:
                payBill();
                break;
            case 7:
                checkBalance();
                break;
            case 8:
                History();
                break;
            case 9:
                return;
            default:
                cout << "Invalid Option" << endl;
        }
    }

    void updateMember(){
        cout << "Old Name: " << newMember.getName() << endl;
        cout << "New Name (enter to ignore): ";
        string name;
        getline(cin, name);
        cout << "Old pin: " << newMember.getPin() << endl;
        int pin;
        cout << "New pin (enter to ignore): ";
        pin = setPin();
        cout << "Confirm new pin: ";
        int repin = setPin();
        if(pin == repin){
            int generatedOtp = getOtp();
            cout << "myCash OTP: " << generatedOtp << endl;
            int enteredOtp;
            cin >> enteredOtp;
            if(enteredOtp == generatedOtp){
                cout << "Update is Successful" << endl;
                //! incomplete
                return goToMain();
            }else{
                return goToMain();
            }
        }else{
            return goToMain();
        }
        
    }

    void removeMember(){
        int generatedOtp = getOtp();
        cout << "myCash OTP: " << generatedOtp << endl;
        cout << "Enter OTP: ";
        int enteredOtp;
        cin >> enteredOtp;
        if(generatedOtp == enteredOtp){
            cout << "Remove is Successful" << endl;
            // ! incomplete
        }
    }

    void sendMoney(){
    start:
        cout << "Enter Destination no.(11-digit): " ;
        string mobile;
        cin >> mobile;
        cout << "Enter amount: ";
        double amount;
        cin >> amount;
        cout << "Sending " << amount << " to " << mobile << endl;
        cout << "Are you sure(Y/N)? ";
        char ch;
        cin >> ch;
        if(ch == 'Y' or ch == 'y'){
            int generatedOtp = getOtp();
            cout << "myCash OTP: " << generatedOtp << endl;
            int enteredOtp;
            cout << "Enter OTP: ";
            cin >> enteredOtp;
            if(generatedOtp == enteredOtp){
                cout << "Send Money is Successful" << endl;
                //! incomplete
                return goToMain();
            }else 
                return goToMain();
        }else
            return goToMain();
        

    }


    void cashIn(){
        cout << "Enter your amount: ";
        double amount;
        cin >> amount;
        if(amount < 1){
            cout << "Invalid Amount" << endl;
            return goToMain();
        }
        cout << "Cash-in " << amount << endl;
        cout << "Are you sure(Y/N)? ";
        char ch;
        cin >> ch;
        if(ch == 'Y' or ch == 'y'){
            //! set new balance i.e Incomplete
            cout << "Cash-in is Successful" << endl;
            return goToMain();
        }else {
            return goToMain();
        }
            
    }

    void cashOut(){
        cout << "Enter Amount: ";
        double amount;
        cin >> amount;
        if(amount > 0 and amount < getBalance(newMember)){
            cout << "Cash-out " << amount << endl;
            cout << "Are you sure(Y/N)? ";
            char ch;
            cin >> ch;
            if(ch == 'Y' or ch == 'y'){
                int genereatedOtp = getOtp();
                cout << "myCash OTP: " << genereatedOtp << endl;
                int enteredOtp;
                cout << "Enter OTP: ";
                cin >> enteredOtp;
                if(enteredOtp != genereatedOtp){
                    cout << "OTP doesn't matched" << endl;
                    return goToMain();
                }
                cout << "Cash-out is Successful" << endl;

                return goToMain();
            }else {
                return goToMain();
            }
        }
    }

    void payBill(){
        cout << "Enter Bill Type (Gas/Electricity/Water/Internet-1/2/3/4): ";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Your Gas Bill: "; 
                break;
            case 2:
                cout << "Your Electricity Bill: "; 
                break;
            case 3:
                cout << "Your Water Bill: "; 
                break;
            case 4:
                cout << "Your Internet Bill: "; 
                break;
            default:
                cout << "Invalid Option" << endl;
        }
        double amount;
        cin >> amount;
        if(amount > 0 and amount < getBalance(newMember)){
            cout << "Want to pay(Y/N)? ";
            char ch;
            cin >> ch;
            if(ch == 'Y' or ch == 'y'){
                int genereatedOtp = getOtp();
                cout << "myCash OTP: " << genereatedOtp << endl;
                int enteredOtp;
                cout << "Enter OTP: ";
                cin >> enteredOtp;
                if(enteredOtp != genereatedOtp){
                    cout << "OTP doesn't matched" << endl;
                    return goToMain();
                }
                cout << "Bill Payment is Successful" << endl;
                return goToMain();
            }else {
                return goToMain();
            }
        }

    }

    void checkBalance(){
        cout << "Balance: " << getBalance(newMember) << endl;
        return goToMain();
    }

    void History(){
        cout << "Tran\tID\t\tDescription\tAmount\tBalance" << endl;  
        return goToMain();
    }
};


int main(){
    myCash member;

    while(true){
        cout << "****MyCash Login*****" << endl;
        cout << "1. Login" << endl;
        cout << "2. Register" << endl;
        cout << "3. Exit" << endl;  
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;
        switch(choice){
            case 1:
                member.Login();
                break;
            case 2:
                member.Register();
                break;
            case 3:
                exit(0);
            default:
                cout << "Invalid choice" << endl;
        }
    }
    

    return 0;
}