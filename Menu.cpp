//  ==========================================
//  Menu.cpp - Defines behavior for Menu class
//
//  Version: 1.0.0
//  Date: 6/3/17
//  By: Colten Sullivent
//  ==========================================

//  ===================
    #include <iostream>

    #include "stdafx.h"
//  ===================

//  ====================
    using namespace std;
//  ====================

//  ============================
//  Constructors and destructors
//  ============================
    Menu::Menu() {
        userMenuSelection = Quit;
    } // constructor

    Menu::~Menu() {
        cout << "Destructor ~Menu invoked" << endl;
    } // destructor
//  ===============

//  ======================
//  Accessors and mutators
//  ======================
    MenuChoices Menu::Get() {
        return userMenuSelection;
    } // accessor

    void Menu::set(MenuChoices newValue) {
        userMenuSelection = newValue;
    } // mutator
//  ============

//  ==================
//  function Display()
//  ======================
    void Menu::Display() {
        cout << "============================================" << endl;
        cout << "1. InitializeList 2. DestroyList            " << endl;
        cout << "3. InsertFirst    4. InsertLast    5. Insert" << endl;
        cout << "6. DeleteFirst    7. DeleteLast    8. Delete" << endl;
        cout << "9. Print          10. ReversePrint          " << endl;
        cout << "11. Quit                                    " << endl;
        cout << "============================================" << endl;
    } // function Display()
//  =======================

//  ====================
//  function QueryUser()
//  ========================
    void Menu::QueryUser() {
        int input;

        cout << "Enter Menu Selection: ";
        cin >> input;

//      ===============================
        if (input < 12 && input > -1) {
            userMenuSelection = (MenuChoices)(input - 1);
        } else {
            cout << "Unknown. Quitting." << endl;
            userMenuSelection = Quit;
        } // if/else
//      ============

    } // function QueryUser
//  =======================

//  ===================
//  function Continue()
//  =======================
    bool Menu::Continue() {
        return userMenuSelection != Quit;
    } // function Continue()
//  ========================

//  ==========================================
//  function ProcessCommand(DoublyLinkedList&)
//  ===================================================
    void Menu::ProcessCommand(DoublyLinkedList &list) {
        int integerValue;
        int location;

//      ================================
        if (userMenuSelection != Quit) {

//          ============================
            switch (userMenuSelection) {
                case InitializeList:
                    list.InitializeList();
                    break;
                case DestroyList:
                    list.DestroyList();
                    break;
                case InsertFirst:
                    cout << "Enter a value to add to the beginning of the list. ";
                    cin >> integerValue;
                    list.InsertFirst(integerValue);
                    break;
                case InsertLast:
                    cout << "Enter a value to add to the end of the list. ";
                    cin >> integerValue;
                    list.InsertLast(integerValue);
                    break;
                case Insert:
                    cout << "Enter a value to insert into the list. ";
                    cin >> integerValue;
                    cout << "Enter a node location for insertion. ";
                    cin >> location;
                    list.Insert(integerValue, location);
                    break;
                case DeleteFirst:
                    list.DeleteFirst();
                    break;
                case DeleteLast:
                    list.DeleteLast();
                    break;
                case Delete:
                    cout << "Enter a node location for deletion. ";
                    cin >> location;
                    list.Delete(location);
                    break;
                case Print:
                    list.Print();
                    break;
                case ReversePrint:
                    list.ReversePrint(list.GetFirst());
                    break;
                default:
                    break;
            } // switch
//          ===========

        } // if
//      =======

    } // function ProcessCommand(DoublyLinkedList&)
//  ===============================================
