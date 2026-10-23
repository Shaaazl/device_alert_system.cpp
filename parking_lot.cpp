#include <iostream>
#include <string>
using namespace std;

class parkingslot{
    private:
    int slotnumber;
    int floor;
    string status;
    public:
    void setslotnumber(int n){
            if (n > 0){
                slotnumber = n;

            }else{
                cout<<"Invalid slot number"<<endl;
                slotnumber = 1;
            }
    }
    void setfloor(int f){
        if(f >= 0){
            floor = f;
        }else{ cout<<"Invalid floor"<<endl;
        floor = 0;}
    }
        void setstatus(string s){
        if(s == "occupied" || s == "free"){
            cout<<"Status set to:"<<s<<endl;
            status = "0";
        }else{ cout<<"invalid status"<<endl;
        status = "free";
        }
    }

        int getslotnumber(){return slotnumber;}
        int getfloor(){return floor;}
        string getstatus(){return status;}

        parkingslot(){
            setslotnumber(1);
            setfloor(0);
            setstatus("free");
        }

        parkingslot(int n, int f, string s){
            setslotnumber(n);
            setfloor(f);
            setstatus(s);
        }

        parkingslot(int n){
            setslotnumber(n);
            setfloor(0);
            setstatus("free");
        }

        void occupy(){
            status = "occupied";
        }
        void release(){
            status = "free";
        }

        void showdetails(){
            cout<<"slotnumber:"<<slotnumber
            <<"\n floor:"<<floor
            <<"\n status:"<<status<<endl;
        }

};

class vehicle{
    private:
    string platenumber;
    string type;
    double hourlycharge;

    public:
    void setplatenumber(string p){
        if(p != ""){
            platenumber = p;
        }else{ cout<<"invalid plate number"<<endl;
            platenumber = "unknown";}
    }

    void settype(string t){
        if(t == "car" || t == "bike"){
            type = t;
        }else{
            cout<<"Invalid type"<<endl;
            type = "Unknown";
        }
    }

    void sethourlycharge(double h){
        if(h > 0){
            hourlycharge = h;
        }else{
            cout<<"Invalid charge"<<endl;
            hourlycharge = 1.0;
        }
    }

    string getplatenumber(){return platenumber;}
    string gettype(){return type;}
    double gethourlycharge(){return hourlycharge;}

    vehicle(){
        setplatenumber("unknown");
        settype("Unknown");
        sethourlycharge(1.0);
    }

    vehicle(string p, string t, double h){
        setplatenumber(p);
        settype(t);
        sethourlycharge(h);
    }

    vehicle(string p, string t){
        setplatenumber(p);
        settype(t);
         sethourlycharge(1.0);
    }

    void showdetails(){
        cout<<"Plate number:"<<platenumber<<
        "\n | Vehicle type:"<<type<<
        "\n | Charges:"<<hourlycharge<<endl;
    }

    double calculatecharge(int hour){
        return hour*hourlycharge;
    }
};

int main(){
    cout<<"-----Parking-----"<<endl;
    parkingslot s1;
    parkingslot s2(3, 6, "free");
    parkingslot s3(7);
    parkingslot s4(5, 6, "occupied");

    s1.showdetails();
    s2.showdetails();
    s3.showdetails();
    s4.showdetails();

    s2.occupy();                       
    s2.showdetails();
    s2.release();                       
    s2.showdetails();

    s3.occupy();                       
    s3.showdetails();
    s3.release();                       
    s3.showdetails();

    s4.occupy();                       
    s4.showdetails();
    s4.release();                       
    s4.showdetails();

    cout<<"-----Vehicle-----"<<endl;

    vehicle v1;
    vehicle v2("BEP-472", "car", 57);
    vehicle v3("LEK-53", "bike", 43);

    v1.showdetails();
    v2.showdetails();
    v3.showdetails();

    cout << "v2 charge for 3 hours: " << v2.calculatecharge(3) << endl;
    cout << "v3 charge for 2 hours: " << v3.calculatecharge(2) << endl;

    return 0;
    
}