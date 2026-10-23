#include <iostream>
using namespace std;

class Device {
    private:
        string ipaddress;
        string operatingsystem;
        string status;
    public:
   void setipaddress(string ip){
        if(ip == ""){
            cout<<"Invalid"<<endl;
              ipaddress ="0.0.0.0";
        }else{
            ipaddress = ip;
        }
    }
    void setoperatingsystem(string os){
        if (os == ""){
            cout<<"Invalid"<<endl;
            operatingsystem = "Unknown";
            
        }else{
            operatingsystem = os;
        }

    }
    void setstatus(string s){
        if (s == "online" || s == "blocked"){
            status = s;
        }
        else{
            cout<<"Invalid"<<endl;
            status = "online";
        }
    }
    string getipaddress(){
        return ipaddress;
    }
    string getoperatingsystem(){
        return operatingsystem;
    }
    string getstatus(){
        return status;
    }
            //Question 5
    Device(){
        setipaddress("0.0.0.0");
        setoperatingsystem("Unknown");
        setstatus("online");
    }
    Device(string ip){
        setipaddress(ip);
        setoperatingsystem("Unknown");
        setstatus("online");
    }
    Device(string ip, string os){
        setipaddress(ip);
        setoperatingsystem(os);
        setstatus("online");
    }
    Device(string ip, string os, string s){
        setipaddress(ip);
        setoperatingsystem(os);
        setstatus(s);
    }
        void show(){
            cout<<"IP :"<<ipaddress
            <<", OS:"<<operatingsystem
            <<", Status:"<<status<<endl;
        }
};
class alert{
    private:
        int alertid;
        int severity;
        string discription;

    public:
        void setalertid(int id){
            if(id > 0){
                alertid = id;

            }
            else{cout<<"Invalid ID!"<<endl;
            alertid = 1;}
        }
        void setseverity(int s){
            if(s >= 1 && s <= 5){
                severity = s;
            }else{cout<<"Invalid severity!"<<endl;
            severity =1;}
        }
        void setdiscription(string d){
            if (d != ""){
                discription =d;

            }else{cout<<"Invalid discription!"<<endl;
                discription = "none";}
        }

        int getalertid(){return alertid;}
        int getseverity(){return severity;}
        string getdiscription(){return discription; }

        alert(){
            setalertid(1);
            setseverity(1);
            setdiscription("none");
        }
        alert(int id, int s, string d){
            setalertid(id);
            setseverity(s);
            setdiscription(d);
        }
        alert(int id){
            setalertid(id);
            setseverity(1);
            setdiscription("none");
        }
        alert(int id, int s){
            setalertid(id);
            setseverity(s);
            setdiscription("none");
        }
    };
int main(){
    Device d1, d2;

    d1.setipaddress("192.186.1.1");
    d1.setoperatingsystem("Windows");
    d1.setstatus("blocked");

    d2.setipaddress("");
    d2.setoperatingsystem("");
    d2.setstatus("online");

    cout<<"Device 1:"<<d1.getipaddress()<<" "<<d1.getoperatingsystem()<<" "<<d1.getstatus()<<endl;
    cout<<"Device 2:"<<d2.getipaddress()<<" "<<d2.getoperatingsystem()<<" "<<d2.getstatus()<<endl;
                    //Question 5
    Device d3("192.186.1.2");
    Device d4("192.186.1.3", "Linux");
    Device d5("192.186.1.4", "macOS", "online");

    d3.show();
    d4.show();
    d5.show();
            //Question 4
     alert a1;
    alert a2(1001);
    alert a3(1003, 3);
    alert a4(1003, 9, "Port scan detected");

    cout<<"Alert ID: "<<a1.getalertid()<<", Severity: "<<a1.getseverity()<<", Description: "<<a1.getdiscription()<<endl;
    cout<<"Alert ID: "<<a2.getalertid()<<", Severity: "<<a2.getseverity()<<", Description: "<<a2.getdiscription()<<endl;
    cout<<"Alert ID: "<<a3.getalertid()<<", Severity: "<<a3.getseverity()<<", Description: "<<a3.getdiscription()<<endl;
    cout<<"Alert ID: "<<a4.getalertid()<<", Severity: "<<a4.getseverity()<<", Description: "<<a4.getdiscription()<<endl;

    return 0;
}