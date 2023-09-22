//Product, Itms, Cart
#include<string>
#include<unordered_map>
using namespace std;

//forward classes
class Item;
class Cart;

class Product{ //product info
    int id;    //they are private members
    string name;
    int price;

public:
    Product(){}// def constructors
    //para const
    Product(int u_id, string name, int price)  //constructor when new product is formed
    {
        id = u_id;   //ASSIGNMENT 
        this -> name = name;  //this used to use the name from product class
        this -> price = price;
    }     

    string getDisplayName()  // to dislplay the name and price
    {
        return name + ": Rs." + to_string(price) + "\n";
    }

    string getShortName()
    {
        return name.substr(0,1); //only value at index 0
    }
    friend class Item;  //price is private data member of class product by this we use pric in class item
    friend class Cart;
};

class Item{
    //init def const in class product to access this prod object
    Product prod;  //if new product is created and it cant be change
    int quantity;

public:

    Item(){} //dummy const used in map
    //costructor using a Init List
    Item(Product p, int q): prod(p), quantity(q){}   //INITIALSE LIST

    int getItemPrice(){
        return quantity * prod.price; //product price is used
    }    
    
    string getItemInfo()
    {
        return to_string(quantity) + " x " + prod.name + " Rs." + to_string(quantity * prod.price) + "\n";
    }
    friend class Cart;
};

class Cart{
    //cart is collection of items
    //ADD
    //view 
    //cart is empty or not
    unordered_map<int, Item> items;  //item is private member

public:

    void addProduct(Product prod) //Product is data type 
    {
        if(items.count(prod.id) == 0) //id in product class
        {  //if first time item is add
            Item newItem(prod, 1);//prod and quantity
            items[prod.id] = newItem;
        }

        else{
            items[prod.id].quantity += 1; //else incerease quantity
        }
    }    

    int getTotal()
    {
        int total = 0;
        for(auto itemPair: items)
        {
            auto item = itemPair.second;
            total += item.getItemPrice();
        }
        return total;
    }

    string viewCart()
    {
        if(items.empty())
        {
            return "Cart is empty"; 
        }

        string itemizedList;
        int cart_total = getTotal();

        for(auto itemPair: items)
        {
            auto item = itemPair.second;
            itemizedList.append(item.getItemInfo());
        }

        return itemizedList + "\n Total Amount: Rs. " + to_string(cart_total) + '\n';
    }

    bool isEmpty()
        {
            return items.empty(); // item(map) is privte number
        }
};

