#include <iostream>
#include<conio.h>
#include<fstream>
#include<map>

using namespace std;
class BRS{
private:
    map<string,string>ticketBooking[6];

public:
    BRS();
    void bookTickets();
    void showTickets(string id);
    void cancelTickets(string id);
    void record();
    void customer();
    void show();

};




void BRS::bookTickets(){
    if(ticketBooking[0].size()<40)
    {
        string info[6]={"","","","","",""};
        cout<<"Enter Your Phone Number: ";
        cin>>info[0];
        cout<<"Enter Your Name: ";
        cin>>info[1];
        cout<<"LEAVING FROM: ";
        cin>>info[2];
        cout<<"Going To: ";
        cin>>info[3];
        cout<<"Date of Journey: ";
        cin>>info[4];
        cout<<"Enter your Seat Number: ";
        cin>>info[5];

        if(ticketBooking[0].find(info[0])==ticketBooking[0].end()){
            for(int x=0;x<6;x++){
                ticketBooking[x].insert({info[0],info[x]});
            }
            cout<<"\t\t\t You have Successfully Create a Account.\n\t\t\t"<<endl;
        }
        else{
            cout<<" \t\t\tThis Phone Number is Already Registered.\n\t\t\t";
        }

    }
    else
    {
        cout<<"\t\t\tThere are only 40 seat available in bus!!\n";
    }



}


void BRS::showTickets(string id){
    if(ticketBooking[0].find(id)==ticketBooking[0].end()){
            cout<<"\t\t\tCustomer not found!\n\t\t\t"<<endl;

    }
    else{
        cout<<"\t\t\tCustomer has Found\n\t\t\t"<<endl;
        for(int x=0;x<6;x++){
            cout<<"\t\t\t"<<ticketBooking[x][id]<<endl;
        }
    }

}


void BRS::cancelTickets(string id){
    if(ticketBooking[0].find(id)==ticketBooking[0].end()){
        cout<<"\t\t\tTicket not found for delete!\n\t\t\t"<<endl;
    }
    else{
        for(int x=0;x<6;x++){
            ticketBooking[x].erase(id);
        }
        cout<<"\t\t\tDelete tickets Successfully\n\t\t\t"<<endl;
    }

}

BRS::BRS(){
   record();
}

void BRS::record (){
    ifstream data;
    data.open("data.txt");
    while(!data.eof()){

        string info[6]={"","","","","",""};
        getline(data,info[0]);
        getline(data,info[1]);
        getline(data,info[2]);
        getline(data,info[3]);
        getline(data,info[4]);
        getline(data,info[5]);


    }
    data.close();
}

void BRS::show(){
   for(auto i:ticketBooking[0]){

        cout<<ticketBooking[0][i.first]<<endl;
        cout<<ticketBooking[1][i.first]<<endl;
        cout<<ticketBooking[2][i.first]<<endl;
        cout<<ticketBooking[3][i.first]<<endl;
        cout<<ticketBooking[4][i.first]<<endl;
        cout<<ticketBooking[5][i.first]<<endl;

        cout<<"-------------------------"<<endl;
    }

}

void BRS::customer(){
    ofstream data;
    data.open("data.txt");

    string info[6]={"","","","","",""};
    for(auto i: ticketBooking[0]){

        data<<ticketBooking[0][i.first]<<endl;
        data<<ticketBooking[1][i.first]<<endl;
        data<<ticketBooking[2][i.first]<<endl;
        data<<ticketBooking[3][i.first]<<endl;
        data<<ticketBooking[4][i.first]<<endl;
        data<<ticketBooking[5][i.first]<<endl;
    }
    data.close();
}




int main(){

BRS booking;
int choice;
string temp;
while(true){
    cout<<"\t\t\t\t****Sky Line Bus Service****"<<endl<<endl;
    cout<<"\n\t\t\t 1.Book Tickets\n\t\t\t"
    <<" 2.Show Ticket \n\t\t\t"
    <<" 3.Cancel Tickets\n\t\t\t"
    <<" 4.Exit\n\t\t\t"<<endl;

    cout<<"\n\t\t\tEnter your choice:-> ";
    cin>>choice;
    switch(choice){
        case 1: booking.bookTickets();

        break;

        case 2:
            cout<<"\t\t\tEnter your Phone Number:";
            cin>>temp;
            booking.showTickets(temp);
          break;

        case 3:
            cout<<"\t\t\tEnter your Phone Number:";
            cin>>temp;
            booking.cancelTickets(temp);
          break;

        case 4:
            cout<<"\t\t\tThanks for using my application\n\t\t\t";
            break;



        default :
            cout<<"\t\t\t wrong choice";


    }

}

getch();

}

