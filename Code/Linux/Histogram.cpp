#include "Histogram.h"
#include <stdio.h>
#include <tchar.h>
#include <string>
#include <fstream>


CHistogram::CHistogram()
{
}


CHistogram::~CHistogram()
{
}

// return word[index] from line
int CHistogram::GetNthWord(int index, std::string line) // word index and actual line
{
  int count = 0; // current word index
  std::string word; // word buffer (return value)

  for (int i = 0; i < line.length(); i++) // loop through each character in line  //+++ Warning
  {
    if (line[i] == ' ') // if current character is a space
    {
      if (line[i + 1] != ' ')  // but next char is not space, we got a word
      {
        count++; // incr current word index counter in line
        if (count == index) // if count == looked for index return word
        {
          return atoi(word.c_str());
        }
        word = "";  // otherwise reset word buffer
      }
    }
    else // character is not space
    {
      word += line[i]; // add letter/digit to word buffer
    }
  }
  return 0;
}

void CHistogram::ReadData(const std::string &fileName)  //Csak egyoszlopos fájlt tud beolvasni
{
  std::ifstream sourceFile;
  double word;
  sourceFile.open(fileName);
  while (sourceFile >> word)
  {
    if (word <= m_binCount*m_binSize) {
      IncBinValue(word / m_binSize);
    }
  }
  sourceFile.close();
}

void CHistogram::ReadData(const std::string & fileName, int col)
{
  std::ifstream sourceFile;
  std::string line;
  double word;
  sourceFile.open(fileName);
  while (std::getline(sourceFile, line))
  {
    word = GetNthWord(col, line);
    if (word <= m_binCount*m_binSize) {
      IncBinValue(word / m_binSize);
      //std::cout << word << '\t' << int(word / m_binSize) << std::endl;
    }
  }
  sourceFile.close();
}

void CHistogram::DataOut(const std::string &fileName)
{
  std::ofstream outFile(fileName);
  int i;
  for (i = 0; i < m_binCount; i++)
  {
    outFile << (i*m_binSize) << " " << m_data[i] << std::endl;
  }
  outFile.close();
}