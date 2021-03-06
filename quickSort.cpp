// 快速排序:分治思想
#include <iostream>
#include <fstream>
#include <sys/time.h>
#include <unistd.h> // sleep(3);

std::ifstream fin("data.in");
std::ofstream fout("data.out");

#define MAX 1024*1024
// 升序,不稳定,时间复杂度平均O(nlg(n)),最坏O(n^2)
void quickSort(int array[], int left, int right)
{
	if(left < right)
	{
		int key = array[left];
		int low = left;
		int high = right;
		while(low < high)
		{
			while(low < high && array[high] > key)
				{high--;}
			array[low] = array[high];
			
			while(low < high && array[low] <= key)// 考虑到有相同元素,故而 array[low] <= key
				{low++;}
			array[high] = array[low];
		}
		array[low] = key;
		quickSort(array, left, low-1);
		quickSort(array, low+1, right);
	}
}

long getCurrentTime()    
{    
   struct timeval tv;    
   gettimeofday(&tv,NULL);    
   return tv.tv_sec * 1000 + tv.tv_usec / 1000;    
} 

int main()
{
	int array[MAX];
	int num = 0;
	while(fin >> array[num])
		++num;

	long start = getCurrentTime();
	std::cout << "before sort(ms): " << start << std::endl;
	quickSort(array, 0, num-1);
	long end = getCurrentTime();
	std::cout << "after sort(ms): " << end << std::endl << "cost time(ms): " << (end-start) << std::endl;

	fin.close();
	for(int j=0; j<num; ++j)
	{
		//std::cout << array[j] << ", ";
		fout << array[j] << ", ";
	}
	std::cout << std::endl << "total num = " << num << std::endl;
	return 0;
}

