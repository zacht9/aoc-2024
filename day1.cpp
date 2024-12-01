#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

int main()
{
  vector<int> ids1{};
  vector<int> ids2{};
  ifstream input_file("day1.txt");

  // Input parsing part
  string curr_line;
  string delimiter = "   ";
  while (getline(input_file, curr_line))
  {
    auto pos = curr_line.find(delimiter);
    while (pos != string::npos)
    {
      ids1.push_back(stoi(curr_line.substr(0, pos + delimiter.length())));
      curr_line.erase(0, pos + delimiter.length());
      pos = curr_line.find(delimiter);
    }
    ids2.push_back(stoi(curr_line));
  }

  // Sorting the vectors
  sort(ids1.begin(), ids1.end());
  sort(ids2.begin(), ids2.end());

  // Processing
  int sum{0};
  for (int i{0}; i < ids1.size(); i++)
  {
    sum += abs(ids1.at(i) - ids2.at(i));
  }
  cout << sum << endl; // Part 1 answer

  // Initiating hash map (ID -> frequency) for right list
  unordered_map<int, int> u = {};
  for (int num : ids2)
  {
    if (u.find(num) == u.end())
    {
      u[num] = 1;
    }
    else
    {
      u[num] += 1;
    }
  }

  // Finding similarity score based on left list and hash map
  int similarity_score{0};
  for (int num : ids1)
  {
    if (u.find(num) != u.end())
    {
      similarity_score += (num * u[num]);
    }
  }
  cout << similarity_score << endl; // Part 2 answer

  input_file.close();

  return 0;
}