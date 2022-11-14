# include<iostream>
# include<vector>
# include<filesystem>
# include<fstream>
# include<string>
#include <cstdio>
#include <memory>
#include <stdexcept>
#include <array>
#include "output.cpp"
#include "run_code.cpp"

//output_path:./r_output/folder_name/file.txt

class judge_diff : public output{
    private:
        run_code run;
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

        bool judger(std::string file_1, std::string file_2, std::string folder_name) {
            
            std::string fir_path = "./r_output/" + folder_name + "/" + file_1 + ".txt";
            std::string sec_path = "./r_output/" + folder_name + "/" + file_2 + ".txt";
            std::string diff_command = "diff -b -B " + fir_path + " " + sec_path;
            std::string diff_res = exec(diff_command.c_str());
            if (diff_res == "") return true;
            return false;
        }

        void save_res() {
            /*
            for every folder, for each program pair,  
            */
            run.compile_files();
            for (auto& f : std::filesystem::directory_iterator("./../input")) {
                if (std::filesystem::is_directory(f)) {
                    std::string folder_path;
                    folder_path = f.path();
                    std::set<std::string> files = run.get_file_set(folder_path);
                    for (int i = 1; i <= 3; i ++) {
                        run.run_test(i);
                        for (auto it = files.begin(); it != files.end(); it ++) {
                            for (auto it_sec = it; it_sec != files.end(); it_sec ++) {
                                if (it_sec == it) it ++;
                                int l_cut_1 = it->find("/");
                                int l_cut_2 = it_sec->find("/");
                                int l_cut_folder = folder_path.find("/");
                                std::string file_1 = it->substr(l_cut_1 + 1);
                                std::string file_2 = it_sec->substr(l_cut_2 + 1);
                                std::string folder_name = folder_path.substr(l_cut_folder + 1);
                                bool res = judger(file_1, file_2, folder_name);
                                if (res) {
                                    insert_equiv(*it);
                                    insert_equiv(*it_sec);
                                } else {
                                    insert_in_equiv(*it);
                                    insert_in_equiv(*it_sec);
                                }
                            }
                        }
                    }
                }
            }
        }
};