# include <iostream>
# include "input.cpp"
# include "judge_diff.cpp"

int main() {
    srand(time(nullptr));
    system("./start.sh");
    input a;
    a.build_input_type();
    judge_diff b;
    b.save_res();
    // b.output_file();
    return 0;
}