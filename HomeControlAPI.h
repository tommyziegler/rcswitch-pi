//
//  whomecontrolpi.h
//  MyTest
//
//  Created by Tommy Ziegler on 10/12/13.
//  Copyright (c) 2013 Tommy Ziegler. All rights reserved.
//

#include "HomeControl.h"

#ifndef HomeControlAPI_h
#define HomeControlAPI_h

static void SwitchElro(char* inSystemCode, char* inUnitCode, const bool switchOn) {
    int unitDigit;
    if (strcmp(inUnitCode, "A") == 0) {
        unitDigit = 1;
    } else if (strcmp(inUnitCode, "B") == 0) {
        unitDigit = 2;
    } else if (strcmp(inUnitCode, "C") == 0) {
        unitDigit = 3;
    } else if (strcmp(inUnitCode, "D") == 0) {
        unitDigit = 4;
    } else if (strcmp(inUnitCode, "E") == 0) {
        unitDigit = 5;
    } else {
        //ThrowException( Exception::TypeError( String::New( "UnitCode for Elro not supported" ) ) );
        printf("UnitCode [%s] for Elro not supported\n", inUnitCode);
        return;
    }

    // TODO: add SystemCode check 00000 - 11111
    
    int kPIN = 0;
    HomeControl myHome = HomeControl();
    myHome.enableTransmit(kPIN);
    
    if(switchOn) {
        printf("sending ON to Elro Switch: inSystemCode[%s] inUnitCode[%s]\n", inSystemCode, inUnitCode);
        myHome.switchOn(inSystemCode, unitDigit);
    } else {
        printf("sending OFF to Elro Switch: inSystemCode[%s] inUnitCode[%s]\n", inSystemCode, inUnitCode);
        myHome.switchOff(inSystemCode, unitDigit);
    }
}

static void SwitchRev(char* inSystemCode, int inUnitCode, const bool switchOn) {
    char systemDigit;
    if (strcmp(inSystemCode, "A") == 0) {
        systemDigit = 'A';
    } else if (strcmp(inSystemCode, "B") == 0) {
        systemDigit = 'B';
    } else if (strcmp(inSystemCode, "C") == 0) {
        systemDigit = 'C';
    } else if (strcmp(inSystemCode, "D") == 0) {
        systemDigit = 'D';
    } else {
        //ThrowException( Exception::TypeError( String::New( "SystemCode for REV not supported" ) ) );
        printf("SystemCode [%s] for REV not supported\n", inSystemCode);
        return;
    }

    // TODO: add UnitCode check here 1 - 3
    
    int kPIN = 0;
    HomeControl myHome = HomeControl();
    myHome.enableTransmit(kPIN);
    
    if(switchOn) {
        printf("sending ON to REV Switch: inSystemCode[%s] inUnitCode[%i]\n", inSystemCode, inUnitCode);
        myHome.switchOnD(systemDigit, inUnitCode);
    } else {
        printf("sending OFF to REV Switch: inSystemCode[%s] inUnitCode[%i]\n", inSystemCode, inUnitCode);
        myHome.switchOffD(systemDigit, inUnitCode);
    }
}

#endif
