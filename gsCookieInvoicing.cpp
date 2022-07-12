#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;

int getCookies(string cookietype, int max_order); // cookie input function prototype

int main()
{
    int thin_mints;
    int lemonUps;
    int lemonades;
    int samoas;
    int tagalongs;
    int dosidos;
    int trefoils;
    int thanksalot;
    int toffee;
    int caramel;
    
    int max_order = 10; // 10 cookies max per type
    int orderNumber = 0; // initial order number
    double cPrice = 5.0; // $5 per order
    
    string qtyStr = "(0-10): ";
    string cookie1 = "Enter the number of Thin Mints " + qtyStr;
    string cookie2 = "Enter the number of Lemon-Ups " + qtyStr;
    string cookie3 = "Enter the number of Lemonades " + qtyStr;
    string cookie4 = "Enter the number of Samoas " + qtyStr;
    string cookie5 = "Enter the number of Tagalongs " + qtyStr;
    string cookie6 = "Enter the number of Do-si-dos " + qtyStr;
    string cookie7 = "Enter the number of Trefoils " + qtyStr;
    string cookie8 = "Enter the number of Thanks-A-Lot " + qtyStr;
    string cookie9 = "Enter the number of Toffee-tastic " + qtyStr;
    string cookie10 = "Enter the number of Caramel Chocolate Chip " + qtyStr;
    string fname, lname, address, cityStZip;

    bool moreOrders = true;

    ofstream outFile; // This will open a .txt file named 'na_orders' with an invoice for the cookie orders

    // Open the output file
    outFile.open ("na_orders.txt", ios::out); 
    while (moreOrders)
    {
        fname = lname = address = cityStZip = "";

        cout << "Enter the customers first and last name (or q to quit): " <<endl;
        cin >> fname;
        if (fname == "q")
            break;

        orderNumber ++;
        cin >> lname;
        cin.ignore();
        cin.clear();

        while (address.length() == 0)
        {
            cout << "Enter the " << fname << " " << lname << "'s address: ";
            getline(cin, address);
        }

        while (cityStZip.length() == 0)
        {
            cout << "Enter the " << fname << " " << lname << "'s city, state and zip code: ";
            getline(cin, cityStZip);
        }

        

        /* The following section is going to be where the user will
        input their specificed amounts for each cookie type */

        thin_mints = getCookies(cookie1, max_order); // input for Thin Mints
        cout << "Thin Mints amount: " << thin_mints << endl;

        lemonUps = getCookies(cookie2, max_order); // input for Lemon-Ups
        cout << "Lemon-Ups amount: " << lemonUps << endl;

        lemonades = getCookies(cookie3, max_order); // input for Lemonades
        cout << "Lemonades amount: " << lemonades << endl;

        samoas = getCookies(cookie4, max_order); // input for Samoas
        cout << "Samoas amount: " << samoas << endl;

        tagalongs = getCookies(cookie5, max_order); // input for Tagalongs
        cout << "Tagalongs amount: " << tagalongs << endl;

        dosidos = getCookies(cookie6, max_order); // input for Do-si-dos
        cout << "Do-si-dos amount: " << dosidos << endl;

        trefoils = getCookies(cookie7, max_order); // input for Trefoils
        cout << "Trefoils amount: " << trefoils << endl;

        thanksalot = getCookies(cookie8, max_order); // input for Thanks-A-Lot
        cout << "Thanks-A-Lot amount: " << thanksalot << endl;

        toffee = getCookies(cookie9, max_order); // input for Toffee-tastic
        cout << "Toffee-tastic amount: " << toffee << endl;

        caramel = getCookies(cookie10, max_order); // input for Caramel Chocolate Chip
        cout << "Caramel Chocolate Chip amount: " << caramel << endl;


        if (outFile.is_open())
        {
            outFile << "================================" << endl;
            outFile << "=== Girl Scout Cookie Invoice ===" << endl;
            outFile << "================================\n" << endl;

            string dateStr;
            time_t result = time(NULL);
            dateStr = ctime(&result);

            outFile << dateStr << endl;
            outFile << fname << " " << lname << endl;
            outFile << address << endl;
            outFile << cityStZip << endl;
            outFile << endl;
            outFile << "Order Number: " << orderNumber << endl;
            outFile << endl;
            outFile << "Dear " << fname << " " << lname << ":" << endl;
            outFile << endl;
            outFile << "Your Girl Scout Cookie order has arrived." << endl;
            outFile << "Your order consists of the following:" << endl;
            outFile << "-------------------------------------------------" << endl;
            outFile << "|" << setw(14) << "Cookie" << setw(11) << "|" << setw(9) << "Quantity" << setw(2) << "|" << setw(7) << "Cost" << setw(5) << "|" << endl;
            outFile << "-------------------------------------------------" << endl;
            outFile << "|" << setw(11) << "Thin Mints" << setw(14) << "|" << setw(9) << thin_mints << setw(2) << "|" << setw(2) << "$" << setw(8) << fixed << setprecision(2) << thin_mints * cPrice << setw(2) << "|" << endl;
            outFile << "|" << setw(9) << "Lemon-up" << setw(16) << "|" << setw(9) << lemonUps << setw(2) << "|" << setw(2) << "$" << setw(8) << fixed << setprecision(2) << lemonUps * cPrice << setw(2) << "|" << endl;
            outFile << "|" << setw(10) << "Lemonades" << setw(15) << "|" << setw(9) << lemonades << setw(2) << "|" << setw(2) << "$" << setw(8) << fixed << setprecision(2) << lemonades * cPrice << setw(2) << "|" << endl;
            outFile << "|" << setw(7) << "Samoas" << setw(18) << "|" << setw(9) << samoas << setw(2) << "|" << setw(2) << "$" << setw(8) << fixed << setprecision(2) << samoas * cPrice << setw(2) << "|" << endl;
            outFile << "|" << setw(10) << "Tagalongs" << setw(15) << "|" << setw(9) << tagalongs << setw(2) << "|" << setw(2) << "$" << setw(8) << fixed << setprecision(2) << tagalongs * cPrice << setw(2) << "|" << endl;
            outFile << "|" << setw(10) << "Do-si-dog" << setw(15) << "|" << setw(9) << dosidos << setw(2) << "|" << setw(2) << "$" << setw(8) << fixed << setprecision(2) << dosidos * cPrice << setw(2) << "|" << endl;
            outFile << "|" << setw(9) << "Trefoils" << setw(16) << "|" << setw(9) << trefoils << setw(2) <<"|" << setw(2) << "$" << setw(8) << fixed << setprecision(2) << trefoils * cPrice << setw(2) << "|" << endl;
            outFile << "|" << setw(13) << "Thanks-A-Lot" << setw(12) << "|" << setw(9) << thanksalot << setw(2) << "|" << setw(2) << "$" << setw(8) << fixed << setprecision(2) << thanksalot * cPrice << setw(2) << "|" << endl;
            outFile << "|" << setw(14) << "Toffee-Tastic" << setw(11) << "|" << setw(9) << toffee << setw(2) << "|" << setw(2) << "$" << setw(8) << fixed << setprecision(2) << toffee * cPrice << setw(2) << "|" << endl;
            outFile << "|" << setw(23) << "Caramel Chocolate Chip" << setw(2) << "|" << setw(9) << caramel << setw(2) << "|" << setw(2) << "$" << setw(8) << fixed << setprecision(2) << caramel * cPrice << setw(2) << "|" << endl;
            outFile << "-------------------------------------------------" << endl;
            outFile << "|" << setw(33) << "Total Due:" << setw(3) << "|" << setw(2) << "$" << setw(8) << fixed << setprecision(2) << cPrice * (thin_mints + lemonUps + lemonades + samoas + tagalongs + dosidos + trefoils + thanksalot + toffee + caramel) << setw(2) << "|" << endl;
            outFile << "-------------------------------------------------" << endl;
        }
    }
}


int getCookies(string cookietype, int max_order)
{
    int quantity = -1;
    int min_order = 0;

    while ((quantity < min_order) || (quantity > max_order))
    {
        cout << cookietype;
        cin >> quantity;
        cin.clear();
    }
    return quantity;
}
