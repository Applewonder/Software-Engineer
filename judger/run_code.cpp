# include <cstdlib>
# include <iostream>
# include <fstream>
# include <filesystem>
# include <string>
# include <vector>
# include <cstdlib>

//

class run_code {
    private:

    public:
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
            int count_folder = 0;
            for (auto& f : std::filesystem::directory_iterator("./r_compile")) {
                if (std::filesystem::is_directory(f)) {
                    count_folder ++;
                    std::string subpath = f.path();
                    
                    std::string inputs = "./r_input/" + std::to_string(count_folder) +"/" + std::to_string(test_case) + ".txt";
                    for (auto& test_file : std::filesystem::directory_iterator(subpath)) {
                        std::string file_name = test_file.path();
                        int down_pos = file_name.rfind("/");
                        file_name = file_name.substr(down_pos + 1);
                        std::string output_path = "./r_output/" + std::to_string(count_folder) + "/" + file_name + ".txt";
                        std::string compile_command = test_file.path().string() + "<" + inputs + ">" + output_path;
                        system(compile_command.c_str());
                        std::string give_back = "echo \"\n\" >> " + output_path;  
                        system(give_back.c_str());
                    }
                
                }
            }
        }
};