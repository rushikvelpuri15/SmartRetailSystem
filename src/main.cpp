#include <iostream>
#include <iomanip>
#include <limits>
#include <fstream>
using namespace std;

struct Product
{
    int id;
    string name;
    double price;
};

struct Customer
{
    int id;
    string name;
    string phone;
};

struct Order
{
    int orderId;
    int productId;
    int customerId;
    int quantity;
    double total;
};

Product products[100];
Customer customers[100];
Order orders[100];

int productCount = 0;
int customerCount = 0;
int orderCount = 0;
bool customerExists(int id); 

void addProduct()
{
    int id;

    cout << "\nEnter Product ID: ";
    cin >> id;

    for(int i = 0; i < productCount; i++)
    {
        if(products[i].id == id)
        {
            cout << "Product ID already exists!\n";
            return;
        }
    }

    products[productCount].id = id;

    cout << "Enter Product Name (no spaces): ";
    cin >> products[productCount].name;

    cout << "Enter Product Price: ";
    cin >> products[productCount].price;

    productCount++;
    ofstream file("data/products.txt", ios::app);
file << id << " "
     << products[productCount-1].name << " "
     << products[productCount-1].price << endl;
file.close();

    cout << "Product added successfully!\n";
}

void viewProducts()
{
    cout << "\nProduct List\n";

    for(int i = 0; i < productCount; i++)
    {
        cout << products[i].id << " "
             << products[i].name << " "
             << fixed << setprecision(2)
             << products[i].price << endl;
    }
}
void addCustomer()
{
    int id;

    cout << "\nEnter Customer ID: ";
    cin >> id;

    if(customerExists(id))
    {
        cout << "Customer ID already exists!\n";
        return;
    }

    customers[customerCount].id = id;

    cout << "Enter Customer Name: ";
    cin >> customers[customerCount].name;

    cout << "Enter Phone: ";
    cin >> customers[customerCount].phone;

    customerCount++;
    ofstream file("data/customers.txt", ios::app);
file << customers[customerCount-1].id << " "
     << customers[customerCount-1].name << " "
     << customers[customerCount-1].phone << endl;
file.close();

    cout << "Customer added successfully!\n";
}

void viewCustomers()
{
    cout << "\nCustomer List\n";

    for(int i=0;i<customerCount;i++)
    {
        cout << customers[i].id << " "
             << customers[i].name << " "
             << customers[i].phone << endl;
    }
}

double findPrice(int productId)
{
    for(int i=0;i<productCount;i++)
    {
        if(products[i].id == productId)
        return products[i].price;
    }
    return 0;
}

void createOrder()
{
    cout << "\nEnter Order ID: ";
    cin >> orders[orderCount].orderId;

    cout << "Enter Customer ID: ";
    cin >> orders[orderCount].customerId;

    cout << "Enter Product ID: ";
    cin >> orders[orderCount].productId;

    cout << "Enter Quantity: ";
    cin >> orders[orderCount].quantity;

    double price = findPrice(orders[orderCount].productId);

    orders[orderCount].total = price * orders[orderCount].quantity;

    cout << "Total Amount: " << orders[orderCount].total << endl;

    orderCount++;
    ofstream file("data/orders.txt", ios::app);
file << orders[orderCount-1].orderId << " "
     << orders[orderCount-1].customerId << " "
     << orders[orderCount-1].productId << " "
     << orders[orderCount-1].quantity << " "
     << orders[orderCount-1].total << endl;
file.close();

    cout << "Order created successfully!\n";
}

void viewOrders()
{
    cout << "\nOrder List\n";

    for(int i=0;i<orderCount;i++)
    {
        cout << "OrderID: " << orders[i].orderId
             << " CustomerID: " << orders[i].customerId
             << " ProductID: " << orders[i].productId
             << " Quantity: " << orders[i].quantity
             << " Total: " << orders[i].total << endl;
    }
}

bool customerExists(int id)
{
    for(int i = 0; i < customerCount; i++)
    {
        if(customers[i].id == id)
        return true;
    }
    return false;
}

void deleteProduct()
{
    int id;

    cout << "\nEnter Product ID to delete: ";
    cin >> id;

    for(int i=0;i<productCount;i++)
    {
        if(products[i].id == id)
        {
            for(int j=i;j<productCount-1;j++)
            {
                products[j] = products[j+1];
            }

            productCount--;

            cout << "Product deleted successfully!\n";
            return;
        }
    }

    cout << "Product not found!\n";
}

void deleteCustomer()
{
    int id;

    cout << "\nEnter Customer ID to delete: ";
    cin >> id;

    for(int i = 0; i < customerCount; i++)
    {
        if(customers[i].id == id)
        {
            for(int j = i; j < customerCount - 1; j++)
            {
                customers[j] = customers[j + 1];
            }

            customerCount--;

            cout << "Customer deleted successfully!\n";
            return;
        }
    }

    cout << "Customer not found!\n";
}

void loadProducts()
{
    ifstream file("data/products.txt");

    while(file >> products[productCount].id
               >> products[productCount].name
               >> products[productCount].price)
    {
        productCount++;
    }

    file.close();
}

void loadCustomers()
{
    ifstream file("data/customers.txt");

    while(file >> customers[customerCount].id
               >> customers[customerCount].name
               >> customers[customerCount].phone)
    {
        customerCount++;
    }

    file.close();
}

void loadOrders()
{
    ifstream file("data/orders.txt");

    while(file >> orders[orderCount].orderId
               >> orders[orderCount].customerId
               >> orders[orderCount].productId
               >> orders[orderCount].quantity
               >> orders[orderCount].total)
    {
        orderCount++;
    }

    file.close();
}

int main()
{
    loadProducts();
    loadCustomers();
    loadOrders();
    
    int choice;

    while(true)
    {
        cout << "\n=================================\n";
        cout << "SMART RETAIL MANAGEMENT SYSTEM\n";
        cout << "=================================\n";

        cout << "1 Add Product\n";
        cout << "2 View Products\n";
        cout << "3 Delete Product\n";
        cout << "4 Add Customer\n";
        cout << "5 View Customers\n";
        cout << "6 Delete Customer\n";
        cout << "7 Create Order\n";
        cout << "8 View Orders\n";
        cout << "9 Exit\n";

        cout << "\nEnter choice: ";
        cin >> choice;

       if(choice==1)
       addProduct();

       else if(choice==2)
       viewProducts();

       else if(choice==3)
       deleteProduct();   // you still need to create this function

       else if(choice==4)
       addCustomer();

       else if(choice==5)
       viewCustomers();

       else if(choice==6)
       deleteCustomer();

       else if(choice==7)
       createOrder();

       else if(choice==8)
       viewOrders();

       else if(choice==9){
       cout << "Exiting system...\n";
       break;
    }
}

    return 0;
}