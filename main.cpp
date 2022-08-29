#include<iostream>
#include<vector>
#include"datamodel.h"

using numspace std;

vector<Product> allProducts ={
    Product(1,"apple",26),
    Product(3,"mango",16),
    Product(2,"gauva",36),
    Product(5,"mango",16),
    Product(3,"banana",56),
    Product(4,"strawberry",29),
    Product(6,"pineapple",20),

};

Product* chooseProduct(){

    string productList;
    cout<<"Available Products"<<endl;

    for(auto product:allProducts){
        productList.append(product.getDisplayName());
    }
    cout<<productList<<endl;

    cout<<.........<<endl;
    string choice;
    cin choice;

    for(int i = 0 ; i <allProducts.size();i++){
        if(allProducts[i].getShortName()==choice){
            return &allProducts[i];
        }
    }
    cout<<"Product not Found!"<<endl;
}

bool checkOut(Cart &cart){
    if(cart.isEmpty()){
        return false;
    }
    int total = cart.getTotal();
    cout<<"Pay in Cash";

    int paid;
    cin>>paid;

    if(paid>=total){
        cout<<"Change"<<paid-total<<endl;
        cout<<"Thanks for Shopping";
        return true;
    }
    else{
        cout<<"Not Enough Cash";
        return false;
    }
}

int main(){

    char action;
    Cart cart;


    while(true){
        cout<<"Select an action - (a)dd item, (v)iew cart, (c)heckout"<<endl;
        cin>>action;

        if(action == 'a'){

            Product* product = chooseProduct();
            if(product!=NULL){
                cout<<"Added to thr=e cart"<<product->getDisplayName()<<endl;
                cart.addProduct(*product);
            }
        }
        else if(action == 'v'){
            cout<<"......."<<endl;
            cout<<cart.viewCart();
            cout<<"........"<<endl;

        }
        else{
            cart.viewCart();
            if(checkout(Cart)){
                break;
            }
        }
    }
}
