//  =========================================
//  Menu.h - Declares behavior for Menu class
//
//  Version: 1.0.0
//  Date: 6/3/17
//  By: Colten Sullivent
//  =========================================

//  ============
    #pragma once

    #include <string>

    #include "stdafx.h"
    #include "DoublyLinkedList.h"
//  =============================

//  ====================
    using namespace std;
//  ====================

//  ============
    class Menu {
    public:
        Menu();
        ~Menu();

        MenuChoices Get();
        void        set(MenuChoices);
        void        Display();
        void        QueryUser();
        bool        Continue();
        void        ProcessCommand(DoublyLinkedList&);
    private:
        MenuChoices userMenuSelection;
    }; // class Menu
//  ================