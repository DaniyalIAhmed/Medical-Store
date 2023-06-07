// Medical Store.cpp : Project Medical Store
//

#include <iostream>
#include <fstream>

using namespace std;
struct account {
    string name, email, password;
};
struct medics {
    string name;
    float price;
    int quantity;
};
string adname = "Daniyal Ahmed", ademail = "admin", adpass = "admin";
int numOfMedicine = 0;
account user;
int adcheck = 0;
void menu() {
    adm:
    system("cls");
    system("color c");
    int choice;
    if (adcheck) {
        int stop;
        cout << "[ADMIN PANEL]\n\n"<<"Admin: " << adname<<"\n\n\n";
        cout << "1.Customer Details\n2.Add Medicine\n3.View Stock\n4.Exit\n";
        cin >> choice;
        if (choice == 1) {
            account temp;
            system("cls");
            cout << "[CUSTOMER INFORMATION]\n\n";
            ifstream rdr("accounts.bin", ios::binary | ios::in);
            while (rdr.read((char*)&temp, sizeof(temp))) {
                cout << "Name: " << temp.name << "\nUsername: " << temp.email<<"\n\n";
            }
            cout << "Press any digit\n";
            cin.ignore();
            rdr.close();
            cin >> stop;
        }
        else if (choice == 2) {
            int no;
            system("cls");
            ifstream nm("nom.txt", ios::in);
            nm >> numOfMedicine;
            nm.close();
            cout << "[MEDICINE PANEL]\n\n";
            cout << "Enter number of medicines to add: ";
            cin >> no;
            numOfMedicine += no;
            cout << "\n\n";
            ofstream med("medicine.txt", ios::app);
            medics temp;
            for (int i = 0;i < no;i++) {
                cout << "Enter medicine name: ";
                cin >> temp.name;
                cout << "Enter medicine price: ";
                cin >> temp.price;
                cout << "Enter medicine quantity: ";
                cin >> temp.quantity;
                med << temp.name << endl << temp.price << endl << temp.quantity << endl;
            }
            ofstream nom("nom.txt");
            nom << numOfMedicine;
            nom.close();
            med.close();
            goto adm;
        }
        else if (choice == 3) {
            system("cls");char stop;
            cout << "[CURRENT STOCK]\n";
            ifstream med("medicine.txt", ios::in);
            ifstream nom("nom.txt", ios::in);
            nom >> numOfMedicine;
            nom.close();
            medics temp;
            for (int i = 0;i < numOfMedicine;i++) {
                med >> temp.name >> temp.price >> temp.quantity;
                cout << "Name: " << temp.name<<endl;
                cout << "Price: " << temp.price<<endl;
                cout << "Quantity: " << temp.quantity<<endl<<endl;
            }
            cin >> stop;
            med.close();
            goto adm;
        }
        else if (choice == 4) {
            exit(1);
        }
        goto adm;
    }
    else {
    cc2:
        medics arr[10];
        static int ctr = 0;
        char more;
        system("color e");
        cout << "[SHOP]\n\n\n";
        cout << "1.Buy Medicine\n2.Search\n3.Exit\n";
        cin >> choice;
        int item;
        if (choice == 1) {
            system("cls");
            cout << "[CURRENT STOCK]\n";
            ifstream med("medicine.txt", ios::in);
            ifstream nom("nom.txt", ios::in);
            nom >> numOfMedicine;
            nom.close();
            medics* ptr = new medics[numOfMedicine];
            for (int i = 0;i < numOfMedicine;i++) {
                med >> ptr[i].name >> ptr[i].price >> ptr[i].quantity;
                cout << i + 1 << " Name: " << ptr[i].name << endl;
                cout << "  Price: " << ptr[i].price << endl << endl;
            }
            med.close();
            cin >> item;
            arr[ctr].name = ptr[(item - 1)].name;
            arr[ctr].price = ptr[(item - 1)].price;
        prev2:
            cout << "Enter Quantity: ";
            cin >> arr[ctr].quantity;
            if (ptr[item - 1].quantity < arr[ctr].quantity) {
                cout << "Limited quantity. Please enter again" << endl;
                goto prev2;
            }
            else
                ptr[item - 1].quantity -= arr[ctr].quantity;
            ctr++;
            cout << "Purchased. Would you like some more?\n";
            cin >> more;
            if (more == 'Y' || more == 'y') {
                system("cls");
                goto cc2;
            }
            else {
                float total = 0;
                system("cls");
                system("color f");
                cout << "[Bill]\n\n";
                cout << "Bill Summary:\nName: " << user.name << endl;
                for (int i = 0;i < ctr;i++) {
                    cout << arr[i].name << "\t" << arr[i].price << endl;
                    total += arr[i].price * arr[i].quantity;
                }
                cout << "Total\t" << total;
                ofstream out("medicine.txt", ios::out);
                for (int i = 0;i < numOfMedicine;i++) {
                    out << ptr[i].name <<endl<< ptr[i].price<<endl << ptr[i].quantity<<endl;
                }
                out.close();
            }
        }
        else if (choice == 2) {
            goto cc2;
        }
        else if (choice == 3) {
            exit(1);
        }
    }
}
void gmenu() {
cc1:
    system("cls");
    int choice;
    medics arr[10];
    static int ctr = 0;
    char more;
    system("color e");
    cout << "[SHOP]\n\n\n";
    cout << "1.Buy Medicine\n2.Search\n3.Exit\n";
    cin >> choice;
    int item;
    if (choice == 1) {
        system("cls");
        cout << "[CURRENT STOCK]\n";
        ifstream med("medicine.txt", ios::in);
        ifstream nom("nom.txt", ios::in);
        nom >> numOfMedicine;
        nom.close();
        medics* ptr = new medics[numOfMedicine];
        for (int i = 0;i < numOfMedicine;i++) {
            med >> ptr[i].name >> ptr[i].price >> ptr[i].quantity;
            cout << i + 1 << " Name: " << ptr[i].name << endl;
            cout << "  Price: " << ptr[i].price << endl << endl;
        }
        med.close();
        cin >> item;
        arr[ctr].name = ptr[(item - 1)].name;
        arr[ctr].price = ptr[(item - 1)].price;
    prev1:
        cout << "Enter Quantity: ";
        cin >> arr[ctr].quantity;
        if (ptr[item - 1].quantity < arr[ctr].quantity) {
            cout << "Limited quantity. Please enter again" << endl;
            goto prev1;
        }
        else
            ptr[item - 1].quantity -= arr[ctr].quantity;
        ctr++;
        cout << "Purchased. Would you like some more?\n";
        cin >> more;
        if (more == 'Y' || more == 'y') {
            system("cls");
            goto cc1;
        }
        else {
            float total = 0;
            system("cls");
            system("color d");
            cout << "[Bill]\n\n";
            cout << "Bill Summary: Guest Mode\n" << endl;
            for (int i = 0;i < ctr;i++) {
                cout << arr[i].name << "\t" << arr[i].price << endl;
                total += arr[i].price * arr[i].quantity;
            }
            cout << "Total\t" << total<<endl;
            ofstream out("medicine.txt", ios::out);
            for (int i = 0;i < numOfMedicine;i++) {
                out << ptr[i].name << endl << ptr[i].price << endl << ptr[i].quantity << endl;
            }
            char c;
            out.close();
            cin >> c;
        }
    }
}
void signup(void);
void login() {
    ifstream rdr;
    account ac;bool flag = 0;
    rdr.open("accounts.bin", ios::binary | ios::in);
    string email, pass;
    system("color b");
    system("cls");
    cout << "[Log In]\n\n\n";
    cin.ignore();
    cout << "Enter Username: ";
    cin >> email;
    while (rdr.read((char*)&ac, sizeof(ac))) {
        if (ac.email == email) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        pss:
        cout << "\nEnter Password: ";
        cin >> pass;
        if (pass == ac.password) {
            cout << "Successfully logged in";
            user.name = ac.name;
            user.email = ac.email;
            user.password = ac.password;
        }
        else {
            cout << "Wrong password\n";
            goto pss;
        }
    }
    else if (email == ademail) {
        apss:
        cin.ignore();
        cout << "\nEnter Password: ";
        cin >> pass;
        if (pass == adpass) {
            cout << "Successfully logged in";
            user.name = adname;
            user.email = ademail;
            user.password = adpass;
            adcheck = 1;
        }
        else {
            cout << "Wrong password\n";
            goto apss;
        }
    }
    else {
        int check;
        cout << "\nUsername does not exists on our systems!\n";
        cout << "Please sign up. Press any digit...\n";
        cin >> check;
        signup();
    }
    menu();
    rdr.close();
}

    

void signup(void) {
    ofstream wtr;
    wtr.open("accounts.bin", ios::binary | ios::app);
    string name,email,pass;
    account ac;int choice =0;
    system("color a");
    system("cls");
    cout << "[SIGN UP]\n\n\n";
    cout << "Enter your name: ";
    cin.ignore();
    cin >> name;
    cout << "\nEnter your email: ";
    cin >> email;
    ifstream rdr;
    rdr.open("accounts.bin", ios::binary);
    while (rdr.read((char*) & ac, sizeof(ac))) {
        if (ac.email == email) {
            cout << "Email already exists.\n1.Sign Up\n2.Log In\n";
            cin >> choice;
            break;
        }
    }
    if (choice == 1) {
        rdr.close();
        signup();
        return;
    }
    else if (choice == 2) {
        login();
        return;
    }
    rdr.close();
    cout << "\nEnter Password: ";
    cin >> pass;
    user.name = name;
    user.email = email;
    user.password = pass;
    wtr.write((char*)&user, sizeof(account));
    wtr.close();
    menu();
}

int main()
{
    int choice;
    cout << "[WELCOME]\n\n\n";
    cout << "Select your choice:\n1.Log In\n2.Sign Up\n3.Guest\n4.Exit\n";
    cin >> choice;
    if (choice == 1) {
        login();
    }
    else if(choice == 2){
        signup();
    }
    else if(choice == 3){
        gmenu();
    }
    else if(choice == 4){
        cout << "Sorry to see you go. We will try to improve our services!";
        exit(1);
    }
}
