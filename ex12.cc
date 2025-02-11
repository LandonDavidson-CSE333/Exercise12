// Copyright 2025 Landon Davidson
// landond@uw.edu

#include <map>
#include <string>
#include <fstream>
#include <iostream>

int main(int argc, char** argv) {
  // Create a map with string, int key value pairs to store the words occurrences in
  std::map<std::string, int> words;

  // Get filename from args
  if (argc != 2) {
    std::cerr << "Requires 1 argument, you entered " << argc - 1;
    return EXIT_FAILURE;
  }
  std::string filename = argv[1];

  // Open the file to an ifstream and ensure it opened
  std::ifstream f(filename);
  if (!f.is_open()) {
    std::cerr << "Error opening file " << filename << ": ";
    perror("");
    return EXIT_FAILURE;
  }

  // Used to store each word from the file
  std::string word;

  // Read the file one word at a time until we hit eof and increment its entry in words
  // words[] will initialize a key to zero if it is new
  while (f >> word) {
    words[word]++;
  }

  // Print the words and their counts in order. Map is ordered so the words will already be sorted
  for (std::pair<std::string, int> p : words) {
    std::cout << p.first << " " << p.second << "\n";
  }

  // Close the file and exit with success
  f.close();
  return EXIT_SUCCESS;
}
