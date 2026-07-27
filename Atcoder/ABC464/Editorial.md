# Japanese Student Championship 2026 -Advance- Qualification (AtCoder Beginner Contest 464)

## Problem : 1
** Decision Battle ** 

### Problem Description

* You are given a string consistion of only 'E' & 'W'.Output 'East' if there are more 'E' than 'W', else 'West'

### Solution 

* Initial variables cnt_of_E,cnt_of_W -> 0
* for each string:
    if char has 'E'
        cnt_of_E = cnt_of_E + 1
    else
        cnt_of_W = cnt_of_W + 1

  if cnt_of_W>cnt_of_E
    return "West"
  else 
    return "East"

### Editorial Solution => Same as my solution !!

---

## Problem : 2
** Crop ** 

### Problem Description
Your given a H x W string grid matrix consisting of '.' and '#'. 

### Solution

