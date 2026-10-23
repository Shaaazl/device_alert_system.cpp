#include <iostream>
#include <string>
using namespace std;

class product{
    private:
    string productCode;
    string name;
    double price;
    int stock;

    public:
    void setproductCode(string c){
        if(c ==""){
            cout<<"Invalid product code"<<endl;
            productCode = "Unknown";
        }else{
            productCode = c;
        }

    }
    void setname(string n){
        if(n == ""){
            cout<<"Invalid name"<<endl;
            name = "Unnamed";
        }else{
            name = n;
        }
    }
    void setprice(double p){
        if(p <= 0){
            cout<<"Invalid price"<<endl;
            price = 1.0;
        }else{
            price = p;
        }
    }
    void setstock(int s){
        if(s < 0){
            cout<<"Invalid stock"<<endl;
            stock = 0;
        }else{
            stock = s;
        }
    }

    string getproductCode(){return productCode;}
    string getname(){return name;}
    double getprice(){return price;}
    int getstock(){return stock;}

        product(){
            setproductCode("Unknown");
            setname("Unnamed");
            setprice(1.0);
            setstock(0);
        }

        product(string c, string n, double p, int s){
            setproductCode(c);
            setname(n);
            setprice(p);
            setstock(s);
        }

        product(string c, string n){
            setproductCode(c);
            setname(n);
            setprice(1.0);
            setstock(0);
        }

        void showdetails(){
            cout<<"Product["<<productCode<<"]"<<name<<"|price:"<<price<<"|stock:"<<stock<<endl;
        }

        bool isinstock(){
            return stock > 0;
        }

        void sell(int unit){
            if(unit <=0){
                cout<<"Invalid unit"<<endl;
            }else if(unit > stock){
                cout<<"Not enough stock"<<endl;
            }else if(unit <= stock){
                stock -= unit;
                cout<<"Sold"<<unit<<"units of"<<name<<endl;
            }
        }


};

class coupon{
    private:
    string couponCode;
    int discountpercent;
    int expiryyear;

    public:
    void setcouponCode(string c){
        if(c == ""){
            cout<<"Invalid coupon code"<<endl;
            couponCode = "Unknown";
        }else{
            couponCode = c;
        }
    }
    void setdiscountpercent(int d){
        if(d < 1 || d > 90){
            cout<<"Invalid discount percent"<<endl;
            discountpercent = 1;
        }else{
            discountpercent = d;
        }
    }

    void setexpiryyear(int e){
       expiryyear = e;
    }
        string getcouponCode(){return couponCode;}
        int getdiscountpercent(){return discountpercent;}
        int getexpiryyear(){return expiryyear;}

        coupon(){
            setcouponCode("Unknown");
            setdiscountpercent(1);
            setexpiryyear(2025);
        }

        coupon(string c, int d, int e){
            setcouponCode(c);
            setdiscountpercent(d);
            setexpiryyear(e);

        }
            void showdetails(){
        cout<<"Coupon["<<couponCode<<"]"<<discountpercent<<"% off, expires in"<<expiryyear<<endl;
            }
            bool isvalid(){
                return expiryyear >= 2025;
            }
};

int main(){
    cout<<"-----Product------"<<endl;
    product p1;
    product p2("P001", "Laptop", 1500.0, 10);
    product p3("P002", "Mouse");
    product p4("P003", "Keyboard", -100.0, -4);

    p1.showdetails();
    p2.showdetails();
    p3.showdetails();
    p4.showdetails();

    cout<<"p2 is in stock: "<<(p2.isinstock() ? "yeas" : "no")<<endl;
    cout<<"p3 is in stock:"<<(p3.isinstock() ? "yeas " : "no")<<endl;
    p2.sell(5);
    p3.sell(3);

    cout<<"-----Coupon-----"<<endl;
    coupon c1;
    coupon c2("C001", 20, 2025);
    coupon c3("c002", 50, 2026);
    
    c1.showdetails();
    c2.showdetails();
    c3.showdetails();

    cout<<"c2 is valid:"<<(c2.isvalid() ? "yeaas" : "no")<<endl;
    cout<<"c3 is valid:"<<(c3.isvalid() ? "yeas" : "no")<<endl;

    return 0;
}