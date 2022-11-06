#include <stdio.h>

// FileWriter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// #include <iostream>
#include <windows.h>
#include <stdlib.h>


static void AsciiToUnicodeConverter(char* in_data, wchar_t** out_data)
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

static void UnicodeToAsciiConverter(wchar_t* in_data, char** out_data)
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

    FILE* fp;
    char* Aoutput_buffer = NULL;

    fopen_s(&fp, fileName, "at+, ccs=UTF-8");
    if (fp)
    {
        UnicodeToAsciiConverter(Uinput_buffer, &Aoutput_buffer);
        fprintf(fp, "%s", Aoutput_buffer);
        fclose(fp);
    }
}


// void FileIO(char* strName)
void FileIO(char *filename,wchar_t* strInput)
{
   // void AUWriteFile(char* fileName, char* Ainput_buffer);
    void UAWriteFile(char* fileName, wchar_t* Uinput_buffer);

    // AUWriteFile((char*)"A.txt", (char*)"Dr Vijay Dattray Gokhale");
    // AUWriteFile((char*)"A.txt", strName);

     UAWriteFile(filename, strInput);
}

/*
void NAME(char* fileName, wchar_t* input_buffer)
{
    void UAWriteFile(char* fileName, char* Uinput_buffer);

    char* output_buffer = NULL;
    strcpy(fileName, "B.txt");
    wcscpy(input_buffer, L"Rama Gokhale Madam");

    UAWriteFile((char*)"A.txt", &output_buffer);
}
*/