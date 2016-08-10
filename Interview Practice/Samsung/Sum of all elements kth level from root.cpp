/*
Source: http://www.geeksforgeeks.org/samsung-rd-sri-noida-interview-experience-set-8-on-campus/

Given an integer ‘K’ and a tree in string format. We had to print the sum of all elements at Kth level from root.
For example:-

	                         0
                          /     \
                        5          7
                      /   \      /   \
                     6     4    1     3
                            \
                             9

Tree was given in the form: (node value(left subtree)(right subtree))
For tree given above: (0(5(6()())(4()(9()())))(7(1()())(3()())))
Input format: K Tree
Output format: Sum
For example, for given tree:
Input: 2 (0(5(6()())(4()(9()())))(7(1()())(3()())))
Output: 14

*/

#include<iostream>
#include<stdlib.h>
using namespace std;

int char_len;
char* tree;
char* temp;
int sumAtKthLevel(int k) {
	int currentLevel=-1;
	int sum = 0;
	for (int i = 0; i < char_len && tree[i]!='\0'; i++) {
		//cout << tree[i];
		if (tree[i] == '(')
			currentLevel += 1;
		else if (tree[i] == ')')
			currentLevel -= 1;
		else if (currentLevel == k) {
			int temp_i = 0;
			while (i < char_len && tree[i] != '\0' && tree[i]!=')' && tree[i] != '(') {
				temp[temp_i++] = tree[i++];
			}
			temp[temp_i] = '\0';
			//cout << "\n"<<temp<<"\n";
			sum += atoi(temp);
			if (tree[i] == ')')
				currentLevel -= 1;
			if (tree[i] == '(')
				currentLevel += 1;
		}

	}
	return sum;
}


int main() {
	cout << endl;
	char str[] = "(0(5(6()())(4()(9()())))(7(1()())(3()())))";
	char_len = sizeof(str) / sizeof(char);
	temp = new char[char_len];
	tree = str;
	cout << "\nSum: "<<sumAtKthLevel(2);
	cout << endl;
	return 0;
}
