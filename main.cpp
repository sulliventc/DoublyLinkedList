//  =============================================================
//  main.cpp - Defines Entry point for 4.singlyLinkedList program
//
//  Version: 1.0.0
//  Date: 6/3/17
//  By: Colten Sullivent
//  ==============================================================

//  ===================
    #include <iostream>

    #include "stdafx.h"
//  ===================

//  ====================
    using namespace std;
//  ====================

//  ===============
//  function main()
//  ============
    int main() {
//      ==========
        Menu menu;
        DoublyLinkedList listA;
//      =======================

        do {
            menu.Display();
            menu.QueryUser();
            menu.ProcessCommand(listA);
        } while (menu.Continue());

        return 0;
    } // function main()
//  ====================