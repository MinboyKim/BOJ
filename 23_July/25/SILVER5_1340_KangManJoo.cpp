#include <bits/stdc++.h>

using namespace std;

int yyyy;
double hh, mm, day, Allday, total, totalday;
string month;
string hm, dd;
int main() {
  cin >> month >> dd >> yyyy >> hm;
  dd = dd.substr(0, dd.length() - 1);
  day = stoi(dd);

  hh = stoi(hm.substr(0, 2));
  mm = stoi(hm.substr(3, 2));

  // 525600

  if (month == "January") {
    Allday += 0;
  } else if (month == "February") {
    Allday += 31;
  } else if (month == "March") {
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
      Allday += 60;
    else
      Allday += 59;
  } else if (month == "April") {
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
      Allday += 91;
    else
      Allday += 90;
  } else if (month == "May") {
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
      Allday += 121;
    else
      Allday += 120;
  } else if (month == "June") {
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
      Allday += 152;
    else
      Allday += 151;
  } else if (month == "July") {
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
      Allday += 182;
    else
      Allday += 181;
  } else if (month == "August") {
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
      Allday += 213;
    else
      Allday += 212;
  } else if (month == "September") {
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
      Allday += 244;
    else
      Allday += 243;
  } else if (month == "October") {
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
      Allday += 274;
    else
      Allday += 273;
  } else if (month == "November") {
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
      Allday += 305;
    else
      Allday += 304;
  } else if (month == "December") {
    if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
      Allday += 335;
    else
      Allday += 334;
  }

  Allday += day;

  Allday--;
  total += Allday * 1440;
  total += hh * 60;
  total += mm;

  if (yyyy % 400 == 0 || (yyyy % 4 == 0 && yyyy % 100 != 0))
    totalday = 527040;
  else
    totalday = 525600;
  double ratio = total / totalday * 100;
  cout << fixed << setprecision(15) << ratio;
}