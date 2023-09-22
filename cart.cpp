#include<iostream>
#include "datamodel.h"
#include<vector>
using namespace std;

vector<Product> allProducts = {
    Product(1, "apple", 22),
    Product(2, "aghyu", 20),
    Product(3, "orange", 25),
    Product(4, "guava", 30),
    Product(5, "banana", 35),
    Product(6, "laptop", 40),
    Product(7, "mobile", 50),
    Product(8, "camera", 65),
    Product(9, "headphones", 62),
    Product(10, "shoes", 77),
}; 

Product* chooseProduct() //pointer to return null if no items choose 
{   
    //Display the list of products

    //string prodList;
    cout<<"Available Products "<<endl;

    for(auto p: allProducts)
    {
        cout<<p.getDisplayName();
    }

    //cout<<prodList<<endl;
    cout<<"_______________"<<endl;

    string choice;
    cin>>choice;

    for(int i = 0; i < allProducts.size(); i++)
    {
        if(allProducts[i].getShortName() == choice)
        {
            return &allProducts[i]; //referece of the products
        }
    }
    cout<<"Product not Found:"<<endl;
    return NULL;
}
    bool checkout(Cart &cart) //dont make copy of cart so by referece
    {
        if(cart.isEmpty())  //declare in .h file
        {
            return false;
        }

        int total = cart.getTotal();
        cout<<"PAY IN CASH: ";

        int paid;
        cin>>paid;

        if(paid >= total)
        {
            cout<<"Change: "<<paid - total<<endl;
            cout<<"___THANK YOU FOR SHOPPING!___";
            return true;
        }

        else
        {
            cout<<"NOT ENOUGH CASH!";
            return false;
        }
    }

int main()
{
    char action;
    Cart cart; // object of cart
    while(true)
    {
        cout<<"Select an Action - (press a, v and c only)\n 1. (a)dd Item \n 2. (v)iew cart \n 3. (c)heckout"<<endl;
        cin>>action;

        if(action == 'a')
        {
            //add to cart
            //view all products + choose products + add to the cart
            Product* prod = chooseProduct();
            if(prod != NULL)
            {
                cout<<"Added to the Cart "<<prod -> getDisplayName()<<endl;
                cart.addProduct(*prod);
            }
        }
        else if(action == 'v')
        {   //view the cart
            cout<<"_____________"<<endl;
            cout<<cart.viewCart();
            cout<<"_____________"<<endl;
            
        }

        else
        { //checkout
            cart.viewCart(); //cart is object
            if(checkout(cart)) //if checkout is successful
            {
                break;
            }

        }
    }
    return 0;
}


