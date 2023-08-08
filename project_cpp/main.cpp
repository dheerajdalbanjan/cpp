#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

class Item
{
protected:
    string name;
    string I_id;
    double I_price;
    int I_quantity;

public:
    string category;

public:
    Item()
    {
        cin >> name >> I_id >> I_price >> I_quantity;
    }
    Item(string name, string I_id, double I_price, int I_quantity, string category)
    {
        this->name = name;
        this->I_id = I_id;
        this->I_price = I_price;
        this->I_quantity = I_quantity;
        this->category = category;
    }

    virtual void display()
    {
        cout << I_id << " " << name << " " << I_price << " " << I_quantity << endl;
    }

    double get_price(){
        return I_price ;
    }

    int get_quantity(){
        return I_quantity ;
    }

    void set_quantity(int quantity){
        this->I_quantity = quantity ;
    }

    void udpate(string name, double I_price, int I_quantity)
    {
        this->name = name;
        this->I_price = I_price;
        this->I_quantity = I_quantity;
    }

    virtual string output_file()
    {
        return name + " " +
               I_id + " " +
               to_string(I_price) + " " +
               to_string(I_quantity) + " " +
               category + "\n";
    }

    string get_id()
    {
        return this->I_id;
    }
};

class Electronic : public Item
{
    string model;

public:
    Electronic(string name, string I_id, double I_price, int I_quantity, string model, string category) : Item(name, I_id, I_price, I_quantity, category)
    {
        this->model = model;
    }

    string output_file()
    {
        return name + " " +
               I_id + " " +
               to_string(I_price) + " " +
               to_string(I_quantity) + " " +
               model + " " +
               category + "\n";
    }

    void display()
    {
        cout << left << setw(20) << I_id << setw(30) << name << setw(20) << I_price << setw(20) << I_quantity << setw(20) << model << endl;
    }
};

class Grocery : public Item
{
    string expiry_date;

public:
    Grocery(string name, string I_id, double I_price, int I_quantity, string model, string category) : Item(name, I_id, I_price, I_quantity, category)
    {
        this->expiry_date = model;
    }

    string output_file()
    {
        return name + " " +
               I_id + " " +
               to_string(I_price) + " " +
               to_string(I_quantity) + " " +
               expiry_date + " " +
               category + "\n";
    }

    void display()
    {
        cout << left << setw(20) << I_id << setw(30) << name << setw(20) << I_price << setw(20) << I_quantity << setw(20) << expiry_date << endl;
    }
};

class Fashion : public Item
{
    string size;

public:
    Fashion(string name, string I_id, double I_price, int I_quantity, string size, string category) : Item(name, I_id, I_price, I_quantity, category)
    {
        this->size = size;
    }
    string output_file()
    {
        return name + " " +
               I_id + " " +
               to_string(I_price) + " " +
               to_string(I_quantity) + " " +
               size + " " +
               category + "\n";
    }

    void display() override
    {
        cout << left << setw(20) << I_id << setw(30) << name << setw(20) << I_price << setw(20) << I_quantity << setw(20) << size << endl;
    }
};

class Employee
{
    string name;
    string E_id;
    string E_phone;
    double salary;
    string designation;

public:
    Employee()
    {
        cin >> name >> E_id >> E_phone >> salary >> designation;
    }
    Employee(string name, string E_id, string E_phone, double salary, string designation)
    {
        this->name = name;
        this->E_id = E_id;
        this->E_phone = E_phone;
        this->salary = salary;
        this->designation = designation;
    }

    string get_id()
    {
        return this->E_id;
    }

    void display()
    {
        cout << left << setw(30) << name << setw(20) << E_id << setw(20) << salary << setw(20) << designation << endl;
    }

    void updateDetails(string name, string E_phone, double salary, string designation){
        this->name = name ;
        this->E_phone = E_phone ;
        this->salary = salary ;
        this-> designation = designation ; 
    }

    virtual string output_file()
    {
        return name + " " +
               E_id + " " +
               E_phone + " " +
               to_string(salary) + " " +
               designation + "\n";
    }
};


class Customer {
    string name;
    string C_id;
    string C_phone;
    string address;

public:
    Customer() {
        cin >> name >> C_id >> C_phone >> address;
    }

    Customer(string name, string C_id, string C_phone, string address) {
        this->name = name;
        this->C_id = C_id;
        this->C_phone = C_phone;
        this->address = address;
    }

    string get_id() const {
        return C_id;
    }

    void display() const {
        cout << "Customer ID: " << C_id << endl;
        cout << "Name: " << name << endl;
        cout << "Phone: " << C_phone << endl;
        cout << "Address: " << address << endl;
    }

    string output_file(){
        return name + " " +
               C_id + " " +
               C_phone + " " +
               address + "\n";
    }
};

void addCustomer(vector<Customer*>& customers) {
    string name, C_id, C_phone, address;

    cout << "Enter Customer Name: ";
    cin >> name;

    cout << "Enter Customer ID: ";
    cin >> C_id;

    cout << "Enter Customer Phone No: ";
    cin >> C_phone;

    cout << "Enter Customer Address: ";
    cin.ignore(); // Ignore the newline character left by the previous input
    getline(cin, address);

    customers.push_back(new Customer(name, C_id, C_phone, address));

    ofstream outputFile("customer.txt", ios::app); // Open the file in append mode
    if (!outputFile.is_open()) {
        cout << "Error opening the file to save the new customer.\n";
        return;
    }

    // Write the new customer details to the file
    outputFile << name << " " << C_id << " " << C_phone << " " << address << endl;
    outputFile.close(); // Close the file after writing
}

void updateCustomer(vector<Customer*>& customers) {
    string id ; 
    cout << "Enter the customer ID" << endl;
    cin >> id ; 
    for (auto& customer : customers) {
        if (customer->get_id() == id) {
            string name, C_phone, address;

            cout << "Enter new Customer Name: ";
            cin >> name;

            cout << "Enter new Customer Phone No: ";
            cin >> C_phone;

            cout << "Enter new Customer Address: ";
            cin.ignore(); // Ignore the newline character left by the previous input
            getline(cin, address);

            // Use the setter methods to update the customer's details
            customer = new Customer(name, id, C_phone, address);

            ofstream outputFile("customer.txt");
            if (!outputFile.is_open())
            {
                cout << "Error opening the file to update the items.\n";
                return;
            }

            for (const auto &item : customers)
            {
                outputFile << item->output_file();
            }

            outputFile.close(); // Close the file after writing

            cout << "Customer details updated successfully!\n";
            return; // Exit the loop once the customer is found and updated
        }
    }

    cout << "Customer with ID " << id << " not found.\n";
}

void deleteCustomer(vector<Customer*>& customers) {
    string id ; 
    cout << "Enter the customer ID" << endl;
    cin >> id ; 
    for (auto it = customers.begin(); it != customers.end(); ++it) {
        if ((*it)->get_id() == id) {
            customers.erase(it);
            cout << "Customer deleted successfully!\n";

            ofstream outputFile("customer.txt");
            if (!outputFile.is_open())
            {
                cout << "Error opening the file to update the items.\n";
                return;
            }

            for (const auto &item : customers)
            {
                outputFile << item->output_file();
            }

            outputFile.close(); // Close the file after writing
            return; // Exit the loop once the customer is found and deleted
        }
    }

    cout << "Customer with ID " << id << " not found.\n";
}

Customer * searchCustomerById(vector<Customer*>& customers) {
    string id ; 
    cout << "Enter the customer ID" << endl;
    cin >> id ; 
    for (const auto& customer : customers) {
        if (customer->get_id() == id) {
            cout << "Customer found:\n";
            customer->display();
            return customer; // Exit the loop once the customer is found
        }
    }

    cout << "Customer with ID " << id << " not found.\n";
}

void handle_view_item(vector<Item *> &items)
{
    char choice;

    do
    {
        cout << "Choose the Category" << endl;
        cout << "--------------------------------" << endl;
        cout << "1. Electronic\n";
        cout << "2. Grocery\n";
        cout << "3. Fashion\n";
        cout << "4. Back to Menu\n";
        cin >> choice;
        switch (choice)
        {
        case '1':
            system("cls");
            cout << "Electronic Items are " << endl;
            cout << left << setw(20) << "ID"
                 << setw(30) << "Name"
                 << setw(20) << "Price"
                 << setw(20) << "Quantity"
                 << setw(20) << "Model" << endl;
            for (auto &item : items)
            {
                if (item->category == "Electronic")
                {
                    item->display();
                }
            }
            break;
        case '2':
            system("cls");
            cout << "Grocery Items are " << endl;
            cout << left << setw(20) << "ID"
                 << setw(30) << "Name"
                 << setw(20) << "Price"
                 << setw(20) << "Quantity"
                 << setw(20) << "Expiry Date" << endl;
            for (auto &item : items)
            {
                if (item->category == "Grocery")
                {
                    item->display();
                }
            }
            break;
        case '3':
            system("cls");
            cout << "Fashions Items are " << endl;
            cout << left << setw(20) << "ID"
                 << setw(30) << "Name"
                 << setw(20) << "Price"
                 << setw(20) << "Quantity"
                 << setw(20) << "Size" << endl;
            for (auto &item : items)
            {
                if (item->category == "Fashion")
                {
                    item->display();
                }
            }
            break;
        case '4':
            return;

        default:
            break;
        }

    } while (1);
}

void addItem(vector<Item *> &items)
{
    string name, I_id, category;
    double I_price;
    int I_quantity;
    string model, expiry_date, size;

    cout << "Enter Item Category (Electronic, Grocery, or Fashion): ";
    cin >> category;

    cout << "Enter Item Name: ";
    cin >> name;

    cout << "Enter Item ID: ";
    cin >> I_id;

    cout << "Enter Item Price: ";
    cin >> I_price;

    cout << "Enter Item Quantity: ";
    cin >> I_quantity;

    // For Electronic items
    if (category == "Electronic")
    {
        cout << "Enter Model: ";
        cin >> model;
        items.push_back(new Electronic(name, I_id, I_price, I_quantity, model, category));
    }
    // For Grocery items
    else if (category == "Grocery")
    {
        cout << "Enter Expiry Date: ";
        cin >> expiry_date;
        items.push_back(new Grocery(name, I_id, I_price, I_quantity, expiry_date, category));
    }
    // For Fashion items
    else if (category == "Fashion")
    {
        cout << "Enter Size: ";
        cin >> size;
        items.push_back(new Fashion(name, I_id, I_price, I_quantity, size, category));
    }
    else
    {
        cout << "Invalid category. Item not added.\n";
        return;
    }

    ofstream outputFile("item.txt", ios::app); // Open the file in append mode
    if (!outputFile.is_open())
    {
        cout << "Error opening the file to save the new item.\n";
        return;
    }

    // Write the new item details to the file
    outputFile << name << " " << I_id << " " << I_price << " " << I_quantity << " ";
    if (category == "Electronic")
    {
        outputFile << model << " " << category << endl;
    }
    else if (category == "Grocery")
    {
        outputFile << expiry_date << " " << category << endl;
    }
    else if (category == "Fashion")
    {
        outputFile << size << " " << category << endl;
    }

    outputFile.close(); // Close the file after writing
}

void updateItem(vector<Item *> &items)
{
    string I_id;
    cout << "Enter Item ID to update: ";
    cin >> I_id;

    bool found = false;
    for (auto &item : items)
    {
        if (item->get_id() == I_id)
        {
            found = true;

            string name;
            double I_price;
            int I_quantity;

            cout << "Enter new Item Name: ";
            cin >> name;

            cout << "Enter new Item Price: ";
            cin >> I_price;

            cout << "Enter new Item Quantity: ";
            cin >> I_quantity;

            // Use the setter methods to update the item's details
            item->udpate(name, I_price, I_quantity);

            cout << "Item updated successfully!\n";

            ofstream outputFile("item.txt");
            if (!outputFile.is_open())
            {
                cout << "Error opening the file to update the items.\n";
                return;
            }

            for (const auto &item : items)
            {
                outputFile << item->output_file();
            }

            outputFile.close(); // Close the file after writing
            break;              // Exit the loop once the item is found and updated
        }
    }

    if (!found)
    {
        cout << "Item with ID " << I_id << " not found.\n";
    }
}

void deleteItem(vector<Item *> &items)
{
    string I_id;
    cout << "Enter Item ID to delete: ";
    cin >> I_id;

    bool found = false;
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if ((*it)->get_id() == I_id)
        {
            found = true;

            // Delete the item from the vector
            delete *it;
            items.erase(it);

            cout << "Item deleted successfully!\n";
            break; // Exit the loop once the item is found and deleted
        }
    }
    
    if (!found)
    {
        cout << "Item with ID " << I_id << " not found.\n";
        return;
    }

    // Save the updated items back to the file
    ofstream outputFile("item.txt");
    if (!outputFile.is_open())
    {
        cout << "Error opening the file to update the items.\n";
        return;
    }

    for (const auto &item : items)
    {
        outputFile << item->output_file();
    }

    outputFile.close(); // Close the file after writing
}

void addEmp(vector<Employee *> &employees)
{
    string name, E_id, E_phone, designation;
    double salary;


    cout << "Enter Employee Name: ";
    cin >> name;

    cout << "Enter Employee ID: ";
    cin >> E_id;

    cout << "Enter Employee Phone No: ";
    cin >> E_phone;

    cout << "Enter Employee Salary: ";
    cin >> salary;

    cout << "Enter Employee Designation: ";
    cin >> designation;

    employees.push_back(new Employee(name, E_id, E_phone, salary,designation));

    ofstream outputFile("employee.txt", ios::app); // Open the file in append mode
    if (!outputFile.is_open())
    {
        cout << "Error opening the file to save the new item.\n";
        return;
    }

    // Write the new item details to the file
    outputFile << name << " " << E_id << " " << E_phone << " " << salary << " " << designation <<endl;
    outputFile.close(); // Close the file after writing
}


void updateEmp(vector<Employee*>& employees) {
    string id ; 
    cout << "Enter the ID:"; 
    cin >> id ;
    for (auto emp : employees) {
        if (emp->get_id() == id) {
            string name, E_phone, designation;
            double salary;

            cout << "Enter new Employee Name: ";
            cin >> name;

            cout << "Enter new Employee Phone No: ";
            cin >> E_phone;

            cout << "Enter new Employee Salary: ";
            cin >> salary;

            cout << "Enter new Employee Designation: ";
            cin >> designation;

            // Use the setter methods to update the employee's details
            emp->updateDetails(name, E_phone, salary, designation);

             ofstream outputFile("employee.txt");
            if (!outputFile.is_open())
            {
                cout << "Error opening the file to update the items.\n";
                return;
            }

            for (const auto &item : employees)
            {
                outputFile << item->output_file();
            }

            outputFile.close(); // Close the file after writing

            cout << "Employee details updated successfully!\n";


            return; // Exit the loop once the employee is found and updated
        }
    }

    cout << "Employee with ID " << id << " not found.\n";
}

void deleteEmp(vector<Employee*>& employees) {
    string id ; 
    cout << "Enter the ID:"; 
    cin >> id ;
    for (auto it = employees.begin(); it != employees.end(); ++it) {
        if ((*it)->get_id() == id) {
            // Delete the employee from the vector and deallocate memory
            delete *it;
            employees.erase(it);

            cout << "Employee deleted successfully!\n";
            return; // Exit the loop once the employee is found and deleted
        }
    }

    cout << "Employee with ID " << id << " not found.\n";
}

void searchEmployeeById(const vector<Employee *> &employees)
{
    string id;
    bool found = false;
    cout << "Enter the ID of the employee" << endl;
    cin >> id;
    for (const auto &emp : employees)
    {
        if (emp->get_id() == id)
        {
            cout << left << setw(30) << "Name" << setw(20) << "ID" << setw(20) << "Salary" << setw(20) << "Designation" << endl;
            emp->display();
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "Employee with ID " << id << " not found.\n";
    }
    char choice ;

    cout <<"Press any key to return to the menu..." << endl;
    cin >> choice ; 
    if(choice){
        return ; 
    }
}

void handle_view_emp(vector<Employee *> &employees)
{
    char choice ;
    cout << left << setw(30) << "Name" << setw(20) << "ID" << setw(20) << "Salary" << setw(20) << "Designation" << endl;
    for (auto emp : employees)
    {
        emp->display();
    }
    cout <<"Press any key to return to the menu..." << endl;
    cin >> choice ; 
    if(choice){
        return ; 
    }
}
void checkout(Customer& customer, vector<Item*> items) {
    string itemId;
    int quantity;
    char choice ;

    cout << "Welcome, " << customer.get_id() << "!\n";
    cout << "Enter the item ID you want to purchase: ";
    cin >> itemId;

    Item* foundItem = nullptr;
    for (auto& item : items) {
        if (item->get_id() == itemId) {
            foundItem = item;
            break;
        }
    }

    if (foundItem == nullptr) {
        cout << "Item with ID " << itemId << " not found.\n";
        return;
    }

    cout << "Enter the quantity you want to purchase: ";
    cin >> quantity;

    if (quantity <= 0 || quantity > foundItem->get_quantity()) {
        cout << "Invalid quantity or insufficient stock.\n";
        return;
    }

    double totalAmount = foundItem->get_price() * quantity;

    cout << "Total amount to pay: " << totalAmount << " USD\n";
    cout << "Thank you for shopping with us, " << customer.get_id() << "!\n";

    // Update the item quantity after purchase
    foundItem->set_quantity(foundItem->get_quantity() - quantity);
    cout <<"Press any key to return to the menu..." << endl;
    cin >> choice ; 
    if(choice){
        return ; 
    }

}

class Department
{
    string name;
    string d_id;
    string address;

public:
    Department()
    {
        cin >> name >> d_id >> address;
    }
    Department(string name, string d_id, string address)
    {
        this->name = name;
        this->d_id = d_id;
        this->address = address;
    }

    void intro()
    {

        cout << "Welcome to " << name << endl;
        cout << "----------------------------------" << endl;
    }

    void manageInventory(vector<Item *> &items)
    {

        char choice;
        do
        {
            system("cls");
            cout << "Manage inventory" << endl;
            cout << "----------------------------------" << endl;
            cout << "1. Add Item\n";
            cout << "2. Update Item\n";
            cout << "3. Remove Item\n";
            cout << "4. View Items\n";
            cout << "5. Back to Main Menu\n";
            cin >> choice;

            switch (choice)
            {
            case '1':
                // Add new item to the inventory
                // Implement code to get input for item details and add it to the department's inventory
                addItem(items);
                break;
            case '2':
                updateItem(items);
                // Update item details
                // Implement code to get item ID from the user and update its details
                break;
            case '3':
                deleteItem(items);
                // Remove item from the inventory
                // Implement code to get item ID from the user and remove it from the department's inventory
                break;
            case '4':
                system("cls");
                handle_view_item(items);
                break;
            case '5':
                return; // Go back to the main menu
            default:
                cout << "ERROR: Unknown choice\n";
            }
        } while (true);
    }

    void manageEmployee(vector<Employee *> &employees)
    {
        char choice;
        do
        {
            system("cls"); 
            cout << "Manage Employee" << endl;
            cout << "----------------------------------" << endl;
            cout << "1. View Employees\n";
            cout << "2. Search For an Employee\n";
            cout << "3. Add Employee\n";
            cout << "4. Remove Employee\n";
            cout << "5. Update Employee\n";
            cout << "6. Back to Main Menu\n";
            cin >> choice;

            switch (choice)
            {
            case '1':
                handle_view_emp(employees);
                break;
            case '2':
                searchEmployeeById(employees);
                break;
            case '3':
                addEmp(employees);
                break;
            case '4':
                deleteEmp(employees); 
                break;
            case '5': 
                updateEmp(employees); 
                break ;

            case '6':
                return; // Go back to the main menu
            default:
                cout << "ERROR: Unknown choice\n";
            }
        } while (true);
    }

    void manageCustomer(vector<Customer*>& customers, vector<Item*>& items){ 
        char choice;
        string id ;
        Customer *c  ;
        do
        {
            system("cls"); 
            cout << "Manage Customer" << endl;
            cout << "----------------------------------" << endl;
            cout << "1. Search For a Customer\n";
            cout << "2. Add Customer\n";
            cout << "3. Remove Customer\n";
            cout << "4. Update Customer\n";
            cout << "5. Check out\n";
            cout << "6. Back to Main Menu\n";
            cin >> choice;

            switch (choice)
            {
            case '1':
                c = searchCustomerById(customers);
                break;
            case '2':
                addCustomer(customers); 
                break;
            case '3':
                deleteCustomer(customers);
                break;
            case '4':
                updateCustomer(customers);
                break;
            case '5': 
                c = searchCustomerById(customers) ; 
                checkout(*c, items) ;
                break ;

            case '6':
                return; // Go back to the main menu
            default:
                cout << "ERROR: Unknown choice\n";
            }
        } while (true);
    }
};

void init_items(vector<Item *> &items)
{
    ifstream inputFile("item.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening the file.\n";
        return;
    }

    string line;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        string name, I_id, category, extra_attribute;
        double I_price;
        int I_quantity;

        // Read data from the line
        if (iss >> name >> I_id >> I_price >> I_quantity >> extra_attribute >> category)
        {
            if (category == "Electronic")
            {
                Item *newItem = new Electronic(name, I_id, I_price, I_quantity, extra_attribute, category);
                items.push_back(newItem);
            }
            else if (category == "Grocery")
            {
                Item *newItem = new Grocery(name, I_id, I_price, I_quantity, extra_attribute, category);
                items.push_back(newItem);
            }
            else if (category == "Fashion")
            {
                Item *newItem = new Fashion(name, I_id, I_price, I_quantity, extra_attribute, category);
                items.push_back(newItem);
            }
        }
        else
        {
            cout << "Error reading data from the line.\n";
        }
    }

    inputFile.close();
}

void init_employees(vector<Employee *> &Employees)
{
    ifstream inputFile("employee.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening the file.\n";
        return;
    }

    string line;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        string name, E_id, E_phone, Designation;
        double salary;
        int I_quantity;

        // Read data from the line
        if (iss >> name >> E_id >> E_phone >> salary >> Designation)
        {
            Employee *newEmployee = new Employee(name, E_id, E_phone, salary, Designation);
            Employees.push_back(newEmployee);
        }
        else
        {
            cout << "Error reading data from the line.\n";
        }
    }

    inputFile.close();
}

void init_customers(vector<Customer*>& customers)
{
    ifstream inputFile("customer.txt");
    if (!inputFile.is_open())
    {
        cout << "Error opening the file.\n";
        return;
    }

    string line;
    while (getline(inputFile, line))
    {
        istringstream iss(line);
        string name, C_id, C_phone, address;

        // Read data from the line
        if (iss >> name >> C_id >> C_phone >> address)
        {
            
            customers.push_back(new Customer(name, C_id, C_phone, address));
        }
        else
        {
            cout << "Error reading data from the line.\n";
        }
    }

    inputFile.close();
}

int main()
{
    vector<Item *> items;
    vector<Employee *> employees;
    vector<Customer *> customers ;
    init_items(items);
    init_employees(employees);
    init_customers(customers);

    char c;
    Department dept("Department Management System", "3dkdk33", "Hubli");

    while (1)
    {
        system("cls");
        dept.intro();

        cout << "1. Administrator" << endl;
        cout << "2. Employee" << endl;
        cout << "3. customer" << endl;
        cin >> c;
        switch (c)
        {
        case '1':
            dept.manageInventory(items);
            break;
        case '2':
            dept.manageEmployee(employees);
            break;
        case '3':
            dept.manageCustomer(customers, items);
            break;

        default:
            cout << "ERROR: Unknown" << endl;
            break;
        }
    }
    items.clear();
    return 0;
}