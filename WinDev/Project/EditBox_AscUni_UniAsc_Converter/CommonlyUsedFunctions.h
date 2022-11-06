#pragma once

void AsciiToUnicodeConverter(char* in_data, wchar_t** out_data);

void UnicodeToAsciiConverter(wchar_t* in_data, char** out_data);

void AUWriteFile(char* fileName, char* Ainput_buffer);

void UAWriteFile(char* fileName, wchar_t* Uinput_buffer);


// void FileIO(char *strName);
//void FileIO(wchar_t* strName);

void FileIO(char* filename, wchar_t* strInput);

