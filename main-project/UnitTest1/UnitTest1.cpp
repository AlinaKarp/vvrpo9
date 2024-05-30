#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "pch.h"
#include "CppUnitTest.h"
#include "..\main-project\utils.h"
#include "..\main-project\utils.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittestproject
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestFilterAndSortData)
        {

            std::string temp_file_name = "test_filter_and_sort_data.txt";
            std::ofstream temp_file(temp_file_name);
            temp_file << "07:00:00 08:00:00 100 200 Skype\n"
                << "09:00:00 10:00:00 300 200 Skype\n";
            temp_file.close();


            std::stringstream output_stream;
            std::streambuf* original_stream_buffer = std::cout.rdbuf();
            std::cout.rdbuf(output_stream.rdbuf());


            filterAndSortData(temp_file_name);


            std::cout.rdbuf(original_stream_buffer);


            std::string expected_output =
                "Sorted by usage time:\n"
                "09:00:00 - 10:00:00, Program: Skype\n"
                "Sorted by program and usage:\n"
                "Program: Skype, Bytes: 500\n";

            Assert::AreEqual(expected_output, output_stream.str());


            remove(temp_file_name.c_str());
        }
    };
}