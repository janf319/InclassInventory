//Final Exam
//ITDEV1 - 185
//Janese Christie
//Grocery Application

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Item.h"
#include "Cart.h"
#include "Coupon.h"
#include "Receipt.h"

using namespace std;

double Item::delivery = 20.00;
double Item::tip = 5.00;
void welcomeScreen();
void displayMainMenu();
void displayFreshProduceMenu();
void displayMeatSeafoodMenu();
void displayFrozenFoodMenu();

int main()
{
    double total = 0.00;
    int deliveryOption = 0;
    bool showMenu = true;
    vector<Item*> cart;

    while (showMenu)
    {
        // Delivery option menu function defined on line 250
        welcomeScreen();
        cin >> deliveryOption;

        // Validate delivery option input
        while (deliveryOption != 1 && deliveryOption != 2 && deliveryOption != 3)
        {
            cout << "Invalid input. Please choose a valid option: ";
            cin >> deliveryOption;
        }

        if (deliveryOption == 3)
        {
            cout << "Looks Like you werent interested in grocery shopping today" << endl;
            showMenu = false;
            return 0;
        }
        // Hide delivery option menu
        system("cls");

        // Main menu
        int mainOption = 0;
        while (mainOption != 4)
        {
            displayMainMenu();
            cin >> mainOption;
            // Validate main menu input
            while (mainOption != 1 && mainOption != 2 && mainOption != 3 && mainOption != 4)
            {
                cout << "Invalid input. Please choose a valid option: ";
                cin >> mainOption;
            }

            // Hide main menu
            system("cls");

            // Fresh Produce menu
            if (mainOption == 1)
            {
                int fpOption = 0;
                while (fpOption != 4)
                {
                    displayFreshProduceMenu();
                    cin >> fpOption;
                    // Validate fresh produce menu input
                    while (fpOption != 1 && fpOption != 2 && fpOption != 3 && fpOption != 4)
                    {
                        cout << "Invalid input. Please choose a valid option: ";
                        cin >> fpOption;
                    }

                    if (fpOption != 4)
                    {
                        // Prompt user for weight
                        double weight;
                        cout << "Enter weight (in pounds): ";
                        cin >> weight;

                        // Calculate price and add to cart
                        FreshProduce* fp = nullptr;
                        if (fpOption == 1)
                        {
                            fp = new Produce("Gala Apples", 3.99, weight);
                            double productTotal = fp->calcPrice();
                            fp->setPrice(productTotal); // Store the total cost in the object

                        }
                        else if (fpOption == 2)
                        {
                            fp = new FreshProduce("Bananas", 0.48, weight);
                            double productTotal = fp->calcPrice();
                            fp->setPrice(productTotal); // Store the total cost in the object
                        }
                        else if (fpOption == 3)
                        {
                            fp = new FreshProduce("Grapes", 2.99, weight);
                            double productTotal = fp->calcPrice();
                            fp->setPrice(productTotal); // Store the total cost in the object
                        }
                        cart.push_back(fp);//add the object to the cart vector
                    }
                    // Hide weight prompt
                    system("cls");
                }
            }
            // Meat and Seafood menu
            else if (mainOption == 2)
            {
                int msOption = 0;
                while (msOption != 4)
                {
                    displayMeatSeafoodMenu();
                    cin >> msOption;
                    // Validate fresh produce menu input
                    while (msOption != 1 && msOption != 2 && msOption != 3 && msOption != 4)
                    {
                        cout << "Invalid input. Please choose a valid option: ";
                        cin >> msOption;
                    }

                    if (msOption != 4)
                    {
                        // Prompt user for weight
                        double weight;
                        cout << "Enter weight (in pounds): ";
                        cin >> weight;

                        // Calculate price and add to cart
                        FreshProduce* ms = nullptr;
                        if (msOption == 1)
                        {//make new object from user input. 
                            ms = new FreshProduce("Whole Chicken", 6.99, weight);
                            //store total into a double in order to pass it to the price 
                            //this is to use it to display the total cost 
                            double productTotal = ms->calcPrice();
                            ms->setPrice(productTotal); // Store the total cost in the object
                        }
                        else if (msOption == 2)
                        {
                            ms = new FreshProduce("Ground Beef", 4.99, weight);
                            double productTotal = ms->calcPrice();
                            ms->setPrice(productTotal); // Store the total cost in the object
                        }
                        else if (msOption == 3)
                        {
                            ms = new FreshProduce("Salmon", 9.99, weight);
                            double productTotal = ms->calcPrice();
                            ms->setPrice(productTotal); // Store the total cost in the object
                        }
                        cart.push_back(ms);
                    }
                    // Hide weight prompt
                    system("cls");
                }
            }
            //Frozen Food Options
            else if (mainOption == 3)
            {
                int ffOption = 0;
                while (ffOption != 4)
                {
                    displayFrozenFoodMenu();
                    cin >> ffOption;
                    // Validate fresh produce menu input
                    while (ffOption != 1 && ffOption != 2 && ffOption != 3 && ffOption != 4)
                    {
                        cout << "Invalid input. Please choose a valid option: ";
                        cin >> ffOption;
                    }

                    if (ffOption != 4)
                    {
                        // Prompt user for quantity
                        double q;
                        cout << "Enter quantity: ";
                        cin >> q;

                        // Calculate price and add to cart
                        MeasuredProduct* ff = nullptr;
                        if (ffOption == 1)
                        {
                            ff = new MeasuredProduct("Waffles", 6.99, q);
                            double productTotal = ff->calcPrice();
                            ff->setPrice(productTotal);
                        }
                        else if (ffOption == 2)
                        {
                            ff = new MeasuredProduct("Pizza", 4.99, q);
                            double productTotal = ff->calcPrice();
                            ff->setPrice(productTotal);
                        }
                        else if (ffOption == 3)
                        {
                            ff = new MeasuredProduct("Popsicle", 2.99, q);
                            double productTotal = ff->calcPrice();
                            ff->setPrice(productTotal);
                        }
                        cart.push_back(ff);
                    }
                    // Hide quantity prompt
                    system("cls");
                }

            }
        }
        if (mainOption == 4 && deliveryOption == 2)
        {
            double deliveryCost = Item::getDelivery();
            double tipCost = Item::getTip();
            // Print out cart
            cout << "****************************************" << endl;
            cout << "Your cart:" << endl;
            for (auto item : cart)
            {
                cout << left << setw(20) << item->getName() << " - $ ";
                cout << right << setw(5) << fixed << setprecision(2) << item->getPrice() << endl;
                total += item->getPrice();
            }
            total += deliveryCost + tipCost;
            cout << left << setw(20) << "\nDelivery" << "  - $ ";
            cout << right << setw(5) << fixed << setprecision(2) << deliveryCost << endl;
            cout << left << setw(20) << "Tip" << " - $ ";
            cout << right << setw(5) << fixed << setprecision(2) << tipCost << endl;
            cout << left << setw(20) << "\nTotal Price" << "  - $ ";
            cout << right << setw(5) << fixed << setprecision(2) << total << endl;
            cout << "***************************************" << endl;

        }
        else if (mainOption == 4)
        {
            // Print out cart
            cout << "******************************" << endl;
            cout << "Your cart:" << endl;
            for (auto item : cart)
            {
                cout << left << setw(20) << item->getName() << " - $ ";
                cout << right << setw(5) << fixed << setprecision(2) << item->getPrice() << endl;
                total += item->getPrice();

            }
            cout << left << setw(20) << "\nTotal Price" << " - $ ";
            cout << right << setw(5) << fixed << setprecision(2) << total << endl;
            cout << "***************************************" << endl;
        }

        return 0;
    }
}

void welcomeScreen()
{
    cout << "******************************" << endl;
    cout << "Welcome to our online grocery store!" << endl;
    cout << "Please choose a delivery option:" << endl;
    cout << "1. Pick up" << endl;
    cout << "2. Delivery ($20 delivery charge + $5 tip)" << endl;
    cout << "3. Exit" << endl;
    cout << "******************************" << endl;
}

void displayMainMenu()
{
    cout << "******************************" << endl;
    cout << "Main Menu:" << endl;
    cout << "1. Fresh Produce" << endl;
    cout << "2. Meat and Seafood" << endl;
    cout << "3. Frozen Foods" << endl;
    cout << "4. Checkout" << endl;
    cout << "******************************" << endl;
}

void displayFreshProduceMenu()
{
    cout << "******************************" << endl;
    cout << "Fresh Produce Menu:" << endl;
    cout << "1. Gala Apples ($3.99/lb)" << endl;
    cout << "2. Bananas ($0.48/lb)" << endl;
    cout << "3. Grapes ($2.99/lb)" << endl;
    cout << "4. Return to Main Menu" << endl;
    cout << "******************************" << endl;
}

void displayMeatSeafoodMenu()
{
    cout << "******************************" << endl;
    cout << "\nMeat and Seafood Menu\n";
    cout << "1. Whole Chicken - $6.99/lb\n";
    cout << "2. Ground Beef - $4.99/lb\n";
    cout << "3. Salmon - $9.99/lb\n";
    cout << "4. Return to Main Menu\n";
    cout << "******************************" << endl;
}

void displayFrozenFoodMenu()
{
    cout << "******************************" << endl;
    cout << "\nFrozen Food Menu\n";
    cout << "1. Waffles $6.99\n";
    cout << "2. Pizza - $4.99\n";
    cout << "3. Popsicle - $2.99\n";
    cout << "4. Return to Main Menu\n";
    cout << "******************************" << endl;

}
