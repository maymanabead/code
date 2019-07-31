// reading a text file
#include <bits/stdc++.h>
#include <string>

using namespace std;


struct area {
    string name = "";
    int diabetes = 0;
    int VirusC = 0;
    int HighBP = 0;
};

int main () {
    //Defining areas
    area cities[3];
    cities[0].name = "NasrCity", cities[1].name = "NewCairo", cities[2].name = "Duqqi";

    map <string, int> dis;
    dis["diabetes"] = 0, dis["VirusC"] = 1, dis["HighBloodPressure"] = 2;

    //Opening the file
    //string line;
    ifstream myfile ("data.txt");
    //Check if there is still remaining lines in file
    if (myfile.is_open()) {
        //get each line
        while ( getline (myfile,line) ) {
            int i = 0;
            string Name = "";
            for (i = 0; i < (int)line.length(); ++i) {
                if (line[i] == '|') {
                    break;
                }
                Name += line[i];
            }
            //cout << Name << "\n";

            //cout << i <<"\n";
            ++i;

            string City = "";
            for (; i < (int)line.length(); ++i) {
                if (line[i] == '|') {
                    break;
                }
                if (line[i] != ' ') {
                    City += line[i];
                }
            }
            //cout << "*" << City << "*" << "\n";

            ++i;

            string disease = "";
            for (; i < (int)line.length(); ++i) {
                if (line[i] == '|') {
                    break;
                }
                if (line[i] != ' ') {
                    disease += line[i];
                }
            }
            //cout << "*" << disease << "*"<< "\n";

            for (int j = 0; j < 3; ++j) {
                if (cities[j].name == City) {
                    if (disease == "Diabetes") {
                        ++cities[j].diabetes;
                    } else if (disease == "VirusC") {
                        ++cities[j].VirusC;
                    } else if (disease == "HighBloodPressure"){
                        ++cities[j].HighBP;
                    }
                    //cout << cities[j].name << " " << disease << " " << "\n";
                    //cout << cities[j].diabetes << endl;
                    //cout << cities[j].VirusC << endl;
                    //cout << cities[j].HighBP << endl;
                }
            }
        }
        myfile.close();
    }

    else {
        cout << "Unable to open file";
    }


    /*string ch, ex;
    cin >> ch;
    ch = string(ch.begin(), ch.end()-1);
    cout << ch;*/

    //Username
    bool fail = false;
    string usernm, passwrd, userName, passWord, mde;
    cout << "Enter username: ";
    cin >> usernm;
    cout << "Password: ";
    cin >> passwrd;

    string line;
    ifstream myfile2 ("usr.txt");

    if (myfile2.is_open()) {
        while(getline (myfile2,line)) {
            int i = 0;
            userName = "";
            passWord = "";
            mde = "";

            for (i = 0; i < (int)line.length(); ++i) {
                if (line[i] == '|') {
                    break;
                }
                userName += line[i];
            }
            userName = string(userName.begin(), userName.end()-1);
            //cout << "*" << userName << "*" << "\n";

            //cout << i <<"\n";
            ++i;

            for (; i < (int)line.length(); ++i) {
                if (line[i] == '|') {
                    break;
                }
                if (line[i] != ' ') {
                    passWord += line[i];
                }
            }
            passWord = string(passWord.begin(), passWord.end()-1);
            //cout << "*" << passWord << "*" << "\n";

            ++i;
            //cout << line[i] << "\n";
            for (; i < (int)line.length(); ++i) {
                if (line[i] == 'c' || line[i] == 'd') {
                    mde += line[i];
                }
            }
            //mde = string(mde.begin(), mde.end()-1);
            //cout << "*" << mde << "*" << "\n";

            if(usernm != userName || passwrd != passWord) {
                cout << "Username or password not correct!\n";
                fail = true;
            }
        }

        myfile2.close();
    }
    if (mde == "c") {
        int choice;
        choice = 10;
        while (choice!= 7) {
            cout << "*******Enter 7 to exit!*******\n";
            cout << "Select what you want ??\n";
            cout << "1-Get the location of a diseases in a city\n";
            cout << "2-Get the number of a specific disease\n";

            cin >> choice;

            if (choice == 1) {
                cout << "Which city do you want to know about??\n";
                cout << "1-Nasr City\n";
                cout << "2-New Cairo\n";
                cout << "3-Duqqi\n";
                cin >> choice;
                --choice;
                if (choice == 0) {
                    cout << "\n\n Nasr City: \n";
                    cout << "Diabetes: " << cities[0].diabetes << "\n";
                    cout << "Virus C: " << cities[0].VirusC << "\n";
                    cout << "High blood pressure: " << cities[0].HighBP << "\n\n";
                } else if (choice == 1) {
                    cout << "\n\n Nasr Cairo: \n";
                    cout << "Diabetes: " << cities[1].diabetes << "\n";
                    cout << "Virus C: " << cities[1].VirusC << "\n";
                    cout << "High blood pressure: " << cities[1].HighBP << "\n\n";
                } else if (choice == 2) {
                    cout << "\n\n Duqqi: \n";
                    cout << "Diabetes: " << cities[2].diabetes << "\n";
                    cout << "Virus C: " << cities[2].VirusC << "\n";
                    cout << "High blood pressure: " << cities[2].HighBP << "\n\n";
                }
            }
        }
    }
/*
    //Opening the file
    //string line;
    ifstream myfile ("data.txt");
    //Check if there is still remaining lines in file
    if (myfile.is_open()) {
        //get each line
        while ( getline (myfile,line) ) {
            int i = 0;
            string Name = "";
            for (i = 0; i < (int)line.length(); ++i) {
                if (line[i] == '|') {
                    break;
                }
                Name += line[i];
            }
            //cout << Name << "\n";

            //cout << i <<"\n";
            ++i;

            string City = "";
            for (; i < (int)line.length(); ++i) {
                if (line[i] == '|') {
                    break;
                }
                if (line[i] != ' ') {
                    City += line[i];
                }
            }
            //cout << "*" << City << "*" << "\n";

            ++i;

            string disease = "";
            for (; i < (int)line.length(); ++i) {
                if (line[i] == '|') {
                    break;
                }
                if (line[i] != ' ') {
                    disease += line[i];
                }
            }
            //cout << "*" << disease << "*"<< "\n";

            for (int j = 0; j < 3; ++j) {
                if (cities[j].name == City) {
                    if (disease == "Diabetes") {
                        ++cities[j].diabetes;
                    } else if (disease == "VirusC") {
                        ++cities[j].VirusC;
                    } else if (disease == "HighBloodPressure"){
                        ++cities[j].HighBP;
                    }
                    //cout << cities[j].name << " " << disease << " " << "\n";
                    //cout << cities[j].diabetes << endl;
                    //cout << cities[j].VirusC << endl;
                    //cout << cities[j].HighBP << endl;
                }
            }
        }
        myfile.close();
    }

    else {
        cout << "Unable to open file";
    }



    int choice;
    choice = 10;
    while (choice!= 7) {
        cout << "*******Enter 7 to exit!*******\n";
        cout << "Select what you want ??\n";
        cout << "1-Get the location of a diseases in a city\n";
        cout << "2-Get the number of a specific disease\n";

        cin >> choice;

        if (choice == 1) {
            cout << "Which city do you want to know about??\n";
            cout << "1-Nasr City\n";
            cout << "2-New Cairo\n";
            cout << "3-Duqqi\n";
            cin >> choice;
            --choice;
            if (choice == 0) {
                cout << "\n\n Nasr City: \n";
                cout << "Diabetes: " << cities[0].diabetes << "\n";
                cout << "Virus C: " << cities[0].VirusC << "\n";
                cout << "High blood pressure: " << cities[0].HighBP << "\n\n";
            } else if (choice == 1) {
                cout << "\n\n Nasr Cairo: \n";
                cout << "Diabetes: " << cities[1].diabetes << "\n";
                cout << "Virus C: " << cities[1].VirusC << "\n";
                cout << "High blood pressure: " << cities[1].HighBP << "\n\n";
            } else if (choice == 2) {
                cout << "\n\n Duqqi: \n";
                cout << "Diabetes: " << cities[2].diabetes << "\n";
                cout << "Virus C: " << cities[2].VirusC << "\n";
                cout << "High blood pressure: " << cities[2].HighBP << "\n\n";
            }
        }
    }
*/
    return 0;
}
