#include <chrono>
#include <fstream>
#include "filter.hpp"
#include "ipe_filter.hpp"

static int ROUND = 10;

void ipe_setup_time(){
    // Open the output files.
    std::ofstream file("ipe_setup_time.txt", std::ios_base::app);
    file << "IPE Setup Timings" << std::endl << std::endl;

    for (int length = 10; length <= 200; length += 10){
        // Create holder for timings.
        std::chrono::duration<double, std::milli> time{};

        // Perform ROUND number of setup.
        for (int i = 0; i < ROUND; ++i){
            // Setup timings.
            auto start = std::chrono::high_resolution_clock::now();
            // Create pp and msk.
            auto pp = IpeFilter::pp_gen(1, length);
            auto msk = IpeFilter::msk_gen(pp);
            auto end = std::chrono::high_resolution_clock::now();
            time += end - start;
        }

        // Output the time.
        file << "(" << length << ", " << time.count() / ROUND << ")" << std::endl;
    }
    // Create some blank spaces.
    file << std::endl << std::endl;
}

void our_setup_time(){
    // Open the output files.
    std::ofstream file("our_setup_time.txt", std::ios_base::app);
    file << "Our Setup Timings" << std::endl << std::endl;

    for (int length = 10; length <= 200; length += 10){
        // Create holder for timings.
        std::chrono::duration<double, std::milli> time{};

        // Perform ROUND number of setup.
        for (int i = 0; i < ROUND; ++i){
            // Setup timings.
            auto start = std::chrono::high_resolution_clock::now();
            // Create pp and msk.
            auto pp = Filter::pp_gen(1, length);
            auto msk = Filter::msk_gen(pp);
            auto end = std::chrono::high_resolution_clock::now();
            time += end - start;
        }

        // Output the time.
        file << "(" << length << ", " << time.count() / ROUND << ")" << std::endl;
    }
    // Create some blank spaces.
    file << std::endl << std::endl;
}

void sse_setup_time(){
    // Open the output files.
    std::ofstream file("sse_setup_time.txt", std::ios_base::app);
    file << "SSE Setup Timings" << std::endl << std::endl;

    for (int length = 10; length <= 200; length += 10){
        // Create holder for timings.
        std::chrono::duration<double, std::milli> time{};

        // Perform ROUND number of setup.
        for (int i = 0; i < ROUND; ++i){
            // Setup timings.
            auto start = std::chrono::high_resolution_clock::now();
            // Create the PRF object.
            auto prf = PRF();
            auto end = std::chrono::high_resolution_clock::now();
            time += end - start;
        }

        // Output the time.
        file << "(" << length << ", " << time.count() / ROUND << ")" << std::endl;
    }
    // Create some blank spaces.
    file << std::endl << std::endl;
}


int main(){
    ipe_setup_time();
    our_setup_time();
    sse_setup_time();
}
