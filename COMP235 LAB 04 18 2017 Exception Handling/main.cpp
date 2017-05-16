# define prog 4


#if(prog == 1)
// EXERCISE 1
// simple exceptions
#include <iostream>
#include <stdexcept>
using namespace std;

// simple check
// index of array
// out of bounds error

// use try throw catch to handle array out of range
// test by going above or below array indicies

int main() {
    int arr[] = { 3, 5, 7, 1, 9 };
    cout << "Enter an array index: ";
    int arr_idx = 0;
    cin >> arr_idx;
    try
    {
        // hard code array range check
        if (arr_idx < 0 || arr_idx > 4)
        {
            exception e;
            throw e;
        }
        cout << arr[arr_idx] << endl;
    }
    catch (exception e)
    {
        cout << e.what() << endl;
        exit(1);
    }
    return 0;
}

#elif(prog == 2)
// EXERCISE 2

#include <iostream>
#include <string>
using namespace std;

class PopEmptyStackException {
public:
    PopEmptyStackException() {}
    PopEmptyStackException(string p) { message = p; }
    string what() { return message; }
    string message;
};

class PushToFullStackException {
public:
    PushToFullStackException() {}
    PushToFullStackException(string p) { message = p; }
    string what() { return message; }
    string message;
};

class Stack {
public:
    Stack() {
        for (int i = 0; i < m_capacity; i++) {
            m_arr[i] = NULL;
        }
    };
    void push(int value) {
        // cout << "\nPush called. Push a member onto stack\n";
        try {
            if (m_size >= m_capacity) {
                throw PushToFullStackException("Stack is full, try something else!\n");
            } else {
                m_arr[m_size++] = value;
            }
        }
        catch (PushToFullStackException e) {
            cout << e.what() << endl;
        }
    };
    void pop() {
        // cout << "\nPop called to pop off last memember of stack \n";
        try {
            if (!(m_size > 0)) {
                throw PopEmptyStackException("Array not bigger tha zero. Nothing to pop off!\n");
            } else {
                // actually pop something off the stack, it's ok
                m_arr[m_size-1] = NULL;
                m_size--;
            }
        }
        catch (PopEmptyStackException e) {
            cout << e.what() << endl;
        }
    };
private:
    int m_arr[3];
    int m_capacity = 3;
    int m_size = 0;
};

int main() {
    
    cout << "Push & Pop Stack Exception Examples" << endl;
    cout << endl;
    // test code
    Stack myStk; //Capacity of 3
    cout << "Popping right away... ";
    myStk.pop();
    cout << "Pushing 1st item... ";
    myStk.push(1);
    cout << endl;
    cout << "Pushing 2nd item... ";
    myStk.push(2);
    cout << endl;
    cout << "Pushing 3rd item... ";
    myStk.push(3);
    cout << endl;
    cout << "Pushing 4th item... ";
    myStk.push(4);
    cout << endl;
    cout << "Popping to make room... ";
    myStk.pop();
    myStk.pop();
    cout << endl;
    cout << "Pushing 5th item... ";
    myStk.push(5);
    cout << endl;
    
    return 0;
}

#elif(prog == 3)
// EXERCISE 3

// create a ProductNotFound exception class
// getProductID should throw Exception
// but not handle it

// Exception handling is left to caller
// i.e. main function

// Two arrays
// one stores products
// one stores product IDs

// function getProductID takes input as:
// two arrays
// length of the arrays
// and target product to search for
// then loops throug product name array
// if match is found, return corresponding product ID

// PROBLEM
// getProductID function returns
// special error code -1
// if target name is not found

// SOLUTION
// rewrite the program so it throws an appropriate Exception
// when product is not found instead of  returning -1

#include <iostream>
#include <string>
using namespace std;

class ProductNotFoundException
{
public:
    //TO DO: constructor(s)
    ProductNotFoundException() {}
    ProductNotFoundException(string msg) {message = msg;}
    void what()
    {
        //TO DO: return exception message
        cout << "EXCEPTION: Product " << message << " not found!" << endl;
    }
private:
    //TO DO: declare message variable
    string message;
};

//Given function in the question. You need to throw a
//     ProductNotFoundException instead of returning -1
void getProductID(int ids[], string names[], int numProducts, string target)
{

    try {
        
        bool productFound = false;
        
        for (int i = 0; i < numProducts; i++)
        {
            if (names[i] == target) {
                cout << ids[i] << endl;
                productFound = true;
            }
        }
        // woops
        if (!productFound) {
            throw ProductNotFoundException(target);
        }
        
    } catch (ProductNotFoundException e) {
        e.what();

    }
}

//Given test code in the question. You need to provide exception
//     handling code in this main function
int main()
{
    int productIds[]{ 4, 5, 8, 10, 13 };
    string products[]{ "computer", "flash drive",
        "mouse", "printer", "camera" };
    
    cout << "Get Product IDs" << endl;
    cout << "Mouse:\t\t\t ";
    getProductID(productIds, products, 5, "mouse");
    cout << "Camera:\t\t\t ";
    getProductID(productIds, products, 5, "camera");
    cout << "Flash Drive:\t ";
    getProductID(productIds, products, 5, "flash drive");
    cout << "Laptop:\t\t\t ";
    getProductID(productIds, products, 5, "laptops");
    cout << "Computer:\t\t ";
    getProductID(productIds, products, 5, "computer");
    
    cout << endl;
    
    return 0;
    
}

#elif(prog == 4)

/*
 Write code to incude these exceptions:
 √ overflow_error
 √ underflow_error
 √ length_error
 √ out_of_range
 */

#include <iostream>
#include <string>
using namespace std;

// underflow error
class PopEmptyStackException {
public:
    PopEmptyStackException() {}
    PopEmptyStackException(string p) { message = p; }
    string what() { return message; }
    string message;
};

// overflow error
class PushToFullStackException {
public:
    PushToFullStackException() {}
    PushToFullStackException(string p) { message = p; }
    string what() { return message; }
    string message;
};

// length error
class StringLengthException {
public:
    StringLengthException() {}
    StringLengthException(string p) { message = p; }
    string what() { return message; }
    string message;
};

// out of range error
class OutOfRangeException {
public:
    OutOfRangeException() {}
    OutOfRangeException(string p) { message = p; }
    string what() { return message; }
    string message;
};


// proudct not found error
class ProductNotFoundException
{
public:
    ProductNotFoundException() {}
    ProductNotFoundException(string msg) {message = msg;}
    void what()
    {
        //TO DO: return exception message
        cout << "EXCEPTION: Product " << message << " not found!" << endl;
    }
private:
    string message;
};

struct Product {
    int product_id;
    string product_name;
};

class Stack {
public:
    Stack() {
        for (int i = 0; i < m_capacity; i++) {
            m_arr[i].product_id = NULL;
            m_arr[i].product_name = "";
        }
    };
    void push(int value, string name) {
        cout << "\nPush called. Push a member onto stack\n";
        try {
            if (name.length() > 80) {
                throw StringLengthException("EXC: Product Name Too Long!");
            }
            try {
                if (m_size >= m_capacity) {
                    throw PushToFullStackException("Stack is full, try something else!\n");
                } else {
                    m_arr[m_size].product_id = value;
                    m_arr[m_size].product_name = name;
                    m_size++;
                }
            }
            catch (PushToFullStackException e) {
                cout << e.what() << endl;
            }
        } catch (StringLengthException e) {
            cout << e.what() << endl;
        }

    };
    void pop() {
        cout << "\nPop called to pop off last memember of stack \n";
        try {
            if (!(m_size > 0)) {
                throw PopEmptyStackException("Array not bigger tha zero. Nothing to pop off!\n");
            } else {
                // actually pop something off the stack, it's ok
                m_arr[m_size-1].product_id = NULL;
                m_arr[m_size-1].product_name = "";
                m_size--;
            }
        }
        catch (PopEmptyStackException e) {
            cout << e.what() << endl;
        }
    };
    void getProductByIdx(int arr_idx) {
        cout << "\nGet product by Index Called \n";
        try {
            // hard code array range check
            if (arr_idx > 4) {
                throw OutOfRangeException("EXC: Query out of range for product list~!\n");
            } else {
                cout << "Returning product info (placeholder)" << endl;
            }
        }
        catch (OutOfRangeException e)
        {
            cout << e.what() << endl;
        }
    };
private:
    Product m_arr[5];
    int m_capacity = 5;
    int m_size = 0;
};

void getProductID(int ids[], string names[], int numProducts, string target)
{
    
    try {
        
        bool productFound = false;
        
        for (int i = 0; i < numProducts; i++)
        {
            if (names[i] == target) {
                cout << ids[i] << endl;
                productFound = true;
            }
        }
        // woops
        if (!productFound) {
            throw ProductNotFoundException(target);
        }
        
    } catch (ProductNotFoundException e) {
        e.what();
        
    }
}

void listProductIds(int productIds [], string products []) {

    cout << "Get Product IDs" << endl;
    cout << "Mouse:\t\t\t ";
    getProductID(productIds, products, 5, "mouse");
    cout << "Camera:\t\t\t ";
    getProductID(productIds, products, 5, "camera");
    cout << "Flash Drive:\t ";
    getProductID(productIds, products, 5, "flash drive");
    cout << "Laptop:\t\t\t ";
    getProductID(productIds, products, 5, "laptops");
    cout << "Computer:\t\t ";
    getProductID(productIds, products, 5, "computer");
}

int main()
{
    
    int productIds[]{ 4, 5, 8, 10, 13 };
    string products[]{ "computer", "flash drive",
        "mouse", "printer", "camera" };
    
    Stack productStack;
    
    for (int i = 0; i < 5; i++) {
        productStack.push(productIds[i],products[i]);
    }
    
    
    bool running = true;
    while (running) {
        
        cout << "Program running - induce some exceptions!\n";
        
        char inputChoice = 0;
        
        cout << "Make a choice to test exceptions:\n" <<
        "[1] PUSH to overflow_error\n" <<
        "[2] POP to underflow_error\n" <<
        "[3] PUSH LONG NAME to length_error\n" <<
        "[4] QUERY > 5 out_of_range\n" <<
        "[X] X to Quit\n";
        cout << "Enter choice: [1] [2] [3] [4] [X]: ";
        
        cin >> inputChoice;
        
        string newProductName = "";
        int productLookUpIdx = 0;
        
        switch (inputChoice) {
            case '1':
                cout << "Choice no 1 made. PUSH to overflow_error\n";
                productStack.push(99, "FOO");
                break;
            case '2':
                cout << "Choice no 2 made. POP to underflow_error\n";
                productStack.pop();
                break;
            case '3':
                cout << "Choice no 3 made. length_error\n";
                cout << "Add a new product name: \n";
                cin >> newProductName;
                productStack.push(99, newProductName);
                break;
            case '4':
                cout << "Choice no 4 made. out_of_range\n";
                cout << "Enter a product index to inspect: ";
                cin >> productLookUpIdx;
                productStack.getProductByIdx(productLookUpIdx);
                break;
            case 'X':
                cout << "Choice X made. Ending program!\n";
                running = false;
                break;
            default:
                cout << "Invalid choice, try again.\n";
                break;
        }
        
    }
    
    cout << "Program ended!\n";
    
    cout << endl;
    
    return 0;
    
}

#endif












