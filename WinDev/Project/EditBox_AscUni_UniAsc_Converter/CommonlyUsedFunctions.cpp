#include <stdio.h>

// FileWriter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// #include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <stdarg.h>

void AsciiToUnicodeConverter(char* in_data, wchar_t** out_data)
{
    int size_required_after_conversion = MultiByteToWideChar(
        CP_UTF8,
        0,
        in_data,
        -1,
        NULL,
        0);

    //printf("%d\n", size_required_after_conversion);


    *out_data = (wchar_t*)malloc(size_required_after_conversion * sizeof(wchar_t));

    int ret = MultiByteToWideChar(
        CP_UTF8,
        0,
        in_data,
        -1,
        *out_data,
        size_required_after_conversion
    );

    wprintf(L"%ls\n", *out_data);
}

void UnicodeToAsciiConverter(wchar_t* in_data, char** out_data)
{
    int size_required_after_conversion = WideCharToMultiByte(
        CP_ACP, WC_NO_BEST_FIT_CHARS | WC_COMPOSITECHECK | WC_DEFAULTCHAR,
        in_data,
        -1,
        NULL,
        0,
        NULL,
        NULL);

    *out_data = (char*)malloc((size_required_after_conversion) * sizeof(char));

    int ret = WideCharToMultiByte(
        CP_ACP, WC_NO_BEST_FIT_CHARS | WC_COMPOSITECHECK | WC_DEFAULTCHAR,
        in_data,
        -1,
        *out_data,
        size_required_after_conversion,
        NULL,
        NULL);
}

void AUWriteFile(char* fileName, char* Ainput_buffer)
{
    void AsciiToUnicodeConverter(char* in_data, wchar_t** out_data);

    FILE* fp;
    wchar_t *Uoutput_buffer = NULL;

    fopen_s(&fp, fileName, "at+, ccs=UTF-8");
    if (fp)
    {
        AsciiToUnicodeConverter(Ainput_buffer, &Uoutput_buffer);
        fwprintf(fp,L"%ls",Uoutput_buffer);
        fclose(fp);
    }
}

void UAWriteFile(char* fileName, wchar_t* Uinput_buffer)
{
    void UnicodeToAsciiConverter(wchar_t* in_data, char** out_data);

    FILE* fp = NULL;
    char* Aoutput_buffer = NULL;

    fopen_s(&fp, fileName, "a+");
    if (fp)
    {
        UnicodeToAsciiConverter(Uinput_buffer, &Aoutput_buffer);
        fprintf(fp, "%s", Aoutput_buffer);
        fclose(fp);
    }
}


void FileIO(char *filename, wchar_t* strInput)
{
    // toDO
    // aplyala te strInput cha type check karun suitable API call karne
    // if - else UAWriteFile or AUWriteFile
    
    void UAWriteFile(char* fileName, wchar_t* Uinput_buffer);
    void AUWriteFile(char* fileName, char* Ainput_buffer);

    // DeleteFile((LPCWSTR)filename);
    
    UAWriteFile(filename, strInput);
}

