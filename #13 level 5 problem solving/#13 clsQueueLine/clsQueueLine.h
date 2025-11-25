#pragma once
#pragma warning(disable : 4996)

/*
*  
*  - Issue the ticket
*     ticket :
        prefix + number of ticket
        time
        waiting client
        serve time in n Minutes
*           
*  - Print The Queue Info
   - Print the Ticket , Ticket Line (RTL , LTR)
*  - Serive the Customer
*  
* 
*/

#include <iostream>
#include "clsDate.h"
#include <string>
#include <Queue>
#include <stack>

using namespace std;

class clsQueueLine
{
    class clsTicket {
        string _Prefix;
        short _TicketNumber;
        short _WaitingClients;
        short _AverageServeTime;
        string _CreateTime;
    public:
        clsTicket(string prefix, short ticketNumber , short waitingClients ,short clientServeTime) {
            _Prefix = prefix;
            _CreateTime = clsDate::GetSystemDateTimeString();
            _WaitingClients = waitingClients;
            _TicketNumber = ticketNumber;
            _AverageServeTime = waitingClients * clientServeTime;
        }

        string GetPrefix() {
            return _Prefix;
        }

        string GetCreateTime() {
            return _CreateTime;
        }

        short GetTicketNumber() {
            return _TicketNumber;
        }

        short GetAverageServeTime() {
            return _AverageServeTime;
        }

        short GetWaitingClients() {
            return _WaitingClients;
        }

        string GetTicketCode() {
            return _Prefix + "" + to_string(GetTicketNumber());
        }

        string getDateAndTime() {
            time_t t = time(0);
            tm* now = localtime(&t);

            int year = now->tm_year + 1900;
            int month = now->tm_mon + 1;
            int day = now->tm_mday;

            int hour = now->tm_hour;
            int minute = now->tm_min;
            int second = now->tm_sec;
            
            string date = to_string(day) + "/" + to_string(month) + "/" + to_string(year);
            string time = to_string(hour) + ":" + to_string(minute) + ":"+ to_string(second);
            return date + "  -  " +time;
        }

        void PrintTicket() {
            cout << "\t\t\t--------------------------\n";
            cout << "\t\t\t\t" <<  GetTicketCode()  << "\n\n";
            cout << "\t\t\t "  << GetCreateTime() << "\n";
            cout << "\t\t\t "  << "Wating Clients = " << GetWaitingClients() << "\n";
            cout << "\t\t\t "  << "Serve Time In\n";
            cout << "\t\t\t "  << GetAverageServeTime() << " Minutes." << "\n";
            cout << "\t\t\t--------------------------\n";
        }

    };
    short _TotalTicket = 0;

protected:
    string _Prefix;
    queue<clsTicket> _TicketList;
    short _AverageServeTime;

public:

    clsQueueLine(string prefix, short averageServeTime) {
        _Prefix = prefix;
        _AverageServeTime = averageServeTime;
    }

    string GetPrefix() {
        return _Prefix;
    }

    short GetAverageServeTime() {
        return _AverageServeTime;
    }

    short GetWaitingClients() {
       return _TicketList.size();
    }

    short GetServeClients() {
        return _TotalTicket - GetWaitingClients();
    }

    void PrintInfo() {
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t\tQueue Info";
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t" << "Prefix         = " << _Prefix << "\n";
        cout << "\t\t\t" << "Total Tickets  = " << _TotalTicket<< "\n";
        cout << "\t\t\t" << "Served Client  = " << GetServeClients() << "\n";
        cout << "\t\t\t" << "Wating Clients = " << GetWaitingClients() << "\n";
        cout << "\t\t\t _________________________\n";
    }

    void IssueTicket() {
        _TotalTicket++;
        clsTicket ticket = clsTicket(_Prefix, _TotalTicket, GetWaitingClients(), _AverageServeTime);
        _TicketList.push(ticket);
    }

    void PrintTicketsLineRTL() {
        cout << "\n\t\t\t" << "Tickets: ";

        queue<clsTicket> readQueue = _TicketList;
        while (!readQueue.empty()) {
            cout << readQueue.front().GetTicketCode() << " <-- ";
            readQueue.pop();
        }
        
        cout <<endl <<endl;
    }

    void PrintTicketsLineLTR() {
        cout << "\t\t\t" << "Tickets: ";

        queue<clsTicket> readQueue = _TicketList;
        stack<clsTicket> readStack;

        while (!readQueue.empty()) {
            readStack.push(readQueue.front());
            readQueue.pop();
        }


        while (!readStack.empty()) {
            cout << readStack.top().GetTicketCode() << " --> ";
            readStack.pop();
        }

        cout << endl;
    }

    bool ServeNextClient() {
        if (GetWaitingClients() <= 0) {
            cout << "No Client To Serve\n";
            return false;
        }

        _TicketList.pop();
        return true;
    }

    void PrintAllTickets() {
        cout << "\n\t\t\t _________________________\n";
        cout << "\n\t\t\t\t---Tickets---";
        cout << "\n\t\t\t _________________________\n";
        queue<clsTicket> readQueue = _TicketList;
        while (!readQueue.empty()) {
            readQueue.front().PrintTicket();
            readQueue.pop();
        }
    }

};