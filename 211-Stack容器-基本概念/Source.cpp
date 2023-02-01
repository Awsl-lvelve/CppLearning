#include<stack>
#include<iostream>
#include<string>
using namespace std;

//stack栈，后进先出！

//stack不允许有遍历行为
//遍历是非质变算法，而栈只有栈顶元素才能被访问
//栈阔以判断容器是否为空

//栈可以返回是否为空
//栈可以返回元素数量

void test() {
	stack<int>i_stack;

	i_stack.push(10);//入栈
	i_stack.push(20);
	i_stack.push(30);
	i_stack.push(40);
	cout << "栈顶元素：" << i_stack.top() << endl;//栈顶元素

	i_stack.pop();//出栈
	i_stack.top();//栈顶元素
	i_stack.emplace(1);//?
	i_stack.size();//元素数量
	i_stack.empty();//为空？
	
}

int main() {
	test();
}