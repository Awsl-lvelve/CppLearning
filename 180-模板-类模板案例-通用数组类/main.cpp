#include"MyArray.cpp"

void test() {
	MyArray<int> arr(100);

	for (int i = 0; i < 100; i++)
	{
		arr.PushBack(i);
	}

	
	
	//arr.PrintArray();
	arr.PrintArray();
	cout << arr.GetElemNum()<<endl;
	//cout << arr.GetCapacity() << endl;
	
}

int main() {
	test();
}