#pragma once
#include <string>
#include <iostream>
#include <fstream>

class CHistogram
{
private:
  int m_binSize; //micro sec
  int m_binCount;
  int m_startPosition;
  int m_endPosition;
  int m_data[50000] = { 0 };

  int GetNthWord(int index, std::string line);

public:
  CHistogram();
  ~CHistogram();

  inline void SetBinSize(int binSize)
  {
    m_binSize = binSize;
  }
  inline void SetBinCount(int binCount)
  {
    m_binCount = binCount;
  }
  inline void SetStartPosition(int startPosition)
  {
    m_startPosition = startPosition;
  }
  inline void SetEndPosition(int endPosition)
  {
    m_endPosition = endPosition;
  }
  inline void IncBinValue(int bin)
  {
    ++m_data[bin];
  }
  inline void IncBinValue(double bin)
  {
    ++m_data[int(bin)];
  }
  void ReadData(const std::string &fileName);
  void ReadData(const std::string &fileName, int col);
  void DataOut(const std::string &fileName);

};
