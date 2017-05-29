// Kutinf.cpp : Defines the entry point for the console application.
//

#include "Histogram.h"
#include <stdio.h>
#include <tchar.h>


int main()
{
  //1. példa
  CHistogram histogram1;
  histogram1.SetBinSize(1000);
  histogram1.SetStartPosition(0);
  histogram1.SetBinCount(2500);
  histogram1.SetEndPosition(2500000);
  histogram1.ReadData("bemenet.txt", 2);
  histogram1.DataOut("histogram_out1.txt");

  //2. példa
  CHistogram histogram2;
  histogram2.SetBinSize(100000);
  histogram2.SetStartPosition(0);
  histogram2.SetBinCount(25);
  histogram2.SetEndPosition(2500000);
  histogram2.ReadData("bemenet.txt", 2);
  histogram2.DataOut("histogram_out2.txt");

  return 0;
}

