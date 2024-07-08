#include<iostream>
#include<vector>
#include<string>
#include<map>
#include <conio.h>
using namespace std;

struct student {
    string std_name;
    int std_id;
    int std_marks;
    string std_grade;
    float std_per;
    string username;
    int password;
};

vector<student> student_data;

class Student_Information_System {
    private:
        // Variables for admin authorization:
        string admin_username = "cecos";
        int admin_password = 1980;

    public:
        void system_authorization() {
            system("cls");
            int choice;
            cout << "===============================================================" << endl;
            cout << "||               Welcome to Management System                ||" << endl;
            cout << "===============================================================" << endl;
            cout << "Choose an option to proceed further: " << endl;
            cout << endl;
            cout << "1:) Admin. " << endl;
            cout << "2:) Student. " << endl;
            cout << "3:) Exit." << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    admin_authorization();
                    break;
                case 2:
                    student_login();
                    break;
                case 3:
                    exit(0);
                    cout << "Program exited successfully....." << endl;
                    break;
                default:
                    cout << "Invalid choice! Try again...." << endl;
                    system_authorization(); // Retry authorization
                    break;
            }
        }

        void admin_authorization() {
            system("cls");
            string admin_Username;
            int admin_Password;
            cout << "===============================================================" << endl;
            cout << "||                    Welcome to Admin View                  ||" << endl;
            cout << "===============================================================" << endl;
            cout << "Enter Username: " << endl;
            cin >> admin_Username;
            cout << "Enter Password: " << endl;
            cin >> admin_Password;
            if(admin_Username == admin_username && admin_Password == admin_password) {
                cout << "\nLogin Done" << endl;
                cout << "Press any key to continue......!" << endl;
                getch();
                management_system();
            } else {
                cout << "404 Error || Page not found!!" << endl;
                int choice;
                cout << "Choose an option to continue:- " << endl;
                cout << endl;
                cout << "1:) Try Again. [Reset to admin authorization]" << endl;
                cout << "2:) Exit. " << endl;
                cin >> choice;
                switch (choice) {
                    case 1:
                        system_authorization();
                        break;
                    case 2:
                        exit(0);
                        cout << "Program exited successfully....." << endl;
                        break;
                    default:
                        cout << "Invalid Choice" << endl;
                        system_authorization(); // Retry authorization
                        break;
                }
            }
        }

        void student_login() {
            system("cls");
            string std_Username;
            int std_Password;
            cout << "Enter Username: " << endl;
            cin >> std_Username;
            cout << "Enter Password: " << endl;
            cin >> std_Password;

            bool found = false;
            for (const auto& student : student_data) {
                if (student.username == std_Username && student.password == std_Password) {
                    cout << "Login Done. " << endl << "Press any key to continue...! " << endl;
                    getch();
                    display_student_record(student.std_id);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Access Denied! \n Please try again! " << endl;
                int choice;
                cout << "Choose an option: " << endl;
                cout << "================================" << endl;
                cout << "1:) Go to System Authorization again! " << endl;
                cout << "2:) Exit by pressing [0]. " << endl;
                cin >> choice;
                switch (choice) {
                    case 1:
                        system_authorization();
                        break;
                    case 2:
                        exit(0);
                        cout << " Program exited successfully......" << endl;
                        break;
                    default:
                        cout << "\nInvalid Choice! Try again" << endl;
                        system_authorization(); // Retry authorization
                        break;
                }
            }
        }

        void management_system() {
            system("cls");
            int choice;
            cout << "Enter Your Choice: " << endl;
            cout << "1. Add Records" << endl;
            cout << "2. Update Records" << endl;
            cout << "3. Delete Records" << endl;
            cout << "4. Search Records" << endl;
            cout << "5. Show All Student Records" << endl;
            cout << "6. Back to System Authorization Portal" << endl;
            cout << "7. Exit" << endl;
            cin >> choice;
            switch (choice) {
                case 1:
                    add_records();
                    break;
                case 2:
                    update_records();
                    break;
                case 3:
                    delete_records();
                    break;
                case 4:
                    {
                        int search_id;
                        cout << "Enter ID to Search Student: ";
                        cin >> search_id;
                        search_records(search_id);
                    }
                    break;
                case 5:
                    show_student_records();
                    break;
                case 6:
                    system_authorization();
                    break;
                case 7:
                    exit(0);
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
                    management_system(); // Retry management system
                    break;
            }
        }

        void add_records() {
            student tmp_obj;
            system("cls");
            cout << "===============================================================" << endl;
            cout << "||                   Add Student Records                     ||" << endl;
            cout << "===============================================================" << endl;
            cout << endl;
            string grade;
            int marks;
            float per;

            cout << "Enter Student Name: ";
            cin.ignore();
            getline(cin,tmp_obj.std_name);
            cout << "Enter Student Id: ";
            cin >> tmp_obj.std_id;
            cout << "Enter Student Marks: ";
            cin >> marks;
            tmp_obj.std_marks = marks;
            per = marks;

            if (per >= 85) {
                grade = "A+";
            } else if (per >= 75) {
                grade = "A";
            } else if (per >= 65) {
                grade = "B+";
            } else if (per >= 55) {
                grade = "B";
            } else if (per >= 50) {
                grade = "C";
            } else if (per >= 45) {
                grade = "D";
            } else if (per >= 35) {
                grade = "E";
            } else {
                grade = "F";
            }

            tmp_obj.std_grade = grade;
            tmp_obj.std_per = per;

            cout << "Enter Unique Username: ";
            cin >> tmp_obj.username;
            cout << "Enter Password: ";
            cin >> tmp_obj.password;

            student_data.push_back(tmp_obj);

            cout << "Record Added successfully." << endl;
            management_system(); // Go back to management system
        }

        void update_records() {
            system("cls");
            cout << "===============================================================" << endl;
            cout << "||                   Update Student Records                  ||" << endl;
            cout << "===============================================================" << endl;
            cout << endl;
            int id;
            cout << "Enter Student Id to update: ";
            cin >> id;

            bool found = false;
            for (auto& student : student_data) {
                if (student.std_id == id) {
                    found = true;
                    string name, grade;
                    int marks;
                    float per;

                    cout << "Enter new Student Name: ";
                    cin.ignore();
                    getline(cin, name);
                    cout << "Enter new Student Marks: ";
                    cin >> marks;

                    per = marks;

                    if (per >= 85) {
                        grade = "A+";
                    } else if (per >= 75) {
                        grade = "A";
                    } else if (per >= 65) {
                        grade = "B+";
                    } else if (per >= 55) {
                        grade = "B";
                    } else if (per >= 50) {
                        grade = "C";
                    } else if (per >= 45) {
                        grade = "D";
                    } else if (per >= 35) {
                        grade = "E";
                    } else {
                        grade = "F";
                    }

                    student.std_name = name;
                    student.std_marks = marks;
                    student.std_grade = grade;
                    student.std_per = per;

                    cout << "Record updated successfully." << endl;
                    break;
                }
            }

            if (!found) {
                cout << "Student Id not found." << endl;
            }

            management_system(); // Go back to management system
        }

        void delete_records() {
            system("cls");
            cout << "===============================================================" << endl;
            cout << "||                 Delete Student Records                    ||" << endl;
            cout << "===============================================================" << endl;
            cout << endl;
            int id;
            cout << "Enter Student Id to delete: ";
            cin >> id;

            bool found = false;
            for (auto it = student_data.begin(); it != student_data.end(); ++it) {
                if (it->std_id == id) {
                    student_data.erase(it);
                    found = true;
                    cout << "Record deleted successfully." << endl;
                    break;
                }
            }

            if (!found) {
                cout << "Record with ID " << id << " not found." << endl;
            }

            management_system(); // Go back to management system
        }

        void search_records(const int& search_id) {
            system("cls");
            cout << "===============================================================" << endl;
            cout << "||             Search Student Records by ID:                 ||" << endl;
            cout << "===============================================================" << endl;
            cout << endl;
            bool found = false;
            for (const auto& student : student_data) {
                if (student.std_id == search_id) {
                    display_student_record(student.std_id);
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "No record found for student ID: " << search_id << endl;
            }

            management_system(); // Go back to management system
        }

        void display_student_record(int id) {
            for (const auto& student : student_data) {
                if (student.std_id == id) {
                    cout << "Student Name: " << student.std_name << endl;
                    cout << "Student Id: " << student.std_id << endl;
                    cout << "Student Marks: " << student.std_marks << endl;
                    cout << "Student Percentage: " << student.std_per << endl;
                    cout << "Student Grade: " << student.std_grade << endl;
                    system("pause");
                    return;
                }
            }
        }

        void show_student_records() {
            system("cls");
            cout << "===============================================================" << endl;
            cout << "||              Displaying All Student Records               ||" << endl;
            cout << "===============================================================" << endl;
            cout << endl;
            if (student_data.empty()) {
                cout << "No record found" << endl;
            } else {
                for (const auto& student : student_data) {
                    cout << "Student Name: " << student.std_name << endl;
                    cout << "Student Id: " << student.std_id << endl;
                    cout << "Student Marks: " << student.std_marks << endl;
                    cout << "Student Percentage: " << student.std_per << endl;
                    cout << "Student Grade: " << student.std_grade << endl;
                    cout << "Username: " << student.username << endl;
                    cout << "Password: " << student.password << endl;
                    cout << "---------------------------------" << endl;
                }
                system("pause");
            }

            management_system(); // Go back to management system
        }
};

int main() {
    Student_Information_System sis1;
    sis1.system_authorization();
    return 0;
}