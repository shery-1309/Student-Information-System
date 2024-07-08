**Student Information and Management System**
**Overview**
This project is a Student Information and Management System that allows administrators to manage student records, including adding, updating, deleting, and searching records. Students can log in to view their own records. The system uses a simple console-based interface.

**Features**
**Admin Login: ** Only authorized administrators can access the management functionalities.
**Student Login:** Students can log in to view their own records.
**Add Records:** Admins can add new student records.
**Update Records:** Admins can update existing student records.
**Delete Records:** Admins can delete student records.
**Search Records:** Admins can search for student records by ID.
**Show All Records:** Admins can display all student records.

**Usage**
**System Authorization:** On running the program, you will be prompted to choose between admin login, student login, or exit.
Admin Login:

**Methods**
system_authorization(): Manages the initial authorization and navigation between admin and student login.
admin_authorization(): Handles admin login and navigation to management system.
student_login(): Handles student login and displays their records.
management_system(): Provides admin with options to manage student records.
add_records(): Adds new student records.
update_records(): Updates existing student records.
delete_records(): Deletes student records.
search_records(const int& search_id): Searches for student records by ID.
display_student_record(int id): Displays a student's record.
show_student_records(): Displays all student records.
Main Function
main(): Initiates the system by calling system_authorization().
**Username:** cecos
**Password:** 1980
**Student Login:** Students need to enter their unique username and password to view their records.
**Admin Functionalities:**
Add, update, delete, and search student records.
Display all student records.
Navigate back to the authorization portal or exit the program.
