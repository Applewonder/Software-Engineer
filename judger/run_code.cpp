#include <bits/types/FILE.h>
# include <cstdlib>
# include <iostream>
# include <fstream>
# include <filesystem>
# include <string>
# include <vector>
# include <map>
# include <set>
# include <cstdlib>

//

class run_code {
    private:
        std::map<std::string, std::set<std::string>> file_import;
    public:

        void insert_map(std::string path_to_folder, std::string path_to_file) {
            file_import[path_to_file].insert(path_to_file);
        }

        std::set<std::string> get_file_set(std::string path_to_folder) {
            return file_import[path_to_folder];
        }

        void compile_files() {
            int count_folder = 0;
            for (auto& f : std::filesystem::directory_iterator("./../input")) {
                if (std::filesystem::is_directory(f)) {
                    count_folder ++;
                    std::string subpath = f.path();
                    for (auto& test_file : std::filesystem::directory_iterator(subpath)) {
                        std::string path = test_file.path();
                        if (path.length() < 4) continue;
                        int pos = path.find(".");
                        std::string succdex = path.substr(pos);
                        if (succdex == ".cpp") {
                            int down_pos = path.rfind("/");
                            std::string file_name = path.substr(0, pos);
                            insert_map(subpath, file_name);
                            file_name = file_name.substr(down_pos + 1);
                            std::string compile_command = "gcc " + path + " -o ./r_compile/" + std::to_string(count_folder) + "/" + file_name;
                            std::cout << compile_command << std::endl;
                            system(compile_command.c_str());
                        } 
                    }
                }
            }
        }

        void run_test(int test_case) {
            std::string folder_name;
            for (auto& f : std::filesystem::directory_iterator("./r_compile")) {
                if (std::filesystem::is_directory(f)) {
                    folder_name = f.path();
                    int position_need = folder_name.rfind("/");
                    folder_name = folder_name.substr(position_need + 1);
                    std::string subpath = f.path();
                    std::string inputs = "./r_input/" + folder_name +"/" + std::to_string(test_case) + ".txt";
                    for (auto& test_file : std::filesystem::directory_iterator(subpath)) {
                        std::string file_name = test_file.path();
                        int down_pos = file_name.rfind("/");
                        file_name = file_name.substr(down_pos + 1);
                        std::string output_path = "./r_output/" + folder_name + "/" + file_name + ".txt";
                        std::string compile_command = test_file.path().string() + "<" + inputs + ">" + output_path;
                        system(compile_command.c_str());
                    }
                }
            }
        }
};