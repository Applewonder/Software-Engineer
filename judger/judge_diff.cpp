# include<iostream>
# include<vector>
# include<filesystem>
# include<fstream>
# include<string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>

//output_path:./r_output/folder_num/file.txt

class judge_diff {
    private:
        std::vector<std::string> equiv;
        std::vector<std::string> in_equiv;
    public:

        std::string exec(const char* cmd) {
            std::array<char, 128> buffer;
            std::string result;
            std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
            if (!pipe) {
                throw std::runtime_error("popen() failed!");
            }
            while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
                result += buffer.data();
            }
            return result;
        }

        bool judger(std::string file_1, std::string file_2, int folder_num) {
            
            std::string fir_path = "./r_output/" + std::to_string(folder_num) + "/" + file_1 + ".txt";
            std::string sec_path = "./r_output/" + std::to_string(folder_num) + "/" + file_2 + ".txt";
            std::string diff_command = "diff -b -B " + fir_path + " " + sec_path;
            std::string diff_res = exec(diff_command.c_str());
            if (diff_res == "") return true;
            return false;
        }

};