#include<stdio.h>
#include<windows.h>
#include "connector.h"

void con_by_serial(){
        HANDLE hComm;
        hComm = CreateFile("COM1",                //port name
                      GENERIC_READ | GENERIC_WRITE, //Read/Write
                      0,                            // No Sharing
                      NULL,                         // No Security
                      OPEN_EXISTING,// Open existing port only
                      0,            // Non Overlapped I/O
                      NULL);        // Null for Comm Devices
                      
        if (hComm == INVALID_HANDLE_VALUE)
        printf("Error in opening serial port");
        else
            printf("Opening serial port successful");
    
        DCB dcbSerialParams = { 0 }; // Initializing DCB structure
        dcbSerialParams.DCBlength = sizeof(dcbSerialParams);
        _Bool Status = GetCommState(hComm, &dcbSerialParams);
        dcbSerialParams.BaudRate = CBR_115200;  // Setting BaudRate = 115200
        dcbSerialParams.ByteSize = 8;         // Setting ByteSize = 8
        dcbSerialParams.StopBits = ONESTOPBIT;// Setting StopBits = 1
        dcbSerialParams.Parity   = NOPARITY;  // Setting Parity = None
        SetCommState(hComm, &dcbSerialParams);

        char lpBuffer[] = "Hi it is COM1\n";
        DWORD dNoOFBytestoWrite;         // No of bytes to write into the port
        DWORD dNoOfBytesWritten = 0;     // No of bytes written to the port
        dNoOFBytestoWrite = sizeof(lpBuffer);
        Status = WriteFile(hComm,        // Handle to the Serial port
                    lpBuffer,     // Data to be written to the port
                    dNoOFBytestoWrite,  //No of bytes to write
                    &dNoOfBytesWritten, //Bytes written
                    NULL);

        CloseHandle(hComm);//Closing the Serial Port
    }  