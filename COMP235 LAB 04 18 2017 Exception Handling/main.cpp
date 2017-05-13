# define prog 1


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

class PopEmptyStackExeption {
public:
    PopEmptyStackExeption() {}
    PopEmptyStackExeption(string p) { message = p; }
    string what() { return message; }
    string message;
};

class PushToFullStackExeption {
public:
    PushToFullStackExeption() {}
    PushToFullStackExeption(string p) { message = p; }
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
                throw PushToFullStackExeption("\nStack is full, try something else!\n");
            } else {
                m_arr[m_size++] = value;
            }
        }
        catch (PushToFullStackExeption e) {
            cout << e.what() << endl;
        }
    };
    void pop() {
        // cout << "\nPop called to pop off last memember of stack \n";
        try {
            if (!(m_size > 0)) {
                throw PopEmptyStackExeption("\nArray not bigger tha zero. Nothing to pop off!\n");
            } else {
                // actually pop something off the stack, it's ok
                m_arr[m_size--] = NULL;
            }
        }
        catch (PopEmptyStackExeption e) {
            cout << e.what() << endl;
        }
    };
private:
    int m_arr[3];
    int m_capacity = 3;
    int m_size = 0;
};

int main() {
    
    cout << "Push pop stack exeptions";
    
    // test code
    Stack myStk; //Capacity of 3
    cout << "Popping right away.\n";
    myStk.pop();
    cout << "\nPushing 1st item.";
    myStk.push(1);
    cout << "\nPushing 2nd item.";
    myStk.push(2);
    cout << "\nPushing 3rd item.";
    myStk.push(3);
    cout << "\nPushing 4th item.";
    myStk.push(4);
    
    return 0;
}

#elif(prog == 3)
// EXERCISE 3

// create a ProductNotFound exception class
// getProductID should throw exeption
// but not handle it

// exeption handling is left to caller
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
// rewrite the program so it throws an appropriate exeption
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
    
    // try catch
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
    
    getProductID(productIds, products, 5, "mouse");
    getProductID(productIds, products, 5, "camera");
    getProductID(productIds, products, 5, "flash drive");
    getProductID(productIds, products, 5, "laptops");
    getProductID(productIds, products, 5, "computer");
    
    cout << endl;
    
    return 0;
    
}

#endif

