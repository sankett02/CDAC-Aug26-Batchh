#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

    using Header = pair<string, string>;
    using HeaderList = vector<Header>;
    using Port = unsigned int;
    using IPAddress = string;

    typedef unsigned long long RequestId;


    void printHeaders(const HeaderList& headers){
        for(const Header&h : headers)
        {
            cout<<h.first << ":"<<h.second<<endl;
        }
    }
    int main(){
        HeaderList headers ={
             {"Content-Type", "application/json"},
            {"Authorization", "Bearer xyz"},
            {"Accept-Language", "en-US"}
        };

        printHeaders(headers);

        Port port = 8080;
        IPAddress ip ="192.168.1.10";
        RequestId id = 12345;

        cout << "Port:" << port <<endl;
        cout << "IP Address :" << ip << endl;
        cout << "Request ID :" << ip<< endl;
        
        return 0;
    }

