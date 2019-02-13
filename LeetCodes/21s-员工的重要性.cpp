//C++ file
/***********************************************
#
#      Filename: 21-员工的重要性.cpp
#
#        Author: luhg - luhg@keyou.cn
#   Description: 
				给定一个保存员工信息的数据结构，它包含了员工唯一的id，重要度 和 直系下属的id。

比如，员工1是员工2的领导，员工2是员工3的领导。他们相应的重要度为15, 10, 5。那么员工1的数据结构是[1, 15, [2]]，员工2的数据结构是[2, 10, [3]]，员工3的数据结构是[3, 5, []]。注意虽然员工3也是员工1的一个下属，但是由于并不是直系下属，因此没有体现在员工1的数据结构中。

现在输入一个公司的所有员工信息，以及单个员工id，返回这个员工和他所有下属的重要度之和。

示例 1:

输入: [[1, 5, [2, 3]], [2, 3, []], [3, 3, []]], 1
输出: 11
解释:
员工1自身的重要度是5，他有两个直系下属2和3，而且2和3的重要度均为3。因此员工1的总重要度是 5 + 3 + 3 = 11。
注意:

一个员工最多有一个直系领导，但是可以有多个直系下属
员工数量不超过2000。
#        Create: 2019-01-18 16:39:09
#**********************************************/
#include<iostream>
#include<vector>

using namespace std;

/*
// Employee info
*/
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};

class Solution {
public:
    int sum = 0;
    int getImportance(vector<Employee*> employees, int id) {
        int index;
        for (size_t i = 0; i < employees.size(); ++i) {
			if (employees[i] == NULL)	
				return sum;
			if (employees[i]->id == id) {
				sum += employees[i]->importance;
				index = i;
			}
        }

		for (size_t i = 0; i < employees[index]->subordinates.size(); ++i) {
			getImportance(employees, employees[index]->subordinates[i]);
		}
		return sum;
    }
};
