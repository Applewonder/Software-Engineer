# include <iostream>
# include "judge_diff.cpp"

int main() {
    srand(time(nullptr));
    system("./start.sh");
    std::cout << "How many test cases do you want?" << std::endl;
    int input_n;
    std::cin >> input_n;
    judge_diff auto_judge(input_n);
    
    auto_judge.save_res();
    return 0;
}